#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLL 6

typedef struct Node {
	int spaceID;
	int backValue;
	struct Node* next;
	struct Node* prev;
}node;

node* add_node(node* head, int spaceID, int backValue);
void play_game(node* head);
node* player_turn(node* user, int playerID);
void free_list(node* head);
void link_back_to_front(node* head);
void print_list(node *head);//prints reverse for some reason
void reverse(node* head);

int main(int argc, char** argv) {
    
    if(argc != 2)
    {
        printf("Incorrect number of arguments\nCorrect Usage: <./a.out> <input.txt>\n");
        exit(0);
    }

    char *file = *(argv+1);
    FILE *fptr = fopen(file, "r");

    node* head = NULL;
    int temp, temp2;
    node *link = NULL;
    head = link;

    while(fscanf(fptr, "%d %d", &temp, &temp2) != EOF)
    {
        link = malloc(sizeof(node));
        link->spaceID = temp;
        link->backValue = temp2;
        head = add_node(head, link->spaceID, link->backValue);
    }
    reverse(head);
       fclose(fptr);
 
    link_back_to_front(head);

    play_game(head);

   reverse(head);
    printf("NULL\n\n");

    player_turn(head, 8);
        
    free_list(head);
	return 0;
}

node* add_node(node* head, int spaceID, int backValue) {
    node* current = malloc(sizeof(node));

    if(current == NULL)
    {
        head = malloc(sizeof(node));
        current = head;
    }
    else
    {
        current->spaceID = spaceID;
        current->backValue = backValue;
        current->next = head;
        current->prev = current;
        head = current;
        current = current->next;
    }
	return head;
}

void link_back_to_front(node* head) {
   node* last = malloc(sizeof(node)); 
    head->prev = last;
    last->next = head;

	return;
}

void play_game(node* head) {
    
    node *p1 = head;
    node *p2 = head;
    int choice;
    int turn = 1;
    do{
        printf("Enter '1' to play the next turn: ");
        scanf("%d", &choice);
        if(choice != 1)
            printf("\nInvalid Choice\n"); 

        printf("Start Turn %d\n", turn);
        player_turn(p1, 1);
        printf("After turn %d player1 is on space %d and player 2 is on %d\n", turn, p1->backValue, p2->backValue);

        player_turn(p2, 2);
        printf("After turn %d player1 is on space %d and player 2 is on %d\n", turn, p1->backValue, p2->backValue); 
           
    turn++;

    }while(p1->spaceID == 0 && p2->spaceID == 0);

	return;
}
node* player_turn(node* user, int playerID) {
  srand(time(NULL));
  int roll;
  roll = rand()%MAX_ROLL;
    
    printf("Player %d rolled a %d!\n",playerID, roll);
  //  user->backValue += roll;
    
    user->spaceID += roll;
  //  user = user->next;
    
   
	return user;
}
void free_list(node* head) {

    node *temp;

    if(head == NULL)
    {
        printf("\nList is empty, cannot free\n");
    }
    else
    {
        while(head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
	return;
}

void print_list(node *head)
{
    node *ptr = head;
    if(ptr == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Printing list forward\n");
        while (ptr != NULL)
        {
            printf("'%d'---'%d' ->  ", ptr->spaceID, ptr->backValue);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void reverse(node* head)
{
    node *ptr = head;
    if(ptr != NULL)
    {
        reverse(ptr->next);
        printf("'%d'---'%d' ->  ", ptr->spaceID, ptr->backValue);
    }
   
}
