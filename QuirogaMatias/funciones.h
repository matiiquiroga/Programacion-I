#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[25] ;
    char apellido[25] ;
    int idDuenio;
    char direccion[25] ;
    int creditCard ;
    int estado;

}EPersona;

typedef struct
{
    char patente[10] ;
    int marca;
    int idDuenio;
    int horarioEntrada;
    int estado;
    int horas;

}Evehiculo;

/** \brief inicia a todos los estados de las personas en 0
 *
 * \param personas[] estructura a inicializar
 * \param tam tamaño del array de personas a inicializar
 *
 */
void comenzarEstados(EPersona personas[], int tam);
void comenzarEstadosVehiculos(Evehiculo autos[], int tam);
void inicializarContador(int contador[],int tam);
/**
 * \brief Obtiene el primer indice libre del array.

 * @param personas[] el array se pasa como parametro.
 * @param tam  tamaño de el array
 * @return el primer indice disponible o -1 si no hay lugares libres
 */
int obtenerEspacioLibre(EPersona personas[], int tam);
int obtenerEspacioLibreVehiculos(Evehiculo autos[], int tam);

/** \brief carga una estructura con todos sus datos
 *
 * \param personas[] estructura de personas a cargar
 * \param tam  tamaño del array de personas
 * \param posicion  posicion libre para guardar los datos de la persona en la estructura
 *
 */
void cargarUsuario(EPersona personas[], int tam, int posicion);
void cargarVehiculo(Evehiculo autos[], int tam, int posicion);

/**
 * \brief Busca la primer ocurrencia haciendo un match

 * \param personas[] Es el array en el cual buscar
 * \param tam Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1)
 *
 */
int buscarPrimerOcurrencia(EPersona personas[],int tam,int valor);

/**
 * \brief registra el egreso de un automovil
 * @param Array contador
 * @param Array dueno
 * @param Array auto
 * @param Tamaño del array
 */
void egresoVehiculo(int [], EPersona[], Evehiculo[], int tam);





#endif // FUNCIONES_H_INCLUDED
