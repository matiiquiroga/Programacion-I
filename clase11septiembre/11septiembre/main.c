#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int validaCadena(char buffer[], int tam);

int main()
{

    char nombre[35];
    char buffer [1024];

    printf("ingrese nombre: ");
    fflush(stdin);
    gets(buffer);

    while(validaCadena(buffer, MAX)==0)
    {
        printf("errorcadenademasiadolarga ");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(nombre,buffer);

   printf("%s",nombre);

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


