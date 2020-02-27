#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "computer.h"
#include "LinkedList.h"

int get_id (eComputer* ptrmov,int* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrmov->id;
            ret = 0;
        }
    }
    return ret;
}

int get_name (eComputer* ptrmov,char* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrmov->descripcion);
            ret = 0;
        }
    }
    return ret;
}

int get_precio (eComputer* ptrmov,int* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrmov->precio;
            ret = 0;
        }
    }
    return ret;
}
int get_idTipo (eComputer* ptrmov,int* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            *this= ptrmov->idTipo;
            ret = 0;
        }
    }
    return ret;
}
int set_id (eComputer* ptrmov,int this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this>0)
        {
            ptrmov->id = this;
            ret = 0;
        }
    }
    return ret;
}
int set_name (eComputer* ptrmov,char* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrmov->descripcion,this);
            ret = 0;
        }
    }
    return ret;
}
int set_year (eComputer* ptrmov,int this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this>0)
        {
            ptrmov->precio = this;
            ret = 0;
        }
    }
    return ret;
}
int set_genre (eComputer* ptrmov,int this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this>0)
        {
            ptrmov->idTipo = this;
            ret = 0;
        }
    }
    return ret;
}

int sortById(void* ptrmov1 ,void* ptrmovTwo)
{
    if (ptrmov1!=NULL&&ptrmovTwo!=NULL)
    {
        ptrmov1 = (eComputer*)ptrmov1;
        ptrmovTwo = (eComputer*)ptrmovTwo;
        int idone  , idtwo;
        get_id(ptrmov1, &idone);
        get_id(ptrmovTwo, &idtwo);
        if(idone>idtwo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
//int movie_filter (void* this);
//int movie_toString (ePelicula* this, char* retStr);

eComputer* eComputer_new (void)
{
    eComputer* ret = NULL;
    ret = (eComputer*)malloc(sizeof(eComputer));
    return ret;
}

eComputer* new_parameters (int id,char* descripcion,int precio,int idTipo)
{
    eComputer* ret = NULL;

    if (id>0)
    {
        if (descripcion!=NULL)
        {
            if (precio>=0)
            {
                if (idTipo > 0)
                {
                    ret = eComputer_new();
                    set_id(ret,id);
                    set_name(ret,descripcion);
                    set_year(ret,precio);
                    set_genre(ret,idTipo);
                }
            }
        }
    }
    return ret;
}

eComputer* new_text (char* id,char* descripcion,char* precio,char* idTipo)
{
    eComputer* ret = NULL;
    if (id!=NULL&&descripcion!=NULL&&precio!=NULL&&idTipo!=NULL)
    {
        int inid = atoi(id);
        int inprecio = atoi(precio);
        int inIdTipo = atoi(idTipo);
        ret = new_parameters(inid,descripcion,inprecio,inIdTipo);
    }
    return ret;
}

void computer_print(eComputer* this)
{
    if (this!=NULL)
    {
        int id , precio , idTipo ;
        char descripcion [500];
        char temp2 [200];
        char temp3 [100];
        get_id(this,&id);
        get_name(this,descripcion);
        get_precio(this,&precio);
        get_idTipo(this,&idTipo);
        strcpy(temp3,this->oferta);


        if(idTipo == 1)
        {
            strcpy(temp2,"DESKTOP");
        }
        else if(idTipo == 2)
        {
            strcpy(temp2,"LAPTOP");
        }
        printf("| %d | %s | %d | %s | %s |\n",id,descripcion,precio,temp2, temp3);
    }
}



