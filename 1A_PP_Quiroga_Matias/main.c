#include <stdio.h>
#include <stdlib.h>
#include "funcionesPrimerParcial.h"
#define TAMDUENIO 20
#define TAMAUTOMOVIL 20

int main()
{
    eDuenio arrayDuenio[TAMDUENIO];
    eAutomovil arrayAutomovil[TAMAUTOMOVIL];

    int  salir = 1;
    int arrayRecaudacionMarca[]= {0,0,0,0};
    int efectivo;
    int recaudacion=0;
    int flagMenu=0;

    inicializarEstadosDuenio(arrayDuenio,TAMDUENIO);
    inicializarEstadosAutomovil(arrayAutomovil,TAMAUTOMOVIL);

    hardcodeaAutomovil(arrayAutomovil,TAMAUTOMOVIL);
    hardcodeaDuenio(arrayDuenio,TAMDUENIO);

    do
    {
        switch(menu())
        {

        case 1:
            flagMenu=1;
            altaDuenio(arrayDuenio,TAMDUENIO);
            break;

        case 2:
            if(flagMenu==1)
            {
                modificarDuenio(arrayDuenio,TAMDUENIO);
            }
            else
            {
                 printf("\nPrimero ingresar cliente al sistema.\n\n");
                 system("pause");
            }
            break;

        case 3:
            if(flagMenu==1)
            {
                altaAutomovil(arrayAutomovil,arrayDuenio,TAMAUTOMOVIL,TAMDUENIO);
            }
            else
            {
                 printf("\nPrimero ingresar cliente al sistema.\n\n");
                 system("pause");
            }
            break;

        case 4:
            if(flagMenu==1)
            {
                efectivo=egresoVehiculo(arrayAutomovil,arrayDuenio,arrayRecaudacionMarca,TAMAUTOMOVIL,TAMDUENIO);
                recaudacion=recaudacion+efectivo;
            }
            else
            {
                 printf("\nPrimero ingresar cliente al sistema.\n\n");
                 system("pause");
            }

            break;

        case 5:
            if(flagMenu==1)
            {
                mostrarAutomovilesYnombreDuenios(arrayAutomovil,arrayDuenio,TAMAUTOMOVIL,TAMDUENIO);
            }
           else
            {
                 printf("\nPrimero ingresar cliente al sistema.\n\n");
                 system("pause");
            }
            break;

        case 6:
            if(flagMenu==1)
            {
                mostrarPropietariosAudi(arrayAutomovil,arrayDuenio,TAMAUTOMOVIL,TAMDUENIO);
            }
           else
            {
                 printf("\nPrimero ingresar cliente al sistema.\n\n");
                 system("pause");
            }
            break;

        case 7:
            if(flagMenu==1)
            {
                mostrarRecaudacionMarca(arrayRecaudacionMarca);
            }
          else
            {
                 printf("\nPrimero ingresar cliente al sistema.\n\n");
                 system("pause");
            }
            break;

        case 8:
            if(flagMenu==1)
            {
                mostrarRecaudacionTotal(recaudacion);
            }
            else
            {
                 printf("\nPrimero ingresar cliente al sistema.\n\n");
                 system("pause");
            }
            break;

        case 9:
            salir=0;
            break;

        default:
            printf("\nSe ingreso una opcion incorrecta, reingrese\n\n");
            system("pause");
        }
    }
    while(salir==1);

    return 0;
}
