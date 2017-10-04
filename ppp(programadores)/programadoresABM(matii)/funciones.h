typedef struct
{
    char idCategoria;
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
    int estado;
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


void inicializarCategorias(eCategorias[]);

int menu();

void inicializarVector(eProgramador[],int);

void inicializarVectorProgramadoresProyectos(eProgramadoresYproyectos[],int);

int buscarEspacioLibre(eProgramador[], int);

int buscarProyectoLibre(eProgramadoresYproyectos[], int);

int buscarCoincidencia(eProgramador[],int,int);

void altaProgramador(eProgramador[], int);

void modificaProgramador(eProgramador[],int);

void bajaProgramador(eProgramador[],int);

void mostrarProgramador(eProgramador, eCategorias[], int);

void mostrarProgramadores(eProgramador[],int);

void ordenaProgramadores(eProgramador[], int);
void altaProyectoProgramador(eProgramadoresYproyectos[],eProgramador[],int,int);
void inicializaProgramadores(eProgramador[]);
void inicializaProyectos(eProyectos[]);




