#include <stdio.h>
#include <stdlib.h>
struct node
{
    int co,po;
    struct node *addr;
};
typedef struct node *NODE;
NODE insertend(NODE Start,int co,int po)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->addr=NULL;
    if(Start==NULL)
        return temp;
    cur=Start;
    while(cur->addr!=NULL)
        cur=cur->addr;
    cur->addr=temp;
    return Start;
}
void display(NODE Start)
{
    NODE temp;
    if(Start==NULL)
        printf("\nPolynomial Empty");
    else
    {
        temp=Start;
        while(temp->addr!=NULL)
        {
            printf("%d*x^%d+",temp->co,temp->po);
            temp=temp->addr;
        }
        printf("%d*x^%d",temp->co,temp->po);
    }
}
NODE addterm(NODE res,int co,int po)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->addr=NULL;
    if(res==NULL)
        return temp;
    cur=res;
    while(cur!=NULL)
    {
        if(cur->po==po)
        {
            cur->co=cur->co+co;
            return res;
        }
        cur=cur->addr;
    }
    if(cur==NULL)
    {
        res=insertend(res,co,po);
        return res;
    }
}
NODE multiply(NODE poly1,NODE poly2)
{
    NODE p1,p2,res=NULL;
    for(p1=poly1;p1!=NULL;p1=p1->addr)
         for(p2=poly2;p2!=NULL;p2=p2->addr)
            res=addterm(res,p1->co*p2->co,p1->po+p2->po);
    return res;
}
int main()
{
    NODE poly1=NULL,poly2=NULL,poly;
    int n,i,co,po;
    printf("\nRead the no.of terms of the first polynomial:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nRead co and po of %d term:",i);
        scanf("%d %d",&co,&po);
        poly1=insertend(poly1,co,po);
    }
    printf("\n 1st polynomial is\n");
    display(poly1);
    printf("\nRead the no.of terms of the second polynomial:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nRead co and po of %d term:",i);
        scanf("%d %d",&co,&po);
        poly2=insertend(poly2,co,po);
    }
    printf("\n 2nd polynomial is\n");
    display(poly2);
    poly=multiply(poly1,poly2);
    printf("\nResultant polynomial is\n");
    display(poly);

    return 0;
}
