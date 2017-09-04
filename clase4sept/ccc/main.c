#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int, int[], int);

int main()
{
    int leg[]={128, 356, 198, 215, 320};
    int n1[]={2, 2, 2, 7, 10};
    int n2[]={7, 2, 8, 6, 9};
    float promedios[5];
     int indice;
     int num;

    for(int i=0; i<5; i++){
        promedios[i]= (float) (n1[i] + n2[i]) / 2;
    }

    printf("\n Legajo Nota1  Nota2 Promedio\n");
    printf("\n ----------------------------\n\n");

    for(int i=0; i<5; i++){

        printf("  %4d  %04d  %4d     %4.2f \n", leg[i], n1[i], n2[i], promedios[i]);
    }

    printf("\n ----------------------------\n\n");

    printf("Ingrese un numero: ");
    scanf("%d", &num);

     indice = buscarNumero(num, leg, 5);;

     if(indice == -1){
        printf("\nEl numero %d no se encuentra en el array\n\n", num);
     }
     else{
        printf("\n***Datos del alumno***\n\n");
        printf("Legajo: %d  Nota 1: %d  Nota 2: %d  Promedio: %.2f\n\n", leg[indice], n1[indice], n2[indice], promedios[indice]);

     }

    return 0;
}

int buscarNumero(int num, int vec[], int tam){

    int indice = -1;

    for(int i=0; i < tam; i++){
        if( vec[i] == num){
            indice = i;
            break;
        }
    }

    return indice;
}

