#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* link;
};
struct node* root=NULL;
void create(int A[],int n)
{
    root=(struct node*)malloc(sizeof(struct node));
    root->data=A[0];
    root->link=NULL;
    struct node* last=root;
    for(int i=1;i<n;i++)
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=A[i];
        temp->link=NULL;
        last->link=temp;
        last=temp;
    }
}
void sort(int n)
{
    struct node* p=root,*q=root;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(p->data>q->data)
            {
                int x;
                x=p->data;
                p->data=q->data;
                q->data=x;
            }
            q=q->link;
        }
        p=p->link;
        q=p;
    }
}
void display()
{
    struct node* temp=root;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
int main()
{
    int A[]={10,9,8,7,6,5,4,3,2,1};
    create(A,10);
    sort(10);
    display();
    return 0;
}