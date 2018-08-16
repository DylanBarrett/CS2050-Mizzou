#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* read_file(char*, int);
void selection_sort(int*, int);
void bubble_sort(int*, int);
void insertion(int*, int);
void print_Array(int*);
int check_user(int);
void heap_sort(int*, int);
//double calculate_time(clock_t begin, clock_t end);
//bonus is merge sort

int main (int argc, char**  argv)
{
    char* input;
    int length;
      int choice;
      int check;
              
    if (argc != 3)
    {
        printf("Incorrect number of arguments\n");
        printf("Correct usage:\n ./a.out <amount of numbers to be sorted> <input file>\n ");
        exit(0);
    }

    input = *(argv+2);
    length = atoi(*(argv+1));
   
  int* array = malloc(sizeof(int)*length);
  int* temp = malloc(sizeof(int)*length);  

   array =  read_file(input, length);

  memcpy(temp, array, sizeof(int)*length);
  //copies memory block of array into temp

do{
    printf("Enter '1' for a bubble sort\nEnter '2' for a selection sort\nEnter '3' for an insertion sort\nEnter '4' for a heap sort\nEnter -1 to exit program\nchoice: ");
    scanf("%d", &choice);

    if (choice == -1)
        {
            exit(0);
        }
        check = check_user(choice);

        while (check ==0)
        {
            printf("Invalid choice. Please enter a valid number\n");
            scanf("%d", &choice);
                if (choice == -1)
                {
                    exit(0);
                }
         check =  check_user(choice);

        }

        if (choice ==1)
            {
            //  clock_t  begin = clock();
                bubble_sort(temp,length);
            //   clock_t  end = clock();
                print_Array(temp);
               //  temp = array;- this assigns array memory location to temps memory location --> wrong and shouldn't work
               //but it did for some reason

            //    int time = calculate_time(begin, end);
            //    printf("bubble sort completed in %d seconds", time);


            }
        if (choice == 2)
        {       
           
              selection_sort(temp, length);
               print_Array(temp);
         //      temp = array;
                   
        }
        
        if (choice == 3)
        {
            insertion(temp, length);
            print_Array(temp);
        //    temp = array; 
            
        }

        if( choice == 4)
        {
            heap_sort(temp, length);
            print_Array(temp);
        }
        
    

  memcpy(temp, array, sizeof(int)*length);
}while(choice != -1);

free(array);
free(temp);

       

  
}

int check_user(int choice)
{
    if( choice < 1 || choice > 4)
    {
        return 0;
    }
    else{
        return 1;
    }
}

int* read_file(char* input, int length)
{
    int i;
    FILE *fptr;
    fptr = fopen(input, "r");
    int* array = malloc(sizeof(int)*length);
  
  

    if (fptr == NULL)
    {
        printf("Error with reading file\n");
        exit (0);
    }

    for(i=0; i < length; i++)
        {
            fscanf(fptr, "%d", array+i);
        }

free(array);
fclose(fptr);

return array;
}


void selection_sort(int* array, int length)
{
    int i =0, j = 0, first = 0;
    int temp; 
    for (i = 0; i < length; i++)
    {
        first = i;
        for(j=i+1; j < length; j++)
        {
            //first = i;
            if( *(array+j) < *(array+first) )
            {
            
            temp = *(array+first);
            *(array+first) = *(array+j);
            *(array+j) = temp; 
    
            }
        }
    }

  

return;
}


void print_Array(int* array)
{
    int i;
       for (i=0; i < 10; i++)
      {   
        printf("%d\n", *(array+i));
      }


return;
}

void bubble_sort(int* array, int length)
{
    int i, j;
    int temp;

    for(i=0; i < length; i++)
    {
        for(j=i+1; j < length; j++)
        {
            if(*(array+i) > *(array+j))
            {
                temp=*(array+i);
                *(array+i) = *(array+j);
                *(array+j) = temp;
            }
        }
    }
    
}

void insertion(int* array, int length)
{
    int i;

    for (i =1; i < length; i++)
    {
        int moveitem = i;
        int insert = *(array+i);
        
        while( moveitem > 0 && *(array + moveitem -1) > insert)
        {
            *(array+moveitem) = *(array + moveitem - 1);
            --moveitem;
        }
        
        *(array+moveitem) = insert;

    }


}

void heap_sort(int* array, int length)
{
    int l1, l2, u1, u2, i, j, k, size;
    size = 1;
    int* temp = malloc(sizeof(int)*length);

    while (size < length)
    {

        l1=0;
        k=0;
            while(l1+size < length)
            {
                l2=l1+size;
                u1=l2-1;
                u2 = (l2+size-1) < length ? (l2+size-1): (length-1);
                for(i=l1, j=l2; i <= u1 && j <= u2; k++)
                    if(*(array+i) >= *(array+j))
                        *(temp+k) = *(array+i++);
                        else
                                *(temp+k) = *(array+j++);
                            while(i <= u1)
                            *(temp+k++) = *(array+i++);
                            while ( j <= u2)
                            *(temp+k++) = *(array+j++);

                    l1=u2+1;        

            }
                for(i=l1; k < length; i++)
                    {
                        *(temp+k++) = *(array+i);
                    }
                for(i=0; i < length; i++)
                {
                    *(array+i) = *(temp+i);
                }

                size*=2;
                
    }


    return;
}


/*double caluclate_time(clock_t begin, clock_t end)
{
    end = clock();
    begin = clock();
    double total = (double)(end-begin)/CLOCKS_PER_SEC;

    return total;

}*/

