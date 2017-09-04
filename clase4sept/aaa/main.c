#include <stdio.h>
#include <stdlib.h>

int main()
{
    int leg[]={128, 356, 198, 215, 320};
    int n1[]={2, 2, 2, 7, 10};
    int n2[]={7, 2, 8, 6, 9};
    float promedios[5];

    for(int i=0; i<5; i++){
        promedios[i]= (float) (n1[i] + n2[i]) / 2;
    }

    printf("\n Legajo Nota1  Nota2 Promedio\n");
    printf("\n ----------------------------\n\n");

    for(int i=0; i<5; i++){

        printf("  %4d  %04d  %4d     %4.2f \n", leg[i], n1[i], n2[i], promedios[i]);
    }

    printf("\n ----------------------------\n\n");

    return 0;
}
