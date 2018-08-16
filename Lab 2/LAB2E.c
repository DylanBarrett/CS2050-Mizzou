#include <stdio.h>
#include <stdlib.h>


//void min_max(double*, int, FILE*);
double* read_file(FILE*, int);
void write_to_file(FILE*, double);
void sort_ascending(double*, int);
void sort_descending(double*, int);

double bonus(FILE*, double*, double*);

int main(int argc, char** argv)
{
    FILE *fptr;
    FILE *fptr2;
    FILE *wptr;
  
   if(argc != 5)
    {   
        printf("incorrect command line arguments\n Correct Usage:\n ./a.out <length> <inputfile one> <inputfile two> <output file> \n");
        return 0;
    }
    int length = atoi(*(argv+1));
    char* inputfile = *(argv+2);
    char* inputfile2 = *(argv+3); 
    char* output = *(argv+4);
    int i;
    double* array;
    double* array2;  
    double value = 0;
    double value2 = 0;
    


    if (inputfile == NULL) 
    {
       printf("Error with file\n");
       return 0;
    }
    
     if (inputfile2 == NULL) 
    {
       printf("Error with file\n");
       return 0;
    }

    if (output == NULL)
    {
        printf("Error with output file\n");
        return 0;
    }


    fptr = (fopen(inputfile, "r"));
    fptr2 = (fopen(inputfile2, "r"));
    wptr = (fopen(output, "w"));


     array = read_file(fptr, length);
     array2 = read_file(fptr2, length);

     

     sort_ascending(array, length);
     sort_descending(array2, length);

    for (i = 0; i < length; i++)
    {
        value = *(array+i);
      //  printf("%.2lf\n",value);
        write_to_file(wptr, value);
        value2 = *(array2+i);
      //  printf("%.2lf\n", value2);
        write_to_file(wptr, value2);
    }

    

 
       

  /*  for(i=0;i < length; i++)
    {
    printf("%.2lf\n", *(array2+i));
    } */
  
    fclose(fptr);
    fclose(fptr2);
    fclose(wptr);
    
    free(array);
    free(array2);

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
    
    return numbers;
 }

 void write_to_file(FILE* file, double value)
 {
    fprintf(file, "%.2lf\n", value);

   // fclose(file);

    return;
 }

 void sort_ascending(double* array, int length)
 {
     int i, j;
     double temp;

     for(i =0; i < length; i++)
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
    return;
 }


 void sort_descending(double* array, int length)
 {
     int i, j;
     double temp;

     for(i =0; i < length; i++)
     {
        for(j=i+1; j < length; j++)
        {
            if(*(array+i) < *(array+j))
            {
                temp=*(array+i);
                *(array+i) = *(array+j);
                *(array+j) = temp;
            }
        }
     }
    return;
 }


