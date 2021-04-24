#include <stdio.h>

int main()
{
    /*
    Queremos calcular el promedio de todos los numeros entrados por pantalla
    */

    int cantNumeros;
    int contador =0;
    int numeroActual;
    printf("Introduce la cantidad deseada: ");
    scanf("%d", &cantNumeros);

    int acumuladorSuma = 0;
    while (contador < cantNumeros)
    {
        scanf("%d",&numeroActual);
        acumuladorSuma = acumuladorSuma + numeroActual;

        contador = contador + 1;
    }
    
    float promedio = (float)acumuladorSuma / cantNumeros;

    printf("El promedio de estos numeros es %f\n",promedio);


    printf("Programa finalizado \n");
    return 0;
}