#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char apellidoYnombre[40];
    char buffer[1024];

    printf("Ingrese nombre: ");
    gets(buffer);

    while(strlen(buffer) <2 || strlen(buffer>19)<19)
    {
        printf("error, reingrese nombre valido");
        gets(buffer);
    }

    strcpy(nombre,buffer);

    printf("Ingrese apellido: ");
    gets(buffer);

    while((strlen(buffer<2||buffer>19)))
    {
        printf("error, reingrese nombre valido");
        gets(buffer);
    }
    strcpy(apellido,buffer);

    strcat(apellido," ");
    strcat(apellido,nombre);

    printf(" apellido y nombre: %s", apellido);

    return 0;
}
