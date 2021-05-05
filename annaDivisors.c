#include <stdio.h>

 

int printDivisores(int numero)

{

       for (int i = 3; i < numero; i++)

       {

             for (int j = 3; j < numero; j++)

             {

                    if (i*j==numero)

                    {

                           printf("%d Es divisible por %d y %d\n", numero, i, j);

                           return 1;

                    }

             }

       }

       return 0;

}

int main()

{

       int numeroleido = 0;

 

       while (1)

       {

             scanf("%d", &numeroleido);

             printf("Hemos leido el numero: %d\n" , numeroleido);

             if (numeroleido==-1)

             {

                    break;

             }

             if (numeroleido==1 ||numeroleido==2)

             {

                    printf("Error\n");

                    continue;

             }

             int found = printDivisores(numeroleido);

             if (found == 0)

             {

                    printf("Error\n");

             }

       }

      

      

       return 0;

}