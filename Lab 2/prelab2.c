//prelab 2
#include <stdio.h>
#include <stdlib.h>

void min_max(double*, int, FILE*);
double* read_file(FILE*, int);

int main(int argc, char** argv)
{
    FILE *fptr;
    FILE *wptr;
  

    int length = atoi(*(argv+1));
    char* inputfile = *(argv+2);
    char* output = *(argv+3);
  //  int i;
    double* array = malloc(sizeof(double)*length);

    fptr = (fopen(inputfile, "r"));
    wptr = (fopen(output, "w"));

    if (fptr == NULL) 
    {
       printf("Error with file\n");
       return 0;
    }
    if (wptr == NULL)
    {
        printf("Error with output file\n");
        return 0;
    }
     array = read_file(fptr, length);
     min_max(array, length, wptr);

   /* for(i=0;i < length; i++)
    {
    printf("%.2lf\n", *(array+i));
    }*/




    
    if(argc != 4)
    {   
        printf("incorrect command line arguments\n Correct Usage:\n ./a.out <length> <input file> <output file> \n");
        return 0;
    }


  
    fclose(fptr);
    fclose(wptr);
    free(array);

    return 0;
}

double* read_file(FILE* inputfile, int length)
{
    int i = 0;
   

    double *numbers = malloc(sizeof(double)*length);

    for(i=0; i < length; i++)
    {
        fscanf(inputfile, "%lf", numbers+i);
      //  printf("%.2lf\n", *numbers);
    }
    
   // free(numbers); 
    return numbers;
 }

 void min_max(double* array, int length, FILE* outputfile)
 {  
     int i;
     double small = *array;
     double big = 0;
       
     
        for(i=0; i < length; i++)
        {   
            if (small > *(array+i))
            {
                small = *(array+i);                
            }
         }
    
        for(i=0; i < length; i++)
        {   
            if (big < *(array+i))
            {
                big = *(array+i);   
            }
        }
      
    
    fprintf(outputfile, "Minimum = %.2lf\nMaximum = %.2lf\n",small, big);
    

    fclose(outputfile);
    return;
 }
