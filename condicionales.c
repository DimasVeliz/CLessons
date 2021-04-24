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

    int heComido = 0;
    int hayBuenClima = 1;
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

    int mamaTrajoMandarinas = 0;
    int mamaTrajoNaranjas = 0;
    int noTengoHambre = mamaTrajoMandarinas || mamaTrajoNaranjas;

    if (noTengoHambre)
    {
        printf("Menos mah\n");
    }
    else
    {
        printf("OStras madre, no me amas\n");
        mamaTrajoMandarinas = 1;
    }


    /*
    regla if-else if -else if..... else
    TAMBIEN SON MUTUAMENTE EXCLUSIVOS
    el else, de alguna manera es una negacion del if y todos los elif anteriores

    */

    int numero1 =7;
    int numero2= 40;
    
    if (numero1 > numero2)
    {
        printf("Numero1 es el mayor\n");
    }
    else if(numero1 < numero2 )
    {
        printf("Numero2 es el mayor\n");
        numero2=numero1;
    }
    else
    {
        printf("Son iguales\n");
    }


    printf("Programa finalizado\n");
    return 0;
}