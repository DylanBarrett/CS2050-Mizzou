#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int num;
    int count;
    struct Node* left;
    struct Node* right;
}node;

node* add_to_tree(node* head, int number);
int print_totals(node* head, int count);
void free_tree(node* head);

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("Correct Usage: ./a.out <input file> <max number>\n");
        exit(0);
    }
    
    char* file = *(argv+1);
    int max = atoi(*(argv+2));
    FILE *fptr;
    fptr = fopen(file, "r");
    if(fptr == NULL)
        {
            printf("Error opening File\n");
            exit(0);
        }
  node* head = NULL;
  int choice = 0;
  int total = 0;
do{

    int temp;
    int addnum;   
    int count = 0;

    printf("\nEnter '1' to add a number to the tree\nEnter '2' to print the totals for each number\nEnter '-1' to terminate the program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);


    if(choice == -1)
    {
        exit(0);
    }


    while(fscanf(fptr, "%d", &temp) != EOF)
    {
               
      //  printf("temp = %d\n", temp);
        head = add_to_tree(head, temp); 
        total++;
     }
    switch (choice)
    {
       case 1:
       
        printf("Enter a number(0-%d)\n", max );
        scanf("%d", &addnum);
        
        while(addnum < 0 || addnum > max)
        {
            printf("Please Enter a number from 0 through %d\n", max);
            scanf("%d", &addnum);
        }

        head = add_to_tree(head, addnum);
        total++;
           break;

       case 2:    
         print_totals(head, count);
         printf("Total = %d", total);
         break;



         default:
         printf("Invalid choice, please try again: \n");
         scanf("%d", &choice);
         break;
    }
    

  
}while(choice != -1);
     free_tree(head);

}

node* add_to_tree(node* head, int number)
{ 
        if(head == NULL)
        {
            head = malloc(sizeof(node));
            head->num = number;
            head->left = NULL;
            head->right = NULL;
        }

       if( number== head->num)
            {
                head->count++;
               // printf("%d\n",head->count);
            }

        else if (number < head->num)
        {
            head->left =  add_to_tree(head->left, number);          
        }
        else if(number > head->num)
        {
           head->right = add_to_tree(head->right, number);
        
        }
    
    return head;
}


int print_totals(node*head, int count)
{
    if (head!= NULL)
    {
        count = print_totals(head->left, count);
        printf("There are %d occurnces of the number %d\n",head->count, head->num);
        count = print_totals(head->right, count)+ head->count;
    }
    return count;
}

void free_tree(node* head)
{
    if (head != NULL)
    {
        free_tree(head->left);
        free_tree(head->right);
        free (head);
    }
}
