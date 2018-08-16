#include <stdio.h>

int main ()
{
    int num, i;

    printf("Enter a number: \n");
    scanf("%d", &num);


    for(i=1; i<=num; i++)
    {
        if (i%3 == 0 && i%5 == 0)
        
            printf("MIZZOU ");
        
        else
            if(i%3 == 0)
            printf("MIZ ");
            else 
                if(i%5 == 0)
                printf("ZOU ");

                    else
                    printf ("%d  ", i);


    }
    
printf("\n\n");
return 0;
}
