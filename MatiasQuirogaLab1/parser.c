#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "parser.h"
#include "LinkedList.h"
#include "computer.h"

FILE* openFILE (char* filename)
{
    FILE* ret = NULL;
    if (filename!=NULL)
    {
        ret = fopen(filename,"r");
    }
    return ret;
}
FILE* openFILEwrite(char* filename)
{
    FILE* ret = NULL;
    if (filename!=NULL)
    {
        ret = fopen(filename,"w");
    }
    return ret;
}
int parser_FromText(FILE* pFile , void* this)
{
    int retVal = 0;
    if (pFile!=NULL&&this!=NULL)
    {
        this = (LinkedList*)this;
        char buffer [6][128];
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while (!feof(pFile))
        {
            eComputer* newComputer;
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);// "%[^,],%[^,],%[^,],%[^\n]\n"
            newComputer = new_text(buffer[0],buffer[1],buffer[2],buffer[3]);
            if (newComputer!=NULL)
            {
                ll_add(this,newComputer);
                retVal++;
            }
        }
    }
    return retVal;
}

int parser_ListToText (FILE* pFile, void* this)
{
    int retVal = 0;
    if (pFile!=NULL&&this!=NULL)
    {
        this = (LinkedList*)this;
        char name[128] ;
        char aux[50];
        int id , precio, idTipo;
        eComputer* auxmov;
        int i;
        fprintf(pFile,"id,descripcion,precio,tipo\n");
        for (i=0;i<ll_len(this);i++)
        {
            auxmov = (eComputer*)ll_get(this,i);
            if (auxmov!=NULL)
            {
                get_id(auxmov,&id);
                get_name(auxmov,name);
                get_precio(auxmov,&precio);
                get_idTipo(auxmov,&idTipo);
                if(idTipo == 1)
                {
                    strcpy(aux,"DESKTOP");
                }
            fprintf(pFile,"%d,%s,%d,%s\n",id,name,idTipo,aux);
            }
        }
        retVal = 0;
    }
    return retVal;
}
