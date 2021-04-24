#include <stdio.h>

int main()
{
    /*
    Para evitar esto, nacio un conjunto de estructuras llamadas BUCLES
    printf("Hola Anna \n");
    printf("Hola Anna \n");
    printf("Hola Anna \n");
    printf("Hola Anna \n");
    printf("Hola Anna \n");
    */

    /*
   Un bucle while repite su barriga mientras su condicion sea verdadera
   por tanto, si deseas detenerlo, TIENES QUE ESPECIFICARLO
   */

    int repeticiones;
    printf("Cuantas veces quieres repetir el nombre de Anna: ");
    scanf("%d", &repeticiones);

    while (repeticiones > 0)
    {
        printf("Hola Anna \n");
        repeticiones = repeticiones -1;
    }


    /*lo mismo pero incrementando*/
    int contador =0;
    int veces;
    printf("Cuantas veces quieres repetir el nombre de Anna: ");
    scanf("%d", &veces);

    while (contador < veces)
    {
        printf("Hola Anna \n");
        contador = contador +1;
    }


    printf("Programa finalizado \n");
    return 0;
}