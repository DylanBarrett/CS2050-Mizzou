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
int Check_User_Search(int);
void Search_Players(player*, int, int);

int main (int argc,char*  argv[])
{
    player* player1;
    int number = 0;
    char* input_file;
    int num_players;
    int check;
     
    if (argc != 3)
    {
        printf("Incorrect number of arguments\n");
        exit(0);
    }

    input_file = *(argv+2);
    num_players = atoi(*(argv+1));
    player1 = malloc(sizeof(char[50])+(sizeof(int)*num_players));



    player1 = read_binary_file(input_file, num_players);


do{
    printf("\nWhat value would you like to search for...? (0-50) or -1 to exit\n");
    scanf("%d",&number);
   
    if (number == -1)
        {
            exit(0);
        }
  
    check = Check_User_Search(number);
   

    while (check == 0)
    {
        printf("-----Search Players-----\n\n");
        printf("\nWhat value would you like to search for...? (0-50) or -1 to exit\n");
        scanf("%d",&number);
            if (number == -1)
            {
                exit(0);
            }
     check =  Check_User_Search(number);
    }
        
    Search_Players(player1, num_players, number);

}while(number != -1);
 
  free(player1);
  return 0;
}

player* read_binary_file(char* input, int length)
{
    int i;
    FILE *fptr;
    fptr = fopen(input, "rb+");
    //int playersize = sizeof(char[50])+(sizeof(int)*3);

    player* player1 =malloc(sizeof(player)*length);

    if (fptr == NULL)
    {
        printf("Error with reading file\n");
        exit (0);
    }

//fread (pointer to what you want to read it into, size, # of elements, file pointer you are reading from)

    for(i=0; i<length; i++)
    {
        fread((player1+i), sizeof(player), length, fptr); //this reads data into file structure
        // printf("Name = %s\n", (player1+i)->Player_Name); // make sure names are printing
    }

    fclose(fptr);
    free(player1);

    return player1;
}


int Check_User_Search(int number)
{   
     if  (number < 0 || number > 50)
     { 
       return 0;
     }
    else{
        return 1;
    }
    
}

void Search_Players(player* player1, int length, int number)
{
    int i, count = 0;
    player* temp = malloc(sizeof(player));
    
    printf("##### Search Results #####\n\n");

    for(i=0; i<length; i++)
    {
         if ((player1+i)->singles == number )  
          {
                   printf("%s has %d Singles!\n",(player1+i)->Player_Name, (player1+i)->singles);
                   count++;
          }
        
         if ((player1+i)->doubles == number )  
          {
                   printf("%s has %d Doubles!\n",(player1+i)->Player_Name,(player1+i)->doubles );
                   count++;
          }
         if ((player1+i)->triples == number )  
          {
                   printf("%s has %d Triples!\n",(player1+i)->Player_Name, (player1+i)->triples );
                   count++;
          }
         if ((player1+i)->homeruns == number )  
          {
                   printf("%s has %d Homeruns!\n",(player1+i)->Player_Name, (player1+i)->homeruns );
                   count++;
          }
    }
    printf("\n\nThis search had a total of %d matching criteria!\n", count);

    free(temp);
    return;
}

