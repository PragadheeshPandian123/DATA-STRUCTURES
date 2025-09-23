#include <stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *next;
};
void create_list();
void insert_beg();
void insert_end();
void delete_beg();
void  delete_end();
void insert_middle();
void delete_middle();
void delete_all();
void display();
void search_node();
void sort_list();
void reverse();
int count=0;
struct node *start=NULL;
int main()
{
    int ch;
   do
   {
     printf("\nMenu:");
     printf("\n1.Create a linked list");
     printf("\n2.Insert a node at beggining");
     printf("\n3.Insert a node at end");
     printf("\n4.Insert a node at some position");
    printf("\n5.Delete a node at beginning");
    printf("\n6.Delete a node at end");
    printf("\n7.Delete a node at some position");
      printf("\n8.Update list");
    printf("\n9.Display linked list");
    printf("\n10.Delete entire list");
    printf("\n11.Search a value in the list");
    printf("\n12.Sort list");
    printf("\n13.Reverse list");
    printf("\n14.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        create_list();
        break;
        case 2:
        insert_beg();
        break;
        case 3:
        insert_end();
        break;
        case 4:
        insert_middle();
        break;
        case 5:
         delete_beg();
          break;
        case 6:
         delete_end(); break;
        case 7:
           delete_middle();break;
        case 8:
             break;
        case 9:
           display();
           break;
        case 10:
             delete_all();break;
        case 11:
          search_node();break;
        case 12:
           sort_list();break;
        case 13:
            reverse();break;
        case 14:
         printf("\nEnd of program!");break;
 
       
        default:
        printf("\nInvalid choice.please retry!");
    }
   }while(ch!=14);
   
    return 0;
}
void create_list()
{
    int val;
     printf("\nEnter value,-1 to stop:");
    scanf("%d",&val);
   
while(val!=-1)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
     new_node->num=val;
     new_node->next=NULL;
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {   struct node *ptr;
       
     ptr=start;
     while(ptr->next!=NULL)
     {
         ptr=ptr->next;
     }
     ptr->next=new_node;
    }
    count++;
    printf("\nEnter value,-1 to stop:");
    scanf("%d",&val);
}
printf("\nLinked list created!");

}
void insert_beg()
{
    int val;
    printf("\nEnter value to be inserted at beggining:");
    scanf("%d",&val);
     struct node *new_node=(struct node *)malloc(sizeof(struct node));
     new_node->num=val;
     new_node->next=NULL;
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {
   
     new_node->next=start;
     start=new_node;
    }
    count++;
    printf("\nValue inserted at beggining!");
}
void insert_end()
{
    int val;
    printf("\nEnter value to be inserted at end:");
    scanf("%d",&val);
     struct node *new_node=(struct node *)malloc(sizeof(struct node));
     new_node->num=val;
     new_node->next=NULL;
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {   struct node *ptr;
       
     ptr=start;
     while(ptr->next!=NULL)
     {
         ptr=ptr->next;
     }
     ptr->next=new_node;
    }
      count++;
      printf("\nValue inserted at end!");
}
void delete_beg()
{
    if(start==NULL)
    {
        printf("\nError!linked list is empty.");
        return;
    }
    struct node *temp;
    temp=start;
    start=start->next;
    free(temp);
     count--;
    printf("\nNode deleted successfully!");
}
void  delete_end()
{
    struct node *ptr,*preptr;
   
    ptr=start;
    preptr=ptr;
    if(ptr==NULL)
    {
        printf("\nError!linked list is empty.");
        return;
    }
    if(ptr->next == NULL) {
    free(ptr);
    start = NULL;
    count--;
    printf("\nNode deleted successfully!");
    return;
}
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
   
   
    preptr->next=NULL;
    free(ptr);
    count--;
    printf("\nNode deleted successfully!");
   
}
void delete_all()
{
     
    struct node *ptr,*temp;
    ptr=start;
   ptr=ptr->next;
    if(start==NULL)
    {
        printf("\nError!linked list is empty.");
        return;
    }
    while(ptr!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
        free(temp);
    }
    start=NULL;
   count=0;
    printf("\nLINKED LIST DELETED!");
}
void display()
{
    struct node *ptr;
    printf("\nLinked list:\n");
    ptr=start;
     if (ptr == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf("\t%d",ptr->num);
        ptr=ptr->next;
        if(ptr!=NULL) printf("->");
    }
    printf("\n%d",count);
}
void search_node()
{
    int i=0,ele;
    printf("\nEnter the value of the element to be searched:");
    scanf("%d",&ele);
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->num==ele)
        {
            printf("\nPosition of given element:%d",i);
            break;
        }
        ptr=ptr->next;
        i++;
    }
    if(ptr==NULL)
    {
        printf("\nElement not found!");
    }
}
void sort_list()
{
    int temp;
    struct node *ptr,*ptr2;
    ptr=start;
    ptr2=start;
    while(ptr!=NULL)
    {
        ptr2=start;
        while(ptr2->next!=NULL)
        {
         if(ptr2->num >ptr2->next->num)
         {
             temp=ptr2->num;
             ptr2->num=ptr2->next->num;
             ptr2->next->num=temp;
         }
         ptr2=ptr2->next;
        }
        ptr=ptr->next;
    }
    printf("\nLIST SORTED IN ASCENDING ORDER!");
}
void reverse()
{
struct node *next,*curr,*prev;
next=NULL;
prev=NULL;
curr=start;
while(curr!=NULL)
{
next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
}
start=prev;
printf("\nLIST REVERSED!");
}
void insert_middle()
{
  int pos,val,i=0;
  printf("\nEnter the position(index):");
  scanf("%d",&pos);
  printf("\nEnter the value to be inserted:");
  scanf("%d",&val);
  struct node *ptr;
   struct node *new_node=(struct node *)malloc(sizeof(struct node));
     new_node->num=val;
     new_node->next=NULL;
    ptr=start;
    if(pos==0)
    {
      insert_beg();
      return;
    }
    else if(pos==count)
    {
        insert_end();
        return;
    }
  while(i<pos-1)
  {
        i++;
     ptr=ptr->next;
  }
  new_node->next=ptr->next;
  ptr->next=new_node;
  count++;
  printf("\nValue inserted!");
}
void delete_middle()
{
     int pos,val,i=0;
  printf("\nEnter the position(index)in which the value is to be deleted:");
  scanf("%d",&pos);
  if(pos>=count)
  {
      printf("\nElement not found at this position");
      return;
  }
  if(pos==0)
  {
      delete_beg();
      return;
  }
  else if(pos==count-1)
  {
      delete_end();
      return;
  }
  struct node *ptr,*temp;
  ptr=start;
  while(i<pos-1)
  {
      ptr=ptr->next;
      i++;
  }
  temp=ptr->next;
  ptr->next=temp->next;
  free(temp);
  printf("\nValue delted!");
   
}