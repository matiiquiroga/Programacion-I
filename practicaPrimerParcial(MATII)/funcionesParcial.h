typedef struct
{
    int id;
    int dni;
    char nombre[25];
    char apellido[25];
    int estadoCliente;
}
eClientes;

typedef struct
{
    int equipo;
    char operador[25];
    int tiempoEstimado;
    int tiempoReal;
    int estadoAlquiler;
}
eAlquileres;

typedef struct
{
    int idCliente;
    int equipo;
    int estado;
}
eData;

int menu();

/**
 * Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \param tam, el  tamaño del array
 * \return el primer indice disponible
 */
void inicializarEstadosClientes(eClientes[],int);

void inicializarEstadosAlquiler(eAlquileres[],int);

void inicializarEstadosData(eData listaData[], int tamData);

int buscarIndiceLibreClientes(eClientes[],int);

int buscarIndiceLibreAlquiler(eAlquileres[],int);

int buscarIndiceLibreData(eData[],int);

int buscarDni(eClientes[],int,int);

int buscarId(eClientes[], int,int);

void altaCliente(eClientes[],int);

void modificarCliente(eClientes[],int);

void bajaCliente(eClientes[],int);

void nuevoAlquiler(eAlquileres[], eClientes[],eData[], int, int, int);

void finAlquiler(eAlquileres[], eClientes[], eData[], int, int, int);

int buscarEquipo(eData[], int, int);

void mostrarCliente(eClientes);

void mostrarClientes(eClientes[],int);

void hardcodearClientes(eClientes[], int);

