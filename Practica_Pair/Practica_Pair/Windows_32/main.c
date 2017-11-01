#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{

    char seguir='s';
    int opcion=0;
    ArrayList* lista;
    FILE* f;
    Employee* auxEmpleado;
    int todoOk;

    lista= al_newArrayList();
    if(lista == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }

    f = fopen("data.csv","r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }


    while(seguir=='s')
    {
        printf("\tMENU\n\n1. Parse del archivo data.csv\n2. Listar Empleados\n3. Ordenar por nombre\n4. Agregar un elemento\n5. Elimina un elemento\n6. Listar Empleados (Desde/Hasta)\n\nELEGIR OPCION(1/6)\n");

        scanf("%d", &opcion);
    }

    switch(opcion)
    {
    case 1:
        todoOk = parserEmployee(f, lista);

        if(todoOk)
            {
                printf("Error al parsear archivo\n\n");
            }

        else
            {
            printf("Archivo cargado con exito\n\n");
            }
        system("pause");
        break;

    case 2:

    printf("Lista de empleados\n\n");
    printf("id  Nombre   Apellido\n\n");

    for(int i=0; i< lista->len(lista); i++)
    {
        auxEmpleado = (Employee*)lista->get(lista, i);
        employee_print(auxEmpleado);
    }
        system("pause");
        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;

    case 6:

        break;

    default:
        printf("\nSe ingreso una opcion incorrecta, reingrese (1/6)\n\n");
        system("pause");
        break;
    }
    return 0;
}
