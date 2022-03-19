#include<stdio.h>
#include<stdlib.h>
 struct node{
   int i;
   struct node *next;
   };
int main()
{
    struct node *head ,*new1;
    int m,n,arr[100][100];
    scanf("%d %d",&m,&n);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {    new1 = (struct node*)malloc(sizeof(struct node));
            scanf("%d",&arr[i][j]);
            new1->i=arr[i][j];
            new1->next=head;
           head=new1;
        }
    }
    delete_end(head);
    display(head);
}
void delete_end(struct node *head)
{
    struct node *del,*prev;
    prev=head;
    del=head;
    while(prev->next!=NULL)
    {
        prev=del;

    }
    del=del->next;
    free(del);
    prev->next=NULL;


}

void display(struct node *head)
{
    struct node *temp;
    temp=head;

    while(temp!=NULL)
    {
        printf("%d",temp->i);
        temp=temp->next;
    }
   }

