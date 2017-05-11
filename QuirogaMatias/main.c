#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANT 20

int main()
{
    char seguir= 's';
    int opcion= 0;

    EPersona propietario [CANT];
    Evehiculo autos [CANT];

    int flagIngreso= 0 ;
    int flagIngresoVehiculo= 0;

    int flagPropietario= 0;
    int flagVehiculo= 0;

    int personaLibre;
    int estacionamientoLibre;

    int resultadoBusqueda;
    int auxCreditCard;

    int contadorPrecio[4];


    while(seguir=='s')
    {
        printf("\n1- Alta de duenio\n2- Modificacion de duenio\n3- Ingreso del automovil\n4- Egreso del automovil\n5-Informar\n6-Salir\n");
        printf("\nIntroduzca opcion (1, 2, 3, 4, 5, 6)\n\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(flagPropietario == 0)
            {
                comenzarEstados(propietario, CANT);
                inicializarContador(contadorPrecio,CANT);
                flagPropietario= 1;
            }

            personaLibre = obtenerEspacioLibre(propietario,CANT);
            flagIngreso = 1;

            if(personaLibre == -1)
            {
                printf("\nDisculpa, ya no quedan lugares disponibles para registrarse\n");
                break;
            }

            cargarUsuario(propietario,CANT,personaLibre);
            break;

        case 2:
            if(flagIngreso == 1)
            {
                printf("\nIngrese su numero de tarjeta de credito a modificar: \n\n");
                scanf("%d", &auxCreditCard);

                resultadoBusqueda= buscarPrimerOcurrencia (propietario, CANT, auxCreditCard);

                if(resultadoBusqueda == -1)
                {
                    printf("\n\nel numero ingresado no existe\n");
                    break;
                }
            }

            else
            {
                printf("Primero debe ingresar un propietario!");
            }
            break;
        case 3:
            if(flagIngreso == 1)
                {
                    if(flagVehiculo == 0)
                    {
                        comenzarEstadosVehiculos(autos, CANT);
                        flagVehiculo= 1;
                    }

                    estacionamientoLibre = obtenerEspacioLibreVehiculos(autos,CANT);
                    flagIngresoVehiculo = 1;
                    if(estacionamientoLibre == -1)
                    {
                        printf("\nDisculpa, ya no quedan lugares disponibles para estacionar\n");
                        break;
                    }

                    cargarVehiculo(autos,CANT,estacionamientoLibre);
                }
            else
                {
                    printf("Primero debe ingresar un propietario!");
                }
            break;

        case 4:
            if(flagIngresoVehiculo == 1)
                {
                   egresoVehiculo(contadorPrecio, propietario, autos, CANT);
                }
            else
                {
                   printf("Primero debe ingresar un vehiculo!");
                }
            break;

        case 5:
            break;

        case 6:
            seguir = 'n';
            break;
        }

    }

    return 0;
}
