#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*NODE;

NODE getNode(int d)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    if(n==NULL)
        exit(0);
    //printf("Enter a number : ");
    n->data = d;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE insert_end(NODE head, int d)
{
    NODE temp = getNode(d);
    if(head==NULL)
        return temp;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

NODE delete_even(NODE head)
{
    if(head==NULL || head->next==NULL)
        return head;
    NODE cur = head, temp = NULL;
    while(cur!=NULL)
    {
        temp = cur;
        cur = cur->next;
        if(temp->data%2==0)
        {
            if(temp->next==NULL)
                temp->prev->next  = NULL;
            else
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
            }
            free(temp);
        }
    }
    return head;
}

void display(NODE head)
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        NODE cur = head;
        while(cur!=NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    NODE head = NULL;
    signed int d;
    while(1)
    {
        scanf("%d", &d);
        if(d==-1)
            break;
        head = insert_end(head, d);
    }
    head = delete_even(head);
    display(head);
    return 0;
}

