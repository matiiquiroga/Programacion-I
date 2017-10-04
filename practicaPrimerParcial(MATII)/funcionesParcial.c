#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesParcial.h"

#define MOLADORA 15
#define MEZCLADORA 16
#define TALADRO 17

#define ALQUILADO 1
#define FINALIZADO 0

int menu()
{
    int opcion;

    system("cls");
    printf("1- Alta Cliente\n");
    printf("2- Modificacion Cliente\n");
    printf("3- Baja Cliente\n");
    printf("4- Nuevo Alquiler\n");
    printf("5- Fin Del Alquiler\n");
    printf("6- Informar\n");

    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEstadosClientes(eClientes listaClientes[], int tamClientes)
{
    int i;

    for(i=0; i<tamClientes; i++)
    {
        listaClientes[i].estadoCliente=0;
    }
}

void inicializarEstadosAlquiler(eAlquileres listaAlquileres[], int tamAlquileres)
{
    int i;

    for(i=0; i<tamAlquileres; i++)
    {
        listaAlquileres[i].estadoAlquiler=0;
    }
}

void inicializarEstadosData(eData listaData[], int tamData)
{
    int i;

    for(i=0; i<tamData; i++)
    {
        listaData[i].estado=0;
    }
}

int buscarIndiceLibreClientes(eClientes listaClientes[], int tamClientes)
{
    int indice=-1;
    int i;

    for(i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].estadoCliente==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int buscarIndiceLibreAlquiler(eAlquileres listaAlquileres[], int tamAlquileres)
{
    int indice=-1;
    int i;

    for(i=0; i<tamAlquileres; i++)
    {
        if(listaAlquileres[i].estadoAlquiler==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int buscarIndiceLibreData(eData listaData[],int tamData)
{
    int indice=-1;
    int i;

    for(i=0; i<tamData; i++)
    {
        if(listaData[i].estado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int buscarEquipo(eData listaData[], int tamData, int numEquipo)
{
    int indice=-1;
    int i;

    for(i=0; i<tamData; i++)
    {
        if(listaData[i].equipo == numEquipo && listaData[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarDni(eClientes listaClientes[], int tamClientes, int coincidencia)
{
    int indice= -1;
    int i;

    for(i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].dni==coincidencia && listaClientes[i].estadoCliente==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarId(eClientes listaClientes[], int tamClientes, int coincidencia)
{
    int indice= -1;
    int i;

    for(i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].id==coincidencia && listaClientes[i].estadoCliente==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaCliente(eClientes listaClientes[], int tamClientes)
{
    eClientes nuevoCliente;
    int nuevoDni;
    int lugar;
    int coincidencia;

    lugar=buscarIndiceLibreClientes(listaClientes,tamClientes);

    if(lugar==-1)
    {
        printf("no hay mas lugar");
    }
    else
    {
        printf("ingrese dni: ");
        scanf("%d", &nuevoDni);

        coincidencia = buscarDni(listaClientes,tamClientes,nuevoDni);

        if(coincidencia!=-1)
        {
            printf("El dni coincide con un cliente ya ingresado: \n");
            mostrarCliente(listaClientes[coincidencia]);
        }
        else
        {
            nuevoCliente.dni= nuevoDni;

            printf("ingrese su nombre:");
            fflush(stdin);
            gets(nuevoCliente.nombre);

            printf("ingrese su apellido:");
            fflush(stdin);
            gets(nuevoCliente.apellido);

            nuevoCliente.estadoCliente=1;

            nuevoCliente.id= lugar+1;

            printf("\n\nCliente agregado con exito\n\n");
        }
        listaClientes[lugar]=nuevoCliente;
    }
}

void modificarCliente(eClientes listaClientes[],int tamClientes)
{
    int auxId;
    int indice;

    printf("Ingrese el id de la persona que desea modificar: ");
    scanf("%d",&auxId);

    indice = buscarId(listaClientes,tamClientes,auxId);

    if(indice != -1)
    {
         mostrarCliente(listaClientes[indice]);

        printf("Ingrese nuevo nombre para el usuario: ");
        fflush(stdin);
        scanf("%s", listaClientes[indice].nombre);

        printf("Ingrese nuevo Apellido para el usuario: ");
        fflush(stdin);
        scanf("%s", listaClientes[indice].apellido);

        printf("\nCliente modificado exitosamente.");
    }
    else
    {
        printf("No se encontro el id del cliente.");
    }
}

void bajaCliente(eClientes listaClientes[],int tamClientes)
{
    int indice;
    int auxId;
    char confirmaEliminar;

    printf("Ingrese el id de la persona que desea eliminar: ");
    scanf("%d",&auxId);

    indice=buscarId(listaClientes,tamClientes,auxId);

    if(indice != -1)
    {
        mostrarCliente(listaClientes[indice]);

        printf("Confirma eliminacion? (s/n)");
        fflush(stdin);
        scanf("%c", &confirmaEliminar);

        if(confirmaEliminar=='s')
        {
            listaClientes[indice].estadoCliente=0;
            printf("\nCliente Eliminado.\n");
        }
        else
        {
            printf("\nEliminacion cancelada.");
        }
    }
}

void nuevoAlquiler(eAlquileres listaAlquileres[], eClientes listaClientes[], eData listaData[], int tamAlquileres, int tamClientes, int tamData)
{
    int lugar;
    int lugarData;
    int auxIdCliente;
    int auxEquipo;
    int coincidencia;

    lugar=buscarIndiceLibreAlquiler(listaAlquileres,tamAlquileres);
    lugarData=buscarIndiceLibreData(listaData,tamData);

    if(lugar==-1)
    {
        printf("no hay mas lugar");
    }
    else
    {
        printf("Ingrese su id de cliente:");
        scanf("%d", &auxIdCliente);

        coincidencia = buscarId(listaClientes,tamClientes,auxIdCliente);

        if(coincidencia==-1)
        {
            printf("El id del cliente no es valido\n");
        }
        else
        {
            //     mostrarProgramador(listaClientes[esta]);

            listaData[lugarData].idCliente=auxIdCliente;

            printf("\n\nIngrese el numero del equipo: \n1)AMOLADORA\n2)MEZCLADORA\n3)TALADRO\n\n");
            scanf("%d", &auxEquipo);

            while(auxEquipo<1 || auxEquipo>3)
            {
                printf("ERROR, reingrese: ");
                scanf("%d",&auxEquipo);
            }
            listaAlquileres[lugar].equipo=auxEquipo;
            listaData[lugarData].equipo=auxEquipo;

            printf("\nIngrese tiempo estimado del alquiler: ");
            scanf("%d",&listaAlquileres[lugar].tiempoEstimado);

            printf("\nIngrese el Operador: ");
            fflush(stdin);
            gets(listaAlquileres[lugar].operador);

            listaAlquileres[lugar].estadoAlquiler=ALQUILADO;
            listaData[lugarData].estado=ALQUILADO;

            printf("Alquiler exitoso!");
        }
    }
}

void finAlquiler(eAlquileres listaAlquileres[], eClientes listaClientes[], eData listaData[], int tamAlquileres, int tamClientes, int tamData)
{
    int auxIdCliente;
    int indice;
    int auxEquipo;
    int equipoindice;

    printf("\nIngrese el ID del Cliente que finaliza el alquiler: ");
    scanf("%d",&auxIdCliente);

    indice=buscarId(listaClientes,tamClientes,auxIdCliente);

    if(indice!=-1)
    {

        printf("\n\nIngrese el numero del equipo: \n1)AMOLADORA\n2)MEZCLADORA\n3)TALADRO\n\n");
        scanf("%d",&auxEquipo);

        while(auxEquipo<1 || auxEquipo>3)
        {
            printf("ERROR, reingrese: ");
            scanf("%d",&auxEquipo);
        }

        equipoindice=buscarEquipo(listaData,tamData,auxEquipo);

        if(equipoindice != -1)
        {
            listaData[indice-1].estado=FINALIZADO;
            printf("\nIngrese duracion de tiempo alquilado real: ");
            scanf("%d",&listaAlquileres[indice-1].tiempoReal);
            printf("\nAlquiler FINALIZADO\n\n");
        }
        else
        {
            printf("\nNo ah sido alquilado!\n");
        }
    }

    else
    {
        printf("\nID no encontrado.\n");
    }
}


void mostrarCliente(eClientes cliente)
{
    printf("\nDNI: %d\nNombre y Apellido: %s %s\nID: %d\n",cliente.dni,cliente.nombre,cliente.apellido,cliente.id);
}

void mostrarClientes(eClientes listaClientes[],int tamClientes)
{
    int i;
    int flag=0;

    for(i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].estadoCliente==1)
        {
            mostrarCliente(listaClientes[i]);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}

void hardcodearClientes(eClientes listaClientes[], int tamClientes)
{
    int id[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int dni[20]={32165478,12345678,74523698,45698761,13269478,75395148,96385248,85274693,46975321,65498712,1594872,36148795,25487963,15487987,66998855,11224455,22115544,33669988,55221144,44558877};
    char nombre[20][25]= {"ana","abril","julio","mica","marcos","pepe","german","ivan","dora","rut","agustin","juan","jose","maria","marta","olga","nora","rocio","santi","matias"};
    char apellido[20][25]={"acosta","landino","piñero","moralez","lopez","andrade","martinez","peña","quiroga","vera","cruz","gonzalez","sanchez","garcia","romero","barakat","deluca","viera","zapata","rodriguez"};

    int i;

     for(i=0; i<20; i++)
    {
        listaClientes[i].id=id[i];
        listaClientes[i].dni=dni[i];
        strcpy(listaClientes[i].nombre,nombre[i]);;
        strcpy(listaClientes[i].apellido,apellido[i]);
    }
}

