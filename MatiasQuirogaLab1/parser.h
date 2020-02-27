#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"


#endif // PARSER_H_INCLUDED

FILE* openFILE (char* filename);
FILE* openFILEwrite(char* filename);
int parser_FromText(FILE* pFile , void* this);
int parser_ListToText (FILE* pFile, void* this);
int archivo_cargar(char* nombreArchivo, LinkedList* nombreLista);


