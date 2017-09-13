#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nombre[25];
    int legajo;
    float peso;
}ePersona;

void muestra(ePersona);
ePersona carga(ePersona);

 // -ESTRUCTURA HARDCODEADA-
   /*  ePersona personita={"matias",37,80.50};
    printf("NAME:%s\nLEGAJO:%d\nPESO:%.2f\n", personita.nombre, personita.legajo, personita.peso);*/

    // -ESTRUCTURA POR ASIGNACION-
  /*  ePersona personita;
    personita.legajo=37;
    strcpy(personita.nombre,"matias");
    personita.peso=85.50;

    printf("NAME:%s\nLEGAJO:%d\nPESO:%.2f\n", personita.nombre, personita.legajo, personita.peso);  */

int main()
{
    ePersona personita, personitaDos;
    personita=carga(personita);
    muestra(personita);
    printf("\n-----\n");
    personitaDos=personita;
    muestra(personitaDos);
    return 0;
}

void muestra(ePersona person)
{
    printf("\nNAME:%s\nLEGAJO:%d\nPESO:%.2f\n", person.nombre, person.legajo, person.peso);
}

ePersona carga(ePersona person)
{
    printf("type your name: ");
    fflush(stdin);
    gets(person.nombre);

    printf("now tell me your weight: ");
    scanf("%f", &person.peso);

    printf("insert leg: ");
    scanf("%d", &person.legajo);
    return person;

}
