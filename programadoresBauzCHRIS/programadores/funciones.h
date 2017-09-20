


typedef struct{
    int id;
    char nombre[20];
    char categoria;
    int proyecto;
    int estado;
}
eProgramador;


void variablesCero(eProgramador[],int);
void inicializarVariables(eProgramador[],int);
void mostrarProgramador(eProgramador);
void mostrarProgramadores(eProgramador[],int);
int buscarLibre(eProgramador[],int);
int buscarProgramador(int,eProgramador[],int);
void alta(eProgramador[],int);
void baja(eProgramador[],int);
void modificacion(eProgramador[],int);
