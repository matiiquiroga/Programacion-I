#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define alpha_romeo 1
#define ferrari 2
#define audi 3
#define otros 4


void comenzarEstados(EPersona personas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        personas[i].estado = 0;
        personas[i].idDuenio++;
    }
}

void comenzarEstadosVehiculos(Evehiculo autos[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        autos[i].estado = 0;

    }
}

void inicializarContador(int contador[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        contador[i] = 0;
    }
}


int obtenerEspacioLibre(EPersona personas[], int tam)
{
    int i;
    int auxFlag= 0;
    int disponible;

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado == 0)
        {
            disponible= i;
            auxFlag= 1;
            break;
        }
    }

    if(auxFlag==0)
    {
        disponible= -1;
    }

    return disponible;
}


int obtenerEspacioLibreVehiculos(Evehiculo autos[], int tam)
{
    int i;
    int auxFlag= 0;
    int disponible;

    for(i=0; i<tam; i++)
    {
        if(autos[i].estado == 0)
        {
            disponible= i;
            auxFlag= 1;
            break;
        }
    }

    if(auxFlag==0)
    {
        disponible= -1;
    }

    return disponible;
}




void cargarUsuario(EPersona personas[], int tam, int posicion)
{
    int i, auxId;

    printf("\nIngresar su nombre: ");
    fflush(stdin);
    gets(personas[posicion].nombre);

    printf("\nIngresar su apellido: ");
    fflush(stdin);
    gets(personas[posicion].apellido);

    printf("\nIngresar su direccion: ");
    fflush(stdin);
    gets(personas[posicion].direccion);

    printf("Ingresar su id del duenio: \n");
    scanf("%d", &auxId);

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado == 1)
        {
            while(auxId == personas[i].idDuenio)
            {
                printf("El id ya fue ingresado; reingrese por favor: \n");
                scanf("%d",&auxId);
            }

        }
    }

    printf("\nIngrese su num de tarjeta de credito: \n\n");
    scanf("%d", &personas[posicion].creditCard);

    personas[posicion].estado = 1;
}


void cargarVehiculo(Evehiculo autos[],EPersona propietario[], int tam, int posicion)
{
    printf("\nIngresar su patente: ");
    fflush(stdin);
    gets(autos[posicion].patente);

    printf("\nIngresar la marca del vehiculo a estacionar:\n1- Alpha Romeo\n2- Ferrari\n3-  Audi\n4- Otra marca\n");
    scanf("%d", &autos[posicion].marca);

    printf("\nIngresar su horario de entrada al estacionamiento (en formato de 24hrs): \n");
    scanf("%d",&autos[posicion].horarioEntrada);

    autos[posicion].estado = 1;
}



int buscarPrimerOcurrencia(EPersona personas[],int tam,int valor)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(personas[i].creditCard == valor && personas[i].estado == 1)
        {
            printf("Ingrese el nuevo numero de tarjeta de credito\n");
            scanf("%d",&personas[i].creditCard);
            printf("Su nuevo numero de tarjeta es: %d ",personas[i].creditCard);
            return 1;
        }
    }
    return -1;
}


void  egresoVehiculo(int contador[], EPersona propietario[], Evehiculo autos[], int tam)
{
    int flagPatente = 0;
    char buffer[200];
    int i, j;
    int auxHsSalida;
    int auxHsEntrada;
    char auxPatente[10];
    int totalHs;
    int pagoPorHora;
    int pagoTotal = 0;

    printf("Ingrese la patente del auto que desea retirar: ");
    fflush(stdin);
    gets(buffer);

    while(flagPatente == 0)
    {
        for(i=0; i<tam; i++)
        {
            if(strcmp(buffer,autos[i].patente)==0 && autos[i].estado == 1)
            {
                flagPatente = 1;
                break;
            }
        }
        if(flagPatente == 0)
        {
            printf("La patente no corresponde a ningun vehiculo, ingrese una distinta!: \n");
            fflush(stdin);
            gets(buffer);
        }

    }

    strcpy(auxPatente, buffer);

    for(i=0; i<tam; i++)
    {
        if(strcmp(autos[i].patente,auxPatente)== 0)
        {
            auxHsEntrada = autos[i].horarioEntrada;
        }
    }

    printf("Ingresar su horario de salida del estacionamiento (en formato de 24hrs): \n");
    scanf("%d", &auxHsSalida);

    totalHs = auxHsSalida - auxHsEntrada;

    for(i=0; i<tam; i++)
    {
        if(strcmp(auxPatente, autos[i].patente)==0)
        {
            if(autos[i].marca == '1')
            {
                pagoPorHora = 150;
                totalHs = pagoPorHora * totalHs;
                contador[0] += totalHs;
                break;
            }
            else if(autos[i].marca== '2')
            {

                pagoPorHora = 175;
                totalHs = pagoPorHora * totalHs;
                contador[1] += totalHs;
                break;
            }
            else if(autos[i].marca== '3')
            {
                pagoPorHora = 200;
                totalHs = pagoPorHora * totalHs;
                contador[2] += totalHs;
                break;
            }
            else if(autos[i].marca== '4')
            {

                pagoPorHora = 250;
                totalHs = pagoPorHora * totalHs;
                contador[3] += totalHs;
                break;
            }
            break;
        }
    }

    for(i=0; i<tam; i++)
    {
        if(strcmp(auxPatente, autos[i].patente)==0)
        {
            for(j=0; j<tam; j++)
            {
                if(autos[i].idDuenio == propietario[j].idDuenio)
                {
                    printf("Nombre del propietario: %s, Patente del vehiculo: %d, Marca: %d, Valor de su estadia: %d",propietario[j].nombre, autos[i].patente, autos[i].marca, pagoTotal);
                    break;
                }
            }
        }
    }
}
