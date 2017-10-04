#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppFunciones.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int menu()
{
    int opcion;

    system("cls");
    printf("1- Alta Cliente\n");
    printf("2- Modificacion Cliente\n");
    printf("3- Ingreso Automovil\n");
    printf("4- Egreso Automovil\n");
    printf("5- Informar listado de autos con dueños ordenados por hs ingreso y patente\n");

    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEstadosDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    int i;

    for(i=0; i<tamDuenio; i++)
    {
        listaDuenio[i].estadoDuenio=0;
    }
}

void inicializarEstadosAutomovil(eAutomovil listaAutomovil[],int tamAutomovil)
{
    int i;

    for(i=0; i<tamAutomovil; i++)
    {
        listaAutomovil[i].estadoAutomovil=0;
    }
}

int buscarIndiceLibreDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    int indice=-1;
    int i;

    for(i=0; i<tamDuenio; i++)
    {
        if(listaDuenio[i].estadoDuenio==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarIndiceLibreAutomovil(eAutomovil listaAutomovil[], int tamAutomovil)
{
    int indice=-1;
    int i;

    for(i=0; i<tamAutomovil; i++)
    {
        if(listaAutomovil[i].estadoAutomovil==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarId(eDuenio listaDuenio[], int tamDuenio, int coincidencia)
{
    int indice= -1;
    int i;

    for(i=0; i<tamDuenio; i++)
    {
        if(listaDuenio[i].idDuenio==coincidencia && listaDuenio[i].estadoDuenio==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    eDuenio nuevoDuenio;
    int nuevoId;
    int lugar;
    int coincidencia;

    lugar=buscarIndiceLibreDuenio(listaDuenio,tamDuenio);

    if(lugar==-1)
    {
        printf("no hay mas lugar");
    }
    else
    {
        printf("ingrese id: ");
        scanf("%d", &nuevoId);

        coincidencia = buscarId(listaDuenio,tamDuenio,nuevoId);

        if(coincidencia!= -1)
        {
            printf("El id coincide con un cliente ya ingresado: \n");
          //  mostrarCliente(listaClientes[coincidencia]);
        }
        else
        {
            nuevoDuenio.idDuenio= nuevoId;

            printf("ingrese su nombre y apellido:");
            fflush(stdin);
            gets(nuevoDuenio.nombreapellido);

            printf("ingrese su direccion:");
            fflush(stdin);
            gets(nuevoDuenio.direccion);

            printf("ingrese su num de tarjeta de credito:");
            scanf("%d", &nuevoDuenio.numeroTarjetaCredito);

            nuevoDuenio.estadoDuenio=1;

            printf("\n\nCliente agregado con exito\n\n");
        }
        listaDuenio[lugar]=nuevoDuenio;
    }
}

void altaAutomovil(eAutomovil listaAutomovil[], eDuenio listaDuenio[], int tamAutomovil, int tamDuenio)
{
    eAutomovil nuevoIngreso;
    int auxId;
    int auxMarca;
    int lugar;
    int coincidencia;

    lugar=buscarIndiceLibreAutomovil(listaAutomovil,tamAutomovil);

    if(lugar==-1)
    {
        printf("no hay mas lugar");
    }
    else
    {
        printf("ingrese id del cliente a ingresar automovil: ");
        scanf("%d", &auxId);

        coincidencia = buscarId(listaDuenio,tamDuenio,auxId);

        if(coincidencia == -1)
        {
            printf("\n No se encontro el id del cliente ingrado \n");
        }
        else
        {
            nuevoIngreso.idCliente=auxId;

            printf("\nIngrese patente del automovil:");
            fflush(stdin);
            gets(nuevoIngreso.patente);

            printf("ingrese marca del automovil: \n1)ALPHA ROMEO\n2)FERRARI\n3)AUDI\n4)OTROS\n");
            scanf("%d", &auxMarca);

            while(auxMarca<1 || auxMarca>3)
            {
                printf("error, reingrese marca valida: ");
                scanf("%d", &auxMarca);
            }
            nuevoIngreso.marca= auxMarca;

            printf("ingrese su horario de entrada (formato 24hs): ");
            scanf("%d", &nuevoIngreso.hsEntrada);

            nuevoIngreso.estadoAutomovil=1;

            printf("\n\nAutomovil Ingresado con exito\n\n");
        }
        listaAutomovil[lugar]=nuevoIngreso;
    }
}

void hardcodeaDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    int id[5]={11,12,24,25,32};
    char nombreYapellido[5][50]={"matias Quiroga","abul Rodriguez","pepe Santos","luis fonsi","lucas rojas"};
    char direccion[5][30]={"mitre","brasil","corrientes","saavedra","granaderos"};
    int numTarjetaCredito[5]={123465,654987,798654,426987,987986};
    int i;

    for(i=0;i<5;i++)
    {
        listaDuenio[i].idDuenio=id[i];
        strcpy(listaDuenio[i].nombreapellido,nombreYapellido[i]);
        strcpy(listaDuenio[i].direccion,direccion[i]);
        listaDuenio[i].numeroTarjetaCredito=numTarjetaCredito[i];
        listaDuenio[i].estadoDuenio=1;
    }
}

void hardcodeaAutomovil(eAutomovil listaAutomovil[], int tamAutomovil)
{
    char patente[5][15]={"abc 123","def 456","ghi 789","jkl 001", "mno 010"};
    int marca[5]={1,2,1,3,1};
    int horasIngreso[5]={12,13,16,17,19};
    int idCliente[5]={11,12,24,25,32};
    int i;

    for(i=0;i<5;i++)
    {
        strcpy(listaAutomovil[i].patente,patente[i]);
        listaAutomovil[i].marca=marca[i];
        listaAutomovil[i].hsEntrada=horasIngreso[i];
        listaAutomovil[i].idCliente=idCliente[i];
        listaAutomovil[i].estadoAutomovil=1;
    }
}

void mostrarAutomovilesPorHoraYpatente(eAutomovil lista[], eDuenio listaDuenio[], int tamAutomovil, int tamDuenio)
{
    int i;

    for(i=0;i<tamAutomovil;i++)
    {
        mostrarAutomovilPorHoraYpatente(lista[i],listaDuenio,tamDuenio);
    }
}

void mostrarAutomovilPorHoraYpatente(eAutomovil automovil, eDuenio listaDuenio[], int tamDuenio)
{
    int i;

    printf("\t\tlistado de automoviles\n\n");
    printf("%s\n%d\n%d--",automovil.patente, automovil.hsEntrada, automovil.marca);

    for(i=0;i<tamDuenio;i++)
    {
        if(automovil.idCliente==listaDuenio[i].idDuenio)
        {
            printf("%s",listaDuenio[i].nombreapellido);
        }
    }

}
