#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[10];
    int reg;
    char Symptoms[1000];
    char Dname[20];
    struct node *next;
};
typedef struct node NODE;
NODE *create(struct node *s);
void display(struct node *s);
NODE *Insert(NODE *s);
NODE *Delete(NODE *s);
void main()
{ 
    struct node *s=NULL;
    int op;int n;
    printf("-----------------------------WELCOME TO PATIENT REGISTRATION SYSTEM-----------------------------");
    printf("\n\nEnter option:\n");
    printf("1..Create\n2..Display\n3..Insert\n4..Delete\n5..Exit\n");
    printf("enter choice:\n");
    do
    {
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                s=create(s);
                break;
            case 2:
                
                printf("Data is :\n");
                display(s);
                break;
            case 3:
                Insert(s);
                break;
            case 4:
                Delete(s);
                break; 
            case 5:
                printf("\nNice working With You\n\n\n-------------Exited-------------");
                exit(0);
                break;
            default:
                printf("\n##### Invalid option #####  \nValid Options are:\n\n");
        }
        printf("Enter option:\n");
        printf("1..Create\n2..Display\n3..Insert\n4..Delete\n5..exit\n");
        printf("enter choice:\n ");     
    }while(op!=5);
}
 NODE *create(struct node *s)
{
    struct node *t,*q;
    int regis,i,c=1;
    s=(struct node *)malloc(sizeof(struct node));
    while (c!=0)
    {
            if(s==NULL)
        {
            printf("Memory not allocated ");
            exit(0);
        }
        else
        {
            t=s;
            q=(NODE*)malloc(sizeof(NODE));
            printf("Enter Name of Patient:");
            scanf("%s",&q->name);
            fflush(stdin);
            printf("Enter PatientID:\n");
            scanf("%d",&q->reg);
            printf("Enter Symptoms:\n");
            scanf("%s",&q->Symptoms);
            printf("Enter Doctor's name:\n");
            scanf("%s",&q->Dname);
            fflush(stdin);
            q->next=NULL;
            t->next=q;
            t= t->next;
            printf("Wish to add another patient:");
            scanf("%d",&c);    
        }
    } 
    return s;
}
NODE *Insert(NODE *s)
{
    NODE *p;NODE *t;
    p=(NODE *)malloc(sizeof(NODE));
     printf("Enter Name of Patient:");
    scanf("%s",&p->name);
    fflush(stdin);
    printf("Enter PatientId :\n");
    scanf("%d",&p->reg);
    printf("Enter Symptoms:\n");
    scanf("%s",&p->Symptoms);
    printf("Enter Doctor's name:\n");
    scanf("%s",&p->Dname);
    fflush(stdin);
    p->next=NULL;
    if(s==NULL)
    {
        s=p;
        return s;
    }
    else
    {
        t=s;
        while (t->next!=NULL)
        {
            t=t->next;
        }
        t->next=p;
        return s;
        
    }
}
NODE *Delete(NODE *s)
{
    NODE *t;NODE *p;
    int d;
    printf("Enter PatientIDNo. to delete :\n");
    scanf("%d",&d);
    if(s==NULL)
    {
        printf("Empty");
        return s;
    }
    else if(s->reg==d)
    {
        p=s;
        s=s->next;
        free(p);
        p=NULL;
    }
    else
    {
        t=p=s;
        while(t->next!=NULL&&t->reg!=d)
        {
            p=t;
            t=t->next;
        }
        if(t->reg==d)
        {
            p->next=t->next;
            free(t);
            t=NULL;
        }
        return s;
    }
}
void display(NODE *start)
{
    
    printf("______\n");
    while(start!=NULL)
    {
        printf("Patient ID:%d\n",start->reg);
        printf("Name :%s\n",start->name);
        printf("Symptoms Name :%s\n",start->Symptoms);
        printf("Doctor's Name:%s\n",start->Dname);
        printf("\n");
        start=start->next;
    }
     printf("______\n");
}