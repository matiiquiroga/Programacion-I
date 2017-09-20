#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
int menu();
int main()
{
    eProgramador equipo[50];
    int salir = 1;
    inicializarVariables(equipo,50);

    do{
        switch(menu()){

    case 1:
        system("cls");
        alta(equipo,50);

        break;

    case 2:
        system("cls");
        modificacion(equipo,50);
        getch();

        break;
    case 3:
        system("cls");
        baja(equipo,50);
        getch();

        break;

    case 4:
        system("cls");
        mostrarProgramadores(equipo,50);
        getch();
        break;



    case 5:
      salir = 0;



        break;

        }

    }while(salir);
    return 0;
}


    int menu(){
        int opcion;
        system("cls");
        printf("\n***Programadores***\n\n\n");
        printf("1- Alta Programador\n");
        printf("2- Modificacion Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Listado Programadores\n");
        printf("5- Salir\n");
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        return opcion;

    }



