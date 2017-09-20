#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"



int buscarLibre(eProgramador lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int buscarProgramador(int id,eProgramador lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1 && lista[i].id==id)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

void variablesCero(eProgramador lista[],int i)
{
    strcpy(lista[i].nombre,"\0");
    lista[i].categoria='\0';
    lista[i].estado=0;
    lista[i].id=0;
    lista[i].proyecto=0;
}

void inicializarVariables(eProgramador lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCero(lista,i);
    }
}


void mostrarProgramador(eProgramador lista)
{
    char cat[11];

    if(lista.categoria=='a')
    {
        strcpy(cat,"Senior");
    }
    else if(lista.categoria=='b')
    {
        strcpy(cat,"SemiSenior");
    }
    else
    {
        strcpy(cat,"junior");
    }


    printf("\n%d     %s     %s     %d",lista.id,lista.nombre,cat,lista.proyecto);
}

void mostrarProgramadores(eProgramador lista[],int tam)
{
    int i;
    int flag=0;


    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarProgramador(lista[i]);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}


void alta(eProgramador lista[],int tam)
{
    eProgramador nuevoProgramador;

    int esta;
    int lugar;
    int id;

    lugar=buscarLibre(lista,tam);

    if(lugar==-1)
    {
        printf("No hay lugar!\n");
    }
    else
    {
        printf("\ningrese ID: ");
        scanf("%d",&id);
        esta=buscarProgramador(id,lista,tam);
    }
    if(esta!=-1)
    {
        printf("El id ya existe");
    }
    else
    {
        nuevoProgramador.id=id;
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nuevoProgramador.nombre);
        printf("\nIngrese proyecto: ");
        scanf("%d",&nuevoProgramador.proyecto);
        printf("\nIngrese categoria (a-Senior  b-SemiSenior  c-Junior): ");
        fflush(stdin);
        nuevoProgramador.categoria=getchar();
        nuevoProgramador.estado=1;

    }
    lista[lugar]=nuevoProgramador;
}


void baja(eProgramador lista[],int tam)
{
    int esta;
    int id;
    char respuesta='n';

    printf("\ningrese ID: ");
    scanf("%d",&id);
    esta=buscarProgramador(id,lista,tam);

    if(esta!=-1)
    {
        mostrarProgramador(lista[esta]);
        printf("\nDesea eliminar esta entrada: S/N");
        fflush(stdin);
        respuesta=getch();
        if(respuesta=='s')
        {
            variablesCero(lista,esta);
            printf("\nEliminado con exito\n");
        }
        if(respuesta=='n')
        {
            printf("accion cancelada.\n");
        }
    }
    else
    {
        printf("\nNo se ha encontrado el ID.");

    }
}


void modificacion(eProgramador lista[],int tam)
{
    int esta;
    int id;
    char respuesta='n';

    printf("\ningrese ID: ");
    scanf("%d",&id);
    esta=buscarProgramador(id,lista,tam);

    if(esta!=-1)
    {
        mostrarProgramador(lista[esta]);
        printf("\nDesea modificar esta entrada: S/N\n");
        fflush(stdin);
        respuesta=getch();
        if(respuesta=='s')
        {
            printf("\nIngrese nueva categoria: ");
            fflush(stdin);
            lista[esta].categoria=getchar();
            printf("\nModificacion con exito");
        }
        if(respuesta=='n')
        {
            printf("accion cancelada.\n");
        }
    }
    else
    {
        printf("\nNo se ha encontrado el ID.");

    }
}
