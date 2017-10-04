typedef struct
{
    int idDuenio;
    char nombreapellido[50];
    char direccion[30];
    int numeroTarjetaCredito;
    int estadoDuenio;
}
eDuenio;

typedef struct
{
    char patente[15];
    int idCliente;
    int marca;
    int hsEntrada;
    int estadoAutomovil;
}
eAutomovil;

int menu();

void inicializarEstadosDuenio(eDuenio[],int);

void inicializarEstadosAutomovil(eAutomovil[],int);

int buscarIndiceLibreDuenio(eDuenio[],int);

int buscarIndiceLibreAutomovil(eAutomovil[], int);

int buscarId(eDuenio[],int,int);

void altaDuenio(eDuenio[],int);

void altaAutomovil(eAutomovil[], eDuenio[], int, int);

void hardcodeaDuenio(eDuenio[],int);

void hardcodeaAutomovil(eAutomovil[],int);

void mostrarAutomovilesPorHoraYpatente(eAutomovil[], eDuenio[], int, int);

void mostrarAutomovilPorHoraYpatente(eAutomovil, eDuenio[], int);

