#include <stdio.h> 
#include <stdlib.h>

/*typedef struct node{
    int data;
    struct node *next;
}node;*/

typedef struct list_node{
        int num;
        struct list_node *next;
} node;

node* readfile(FILE* fptr, node* head);
void printlist(node* head);
void freelist(node* head);

node* add_node(node* head, int *number);
node* delete_node(node *head);
int sum_list(node *head);
void free_list(node *head);

int main ()
{   
    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    node* head = NULL;
  
    head = malloc(sizeof(node));
 
    int i;
    for(i =0; i <10; i++)
    {
        head = add_node(head, (array+i));
    }

         printf("%d\n", (head->num));
  
  
   // head = readfile(fptr, head); 
   // printlist(head);

return 0;
}

node* add_node (node* head, int* number)
{
      node *temp;
      temp = malloc(sizeof(node));
      temp->num= *number;
      if (head == NULL)
      {
        head = temp;
        head->next = NULL;
      }
      else
      {
        temp->next = head;
        head = temp;
      }
    
return head;
}


void printlist(node* head)
{
  node *ptr = head;
    if( head  == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf( "The list is:\n" );
    
        while(ptr != NULL)
        {
            printf( "%d\n" , ptr->num);
            ptr = ptr->next;
        }
    }
    return;
}


