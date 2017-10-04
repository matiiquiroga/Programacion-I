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
    printf("5- Alta Proyecto\n");
    printf("6- Salir\n");

    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarProgramador(eProgramador programador, eCategorias cates[], int tam)
{
    int i;
    printf("\n%d\t%s\t%s\t",programador.id,programador.nombre);

    for(i=0;i<tam;i++)
    {
        if(programador.categoria==cates[i].idCategoria)
        {
            printf("%s",cates[i].descripcion);
            break;
        }
    }
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

void altaProgramador(eProgramador lista[],int tam)
{
    eProgramador newProgramador;
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
            newProgramador.id= newId;

            printf("ingrese su nombre:");
            fflush(stdin);
            gets(newProgramador.nombre);

            printf("ingrese categoria:");
            fflush(stdin);
            scanf("%c", &newProgramador.categoria);

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
    int id[3]= {11,12,13};
    char descripcionProyectos[3][25]= {"ssGestion","afip","arba"};

    for(i=0; i<3; i++)
    {
        listaProyectos[i].idProyecto=id[i];
        strcpy(listaProyectos[i].descripcion,descripcionProyectos[i]);
    }
}

void inicializarCategorias(eCategorias lista[])
{
    int i;
    char auxId[3]={'a','b','c'};
    char auxDescripcion[3][25]={"senior","semiSenior","junior"};
}

void altaProyectoProgramador(eProgramadoresYproyectos listaProgYproy[],eProgramador listaProg[],int tamProyYpro,int tamProgramadores)
{
    int lugar;
    eProgramadoresYproyectos auxProgYproy;

    lugar=buscarProyectoLibre(listaProgYproy,tamProyYpro);

    if(lugar==-1)
    {
        printf("no hay mas lugar");
    }
    else
    {
        ordenaProgramadores(listaProg,tamProgramadores);
        printf("\tlistado de programadores\n\n");
        mostrarProgramadores(listaProg,tamProgramadores);

        printf("\n\nElija el id del programador a ingresar proyecto: ");
        scanf("%d",&auxProgYproy.idProgramadores);

        printf("\tlistado de proyectos\n\n11\tssGestion\n12\tafip\n13\tarba");
        printf("\n\nelija el id del proyecto: ");
        scanf("%d",auxProgYproy.idProyectos);

        printf("\nIngrese la cantidad de hs dedicadas al proyecto: ");
        scanf("%d",&auxProgYproy.horasTrabajadas);

        printf("\n\n proyecto agregado exitosamente");
    }

    listaProgYproy[lugar]=auxProgYproy;
}

int buscarProyectoLibre(eProgramadoresYproyectos lista[], int tam)
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

void inicializarVectorProgramadoresProyectos(eProgramadoresYproyectos lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}

