#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player{
    char Player_Name[50];
    int singles;
    int doubles;
    int triples;
    int homeruns;
}player;

player* read_binary_file(char*, int);
void selection_sort(player*, int);
void print_Array(player*, int);

int main (int argc, char*  argv[])
{
    player* player1;
    char* input_file;
    int length;
     
    if (argc != 3)
    {
        printf("Incorrect number of arguments\n");
        exit(0);
    }

    input_file = *(argv+2);
    length = atoi(*(argv+1));
   // player1 = malloc(sizeof(char[50])+(sizeof(int)*length));
    player1 = malloc(sizeof(player)*length);


    player1 = read_binary_file(input_file, length);
  //  print_Array(player1, length);
 //   printf("\n\nSelection sort\n");
    selection_sort(player1, length);
    print_Array(player1, length);


       
free(player1);

  return 0;
}

player* read_binary_file(char* input, int length)
{
    int i;
    FILE *fptr;
    fptr = fopen(input, "rb+");
  
    player* players =malloc(sizeof(player)*length);
  

    if (fptr == NULL)
    {
        printf("Error with reading file\n");
        exit (0);
    }

//fread (pointer to what you want to read it into, size, # of elements, file pointer you are reading from)

    for(i=0; i<length; i++)
        {
            fread((players+i), sizeof(player), length, fptr); //this reads data into file structure
        // printf("Name = %s\n", (player1+i)->Player_Name); // make sure names are printing
        }

fclose(fptr);
//free(players); //--> causes abort trap 6 error

return players;
}


void selection_sort(player* player1, int length)
{
    int i =0, j = 0, first = 0;
    int count = 0;
    player* temp = malloc(sizeof(player)*length);

    for (i = 0; i < length; i++)
    {
        first = i;
        for(j=i+1; j < length; j++)
        {
            if( (player1+j)->homeruns > (player1+first)->homeruns )
            {
                first = j;       
            }// end of if
        }//end of inner for
            *temp = *(player1+first);
            *(player1+first) = *(player1+i);
            *(player1+i) = *temp; 
            count ++; 
    }// end of for

    printf("Successfully Sorted %d players\n", count);


return;
}


void print_Array(player* player1, int length)
{
    int i;
       for (i=0; i < length; i++)
      {   
        printf("%s %d\n", (player1+i)->Player_Name, (player1+i)->homeruns);
      }


return;
}
