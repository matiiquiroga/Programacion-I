#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    char seguir='s';
    int opcion;
    int numUno=0;
    int numDos=0;
    int resultado= 0;
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
    while(seguir=='s')
    {
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            printf("ingrese su primer numero ");
            scanf("%d", &numUno);
            system("cls");
            printf("1- Ingresar 1er operando (A=%d)\n",numUno);
            printf("2- Ingresar 2do operando (B=y)\n");
            break;

        case 2:
            printf("ingrese segundo numero: ");
            scanf("%d", &numDos);
            system("cls");
            printf("1- Ingresar 1er operando (A=%d)\n",numUno);
            printf("2- Ingresar 2do operando (B=%d)\n",numDos);
            break;

        case 3:
            resultado= suma(numUno, numDos);
            printf("la suma es: %d", resultado);
            break;

        case 4:
            resultado= resta(numUno, numDos);
            printf("la resta es: %d", resultado);
            break;

        case 5:
            resultado = division(numUno, numDos);
            printf("la division es: %d", resultado);
            break;

        case 6:
            resultado= multiplicacion(numUno,numDos);
            printf("la multiplicacion es: %d", resultado);
            break;

        case 7:
            resultado= factorial(numUno);
            printf("el factorial es; %d", resultado);
            break;

        case 8:
            resultado= suma(numUno, numDos);
            printf("la suma es: %d\n", resultado);
            resultado= resta(numUno, numDos);
            printf("la resta es: %d\n", resultado);
            resultado = division(numUno, numDos);
            printf("la division es: %d\n", resultado);
            resultado= multiplicacion(numUno,numDos);
            printf("la multiplicacion es: %d\n", resultado);
            resultado= factorial(numUno);
            printf("el factorial es; %d\n", resultado);
            break;

        case 9:
            seguir = 'n';
            break;
        }
    }
    return 0;
}
