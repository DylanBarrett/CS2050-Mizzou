
void addWishlist(student* head,char* wishListfile);
book* createBookList(char* bookFile,book* bookHead);
void printBookList(book* bookHead);
void copy(student *name1, student *name2, student *hold);

//Part Three
void checkOutBooks(student* studentHead, book* bookHead);
book* findBook(book* bookhead, int book_id);

#define NAME 25
#define TITLE 50
int main(int argc, char* argv[]){

      if (argc != 4)
    {
        printf("Inccorect number of arguments\nCorrect Usage: <./a.out> <students.txt> <wishlist.txt> <books.txt>\n");
        exit(0);
    }

    student *head = NULL;
 
    char *studentsFile = *(argv+1);
    char *wishListfile = *(argv+2);
    char *bookFile = *(argv+3);

    head = buildStudentList(studentsFile, head); 
    createPriorityQueue(head);


    addWishlist(head, wishListfile);
    printStudents(head);    
    book *bookHead = NULL;
    bookHead =  createBookList(bookFile, bookHead);
    printBookList(bookHead);


	return 0;
}

student* buildStudentList(char* studentsFile, student* head) {

  
    FILE *fptr = NULL;
    fptr = fopen(studentsFile, "r");
    if(fptr == NULL)
    {
        printf("\nError! Please check student.txt file\n");
        exit(0);
    }
//   fseek(fptr, 0, SEEK_SET);

    student *current = NULL;
    student *temp = NULL;
    temp = malloc(sizeof(student));

    temp->firstName = malloc((sizeof(char)*NAME));
    temp->lastName = malloc((sizeof(char)*NAME));

       head = current = NULL;
        while (  fscanf(fptr, "%s %s %d %d",temp->firstName, temp->lastName, &temp->priority, &temp->readingLevel) != EOF)
            {   
              //  printf("%s %s\n", temp->firstName, temp->lastName);

                student *link = malloc(sizeof(student));
                link->firstName = malloc(strlen(temp->firstName)+1);
                link->lastName = malloc(strlen(temp->lastName)+1);
                strcpy(link->firstName,temp->firstName);
                strcpy(link->lastName,temp->lastName);
                link->priority = temp->priority;
                link->readingLevel = temp->readingLevel;
                link->next = NULL;
                if(head == NULL)
                {
                   current = head = link;
                   //  printf("%s %s\n", head->firstName, head->lastName);
                }
                else
                {
                    current = current->next = link;
                }        
                                         
            }
              // printf("%s %s", head->firstName, head->lastName);

    fclose(fptr);
   	return head;
}
void printStudents(student* head) {

    student *ptr = malloc(sizeof(student));
    ptr = head;
  

    if (ptr == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nStudent List: \n");

        while(ptr != NULL)
        {
  
            printf("First Name: %s\nLast Name: %s\nPriority: %d\nReading Level:  %d\nWishList: ", ptr->firstName, ptr->lastName, ptr->priority, ptr->readingLevel);
          //  ptr = ptr->next;
            
            bookIds *ids = ptr->wishlist;
            while(ids != NULL)
            {       
                printf("%d-> ",ids->id);
                ids=ids->next;
            }
            printf("\n");
            ptr = ptr->next;
        }
         
    }
   
}
void createPriorityQueue(student* head) {
        
    student *current = head;
    student *traverse;
    student *min; 
    student *link = malloc(sizeof(student));
    link->firstName = malloc(sizeof(char)*NAME);
    link->lastName = malloc(sizeof(char)*NAME);

    while(current->next)
    {
        min = current;
        traverse = current->next;

        while(traverse)
        {
            if(min->priority > traverse->priority)
            {
                min = traverse;
            }
            traverse = traverse->next;
        }
      /*  int temp = current->priority;
        current->priority = min->priority;
        min->priority = temp;
        
        temp = current->readingLevel;
        current->readingLevel = min->readingLevel;
        min->readingLevel = temp;*/


     copy(current, min, link);
     // copy(name1, name2, hold)
      //      current, min, link
    /*   strcpy(link->firstName, current->firstName);
    strcpy(link->lastName, current->lastName);

    strcpy(current->firstName, min->firstName);
     strcpy(current->lastName, min->lastName);

     strcpy(current->firstName, link->firstName);
    strcpy(current->lastName, link->lastName);*/


      //  printf("test\n"); 
       // student *link = malloc(sizeof(student));
       // link->firstName = malloc(sizeof(char)*NAME);
 
  /*     strcpy(link->firstName, current->firstName);
       strcpy(current->firstName, min->firstName);
       strcpy(min->firstName, link->firstName);
        strcpy(start->firstName, min->firstName);
        strcpy(min->firstName, link->firstName);
        
       char *string = malloc(sizeof(char)*NAME);
        strcpy(string,start->firstName);
        strcpy(start->firstName,min->firstName);
        strcpy(min->firstName, string);
       
       
        strcpy(hold, start->firstName);
        strcpy(start->firstName, min->firstName);
        strcpy(min->firstName, hold);*/

      
        current = current->next; //remove link; 
    }
 
 }

