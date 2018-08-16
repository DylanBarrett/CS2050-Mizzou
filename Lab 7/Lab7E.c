#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
        char *string;
        struct node *next;
}Node;

#define MAX 25

Node* add_to_front(char* word, Node *head);
void print(Node *head);
void menu();
Node* remove_from_front(Node *head);
Node* add_to_back(char* word, Node *head);
void free_list(Node* head);
char* grab_back(Node* head);

Node* remove_from_back(Node *head);

int main (void)
{
    Node* head = NULL;
    int choice; 
    char word;
    char* temp;
 
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
            printf("Enter a word to add to the document: ");
            scanf("%s", &word);
                  head = add_to_back(&word, head);
            break;

            case 2:
            if (head == NULL)
            {     
                break;
            }
             temp = grab_back(head);
           // head = remove_from_back(head);        
            head = remove_from_front(head); 
        
            

            break;

            case 3:
            head= add_to_front(temp, head);
            break;


    
        

        default:
        printf("Invalid choice, please try again: \n");
        menu();
        scanf("%d",&choice);
        break;
        }

       } while (choice != -1);
free(temp);
free_list(head);
}

Node* add_to_front(char *word, Node* head)
{
    Node* temp = malloc(sizeof(Node));
    temp->string = malloc(strlen(word)*MAX);

     if(head == NULL)
    {
        strcpy(temp->string, word);
        head = temp;
    }
    else
    {
       strcpy(temp->string, word);     
       temp->next = head;
       head = temp;
       }



return head;
}


char* grab_back(Node* head)
{
    Node* temp = head;
    char* thing = temp->string;
 
    return thing;
}

Node* remove_from_front(Node* head)
{
  Node*  temp = head;
    head = head->next;
    
 free(temp);
 return head;

}

Node* remove_from_back(Node *head)
{
    Node *temp = head;
    Node *current;

    while(temp->next!= NULL)
    {
        current = temp;
        temp = temp->next;
    }

    free(current);
    //current->next = NULL;
    
    return head;
}



void menu()
{
    printf("Enter '1' to add a word to the sentence\nEnter '2' to undo\nEnter '3' to redo\nEnter '-1' to exit: \n");

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
            printf("%s ", (ptr)->string);
            ptr = (ptr)->next;
        }
        printf("\n");
    } 
}

Node* add_to_back(char *word, Node *head)
{
    
    Node* temp = malloc(sizeof(Node));
    Node* current;
    temp->string = malloc(strlen(word)*MAX);
     strcpy(temp->string, word);
     temp->next = NULL;

     if (!head)
         return temp;

         current= head;

         while(current->next)
             current = current->next;
             current->next = temp;
             return head;

    
     
    return head;
}

void free_list(Node *head)
{
    Node* temp;

    if( head == NULL)
    {
        printf("The list is already empty\n");
    }
    else{
        while (head!= NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    return;
}
