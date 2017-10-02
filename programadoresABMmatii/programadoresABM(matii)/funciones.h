typedef struct
{
    char idCategoria;                  //a = Senior b = SemiSenior c = Junior
    char descripcion[25];
}
eCategorias;

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

typedef struct
{
    int id;
    char nombre[20];                  //a = Senior b = SemiSenior c = Junior
    char categoria;
    int estado;
}
eProgramador;

int menu();

void mostrarProgramador(eProgramador);

void mostrarProgramadores(eProgramador[],int);

int buscarEspacioLibre(eProgramador[], int);

void inicializarVector(eProgramador[],int);

int buscarCoincidencia(eProgramador[],int,int);

void altaProgramador(eProgramador[], eProgramadoresYproyectos[], int, int);

void bajaProgramador(eProgramador[],int);

void modificaProgramador(eProgramador[],int);

void ordenaProgramadores(eProgramador[], int);

void inicializaProgramadores(eProgramador[]);

void inicializaProyectos(eProyectos[]);

//recien puliendo altaProgramador, verificar ingresos de id programador y proyectos en array programadoresYproyectos, tmb verificar compatibilidad de las funciones
