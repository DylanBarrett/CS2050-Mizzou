#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAXLINELENGTH 200
#define MAXCARPRICE 1000000

typedef struct node {
        char make[25];
        char model[25];
		int price;
        int year;
        char color[25];
        char type[25];
		int mileage;
        struct node* left;
        struct node* right;
} Node;

Node* get_cars(char* filename);
Node* add_to_tree(Node* head, Node* new);
void Free_Tree(Node* root);
void search_tree(Node* root, int year, int price, int* count);
int bonus_search(Node* root, int price, char* make, char* color, int* count);
void menu();

int main (int argc, char *argv[])
{
	Node *root = malloc(sizeof(Node));
	char* input = argv[1];
	int choice = 0;
	int year = 0;
	int price = 0;
	int count = 0; 
    char make[25];
    char color[25];
    int checkBonus;
	
	if(argc != 2)
	{
		printf("Correct input: ./a.out <input file>\n");
	}
	
	root = get_cars(input);
    do{
         menu();
         scanf("%d", &choice);
         if(choice == -1)
         {
            exit(0);
         }

	        switch(choice)
            {
	            count = 0;
	            year = 0;
	            price = 0;
	            
      	        case 1:   
		        printf("\nEnter the year you would like the vehicles to be newer than: ");
		        scanf("%d", &year);
		        search_tree(root, year, price, &count);
                printf("\nThere were %d cars found\n", count);
                count = 0;

                break;
	        
	            case 2:
		        printf("\nEnter the price you would like the vehicles to be less than: ");
		        scanf("%d", &price);
		        search_tree(root, year, price, &count);
                printf("\nThere were %d cars found\n", count);
                count = 0;

	            break;

	            case 3:
		        printf("\nEnter the year you would like the vehicles to be newer than: ");
		        scanf("%d", &year);
		        printf("\nEnter the price you would like the vehicles to be less than: ");
		        scanf("%d", &price);
		        search_tree(root, year, price, &count);
                printf("\nThere were %d cars found\n", count);
                count = 0;
	            break;

                case 4:
                 printf("\nEnter the price you would like the vehicles to be less than: ");
		         scanf("%d", &price);
                 printf("\nEnter the make of the vehicle you would like: ");
                 scanf("%s", make);
                 printf("Enter the color of the vehicle you would like: ");
                 scanf("%s", color);
               checkBonus =  bonus_search(root, price, make, color, &count);
               if (checkBonus == 1)
               {
                 printf("\nThere were %d cars found\n", count);
               }
                 count = 0;
                 break; 

            default:
            printf("\nInvalid choice, please try again: \n");
            menu();
            scanf("%d", &choice);
            break;
        }
	}while(choice != -1);
	
//	Free_Tree(root); // gives abort trap error when user puts invalid number into 'choice'

	
return 0;	
}

void menu()
{
    printf("\nTo search for a vehicle newer than a specific year enter '1'");
	printf("\nTo search for a vehicle that costs less than a certain price enter '2'");
    printf("\nTo search for a vehicle with both of the above parameters enter '3'");
    printf("\nTo search for a vehicle by price, make, and color enter '4'");
    printf("\nTo exit enter '-1'\n");	
}
void search_tree(Node* root, int year, int price, int* count)
{
	if(price == 0)
	{
	    if(root != NULL)
	    {
             search_tree(root->left, year, price, count);		
	        if(root->year >= year)
		    {
			    printf("\n%d %s %s that cost $%d", root->year, root->make, root->model, root->price);  
                *count = *count+1;
		    }
           search_tree(root->right, year, price, count);
	    }
	}
	else if(year == 0)
	{	    
	    if(root != NULL)
	        {               
                search_tree(root->left, year, price, count);
		        if(root->price <= price)
		        {   
			        printf("\n%d %s %s that cost $%d", root->year, root->make, root->model, root->price);
                    *count = *count+1;
		        }
  		        search_tree(root->right, year, price, count);
	        }
	   } 
	    else if(year != 0 && price != 0) 
	    {
	    	        
	        if(root != NULL)
	        {
                search_tree(root->left, year, price, count);
	            if(root->price <= price && root->year >= year)
		        {
			        printf("\n%d %s %s that cost $%d", root->year, root->make, root->model, root->price);
                    *count=*count+1;
		        }                    
		        search_tree(root->right, year, price, count);
	        }
	        
	    }	
}

