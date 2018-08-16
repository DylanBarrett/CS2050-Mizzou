//Libraries in use
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//CLA = command line arguments for the program
#define CLA 2

//Given limits
#define MAXLINELENGTH 200
#define MAXWORD 25
#define MAXCARPRICE 1000000

typedef struct node {
        char *make;
        char *model;
		int price;
        int year;
        char *color;
        char *type;
		int mileage;
        struct node* left;
        struct node* right;
} node;

//prototypes
node* get_cars(char* filename);
node* add_to_tree(node* head, node* new);
void Free_Tree(node* root);
void search_tree(node* root, int year, int price, int* count);
int OpenFile(FILE **InPtr, char *argv);

int main (int argc, char *argv[])
{
	//Declare variables
	node *root = NULL;
	char* File_Name = argv[1];
	int choice = 0;
	int year = 0;
	int price = 0;
	int count = 0;
	
	//argument enforcement
	if(argc != 2)
	{
		printf("\tInvalid Use of Program\n\tValid Use: 'Program Name' input.txt\n");
	}
	
	root = get_cars(File_Name);
	
	while(choice != -1)
	{
	count = 0;
	year = 0;
	price = 0;
	count = 0;
	
	printf("\nTo search for a vehicle newer than a specific year enter '1'");
	printf("\nTo search for a vehicle that costs less than a certain price enter '2'");
	printf("\nTo search for a vehicle with both of the above parameters enter '3'");
	printf("\nTo exit enter '-1' :    ");
	
	scanf("%d", &choice);
	
	if(choice == 1)
	{
		printf("\nEnter year: ");
		scanf("%d", &year);
		search_tree(root, year, price, &count);
	}
	if(choice == 2)
	{
		printf("\nEnter price: ");
		scanf("%d", &price);
		search_tree(root, year, price, &count);
	}
	if(choice == 3)
	{
		printf("\nEnter year: ");
		scanf("%d", &year);
		printf("\nEnter price: ");
		scanf("%d", &price);
		search_tree(root, year, price, &count);
	}
	}
	
	Free_Tree(root);
	//printf("\n\nFree ran....");
	
return(0);	
}

void search_tree(node* root, int year, int price, int* count)
{
	if(price == 0)
	{
	if(root != NULL)
	{
	if(root->year >= year)
		{
			printf("\n%d %s %s that cost $%d", root->year, root->make, root->model, root->price);
		}
		if(root->price <= price && root->year <= year)
		{
			printf("\n%d %s %s that cost $%d", root->year, root->make, root->model, root->price);
		}
		search_tree(root->right, year, price, count);
		search_tree(root->left, year, price, count);
	}
	}
	else
	{
	if(year == 0)
	{
	if(root != NULL)
	{
		if(root->price <= price)
		{
			printf("\n%d %s %s that cost $%d", root->year, root->make, root->model, root->price);
		}
		search_tree(root->right, year, price, count);
		search_tree(root->left, year, price, count);
	}
	}
	else
	{
	if(year != 0 && price != 0)
	{
	if(root != NULL)
	{
	if(root->price <= price && root->year >= year)
		{
			printf("\n%d %s %s that cost $%d", root->year, root->make, root->model, root->price);
		}
		search_tree(root->right, year, price, count);
		search_tree(root->left, year, price, count);
	}
	}
	}
	}
}

node *get_cars(char* filename)
{
node* root = NULL;
char whole[MAXLINELENGTH];
FILE *InPtr = NULL;
OpenFile(&InPtr, filename);
int testcount1 = 0;
int testcount2 = 0;

while(testcount1 != -1){
char* previous = NULL;
char* current = NULL;
if(fgets(whole, MAXLINELENGTH, InPtr) == NULL){break;}

node *temp = malloc(sizeof(node));

//printf("\n %s", whole);
	while(testcount2 < 7)
	{
	if (!current)
	{
		previous = strtok(whole, "|");
		current = strtok(NULL, "|");
		//printf("\n\n1.) %s %s\n\n", current, previous);
	}
	else
	{
		previous = strtok(NULL, "|");
		current = strtok(NULL, "|");
		//printf("\n\n2.) %s %s\n\n", current, previous);
	}
	if(strcmp(previous, "make") == 0)
	{
		temp->make = strdup(current);
		//printf("\n\nTest make load\n\n");
	}
	if(strcmp(previous, "model") == 0)
	{		
		temp->model = strdup(current);
	}
	if(strcmp(previous, "color") == 0)
	{
		temp->color = strdup(current);
	}
	if(strcmp(previous, "type") == 0)
	{
		temp->type = strdup(current);
	}
	if(strcmp(previous, "price") == 0)
	{
		temp->price = atoi(current);
	}
	if(strcmp(previous, "year") == 0)
	{
		temp->year = atoi(current);
	}
	if(strcmp(previous, "mileage") == 0)
	{
		temp->mileage = atoi(current);
	}
	testcount2++;
	}
temp->left = NULL;
temp->right = NULL;
root = add_to_tree(root, temp);
testcount2 = 0;
}
fclose(InPtr);
return root;
}

void Free_Tree(node* root)
{
	if(root != NULL)
	{
	//printf("\n\n Make: %s\n  Model: %s\n  Price: %d\n  Year: %d\n  Colour: %s\n  Type: %s\n  Mileage: %d \n\n", root->make, root->model, root->price, root->year, root->color, root->type, root->mileage);
	Free_Tree(root->left);
	Free_Tree(root->right);
	free(root->make);
	free(root->model);
	free(root->color);
	free(root->type);
	free(root);
	}
}

node* add_to_tree(node* root, node* leaf)
{
if(root == NULL)
	{
	return leaf;
	}
if(leaf->price <= root->price)
{
root->left = add_to_tree(root->left, leaf);
}
else
{
root->right = add_to_tree(root->right, leaf);
}
return (root);
}

int OpenFile(FILE **InPtr, char *argv)
{
int State = 1;
*InPtr = fopen(argv, "r");
if(*InPtr == NULL){printf("\nFile failed to load at open..."); State = 0;}
return (State);
}
