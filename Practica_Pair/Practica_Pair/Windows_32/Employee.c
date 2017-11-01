#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

void opcionDos(ArrayList* pArrayList, Employee* pEmployee)
{

}

int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    if(pEmployeeA!=NULL && pEmployeeB!=NULL)
    {

    }
    return 0;
}

void employee_print(Employee* this)
{
    if(this != NULL)
    {
        printf("%d %s %s \n", this->id, this->name, this->lastName);
    }
}

Employee* employee_new(void)
{
    Employee* returnAux;
    returnAux = (Employee*)malloc(sizeof(Employee));
    if(returnAux !=NULL)
    {
        returnAux->id = 0;
        strcpy(returnAux->name, "");
        strcpy(returnAux->lastName, "");
        returnAux->isEmpty = 1;
    }
    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;
}

int employee_getId(Employee* this)
{

    return 0;

}
