#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{   
    int roll_no;
    char name[30];
};

struct queue
{   int roll_no;
    char name[30];
    int front , rear;
};

void init( struct queue* q){
    q->front=0;
    q->rear=0;}


void enqueue(struct student *p , struct queue *q)
{
    q->roll_no=p->roll_no;
    strcpy(q->name , p->name);
    (q->rear) = (q->rear) +1;
    
    printf("\n %s",q->name);
    printf(" %d",q->roll_no);
}


int main()
{
    int num , i;
    struct student *p ;
    struct queue *q;

    printf("\n Enter total number of students : ");
    scanf("%d" , &num);

    p = (struct student *)malloc(num*sizeof(struct student));
    q = (struct queue *)malloc(num*sizeof(struct queue));
    init(q);

    printf("Enter the details of student: \n");
    for ( i=0 ; i<num ; i++)
    {
        printf("Roll No : ");
        scanf("%d" , &(p+i)->roll_no);
        fflush(stdin);

        printf("Name : ");
        gets((*(p+i)).name);
        fflush(stdin);

    } 

    for ( i=0 ; i<num ; i++)
    {
        if( ((p+i)->roll_no) % 2 == 0) 
        {
            enqueue(p+i , q);
        }
    }
    
    return 0;
}