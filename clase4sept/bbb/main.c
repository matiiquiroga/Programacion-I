#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int, int[], int);

int main()
{
     int leg[]={128, 356, 198, 215, 320};
     int indice;
     int num;

     printf("Ingrese un numero: ");
     scanf("%d", &num);

     indice = buscarNumero(num, leg, 5);

     if(indice == -1){
        printf("\nEl numero %d no se encuentra en el array\n\n", num);
     }
     else{
        printf("\nEl numero %d se encuentra en el indice %d del array\n\n", num, indice);
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
