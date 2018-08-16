#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct Person {
    char first[25];
    char last[25];
    char email[25];
    char phone[25];
    struct Person* left;
    struct Person* right;
}person;

void parseWord(char* word);
int isPhone(char* phone);
int isEmail(char* email);
int isName(char* name);
void free_tree(person* head);
person* add_person(person* head, char* first, char* last, char* phone, char* email);
void print_address_book(person* head);

int main(int argc, char** argv)
{
       char* word = malloc(sizeof(char)*25); 
    int check = 0;
    int count = 0;
    char* fname = malloc(sizeof(char)*25);
 char* tempfname = malloc(sizeof(char)*25);
    int foundName = 0;
    char* lname = malloc(sizeof(char)*25);
    char* email = malloc(sizeof(char)*25);
   char* phone = malloc(sizeof(char)*25);
   int i = 0;
//   FILE* fp = NULL;
   char* file;

    
 
    person* head = NULL;
        
 for( i = 0; i < argc-1; i++)
 {
   
    file  = argv[i+1];
    FILE* fp = fopen(file, "r");
    foundName = 0;
    while(fscanf(fp, "%s", word) != EOF)
    { 
      
        if(isPhone(word))
        {
           // printf("\nPhone Number found: %s\n", word);
           strcpy(phone,word);
           check = 0;
        }
                
        else if(isEmail(word))
        {
          //  printf("\nEmail is : %s\n", word);
            strcpy(email, word);
            check = 0;
        }
       
         else if (isName(word)&& foundName ==0)
        {
            //count++; 
            if(check == 1)
            {
                                
               // printf("Name: %s %s\n", fname, word);
                strcpy(lname,word);
                strcpy(fname, tempfname);
                check = 0; 
                foundName = 1;
            }
            else{
             
                strcpy(tempfname, word);
                check = 1;
            }
        }
       else
        {
            check = 0; 
          //  strcpy(fname, " ");
        } 
    }

         
 
    head = add_person(head, tempfname, lname, phone, email);
    fclose(fp);
  
}
    print_address_book(head);

 //   fclose(fp);
    free(word);
    free(fname);
    free(lname);
    free(phone);
    free(email);
    free_tree(head);
    return 0;
}

person* add_person(person* head, char* first, char* last, char* phone, char* email)
{
    if(head == NULL)
    {
        head = malloc(sizeof(person));
        strcpy(head->first, first);
        strcpy(head->last, last);
        strcpy(head->phone, phone);
        strcpy(head->email, email);   

        head->left = NULL;
        head->right = NULL;
    }
       
    else if (last < head->last)
    {
        head->left =  add_person(head->left, first, last, phone, email);
    }
    else if(last > head->last)
    {
        head->right = add_person(head->right, first, last, phone, email);        
    }
    
    return head;

}

int isPhone(char* phone)
{
    int i = 0;
    
    for(i = 0; phone[i] != '\0'; i++)
    {
        
        if(i == 3 || i == 7)
        {
            if(phone[i] != '-')
            {
                return 0;
            }
        }
        
        else if(!isdigit(phone[i]))
        {
            return 0;
        }
    }
    if(i != 12)
    {
        return 0;
    }
    return 1;
}
int isEmail(char* email)
{
    int i = 0;
    int len = strlen(email);

   
    
    for(i = 0; i < len; i++)
    {
        if ( (*(email+i) == '@' && *(email+len-3) == 'c' && *(email+len-2)=='o' && *(email+len-1)=='m') || (*(email+i) == '@' && *(email+len-3) == 'e' && *(email+len-2)=='d' && *(email+len-1)=='u')  )
        {
            return 1;
        }
    }
    return 0;
}

int isName(char* name)
{   
    int len;
    len = strlen(name);
    if (len <=2)
    {
        return 0;
    }
    if (*(name+0) >= 65 && *(name+0) <= 90 )
    {
        printf("%s",name);
        return 1;
    }

    return 0;
    
}

void free_tree(person* head)
{
    if (head != NULL)
    {
        free_tree(head->left);
        free_tree(head->right);
        free (head);
    }
}

void print_address_book(person* head)
{
    if (head != NULL)
    {
        print_address_book(head->left);
        printf("\nName: %s %s\nPhone: %s\nEmail: %s\n", head->first, head->last, head->phone, head->email);
        print_address_book(head->right);
    }
}
