#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "computer.h"
#include "parser.h"

void printList(LinkedList*);
void depurarPeliculas(LinkedList* this);
LinkedList* filtrar(LinkedList* this, LinkedList*);
int filtrarComputer(eComputer* this);
int filtrarTwo(eComputer* this);
char filtro[50];

int main()
{
    int opcion;
    LinkedList* computerList = ll_newLinkedList();
    LinkedList* newComputerList = ll_newLinkedList();
    char filename[50];
    while(opcion != 0)
    {
        mostrarMenu();
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("\nIngrese nombre de archivo: ");
                fflush(stdin);
                gets(filename);

                FILE* fl = openFILE(filename);
                parser_FromText(fl,computerList);
                fclose(fl);
                printList(computerList);
                getche();
                break;
            case 2:
                ll_sort(computerList,sortById, 1);
                printf("ordenado!");
                break;
            case 3:
                printList(computerList);
                getche();
                break;
            case 4:
                ll_map(computerList, filtrarTwo);
                break;
            case 5:
                newComputerList = filtrar(computerList, newComputerList);
                printf("\nFiltrado!!\n\n");
                printList(newComputerList);
                getche();
                break;
            case 6:
                if(newComputerList->pFirstNode == NULL)
                {
                    printf("No se encuentra lista filtrada.\n\nGenerando nueva lista");
                    newComputerList = filtrar(computerList,newComputerList);
                }
                FILE* fl3 = openFILEwrite("filtrado.csv");
                parser_ListToText(fl3,newComputerList);
                fclose(fl3);
                printf("\nArchivo Generado!\n\n");
                getche();
                break;
        }
        system("cls");
    }
    return 0;
}

void printList (LinkedList* this)
{
    if (this!=NULL)
    {
        int i;
        eComputer* temp;
        for (i=0;i<ll_len(this);i++)
        {
            temp =(eComputer*)ll_get(this,i);
            computer_print(temp);
        }
    }
}

LinkedList* filtrar(LinkedList* this, LinkedList* newList)
{

    newList = ll_filter(this, filtrarComputer);
    return newList;
}

int filtrarComputer(eComputer* this)
{
    int aux=0;
    get_idTipo(this,&aux);
    if(aux == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int filtrarTwo(eComputer* this)
{
    int aux=0;
    int auxPrecio;
    get_idTipo(this,&aux);

    if(aux == 1)
    {
        get_precio(this,&auxPrecio);
        if(auxPrecio > 2000)
        {
            strcpy(this->oferta,"50% Descuento");
        }

        return 1;
    }
    else
    {
        strcpy(this->oferta, "SIN DATOS");
        return 0;
    }
}

void mostrarMenu()
{
    printf("---------------------------\n");
    printf("1- cargar archivo\n2- ordenar lista por ID\n3- mostrar lista\n4- funcion MAP\n5- filtrar por criterio\n6- generar filtrado.csv\n0- salir\n");
    printf("---------------------------\n");

}
