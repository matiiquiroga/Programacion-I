#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesParcial.h"

#define TAMCLIENTES 50 // TAM ESTRUCTURA CLIENTES
#define TAMALQUILERES 150 //TAM ESTRUCTURA ALQUILERES
#define TAMDATA 150

int main()
{
    eClientes arrayClientes[TAMCLIENTES];
    eAlquileres arrayAlquileres[TAMALQUILERES];
    eData arrayData[TAMDATA];

    int salir=1;

    inicializarEstadosClientes(arrayClientes,TAMCLIENTES);
    inicializarEstadosAlquiler(arrayAlquileres,TAMALQUILERES);
    inicializarEstadosData(arrayData,TAMDATA);

    do
    {
        switch(menu())
        {

        case 1:
            altaCliente(arrayClientes,TAMCLIENTES);
            break;

        case 2:
            modificarCliente(arrayClientes,TAMCLIENTES);
            break;

        case 3:
            bajaCliente(arrayClientes,TAMCLIENTES);
            break;

        case 4:
            nuevoAlquiler(arrayAlquileres,arrayClientes,arrayData, TAMALQUILERES,TAMCLIENTES,TAMDATA);
            break;

        case 5:
            finAlquiler(arrayAlquileres,arrayClientes,arrayData, TAMALQUILERES,TAMCLIENTES,TAMDATA);
            break;

        case 6:

            break;

        default:
            printf("\nSe ingreso una opcion incorrecta, reingrese\n\n");
            system("pause");
        }
    }while(salir==1);

    return 0;
}


