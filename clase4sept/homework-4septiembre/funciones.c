#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void mostrarAlumno(int leg, int notaUno, int notaDos, float promedio, int tam)
{
    printf("  %4d     %4d     %4d      %4.2f \n", leg, notaUno, notaDos, promedio);
}

void mostrarAlumnos(int leg[], int n1[], int n2[], float promedio[], int tam)
{
    int i;
    printf(" Legajos - Nota 1 - Nota 2 - Promedio \n");

    for(i=0; i<tam; i++)
    {
        mostrarAlumno(leg[i], n1[i], n2[i], promedio[i],tam);
    }

}

void calcularPromedios(int notaUno[], int notaDos[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        promedio[i]=(float) (notaUno[i]+notaDos[i]) / 2;
    }
}

void ordenarVectores(int leg[], int notaUno[], int notaDos[], float promedio[], int tam)
{
    int i, j;
    int aux;
    float fAux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++);
        {
            if(leg[i]>leg[j])
            {
                aux=leg[j];
                leg[j]=leg[i];
                leg[i]=aux;

                aux=notaUno[j];
                notaUno[j]=notaUno[i];
                notaUno[i]=aux;

                aux=notaDos[j];
                notaDos[j]=notaDos[i];
                notaDos[i]=aux;

                fAux=promedio[j];
                promedio[j]=promedio[i];
                promedio[i]=fAux;
            }
        }
    }

     printf(" Legajos - Nota 1 - Nota 2 - Promedio \n");
     for(j=0;j<5;j++)
     {
         printf("  %4d     %4d     %4d      %4.2f \n", leg[j], notaUno[j], notaDos[j], promedio[j]);
     }
}

