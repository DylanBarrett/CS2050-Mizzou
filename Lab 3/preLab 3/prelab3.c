#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player{
    char Player_Name[50];
    int homeruns;
    int triples;
    int doubles;
}player;

player* read_binary_file(char*);

int main (int argc,char*  argv[])
{
    player* player1;
    player1 = malloc(sizeof(char[50])+(sizeof(int)*3));
   
    if (argc != 2)
    {
        printf("Incorrect number of arguments\nme");
        exit(0);
    }
    char* input = *(argv+1);

    player1 = read_binary_file(input);


    printf("Player name = %s\nHomeruns = %d\nTriples = %d\nDoubles = %d\n", player1->Player_Name, player1->homeruns, player1->triples, player1->doubles);
        

  return 0;
}

player* read_binary_file(char* input)
{
    FILE *fptr;
    fptr = fopen(input, "rb+");
  //  int playersize = sizeof(char[50])+(sizeof(int)*3);

    player* player1 =malloc(sizeof(player));

    if (fptr == NULL)
    {
        printf("Error with reading file\n");
        exit (0);
    }
//fseek(fptr, SEEK_SET, 0);

//fread (pointer to what you want to read it into, size, # of elements, file pointer you are reading from)

   fread(player1, sizeof(player), 1, fptr); //this reads data into file structure

fclose(fptr);

return player1;
}
    
