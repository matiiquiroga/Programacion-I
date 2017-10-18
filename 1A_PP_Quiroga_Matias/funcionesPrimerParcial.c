#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesPrimerParcial.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int menu()
{
    int opcion;

    system("cls");
    printf("1- Alta Cliente\n");
    printf("2- Modificacion Cliente\n");
    printf("3- Ingreso Automovil\n");
    printf("4- Egreso Automovil\n\n");
    printf("5- Informar listado de autos con dueneos ordenados por hs ingreso y patente\n");
    printf("6- Informar todos los propietarios de marca audi\n");
    printf("7- informar la recaudacion por cada marca del automovil\n");
    printf("8- informar la recaudacion total\n\n");
    printf("9- salir");

    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEstadosDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    int i;

    for(i=0; i<tamDuenio; i++)
    {
        listaDuenio[i].estadoDuenio=0;
    }
}

void inicializarEstadosAutomovil(eAutomovil listaAutomovil[],int tamAutomovil)
{
    int i;

    for(i=0; i<tamAutomovil; i++)
    {
        listaAutomovil[i].estadoAutomovil=0;
    }
}

int buscarIndiceLibreDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    int indice=-1;
    int i;

    for(i=0; i<tamDuenio; i++)
    {
        if(listaDuenio[i].estadoDuenio==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarIndiceLibreAutomovil(eAutomovil listaAutomovil[], int tamAutomovil)
{
    int indice=-1;
    int i;

    for(i=0; i<tamAutomovil; i++)
    {
        if(listaAutomovil[i].estadoAutomovil==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarId(eDuenio listaDuenio[], int tamDuenio, int coincidencia)
{
    int indice= -1;
    int i;

    for(i=0; i<tamDuenio; i++)
    {
        if(listaDuenio[i].idDuenio==coincidencia && listaDuenio[i].estadoDuenio==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarPatente(eAutomovil listaAutomovil[], int tamAutomovil, char coincidencia[])
{
    int indice= -1;
    int i;

    for(i=0; i<tamAutomovil; i++)
    {
        if(strcmp(listaAutomovil[i].patente,coincidencia)==0 && listaAutomovil[i].estadoAutomovil==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    eDuenio nuevoDuenio;
    int nuevoId;
    int lugar;
    int coincidencia;

    lugar=buscarIndiceLibreDuenio(listaDuenio,tamDuenio);

    if(lugar==-1)
    {
        printf("el estacionamiento no tiene capacidad para mas clientes, esta lleno.");
    }
    else
    {
        printf("\ningrese id: ");
        scanf("%d", &nuevoId);

        coincidencia = buscarId(listaDuenio,tamDuenio,nuevoId);

        if(coincidencia!= -1)
        {
            printf("\nEl id coincide con un cliente ya ingresado: \n");
            mostrarDuenio(listaDuenio[coincidencia]);
            system("pause");
        }
        else
        {
            nuevoDuenio.idDuenio= nuevoId;

            printf("ingrese su nombre y apellido: ");
            fflush(stdin);
            gets(nuevoDuenio.nombreapellido);

            printf("ingrese su direccion: ");
            fflush(stdin);
            gets(nuevoDuenio.direccion);

            printf("ingrese su num de tarjeta de credito: ");
            scanf("%d", &nuevoDuenio.numeroTarjetaCredito);

            nuevoDuenio.estadoDuenio=1;

            printf("\n\nCliente agregado con exito\n\n");
            system("pause");
        }
        listaDuenio[lugar]=nuevoDuenio;
    }
}

void altaAutomovil(eAutomovil listaAutomovil[], eDuenio listaDuenio[], int tamAutomovil, int tamDuenio)
{
    eAutomovil nuevoIngreso;
    int auxId;
    int auxMarca;
    int lugar;
    int coincidencia;

    lugar=buscarIndiceLibreAutomovil(listaAutomovil,tamAutomovil);

    if(lugar==-1)
    {
        printf("\nno hay mas lugar en el estacionamiento\n\n");
        system("pause");
    }
    else
    {
        printf("\ningrese id del cliente a ingresar automovil: ");
        scanf("%d", &auxId);

        coincidencia = buscarId(listaDuenio,tamDuenio,auxId);

        if(coincidencia == -1)
        {
            printf("\nNo se encontro el id del cliente ingresado \n");
            system("pause");
        }
        else
        {
            mostrarDuenio(listaDuenio[coincidencia]);

            nuevoIngreso.idCliente=auxId;

            printf("\nIngrese patente del automovil: ");
            fflush(stdin);
            gets(nuevoIngreso.patente);

            printf("\ningrese marca del automovil: \n1)ALPHA ROMEO\n2)FERRARI\n3)AUDI\n4)OTROS\n\n");
            scanf("%d", &auxMarca);

            while(auxMarca<1 || auxMarca>4)
            {
                printf("error, reingrese marca valida: ");
                scanf("%d", &auxMarca);
            }
            nuevoIngreso.marca= auxMarca;

            printf("\ningrese su horario de entrada (formato 24hs): ");
            scanf("%f", &nuevoIngreso.hsEntrada);
            while(nuevoIngreso.hsEntrada<0 || nuevoIngreso.hsEntrada>23)
            {
                printf("Ingresa una hora correcta por favor, en formato de 24 hs: ");
                scanf("%f", &nuevoIngreso.hsEntrada);
            }

            nuevoIngreso.estadoAutomovil=1;

            printf("\n\nAutomovil Ingresado con exito\n\n");
            system("pause");
        }
        listaAutomovil[lugar]=nuevoIngreso;
    }
}

void hardcodeaDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    int id[5]= {11,12,24,25,32};
    char nombreYapellido[5][50]= {"matias Quiroga","abul Rodriguez","pepe Santos","luis fonsi","lucas rojas"};
    char direccion[5][30]= {"mitre","brasil","corrientes","saavedra","granaderos"};
    int numTarjetaCredito[5]= {123465,654987,798654,426987,987986};
    int i;

    for(i=0; i<5; i++)
    {
        listaDuenio[i].idDuenio=id[i];
        strcpy(listaDuenio[i].nombreapellido,nombreYapellido[i]);
        strcpy(listaDuenio[i].direccion,direccion[i]);
        listaDuenio[i].numeroTarjetaCredito=numTarjetaCredito[i];
        listaDuenio[i].estadoDuenio=1;
    }
}

void hardcodeaAutomovil(eAutomovil listaAutomovil[], int tamAutomovil)
{
    char patente[5][15]= {"abc 123","def 456","ghi 789","jkl 001", "mno 010"};
    int marca[5]= {1,2,3,2,1};
    int horasIngreso[5]= {13,16,17,19,12};
    int idCliente[5]= {11,12,24,25,32};
    int i;

    for(i=0; i<5; i++)
    {
        strcpy(listaAutomovil[i].patente,patente[i]);
        listaAutomovil[i].marca=marca[i];
        listaAutomovil[i].hsEntrada=horasIngreso[i];
        listaAutomovil[i].idCliente=idCliente[i];
        listaAutomovil[i].estadoAutomovil=1;
    }
}

void mostrarAutomovil(eAutomovil automovil)
{
    printf("\nPatente del automovil: %s\nHorario de entrada: %.2f\nMarca del automovil: %d\n",automovil.patente, automovil.hsEntrada, automovil.marca);
}

void mostrarDuenio(eDuenio duenio)
{
    printf("\nId del cliente: %d\nNombre y Apellido: %s\nDireccion: %s\nNum tarjeta de credito: %d\n\n", duenio.idDuenio, duenio.nombreapellido, duenio.direccion, duenio.numeroTarjetaCredito);
}

void mostrarAutomovilesYnombreDuenios(eAutomovil listaAutomovil[], eDuenio listaDuenio[], int tamAutomovil, int tamDuenio)
{
    int i,j;

    ordenarAutomovilesPorHoraYpatente(listaAutomovil,tamAutomovil);

    for(i=0; i<tamAutomovil; i++)
    {
        if(listaAutomovil[i].estadoAutomovil!=0)
        {
            mostrarAutomovil(listaAutomovil[i]);
            for(j=0; j<tamDuenio; j++)
            {
                if(listaAutomovil[i].idCliente==listaDuenio[j].idDuenio)
                {
                    printf("Duenio del automovil:%s\n\n",listaDuenio[j].nombreapellido);
                }
            }
        }
    }
    system("pause");
}

void ordenarAutomovilesPorHoraYpatente(eAutomovil listaAutomovil[], int tamAutomovil)
{
    int i, j;
    eAutomovil auxAutomovil;

    for(i=0; i<tamAutomovil-1; i++)
    {
        for(j=i+1; j<tamAutomovil; j++)
        {
            if(listaAutomovil[i].estadoAutomovil==1 && listaAutomovil[j].estadoAutomovil==1 && listaAutomovil[i].hsEntrada > listaAutomovil[j].hsEntrada)
            {
                auxAutomovil=listaAutomovil[i];
                listaAutomovil[i]=listaAutomovil[j];
                listaAutomovil[j]=auxAutomovil;
            }
            else if(listaAutomovil[i].hsEntrada == listaAutomovil[j].hsEntrada)
            {
                if(stricmp(listaAutomovil[i].patente,listaAutomovil[j].patente)>0)
                {
                    auxAutomovil=listaAutomovil[i];
                    listaAutomovil[i]=listaAutomovil[j];
                    listaAutomovil[j]=auxAutomovil;
                }
            }
        }
    }
}

void modificarDuenio(eDuenio listaDuenio[], int tamDuenio)
{
    int auxId;
    int indice;
    char confirma;

    printf("\nIngrese ID a modificar: ");
    scanf("%d",&auxId);

    indice=buscarId(listaDuenio,tamDuenio,auxId);

    if(indice!=-1)
    {
        mostrarDuenio(listaDuenio[indice]);

        printf("\nmodificar el numero de Tarjeta? (s/n) ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            printf("\nIngrese nuevo numero de tarjeta: ");
            scanf("%d",&listaDuenio[indice].numeroTarjetaCredito);
            printf("\nTarjeta modificada con exito!\n");
            system("pause");
        }
        else
        {
            printf("\naccion cancelada.\n");
            system("pause");
        }
    }
    else
    {
        printf("\nID de cliente no encontrado.\n");
        system("pause");
    }
}

int egresoVehiculo(eAutomovil listaAutomovil[], eDuenio listaDuenio[], int recaudacionPorMarca[], int tamAutomovil, int tamDuenio)
{
    int auxId;
    char auxPatente[15];

    int indiceId;
    int indicePatente;

    int horarioSalida=0;
    int auxHsTotal=0;
    int valorEstadia=0;

    char motivo[20];

    printf("\nIngrese el ID del Cliente que se retira: ");
    scanf("%d",&auxId);

    indiceId= buscarId(listaDuenio, tamDuenio, auxId);

    if(indiceId!= -1)
    {
        printf("\nIngrese Patente: ");
        fflush(stdin);
        gets(auxPatente);

        indicePatente= buscarPatente(listaAutomovil, tamAutomovil, auxPatente);

        if(indicePatente!= -1 && listaDuenio[indiceId].idDuenio == listaAutomovil[indicePatente].idCliente)
        {
            printf("\nIngrese su horario de salida: ");
            scanf("%d",&horarioSalida);

            if( (horarioSalida>0) && (horarioSalida<=24) && (horarioSalida>listaAutomovil[indicePatente].hsEntrada) )
            {
                auxHsTotal= horarioSalida - listaAutomovil[indicePatente].hsEntrada;

                if(listaAutomovil[indicePatente].marca==ALPHA_ROMEO)
                {
                    valorEstadia= auxHsTotal*150;
                    recaudacionPorMarca[0]= valorEstadia;
                    strcpy(motivo,"ALPHA ROMEO");
                }
                if(listaAutomovil[indicePatente].marca==FERRARI)
                {
                    valorEstadia= auxHsTotal*175;
                    recaudacionPorMarca[1]= valorEstadia;
                    strcpy(motivo,"FERRARI");
                }
                if(listaAutomovil[indicePatente].marca==AUDI)
                {
                    valorEstadia= auxHsTotal*200;
                    recaudacionPorMarca[2]= valorEstadia;
                    strcpy(motivo,"AUDI");
                }
                if(listaAutomovil[indicePatente].marca==OTRO)
                {
                    valorEstadia=auxHsTotal*250;
                    recaudacionPorMarca[3]=valorEstadia;
                    strcpy(motivo,"OTRO");
                }

                printf("\nNombre: %s\nPatente: %s\nMarca: %s\nValor de estadia por: $%d\n\n",listaDuenio[indiceId].nombreapellido, listaAutomovil[indicePatente].patente, motivo,valorEstadia);
                system("pause");

                listaAutomovil[indicePatente].estadoAutomovil=0;
            }
            else
            {
                printf("\nHorario no valido!\n\n");
                  system("pause");
            }
        }
        else
        {
            printf("\nLa patente no coincide con el id!!\n\n");
            system("pause");
        }
    }
    else
    {
        printf("\nNo se encontro el id registrado.\n\n");
        system("pause");
    }

    return valorEstadia;
}

void mostrarPropietariosAudi(eAutomovil listaAutomovil[], eDuenio listaDuenio[], int tamAutomovil, int tamDuenio)
{
    int i;
    int auxId;
    int indiceDuenio;

    printf("\nClientes con marca AUDI: \n\n");

    for(i=0;i<tamAutomovil;i++)
    {
        if(listaAutomovil[i].marca==3 && listaAutomovil[i].estadoAutomovil!=0)
        {
              auxId=listaAutomovil[i].idCliente;
              indiceDuenio=buscarId(listaDuenio,tamDuenio,auxId);
              printf("%s\n", listaDuenio[indiceDuenio].nombreapellido);
        }
    }
    printf("\n");
    system("pause");
}

void mostrarRecaudacionMarca(int listaNumeros[])
{
    printf("\nRecaudacion total por marca:\n\nAlpha Romeo: $%d\nFerrari: $%d\nAudi: $%d\nOtro: $%d\n\n", listaNumeros[0],listaNumeros[1],listaNumeros[2],listaNumeros[3]);
    system("pause");
}

void mostrarRecaudacionTotal(int valor)
{
    printf("\nRecaudacion total del estacionamiento: $%d\n\n", valor);
    system("pause");
}
