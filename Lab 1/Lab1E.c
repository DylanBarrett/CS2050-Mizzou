#include <stdio.h>
#include <stdlib.h>

double* read_file(char* , int);
double find_min(double*, int);
double find_max(double*, int);
void write_to_file(char*, double*, int);

int main(int argc, char** argv)
{
    double *num;
    if(argc != 4)
    {
        printf("Incorrect Usage\n");
        return 0;
    }
  
   
    char* inputfile = *(argv+2);
    int n = atoi(*(argv+1));
    char* output = *(argv+3);

     num = malloc(sizeof(double)*n);

  
 

    double size = *read_file(inputfile, n);
    double smallest =  find_min(&size, n);
   printf("%.2lf\n", smallest);

   double big = find_max(&size, n);
   printf("%.2lf\n", big);

    write_to_file(output, &size, n);




   free(num); 
  return 0; 
}

double* read_file(char* filename, int length)
{
    int i = 0;
    FILE *file;
    double *numbers = malloc(sizeof(double)*length);     
 

    if ((file=fopen(filename, "r")) == NULL)
    {
        return 0;
    }
   
     if (file==0)
    {
        printf("File could not be opened");
        return 0;
    }

    for(i=0; i < length; i++)
    {
        fscanf(file, "%lf", numbers);    
       // printf("%.2lf\n", *numbers);
    }

    
    fclose(file);
 

    return numbers;
    
}


double find_min(double* amount, int n)
{
    double small = *amount;
    int i;
      

    for (i=0; i < n; i++)
    {
        if (small < *(amount+i))
        {
            small = *amount; 
        }
    }

    return small;
}

double find_max(double* amount, int n)
{
    double large = *amount;
    int i;
   

    for (i=0; i < n; i++)
    {
        if (large > *(amount+i))
        {
            large = *(amount+i); 
        }
    }

    return large;
}

 void write_to_file(char*output, double* size, int n)
 {
    int i = 0;
    FILE *outputfile = fopen(output, "w");

    while( i < n)
    {
        fprintf(outputfile, "%lf\n", *(size+i));
        i++;
    }
    fclose(outputfile);

    return;
 }

