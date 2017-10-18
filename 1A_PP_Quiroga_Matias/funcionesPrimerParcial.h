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
    float hsEntrada;
    int hsTotal;
    int estadoAutomovil;
    char motivo[25];
}
eAutomovil;

int menu();

void inicializarEstadosDuenio(eDuenio[],int);

void inicializarEstadosAutomovil(eAutomovil[],int);

int buscarIndiceLibreDuenio(eDuenio[],int);

int buscarIndiceLibreAutomovil(eAutomovil[], int);

int buscarId(eDuenio[],int,int);

int buscarPatente(eAutomovil[], int, char[]);

void altaDuenio(eDuenio[],int);

void altaAutomovil(eAutomovil[], eDuenio[], int, int);

void hardcodeaDuenio(eDuenio[],int);

void hardcodeaAutomovil(eAutomovil[],int);

void mostrarAutomovil(eAutomovil);

void mostrarDuenio(eDuenio);

void mostrarAutomovilesYnombreDuenios(eAutomovil[], eDuenio[], int, int);

void ordenarAutomovilesPorHoraYpatente(eAutomovil[], int);

void modificarDuenio(eDuenio[],int);

int egresoVehiculo(eAutomovil[], eDuenio[], int[], int, int);

void mostrarPropietariosAudi(eAutomovil[], eDuenio[], int, int);

void mostrarRecaudacionMarca(int[]);

void mostrarRecaudacionTotal(int);

