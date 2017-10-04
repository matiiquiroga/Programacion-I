#include <stdio.h>
#include <stdlib.h>
#include "ppFunciones.h"
#define TAMDUENIO 20
#define TAMAUTOMOVIL 20

int main()
{
    eDuenio arrayDuenio[TAMDUENIO];
    eAutomovil arrayAutomovil[TAMAUTOMOVIL];

    int  salir = 1;

    inicializarEstadosDuenio(arrayDuenio,TAMDUENIO);
    inicializarEstadosAutomovil(arrayAutomovil,TAMAUTOMOVIL);

    do
    {
        switch(menu())
        {

        case 1:
            altaDuenio(arrayDuenio,TAMDUENIO);
            break;

        case 2:

            break;

        case 3:
            altaAutomovil(arrayAutomovil,arrayDuenio,TAMAUTOMOVIL,TAMDUENIO);
            break;

        case 4:

            break;

        case 5:
            mostrarAutomovilesPorHoraYpatente(arrayAutomovil,arrayDuenio,TAMAUTOMOVIL,TAMDUENIO);
            system("pause");
            break;
        default:
            printf("\nSe ingreso una opcion incorrecta, reingrese\n\n");
            system("pause");
        }
    }while(salir==1);

        return 0;
}
