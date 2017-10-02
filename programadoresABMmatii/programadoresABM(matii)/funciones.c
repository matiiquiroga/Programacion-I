#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menu()
{
    int opcion;

    system("cls");
    printf("\n***Programadores***\n\n\n");
    printf("1- Alta Programador\n");
    printf("2- Modificacion Programador\n");
    printf("3- Baja Programador\n");
    printf("4- Listado Programadores\n");
    printf("5- Listado por cada programador cada proyecto");
    printf("6- Salir\n");

    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
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
    printf("\n%d     %s     %s     ",lista.id,lista.nombre,cat);
}

void mostrarProgramadores(eProgramador lista[], int tam)
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

int buscarEspacioLibre(eProgramador lista[], int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void inicializarVector(eProgramador lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}

int buscarProgramador(eProgramador lista[],int tam, int id)
{
    int indice=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].id==id && lista[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaProgramador(eProgramador lista[],eProgramadoresYproyectos listaProgramadoresYproyectos[], int tam, int tamProgYproy)
{
    eProgramador newProgramador;
    eProgramadoresYproyectos newProgYproy;
    int newId;
    int lugar;
    int esta;

    lugar=buscarEspacioLibre(lista,tam);

    if(lugar==-1)
    {
        printf("no hay mas lugar");
    }
    else
    {
        printf("ingrese id: ");
        scanf("%d", &newId);
        esta = buscarProgramador(lista,tam,newId);

        if(esta!=-1)
        {
            printf("El id coincide con un programador ya ingresado: \n");
            mostrarProgramador(lista[esta]);
        }
        else
        {

            /*
            EN LA VALIDACION DEL ID DEL PROYECTO INGRESAR
            TAMBIEN LAS HORAS DE TRABAJO DEDICADAS AL PROYECTO
            Y PREGUNTAR PARA AGREGAR OTRO
            */
            newProgramador.id= newId;
            newProgYproy.idProgramadores=newId;

            printf("ingrese su nombre:");
            fflush(stdin);
            gets(newProgramador.nombre);

            printf("ingrese categoria:");
            fflush(stdin);
            scanf("%c", &newProgramador.categoria);

            printf("ingrese id del proyecto:");
            scanf("%d", &newProgYproy.idProyectos);

            while(newProgYproy.idProyectos<11 || newProgYproy.idProyectos>13)
            {
                printf("ERROR, reingrese id proyecto valido: (11-12-13");
            }

            newProgramador.estado=1;
            printf("\n\nProgramador agregado con exito\n\n");
        }
        lista[lugar]=newProgramador;

    }

}

int buscarCoincidencia(eProgramador lista[], int tam, int id)
{
    int indice= -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].id==id && lista[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


void bajaProgramador(eProgramador lista[], int tam)
{
    int indice;
    int auxId;
    char confirmaEliminar;

    printf("Ingrese el id de la persona que desea eliminar: ");
    scanf("%d",&auxId);

    indice=buscarCoincidencia(lista,tam,auxId);

    if(indice != -1)
    {
        mostrarProgramador(lista[indice]);

        printf("Confirma eliminacion? (s/n)");
        fflush(stdin);
        scanf("%c", &confirmaEliminar);

        if(confirmaEliminar=='s')
        {
            lista[indice].estado=0;
            printf("\nProgramador Eliminado\n");
        }
        else
        {
            printf("\nBaja cancelada por el usuario");
        }
    }
}

void modificaProgramador(eProgramador lista[],int tam)
{
    int auxId;
    char modificacion;

    printf("Ingrese el id de la persona que desea modificar: ");
    scanf("%d",&auxId);

    auxId=buscarCoincidencia(lista,tam,auxId);

    if(auxId != -1)
    {
        mostrarProgramador(lista[auxId]);

        printf("Ingrese nueva categoria para el usuario: ");
        fflush(stdin);
        scanf("%c", &modificacion);
        lista[auxId].categoria=modificacion;
        printf("categoria modificada exitosamente.");
    }
    else
    {
        printf("No se encontro coincidencia con ningun usuario");
    }
}

void ordenaProgramadores(eProgramador lista[], int tam)
{
    eProgramador aux;
    int i,j;

    for(i=0; i<tam; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].id>lista[j].id)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}

void inicializaProgramadores(eProgramador lista[])
{
    int i;
    int id[20]= {15,12,13,14,55,6,20,21,22,23,24,25,26,40,41,42,43,44,45,46};
    char nombre[20][20]= {"ana","abril","julio","mica","marcos","pepe","german","ivan","dora","rut","agustin","juan","jose","maria","marta","olga","nora","rocio","santi","matias"};
    char categoria[20]= {'c','a','b','c','c','a','b','c','c','a','b','c','c','a','b','c','c','a','b','c'};

    for(i=0; i<20; i++)
    {
        lista[i].id=id[i];
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].categoria=categoria[i];
        lista[i].estado=1;
    }
}

void inicializaProyectos(eProyectos listaProyectos[])
{
    int i;
    int id[3]={11,12,13};
    char descripcionProyectos[3][25]={"ssGestion","afip","arba"};

    for(i=0;i<3;i++)
    {
        listaProyectos[i].idProyecto=id[i];
        strcpy(listaProyectos[i].descripcion,descripcionProyectos[i]);
    }
}

