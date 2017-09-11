#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

void muestraNombre(char name[]);
void muestraNombreS(char matriz[][35],int tam);
void ordenaNombres(char matriz[][35],int tam);

int validaCadena(char buffer[],int tam);

int main()
{

    char nombre[MAX][35];
    char buffer [1024];
    int i;

    for(i=0;i<MAX;i++)
    {
        printf("ingrese nombre: ");
        fflush(stdin);
        gets(buffer);
        while(validaCadena(buffer, MAX)==0)
        {
            printf("errorcadenademasiadolarga ");
            fflush(stdin);
            gets(buffer);
        }
        strcpy(nombre[i],buffer);
    }

    muestraNombreS(nombre,MAX);
    printf("\n\n");
    ordenaNombres(nombre,MAX);
    printf("\n\n");
    muestraNombreS(nombre,MAX);
    return 0;
}

int validaCadena(char buffer[], int tam)
{
    int valida=0;
    if(strlen(buffer)<45)
    {
        valida=1;
    }
    return valida;
}

void muestraNombre(char name[])
{
    printf("%s\n", name);
}

void muestraNombreS(char name[][35],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        muestraNombre(name[i]);
    }
}

void ordenaNombres(char matriz[][35],int tam)
{
    char aux[35];
    int i,j;

    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(strcmp(matriz[i],matriz[j])>0)
            {
                 strcpy(aux,matriz[j]);
                 strcpy(matriz[j],matriz[i]);
                 strcpy(matriz[i],aux);
            }

        }
    }
}
