#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char idCategoria;
    char descripcion[25];
}
eCategoria;

typedef struct
{
    int  idProgramador;
    char nombre;
}
eProgramador;

typedef struct
{
    int idProyecto;
    char descripcion[20];
}
eProyectos;

typedef struct
{
    int idProgramadores;
    int idProyectos;
    int horasTrabajadas;
}
eProgramadoresYproyectos;

int main()
{
    eProgramador listaProgramadores[3]={1,"mati",2,"ari",3,"jose"};
    eCategoria listaCategorias[3]=['a',"Senior",'b',"SemiSenior",'c',"junior"];
    eProyectos listaProyectos[3]={10,"ssGestion",11,"afip",12,"arba"};
    eProgramadoresYproyectos listaProgramadoresYproyectos[5]={1,11,10,2,12,10,1,12,10,2,11,10,3,10,11};


    int i;
    int auxIdProg;
    int auxCantidadHoras=0;

    printf("\nIngrese numero de id del programador a mostrar sueldo: ");
    scanf("%d",&auxIdProg);

    for(i=0;i<3;i++)
    {
        if(listaProgramadores[i].idProgramador==auxIdProg)
        {
            for(i=0;i<5;i++)
            {
                if(listaProgramadoresYproyectos[i].idProgramadores==auxIdProg)
                    {
                        auxCantidadHoras=auxCantidadHoras+listaProgramadoresYproyectos[i].horasTrabajadas;
                    }
            }
            for(i=0;i<3;i++)
            {
                if(id=id)
                    for(prograyproy)
                    if(arrayprogr[].id==arrayprogyproy[i].id)

            }



        }else{printf("\nProgramador no encontrado.");}
    }

    /*
            mostrar:
            1)por cada programador cada proyecto
            2)por cada proyecto cada programador
            3)por cada programador el salario que debe cobrar
            4)cual es el proyecto que tiene mas programadores

    */
}
