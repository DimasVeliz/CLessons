#include <stdio.h>

int main()
{
     /*
    6, REGLA del AND &&

    comer | irAlCine | SER FELIZ resultado AND
    0       0         0
    0       1         0
    1       0         0
    1       1         1


    7, REGLA del OR ||

    comer | irAlCine | SER FELIZ resultado OR
    0       0         0
    0       1         1
    1       0         1
    1       1         1

    8, REGLA del NOT !=   

    comer | Resultado NOT
    0       1
    1       0 
    */
    

    int heComido =0;
    int hayBuenClima =1;
    int serFeliz = heComido && hayBuenClima;
    
    /*
    El if-else son mutuamente exclusivos
    el else, de alguna manera es una negacion del if
    */
   
    if (serFeliz)
    {
        printf("Heheh ire al cine\n");
    }
    else
    {
        printf("Que pena\n");
    }
    
    return 0;
}