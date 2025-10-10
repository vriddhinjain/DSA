#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue
{
    int front,rear;
    int data[SIZE];
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item)
{
    if(q->rear==SIZE-1)
    {
        printf("\n Queue overflow-Queue is full!\n");
    }
    else
    {
        q->rear++;
        q->data[q->rear]=item;
        if(q->front==-1)
            q->front=0;
        printf("\n Inserted %d into the queue\n",item);
    }
}
void dequeue(QUEUE *q)
{
    if(q->front==-1)
        printf("\n queue underflow-Queue is empty!\n");
    else
    {
        printf("\n Deleted element is %d\n",q->data[q->front]);
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else
        {
            q->front++;
        }
    }
}
void display(QUEUE q)
{
    int i;
    if(q.front==-1)
        printf("\n Queue is empty\n");
    else
    {
        printf("\n Queue contents are:\n");
        for(i=q.front;i<=q.rear;i++)
            printf("\n %d\t",q.data[i]);
        printf("\n");
    }
}
int main()
{
    int item,ch;
    QUEUE q;
    q.front=-1;
    q.rear=-1;
    while(1)
    {
        printf("\n---------------queue-------------------");
        printf("\n1.enqueue. \n2.dequeue. \n3.display. \n4.exit.");
        printf("\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter element to insert:");
                scanf("%d",&item);
                enqueue(&q,item);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("\nExiting program.....\n");
                exit(0);
            default:
                printf("\n Invalid choice!Please try again\n");

        }
    }
    return 0;
}
