#include <stdio.h>

int main()
{
    /*
    1, todos los programas se leen de arriba hacia abajo
    2, todos se leen de derecha a izquierda
    3, todos se leen de adentro hacia afuera
    4, hay tipos de datos
    5, los datos se pueden mostrar por pantalla (Necesita especificar cambio de linea)
    */

    int miAbuela = 7;
    int segundoNumero = 14;
    int numero3 = miAbuela + 21;
    int numero4 = numero3 + 14;
    float precio = 40.5;
    double salario = 1.24712;
    char letra = 'k';
    char *cadenaTexto = "Anna es una Alumna de ASIR";

    printf("%d\n", miAbuela);
    printf("%d\n", numero4);

    printf("Por favor teclee un numero\n");
    
    int numeroUsuario;
    scanf("%d", &numeroUsuario);
    printf("El usuario introdujo el numero %d\n", numeroUsuario);

   

    printf("Programa finalizado\n");  
    return 0;
}