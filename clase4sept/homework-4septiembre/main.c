#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    int vectorLegajos[]= {128, 356, 198, 215, 320};
    int vectorNotaUno[]= {2, 2, 2, 7, 10};
    int vectorNotaDos[]= {7, 2, 8, 6, 9};
    float vectorPromedios[5];
    int i,j;
    int aux;
    float fAux;

    calcularPromedios(vectorNotaUno, vectorNotaDos, vectorPromedios, 5);
    mostrarAlumnos(vectorLegajos, vectorNotaUno, vectorNotaDos, vectorPromedios,5);
    ordenarVectores(vectorLegajos,vectorNotaUno,vectorNotaDos,vectorPromedios,5);
    // tratando de ordenar sin funciones:

    for(i=0; i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(vectorLegajos[i]<vectorLegajos[j])
            {
                aux=vectorLegajos[j];
                vectorLegajos[j]=vectorLegajos[i];
                vectorLegajos[i]=aux;

                aux=vectorNotaUno[j];
                vectorNotaUno[j]=vectorNotaUno[i];
                vectorNotaUno[i]=aux;

                aux=vectorNotaDos[j];
                vectorNotaDos[j]=vectorNotaDos[i];
                vectorNotaDos[i]=aux;

                fAux=vectorPromedios[j];
                vectorPromedios[j]=vectorPromedios[i];
                vectorPromedios[i]=fAux;
            }
        }
    }
    printf(" Legajos - Nota 1 - Nota 2 - Promedio \n");
    for(j=0; j<5; j++)
    {
        printf("  %4d    %4d     %4d      %4.2f \n", vectorLegajos[j], vectorNotaUno[j], vectorNotaDos[j], vectorPromedios[j]);

    }

    return 0;
}
