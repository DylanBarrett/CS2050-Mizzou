#include <stdio.h> 
#include <stdlib.h>


typedef struct list_node{
        int num;
        struct list_node *next;
} node;


void printlist(node* head);

node* add_node(node* head, int *number);
node* delete_node(node *head);
int sum_list(node *head);
void free_list(node *head);

int main ()
{   
    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    node *head = NULL;
  
    int i = 0;
    for(i=0; i <10; i++) 
    {
         head = add_node(head, (array+i));
        //  printf("%d\n", (head->num));

    }
//    printlist(head);
 /*   printf("\nThe sum of the list is %d\n", sum_list(head));
       
    free_list(head);
    head = NULL;

    printf("\nThe sum of the list is %d\n", sum_list(head));*/


    

return 0;
}

node* add_node (node* head, int* number)
{
        node  *current = head;
     
        
            if(head==NULL)
            {
                head = malloc(sizeof(node));
                current = head;          
            }
            else
            {
                 while( current->next != NULL)
                {
                    current = current->next;
                }
                current->next = malloc(sizeof(node));
                current = current->next;
            }
              
         current->num = *number;  

return head;
}

int sum_list (node* head)
{
    node *ptr = head;
    int sum = 0;
    
    if(head == NULL)
    {   
        printf("Node is empty\n");
        return -1;

    }
    else
    {
        while(ptr != NULL)
        {
            sum += ptr->num;
            ptr = ptr->next;
        }
    }

free(ptr);
return sum;
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
    
      while ( ptr != NULL) 
       {
            printf( "%d\n" , ptr->num);
            ptr = ptr->next;
        }
    }
    return;
}

void free_list(node *head)
{
    node *temp;
    
    if(head == NULL)
    {
        printf("\nList is empty, cannot free\n");
    }
    else{
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

   // free(temp);
    return;
}


