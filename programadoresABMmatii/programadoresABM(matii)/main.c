#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define TAM 50
int main()
{
    eProgramador equipo[TAM];
    eProgramadoresYproyectos proyectosYequipo[150];

    int salir = 1;

    inicializarVector(equipo,TAM);
    inicializaProgramadores(equipo);
    inicializaProyectos(proyectosYequipo);

    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            printf("Opcion1\n\n");
            altaProgramador(equipo,proyectosYequipo,TAM,150);
            getch();
            break;

        case 2:
            system("cls");
            printf("Opcion2\n\n");
            modificaProgramador(equipo,TAM);
            getch();
            break;

        case 3:
            system("cls");
            printf("Opcion3\n\n");
            bajaProgramador(equipo,TAM);
            getch();
            break;

        case 4:
            system("cls");
            printf("Opcion4\n\n");
            ordenaProgramadores(equipo,TAM);
            mostrarProgramadores(equipo,TAM);
            getch();
            break;

          case 5:

            break;

        case 6:
            salir = 0;
            break;
        }

    }
    while(salir);

    return 0;
}

/*
1.Cargar Categorias
2.Cargar Programadores
3.Mostrar
a)Todos las categorias
b)todos los programadaores(ocultar sueldo->no calculado)
c)""      ""    ""   y la descripcion de la categoria y el sueldo
d)Todos los programadores de categoria Semi Senior
e)Para cada categoria, todos los programadores
f)El monto total de sueldos a pagar, en concepto de programadores Junior.
g)la/s categoria/s con menos programadores
*/
