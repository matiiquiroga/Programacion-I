#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char nombre[20];
    char apellido[20];
    char apellidoYnombre[50];
    char buffer[1024];
    char aux;

    printf("Ingrese nombre: ");
    gets(buffer);
    while(strlen(buffer) <2 || strlen(buffer)>19){
        printf("error, reingrese nombre valido");
        gets(buffer);
    }
    strcpy(nombre,buffer);
    aux=nombre[0];
    aux= toupper(aux);
    nombre[0]=aux;

    printf("Ingrese apellido: ");
    gets(buffer);
    while(strlen(buffer)<2||strlen(buffer)>19){
        printf("error, reingrese nombre valido");
        gets(buffer);
    }
    strcpy(apellido,buffer);
    aux=apellido[0];
    aux=toupper(aux);
    apellido[0]=aux;

    strcat(apellidoYnombre,apellido);
    strcat(apellidoYnombre," ");
    strcat(apellidoYnombre,nombre);

    printf(" apellido y nombre: %s", apellidoYnombre);

    return 0;
}