Node *get_cars(char* filename)
{
    Node* head = NULL;
    char line[MAXLINELENGTH];
    FILE *fptr = fopen(filename, "r");
    int counter = 0;
  
    while(counter != -1)
{
    char* previous = NULL;
    char* current = NULL;
    int checkmake = 0;
    int checkcolor = 0;
    int checktype = 0;

    if(fgets(line, MAXLINELENGTH, fptr) == NULL)
    {
        break;
    }

    Node *temp = malloc(sizeof(Node));



    while (counter < 7)
    {
	    if (!current)
	    {
		    previous = strtok(line, "|");
		    current = strtok(NULL, "|");
	    }
	    else
	    {
		    previous = strtok(NULL, "|");
		    current = strtok(NULL, "|");
	    }
	    if(strcmp(previous, "make") == 0)
	    {
            if(strcmp(current, "chevrolet") == 0|| strcmp(current, "ford") == 0 || strcmp(current, "bmw") == 0  || strcmp(current, "mercury") == 0 || strcmp(current, "pontiac") == 0 || strcmp(current, "mercedes") == 0 || strcmp(current, "hundai") == 0 || strcmp(current, "bugatti") == 0 || strcmp(current, "toyota")  == 0|| strcmp(current, "gmc") == 0 || strcmp(current, "buick") == 0  || strcmp(current, "audi") == 0 || strcmp(current, "ferrari") == 0 || strcmp(current, "honda") == 0 || strcmp(current, "jeep") == 0 || strcmp(current, "kia") == 0 || strcmp(current, "dodge") == 0  || strcmp(current, "porche") == 0 )
            {
		       // temp->make = strdup(current);
               strcpy(temp->make, current);
                checkmake = 1;
            }
            else{ checkmake = 0; }
    
	    }

	    if(strcmp(previous, "color") == 0)
	    {
            if(strcmp(current, "blue") == 0 || strcmp(current, "red") == 0 || strcmp(current, "orange") == 0 || strcmp(current, "silver") == 0|| strcmp(current, "black") == 0 || strcmp(current, "white") == 0 || strcmp(current, "green") == 0|| strcmp(current, "turquise") == 0 ) 
            {
              //  temp->color = strdup(current);
              strcpy(temp->color, current);
                checkcolor = 1;
            }
            else{checkcolor = 0;}
	    }
       if(strcmp(previous, "type") == 0)
	    {   
            if(strcmp(current, "car") || strcmp(current, "truck") || strcmp(current, "van") || strcmp(current, "suv")  )      
            {
		     //   temp->type = strdup(current);
                strcpy(temp->type, current);
                checktype = 1;
            }
            else{checktype = 0;}
	    }
    
        if(strcmp(previous, "model") == 0)
	    {		                  
		   // temp->model = strdup(current); 
           strcpy(temp->model, current);
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
    
	   counter++;
    }

    temp->left = NULL;
    temp->right = NULL;
    if (checktype == 1 && checkmake == 1 && checkcolor == 1)
    {
        head = add_to_tree(head, temp);
    }
    checktype = 0;
    checkmake = 0;
    checkcolor = 0;
    counter = 0;
}
    fclose(fptr);

return head;
}

Node* add_to_tree(Node* head, Node* new)
{
    if(head == NULL)
	{
	    return new;
	}
    if(new->price <= head->price)
    {
        head->left = add_to_tree(head->left, new);
    }
    else
    {
        head->right = add_to_tree(head->right, new);
    }

return head;
}

int bonus_search(Node* root, int price, char* make, char* color, int* count)
{
    int checkcolor = 0;
    int checkmake = 0;

     if(price != 0)
	{	    
	    if(root != NULL)
	        { 

            if(strcmp(color, "blue") == 0 || strcmp(color, "red") == 0 || strcmp(color, "orange") == 0|| strcmp(color, "silver") == 0|| strcmp(color, "black") == 0 || strcmp(color, "white") == 0|| strcmp(color, "green") == 0|| strcmp(color, "turquise") == 0 ) 
            {
                checkcolor = 1;
            }
            else
            {
                printf("\nERROR! Color is invalid\n");
                checkcolor = 0;
                return 0;
            }

             if(strcmp(make, "chevrolet") == 0|| strcmp(make, "ford") == 0 || strcmp(make, "bmw") == 0  || strcmp(make, "mercury") == 0 || strcmp(make, "pontiac") == 0 || strcmp(make, "mercedes") == 0 || strcmp(make, "hundai") == 0 || strcmp(make, "bugatti") == 0 || strcmp(make, "toyota")  == 0|| strcmp(make, "gmc") == 0 || strcmp(make, "buick") == 0  || strcmp(make, "audi") == 0 || strcmp(make, "ferrari") == 0 || strcmp(make, "honda") == 0 || strcmp(make, "jeep") == 0 || strcmp(make, "kia") == 0 || strcmp(make, "dodge") == 0  || strcmp(make, "porche") == 0 )
            {
                checkmake = 1;
            }
            else
            {
                printf("\nERROR! Make is invalid\n");
                checkmake = 0;
                return 0;
            }

            if(checkcolor == 1 && checkmake == 1)
            {
                bonus_search(root->left, price, make, color, count);
		        if(root->price <= price && strcmp(color, root->color) == 0 && strcmp(make, root->make) == 0)
		        {   
			        printf("\n%d %s %s %s that cost $%d", root->year, root->color, root->make, root->model, root->price);
                    *count = *count+1;
		        }
  		        bonus_search(root->right, price, make, color, count);
	        }

            }
	   } 

       return 1;
}

void Free_Tree(Node* root)
{
	if(root != NULL)
	{
	    Free_Tree(root->left);
	    Free_Tree(root->right);
	    free(root->make);
	    free(root->model);
	    free(root->color);
	    free(root->type);
	    free(root);
	}

}
