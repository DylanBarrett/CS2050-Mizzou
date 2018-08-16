
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct player{

    char Fname[25];
    char Lname[25];
    int Singles;
    int Doubles;
    int Triples;
    int Homeruns;
    int At_Bats;
    float Slugging_Percentage;

    } Player;

void read_from_file(char*, Player*, int, int);
void write_to_file(char*, Player*, int);
void calculate_slugging(Player*, int);
void sort_array(Player*, int);
void bonus(Player*, int);



int main(int argc, char** argv)
{
    FILE *fptr1 = NULL;
    FILE *fptr2 = NULL;
    FILE *fptr3 = NULL;
    FILE *wptr = NULL;

   if(argc != 6)
    {
        printf("INCORRECT USE OF PROGRAM\n Correct Usage: ./a.out <Total_Number_Of_Players> <input1> <input2> <input3> <output>\n ....exiting.....\n");
        return 0;
    }
    int length = atoi(*(argv+1));
    char* input1 = *(argv+2);
    char* input2 = *(argv+3);
    char* input3 = *(argv+4);
    char* output = *(argv+5);
    int index = 0;

    Player* players;
    players = malloc((sizeof(char[25])*2+sizeof(int)*5+sizeof(float))*length);


   length = length/3;
     read_from_file(input1, players, index, length);
     index += length;
     read_from_file(input2, players, index, length);
     index += length;
     read_from_file(input3, players, index, length);



     length = length*3;
     calculate_slugging(players, length);
     sort_array(players, length);

 /*  for (int i=0; i<length; i++)
    {
        printf("%s %s %d %d %d %d %d %.4f\n", (players+i)->Fname, (players+i)->Lname,
            (players+i)->Singles, (players+i)->Doubles, (players+i)->Triples,
            (players+i)->Homeruns, (players+i)->At_Bats,
            (players+i)->Slugging_Percentage);
    }*/

    write_to_file(output, players,length);

    bonus(players,length);

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(wptr);

    free(players);
    return 0;
}

void read_from_file(char* file, Player* players, int index, int length)
{
    int i = 0;

    FILE *fptr;

    fptr = fopen(file, "r");
    if (fptr == NULL)
    {
        printf("Error...please check file\n");
        exit (0);
    }
    else
    {
       for(i = 0; i<length; i++)
       {
            fscanf(fptr, "%s %s %d %d %d %d %d", (players+i+index)->Fname, (players+i+index)->Lname,
            &(players+i+index)->Singles, &(players+i+index)->Doubles, &(players+i+index)->Triples,
            &(players+i+index)->Homeruns, &(players+i+index)->At_Bats);

           /* printf("%s %s %d %d %d %d %d\n", (players+i+index)->Fname, (players+i+index)->Lname,
            (players+i+index)->Singles, (players+i+index)->Doubles, (players+i+index)->Triples,
            (players+i+index)->Homeruns, (players+i+index)->At_Bats);*/
            //this reads off the file
       }
    }
    fclose(fptr);
    return;
}

void calculate_slugging(Player* players, int length)
{
    int i;
    int bases = 0;

       for(i=0; i < length; i++)
    {
        bases = (players+i)->Singles + ((players+i)->Doubles*2) +
        ((players+i)->Triples*3) + ((players+i)->Homeruns*4);

        (players+i)->Slugging_Percentage  = bases/(float)(players+i)->At_Bats;
        //printf("%.4f\n", (players+i)->Slugging_Percentage);
    }

    return;
}
void sort_array(Player* players, int length)
{
    int i,j;
    Player *temp = malloc(sizeof(Player));

    for(i=0;i<length;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if((players+i)->Slugging_Percentage < (players+j)->Slugging_Percentage)
            {
                *temp = *(players+i);
                *(players+i) = *(players+j);
                *(players+j) = *temp;
            }
        }
      //  printf("%s\n", (players+i)->Fname);
    }
    free(temp);
    return;
}

void write_to_file(char* outputfile, Player* players, int length)
{
    FILE *output = fopen(outputfile,"w");
    int i;

  if (output == NULL)
    {
        printf("Error...please check file");
        exit(0);
    }


    for (i=0; i<length; i++)
    {
        fprintf(output, "%s %s %d %d %d %d %d %.4f\n",  (players+i)->Fname, (players+i)->Lname,
            (players+i)->Singles, (players+i)->Doubles, (players+i)->Triples,
            (players+i)->Homeruns, (players+i)->At_Bats,
            (players+i)->Slugging_Percentage);

    }

    fclose(output);
    return;
}


void bonus(Player* players, int length)
{
    int i,j;
    Player *temp = malloc(sizeof(Player));

    for(i=0;i<length;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(strcmp((players+i)->Lname, (players+j)->Lname)>0)
            {
                *temp = *(players+i);
                *(players+i) = *(players+j);
                *(players+j) = *temp;
            }
        }
    }


  for (int i=0; i<length; i++)
   {
        printf("%s %s %d %d %d %d %d %.4f\n", (players+i)->Fname, (players+i)->Lname,
            (players+i)->Singles, (players+i)->Doubles, (players+i)->Triples,
            (players+i)->Homeruns, (players+i)->At_Bats,
            (players+i)->Slugging_Percentage);
    }

    free(temp);
    return;

}
