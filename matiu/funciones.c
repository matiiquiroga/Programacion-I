#include "funciones.h"

int suma(int numUno, int numDos)
{
    int sumar;
    sumar = numUno + numDos;

    return sumar;
}


int resta(int numUno, int numDos)
{
    int restar;
    restar = numUno-numDos;

    return restar;
}

int division(int numUno, int numDos)
{
    int dividir;
    dividir = numUno/numDos;

    return dividir;

}

int multiplicacion(int numUno, int numDos)
{
    int multiplicar;
    multiplicar= numUno*numDos;

    return multiplicar;
}

int factorial(int numUno)
{
    int i, fact=1;

    for(i=1; i<=numUno; i++)
    {
        fact= fact * i;
    }

    return fact;
}
