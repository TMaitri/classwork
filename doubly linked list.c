#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct playlist
{
	char song[25];
	char singer[25];
	char movie[25];
     float size_of_song;
	struct playlist *next;
	struct playlist *previous;

};
typedef struct playlist *NODE;

NODE getnode()
 {
	NODE newNode = (NODE)malloc(sizeof(struct playlist));
	if(newNode==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	printf("Enter details\n");
	scanf("%s%s%s%f", newNode->song, newNode->singer,newNode->movie, &newNode->size_of_song);
	newNode->previous = NULL;
	newNode->next = NULL;
	return newNode;
}

NODE insert_front(NODE head){
NODE newNode = getnode();

if(head == NULL){

    head = newNode;
    return head;
 }

  head->previous = newNode;
  newNode -> next = head;
  head = newNode;
  return head;
 }

 void display(NODE head)
 {
   NODE cur = head;
   if(head == NULL)
   {
       printf("EMPTY LIST\n");
   }
     else{
            printf("THE LIST IS \n");
           while(cur!=NULL){

            printf("%s\t%s\t%s\t%f\n",cur->song,cur->movie,cur->singer,cur->size_of_song);
            cur=cur->next;
        }

    }
 }
 NODE insert_end(NODE head)
 {
     NODE newNode = getnode();
     if(head == NULL)
       {
           head = newNode;
           return head;
       }
       NODE cur = head;
       while(cur->next !=NULL)
             cur = cur ->next;
       cur->next = newNode;
       newNode->previous = cur;
       return head;

 }
 NODE insert_pos(NODE head)
 {
     float size;
     int flag = 0;
     printf("Enter the node to insert after a specified node");
     NODE newNode = getnode();
     printf("Enter the size after which to insert\n");
     scanf("%f",&size);
     if(head == NULL)
       {
           head = newNode;
           return head;
       }
    NODE temp1, temp2;
    temp1= head;
    while(temp1->next!= NULL)
    {
        if(temp1->size_of_song == size)
      {
          flag=1;
          temp2=temp1->next;
          temp1->next = newNode;
          newNode->previous = temp1;
          temp2->previous = newNode;
          newNode->next = temp2;

          return head;
      }
      temp1 = temp1->next;
    }//end of while

// to handle last node
     if(temp1->next == NULL)
        {
         if(temp1->size_of_song == size)
          {
              flag=1;
              temp1->next = newNode;
              newNode->previous = temp1;
              return head;

          }
        }
       if(flag ==0)
           printf("Invalid size\n");
     return head;
 }


 NODE delete_front(NODE head){

  if(head == NULL)
    printf("Cannot delete . List is empty\n");
  else if(head ->next == NULL)
    {

          free(head);
          head = NULL;

    }
    else
    {
        NODE temp = head;
        head = head->next;
        head->previous = NULL;
        free(temp);
    }
        return head;
 }
 NODE delete_end(NODE head){
   if(head == NULL)
      printf("\nCannot delete . List is empty\n");
  else if(head ->next == NULL)
    {

          free(head);
          head = NULL;

    }
    else{
          NODE prev = NULL,  cur= head;
          while(cur->next != NULL)
          {

              cur = cur->next;

          }
            prev = cur->previous;
            prev->next = NULL;
            free(cur);
    }

        return head;
 }

 NODE delete_song(NODE head){
 if(head == NULL)
    printf("Cannot delete.List is empty.\n");
 else
 {
   int flag =0;
   char sname[20];
   printf("Enter the song to delete\n");
   scanf("%s",sname);
   NODE cur = head,prev;

   if(strcmp(head ->song,sname)==0)
   {
       NODE temp = head;
       flag =1;
       head=head->next;
       free(temp);
       head->previous = NULL;
       return head;
   }
   else
   {
     while(cur->next != NULL)
     {
     if(strcmp(cur->song, sname)==0)
        {


             flag =1;
            prev = cur->previous;
            prev->next = cur->next;
            cur->next->previous = prev;
            free(cur);
         }
           cur= cur->next;
    }

     if( cur->next == NULL)
     {
         if(strcmp(cur->song,sname)==0)
         {
             flag=1;
             prev= cur->previous;
             prev->next=NULL;
             free(cur);
         }
     }

   }
    if(flag == 0)
        printf("No such song found. Cannot delete\n");

  }//end of outer else
    return head;
 }
 int main(){

 NODE head=NULL;

 head = insert_front(head);
 head = insert_front(head);


 for(int i=1;i<=3;i++)
        head = insert_end(head);

  head = insert_pos(head);

 display(head);

 head = delete_front(head);
 head = delete_end(head);
     display(head);

 head = delete_song(head);

   display(head);


 }
