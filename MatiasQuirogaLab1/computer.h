#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[500];
    int precio;
    int idTipo;
    char oferta[100];
}eComputer;

#endif // PELICULA_H_INCLUDED


int get_id (eComputer* ptrmov,int* this);
int get_name (eComputer* ptrmov,char* this);
int get_precio (eComputer* ptrmov,int* this);
int get_idTipo (eComputer* ptrmov,int* this);

int set_id (eComputer* ptrmov,int this);
int set_name (eComputer* ptrmov,char* this);
int set_precio (eComputer* ptrmov,int this);
int set_idTipo (eComputer* ptrmov,int this);

int sortById(void* ptrmov1 ,void* ptrmovTwo);
//int movie_filter (void* this);
//int movie_toString (ePelicula* this, char* retStr);

eComputer* eComputer_new (void);
eComputer* new_parameters (int id,char*,int precio,int idtwo);
eComputer* new_text (char* id,char* name,char* year,char* genre);

void computer_print(eComputer*);



