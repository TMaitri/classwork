#include<stdio.h>
#include<stdlib.h>

typedef struct PATIENT
{
    char p_name[30];
    int age;
    char gender;
    int p_id;
    long int aadhar;
    struct PATIENT *next;
} *PT;
/* INSERTION,  DELETION, COUNT, SEARCH */
int c=0;

 PT  create_node()
   {
       PT new1;
       new1 = (PT)malloc(sizeof(struct PATIENT));// allocation of memory

         printf("ENTER THE DETAILS OF THE PATIENT\n");// storing the information into the node
       scanf("%s%d%c%d%ld",new1->p_name,&new1->age,&new1->gender, &new1->p_id,&new1->aadhar);

       new1->next=NULL;

       return new1;
   }
    PT insert_front(PT head,PT temp){
 c++;
 if( head == NULL)
     head = temp;
 else
 {
     temp->next = head;
     head = temp;
 }
 return head;

 }
 void display(PT head){
      PT cur;
   cur=head;
   if(head==NULL){
        printf("NO PATIENTS");
   }
   else
   {
      printf("THE DETAILS OF PATIENTS ARE \n");
      while(cur!=NULL)
      {
         printf("%s\t%d\t%c\t%d\t%ld\n",cur->p_name, cur->age,cur->gender,cur->p_id,cur->aadhar);
         cur=cur->next;
      }
   }
 }
 PT insert_end(PT head, PT temp)
 {
     PT cur = head;
     c++;
      if(head==NULL)
         head=temp;
      else
      {
          while(cur->next != NULL)
            cur = cur->next;

          cur ->next =temp;
          temp->next=NULL;
      }
      return head;
 }

 PT delete_front(PT head)
 {

  if(head == NULL){
    printf("NO PATIENTS\n");

  }
  else {
          c--;
           PT cur=head;
           head = cur->next;
           free(cur);
       }
  return head;

 }
 PT delete_end(PT head){
  if(head ==NULL){
    printf("NO PATIENTS\n");

  }
  else
  {
      c--;
      PT cur=head,prev=NULL;
     while(cur->next !=NULL){
        prev=cur;
        cur=cur->next;
     }
     prev->next =NULL;
     free(cur);

  }
  return head;
 }
int count(PT head)
{
    int cnt=0;
    PT cur=head;
    while(cur!= NULL)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

PT insert_pos(PT head, int pos,PT temp){
  PT cur=head;
  c++;
  if(head == NULL)
  {
    head = temp;
    return head;
  }
  // single node in the list
 /*if(cur->next == NULL){
    cur->next = temp;
    return head;
  }*/
  if(pos==1){
    temp->next = cur;

    head= temp;
    return head;
  }

  int i;
  for(i=1;i<pos-1;i++)
    cur=cur->next;

  temp->next = cur->next;
  cur->next=temp;
  return head;
}

PT delete_pos(PT head, int pos)
{
   PT prev =NULL , cur= head;
   int i;
   if(pos==1)
    {
      head = cur->next;
      free(cur);
      return head;
   }

   for(i=1;i<pos;i++)
   {
       prev=cur;
       cur=cur->next;
   }
   c--;
   prev->next = cur->next;
   free(cur);
   return head;
}

void search(PT head, int id)
{
 PT cur= head;
 int flag=0;
 while(cur!=NULL)
    {
        if(cur->p_id == id)
        {
            flag =1;
            printf("The details of the patient are \n");
            printf("%s\t%d\t%c\t%d\t%ld\n",cur->p_name,cur->age,cur->gender,cur->p_id,cur->aadhar);
            break;
        }
        cur=cur->next;
   }
        if(flag == 0)
            printf("Patient not found \n");

}

    int main()
    {
       PT temp,head = NULL;
       int cnt,id,ch,pos;
       printf("\n 1. Insert_front\n 2. Insert_end\n 3. Insert_pos\n 4. Delete_front\n 5. Delete_end\n 6. Delete_pos\n 7. Display\n 8. Search\n");
       while(1)
       {
          printf("Enter your choice\n");
          scanf("%d",&ch);
       switch(ch)
       {
        case 1: temp = create_node();
                head = insert_front(head,temp);
                break;
        case 2: temp= create_node();
                head= insert_end(head,temp);
                break;
        case 3:
                 printf("\nEnter the position to insert\n");
                 scanf("%d", &pos);
                 if(pos<=c+1)
                     {
                    temp=create_node();
                    head = insert_pos(head, pos,temp);

                 }
                 else
                     printf("Cannot insert\n");

                  break;

         case 4 :   head  = delete_front(head);
                     break;
         case 5:    head = delete_end(head);
                     break;

         case 6 :    printf("Enter the position to delete\n");
                      scanf("%d", &pos);
                      if(pos<=c)
                      {
                         head=delete_pos(head, pos);
                         display(head);
                      }
                      else
                          printf("Invalid position cannot delete");
                       break;

          case 7 :   display(head);
                      break;
          case 8 :   printf("Enter the patient id\n");
                      scanf("%d",&id);
                      search(head,id);
                       break;

          default : printf("Invalid choice");
                       exit(0);
        }//  end of switch

       } //end of while

    }// end of main
