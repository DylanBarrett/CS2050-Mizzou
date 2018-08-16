#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int data;
        struct node *next;
}Node;



Node* push(int number, Node *head);
void print(Node *head);
void menu();
Node* pop(Node *head);

int main (void)
{
    Node* head = NULL;
    int choice, number;
 
    do{
           print(head);
           menu();
           scanf("%d",&choice);
           if (choice == -1)
           {
            exit(0);
           }

        switch (choice) 
        {
            case 1:
            printf("Enter a number to push a node onto the list: ");
            scanf("%d", &number);
           head =  push(number, head);
            break;

            case 2:
            head = pop(head);  
            break;
    
        

        default:
        printf("Invalid choice, please try again: \n");
        menu();
        scanf("%d",&choice);
        break;
        }

       } while (choice != -1);

}

Node* push(int number, Node* head)
{
    Node* temp = malloc(sizeof(Node));

    if(temp==NULL)
    {
        printf("head is empty");
    }
    else
    {
        temp-> data = number;
        temp->next = head;
        head = temp;
    }

return head;
}

Node* pop(Node* head)
{
  Node*  temp = head;
    head = head->next;
    
 free(temp);
 return head;

}


void menu()
{
    printf("Enter '1' to push a node onto the list\nEnter '2' to pop a node off of the list\nEnter '-1' to exit: \n");

    return;
}

void print(Node* head)
{
    Node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d -->", (ptr)->data);
            ptr = (ptr)->next;
        }
        printf("NULL\n");
    } 
}


