#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 25
#define BOOK_SIZE 5


typedef struct info{
   long int phone;
    char* email;
}Info;

typedef struct person {
        char* firstName;
        char* lastName;
        Info contact;
}Person;

void sortAscending(Person* list);
Person* allocate_memory();
int check_email(char* email);
//void freeArray(Person*);
void print_list(Person* list);
void add_contacts(Person* list);
int check_phone(long int phone);
void free_list(Person* list);
// bonus is sort by last name using sort not O(n^2)

int main(void)
{
     
     Person* list = allocate_memory();

     add_contacts(list);

       print_list(list);
       printf("list after sorting\n");
 sortAscending(list);
  print_list(list);
     free_list(list);
            
     

    return 0;
}



Person* allocate_memory()
{   
 Person* person = malloc((sizeof(Person)*BOOK_SIZE));



    for (int i = 0; i < BOOK_SIZE; i++)
    {
  
    (person+i)->firstName = malloc((sizeof(char)*MAX_NAME_LENGTH)*BOOK_SIZE);
    (person+i)->lastName = malloc((sizeof(char)*MAX_NAME_LENGTH)*BOOK_SIZE);
     //   (person+i)->contact.phone = malloc(sizeof(long int)*BOOK_SIZE); <- contains long int, no need to malloc
        (person+i)->contact.email = malloc(sizeof(char)*BOOK_SIZE);
    }
    
    return person;

}

void add_contacts(Person* list)
{
    int i, check, check2;
    int d = 1;
    for( i = 0; i < BOOK_SIZE; i++)
    {
        printf("-----Contact %d -----", d);
        printf("\nEnter the first Name: ");
        scanf("%s", (list+i)->firstName);
        printf("\nEnter the last Name: ");
        scanf("%s", (list+i)->lastName);
        do{
       printf("\nEnter the email: ");
        scanf("%s", (list+i)->contact.email);
       check2  = check_email((list+i)->contact.email);
            if (check2 == 0)
            {
                printf("Invalid email\n");
            }
           } while(check2 ==0);
    do{
        printf("\nEnter the phone number: ");
        scanf("%ld", &(list+i)->contact.phone);
      check= check_phone((list+i)->contact.phone);
    }while(check == 1);
        d++;

    }

    return;
}
int check_phone(long int phone)
{
   
    if (phone <= 999999999 || phone > 9999999999)
    {
        printf("invalid phone number\n");
        return 1; 
    }
    else
    return 0;
}


int check_email(char* email)
{
    int len = strlen(email);
    for( int i =0; i <len; i++)
    {
       if (*(email+i) == '@')
       {
         
            return 1;
       }

    }            

return 0;
 }

void print_list(Person* list)
{
    int count = 1;
        for( int i = 0; i < BOOK_SIZE; i++)
    {  
        printf("%d) %s %s\n", count, (list+i)->firstName, (list+i)->lastName);
        printf("Email: %s\n", (list+i)->contact.email);
        printf("Phone: %ld\n", (list+i)->contact.phone);
        count++;
    }

}


void free_list(Person* list)
{   
    for (int i=0; i<BOOK_SIZE; i++)
    {
     free ((list+i)->firstName);
     free((list+i)->lastName);
     free((list+i)->contact.email);
     
  }
  return;
}




void sortAscending(Person* list) // heap sort
{
    int l1, l2, u1, u2, i, j,k, size;
    size = 1;

    Person* temp = malloc(sizeof(Person)*BOOK_SIZE);
    

    while(size < BOOK_SIZE)
    {
        l1 = 0;
        k = 0;
            
            while(l1+size < BOOK_SIZE)
            {
                l2=l1+size;
                u1=l2-1;
                u2 = (l2+size-1) < BOOK_SIZE ? (l2+size-1): (BOOK_SIZE-1);
                for (i=l1, j=l2; i <= u1 && j <=u2; k++)
                    if(strcmp((list+i)->lastName, (list+j)->lastName) < 0)
                        *(temp+k) = *(list+i++);
                        else
                                *(temp+k) = *(list+j++);
                                while(i <= u1)
                                    *(temp+k++) = *(list+i++);
                                while(j <= u2)
                                    *(temp+k++) = *(list+j++);
                
                    l1=u2+1;
            }

            for(i=l1; k < BOOK_SIZE; i++)
            {
                *(temp+k++) = *(list+i);
            }
            
            for(i=0; i < BOOK_SIZE; i++)
            {
                *(list+i) = *(temp+i);
            }
            
            size*=2;
    }

free(temp);
return;
}


