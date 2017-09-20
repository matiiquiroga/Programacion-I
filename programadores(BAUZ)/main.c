#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 50

typedef struct
{
    int id;
    char desc;
    float precio;
} categoria;

typedef struct
{
    int id;
    char nombre[20];
    char categoria;
    int proyecto;
    int estado;
    int sueldo;
    int cathstab;
} eProgramador;
int buscarProgramador(int id, eProgramador lista[],int tam);
int buscarLibre(eProgramador lista[],int tam);
void variablesCero(eProgramador lista[],int i);
//1.Cargar Categorias
//2.Cargar Programadores
//3.Mostrar
//a)Todos las categorias
//b)todos los programadaores(ocultar sueldo->no calculado)
//c)""      ""    ""   y la descripcion de la categoria y el sueldo
//d)Todos los programadores de categoria Semi Senior
//e)Para cada categoria, todos los programadores
//f)El monto total de sueldos a pagar, en concepto de programadores Junior.
//g)la/s categoria/s con menos programadores
void mostrarProgramador(eProgramador lista);
void mostrarProgramadores(eProgramador lista[],int tam);
void altaProgramador(eProgramador lista[],int tam);
void inicializarvector(eProgramador[],int);
void ordenarProgramadores(eProgramador lista[],int tam);
void modificarProgramador(eProgramador lista[],int tam);
void bajaProgramador(eProgramador lista[], int tam);
//a = Senior
//b = SemiSenior
//c = Junior
int main()
{
    eProgramador equipo[TAM];
    inicializarvector(equipo,TAM);
    int salir = 1;
    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            printf("Opcion1");
            altaProgramador(equipo,TAM);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("Opcion2");
            modificarProgramador(equipo,TAM);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("Opcion3");
            bajaProgramador(equipo,TAM);
            system("pause");
            break;
        case 4:
            system("cls");
            printf("Opcion4");
            mostrarProgramadores(equipo,50);
            system("pause");
            break;
        case 5:
            salir = 0;
            break;
        }
    }
    while(salir);
    return 0;
}
int menu()
{
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
int buscarLibre(eProgramador lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=1;
            break;
        }
    }
    return indice;
}
int buscarProgramador(int id, eProgramador lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].id==id&&lista[i].estado==1)
        {
            indice=1;
            break;
        }
    }
    return indice;
}
void altaProgramador(eProgramador lista[],int tam)
{
    eProgramador nuevoProgramador;
    int lugar;
    int id;
    int esta;
    lugar=buscarLibre(lista,tam);
    if(lugar==-1)
    {
        printf("\nNo hay lugar en el sistema.\n\n");
    }
    else
    {
        printf("\nIngrese Id: ");
        scanf("%d",&id);
        esta=buscarProgramador(id,lista,tam);
    }
    if(esta!=-1)
    {
        printf("\nEl id: %d ya se encuentra registrado en el sistema. \n\n",id);
    }
    else
    {
        nuevoProgramador.id=id;
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nuevoProgramador.nombre);
        printf("\nIngrese categoria a-Senior,b-SemiSenor,c-Junior: ");
        fflush(stdin);
        scanf("%c",&nuevoProgramador.proyecto);
        nuevoProgramador.estado=1;
        printf("\nIngrese numero de proyecto: ");
        fflush(stdin);
        scanf("%d",&nuevoProgramador.proyecto);
        lista[lugar]=nuevoProgramador;
    }
}

void mostrarProgramador(eProgramador lista)
{
    char cat[11];
    if(lista.categoria=='a')
    {
        strcpy(cat,"Senior");
    }
    else if(lista.categoria=='b')
    {
        strcpy(cat,"SemiSenior");
    }
    else
    {
        strcpy(cat,"junior");
    }
    printf("\n%d     %s     %s     %d",lista.id,lista.nombre,cat,lista.proyecto);
}

void mostrarProgramadores(eProgramador lista[],int tam)
{
    int i;
    int flag=0;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarProgramador(lista[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}
void cargarcat(categoria cat[],int tam)
{
    int id[]= {70,75,80};
    char desc[][80]= {"junior","SemiSenior","Senior"};
    float precio[]= {50,75,10};
    for(int i=0; i<tam; i++)
    {
        cat[i].id=id[i];
    }
    for(int i=0; i<tam; i++)
    {
        cat[i].desc=desc[i];
    }
    for(int i=0; i<tam; i++)
    {
        cat[i].precio=precio[i];
    }
}
void variablesCero(eProgramador lista[],int i)
{
    strcpy(lista[i].nombre,"\0");
    lista[i].categoria='\0';
    lista[i].estado=0;
    lista[i].id=0;
    lista[i].proyecto=0;
}

void inicializarvector(eProgramador lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCero(lista,i);
    }
}
void bajaProgramador(eProgramador lista[], int tam)
{
    int id;
    int indice;
    char confirma;
    printf("\nIngrese ID: ");
    scanf("%d",&id);
    indice=buscarProgramador(id,lista,tam);
    if(indice!=-1)
    {
        mostrarProgramador(lista[indice]);
        printf("\nConfirma la baja? s\n: ");
        fflush(stdin);
        confirma=getchar();
        if(confirma=='s')
        {
            lista[indice].estado=0;
            printf("\nProgramador Eliminado\n");
        }
        else
        {
            printf("\nBaja cancelada por el usuario");
            system("pause");
        }
    }
    else
    {
        printf("\nID no encontrada.\n");
    }
}
void modificarProgramador(eProgramador lista[],int tam)
{
    int id;
    int indice;
    char confirma;
    printf("\nIngrese ID a modificar: ");
    scanf("%d",&id);
    indice=buscarProgramador(id,lista,tam);
    if(indice!=-1)
    {
        mostrarProgramador(lista[indice]);
        printf("\nIngrse nueva categoria: ");
        fflush(stdin);
        lista[indice].categoria=getchar();
        printf("\nCategoria modificada con exito!\n");
    }
    else
    {
        printf("\nID no encontrada.\n");
        system("pause");
    }
}
void ordenarProgramadores(eProgramador lista[],int tam)
{
    eProgramador aux;
    for(int i=0;i<tam;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(lista[i].id>lista[j].id)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}
