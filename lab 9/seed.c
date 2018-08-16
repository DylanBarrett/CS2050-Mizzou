#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char **argv)
{
    if(argc != 4)
    {
        printf("Correct usage: ./a.out <output file> <number of randoms> <largest random number>");
        exit(0);
    }
    
    int max = atoi(*(argv+3));
    int amount = atoi(*(argv+2));
    char* output = *(argv+1);

    FILE *fptr = NULL;

fptr = fopen(output, "w");

srand(time(NULL));
int i;

for(i = 0; i < amount; i++)
{
    int num = rand()%max+1;
    fprintf(fptr, "%d\n", num);
}

fclose(fptr);
    return 0;
}