void copy(student *name1, student *name2, student *temp)
{
    temp->priority = name1->priority;
    strcpy(temp->firstName, name1->firstName);
    strcpy(temp->lastName, name1->lastName);
    temp->readingLevel = name1->readingLevel;

    name1->priority = name2->priority;
    strcpy(name1->firstName, name2->firstName);
    strcpy(name1->lastName, name2->lastName);
    name1->readingLevel = name2->readingLevel;

    name2->priority = temp->priority;
    strcpy(name2->firstName, temp->firstName);
    strcpy(name2->lastName, temp->lastName);
    name2->readingLevel = temp->readingLevel;


}
void addWishlist(student* head,char* wishListfile) {
 

    FILE *fptr = NULL;
    fptr = fopen(wishListfile, "r");
    if(fptr == NULL)
    {
        printf("\nError! Please check student.txt file\n");
        exit(0);
    }

        int i = 0;
      int *id = malloc(sizeof(int)*4);
      student *current = head;
    
    while(current != NULL)
    {    
        fscanf(fptr, "%d %d %d %d", id, (id+1), (id+2),(id+3));   
             
       bookIds *ptr = NULL;
       for(i = 0; i < 4; i++)
        {
            if(i ==0)
            {

                current->wishlist = malloc(sizeof(bookIds));  
                ptr = current->wishlist;
            }
            else
            {
                ptr->next = malloc(sizeof(bookIds));
                ptr = ptr->next;
            }
            ptr->id = *(id+i);
            ptr->next = NULL;
        }
        current = current->next;
    }
    free(id);
    fclose(fptr);
 
    
}
book* createBookList(char* bookFile,book* bookHead) {
	 FILE *fptr = NULL;
    fptr = fopen(bookFile, "r");
    if(fptr == NULL)
    {
        printf("\nError! Please check student.txt file\n");
        exit(0);
    }
//   fseek(fptr, 0, SEEK_SET);

    book *current = NULL;
    book *temp = NULL;
    temp = malloc(sizeof(book));

    temp->title = malloc((sizeof(char)*TITLE));


       bookHead = current = NULL;
        while (  fscanf(fptr, "%d %s",&temp->bookID, temp->title) != EOF)
            {   
             
                book *link = malloc(sizeof(book));
                link->title = malloc(strlen(temp->title)+1);
                strcpy(link->title, temp->title);
                link->bookID = temp->bookID;
                link->next = NULL;
                if(bookHead == NULL)
                {
                   current = bookHead = link;
                }
                else
                {
                    current = current->next = link;
                }        
                                         
            }

    fclose(fptr);
   	return bookHead;

}
void printBookList(book* bookHead) {
    book *ptr = malloc(sizeof(book));
    ptr = bookHead;
  

    if (ptr == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nBook List: \n");

        while(ptr != NULL)
        {  
            printf("ID: %d Title: %s\n", ptr->bookID, ptr->title);                  
            ptr = ptr->next;
        }
         
    }

}

void checkOutBooks(student* studentHead, book* bookHead) {
        

}
book* findBook(book* bookhead, int book_id) {
	return NULL;
}
