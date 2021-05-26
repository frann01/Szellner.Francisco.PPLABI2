#include "trabajo.h"
#include "mascota.h"
#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>

int idmascotas[20]={3000,3001,3005,3006,3001,3002,3003,3004,3005,3002};
int idServicios[20]={2000,2001,2002,2002,2001,2000,2002,2001,2001};
eFecha Fecha[10]= {{15,07,1966},
    {15,07,1966},
    {10,07,1986},
    {5,9,1999},
    {22,6,1998},
    {18,07,2001},
    {21,12,1989},
    {22,2,1990},
    {8,8,1994},
    {18,07,1996}
};

/** \brief Inicializa todos los trabajos en 0
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tam int tamaño del array
 * \return void
 *
 */
void inicializarTrabajo(eTrabajo lista[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        lista[i].isEmpty = 0;
    }
}

/** \brief busca un espacio vacio en un array de trabajos
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tama int tamaño
 * \return int
 *
 */
int buscarTrabajoLibre(eTrabajo lista[], int tama)
{
    int bandera=-1;
    for(int i = 0; i<tama; i++)
    {
        if(lista[i].isEmpty==0)
        {
            bandera=i;
            break;
        }
    }
    return bandera;
}

/** \brief pERMITE iNGRESAR UN NUEVO TRABAJOS
 *
 * \param trabajos[] eTrabajo ARRAY DE TRABAJOS
 * \param tam int tamaño
 * \param mascotas[] eMascota array de mascotas
 * \param TamMas int tamaño
 * \param servicios[] eServicio array de servicios
 * \param TamS int tamaño
 * \param trabajoId int* ID a asignar
 * \return int 0 en caso de error
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tam, eMascota mascotas[], int TamMas, eServicio servicios[], int TamS, int* trabajoId, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    eTrabajo aux;
    if(trabajoId != NULL && tam > 0 && mascotas !=NULL && TamMas>0 )
    {
        printf("***Alta trabajo***\n");
        printf("Id: %d\n", *trabajoId);
        int indice = buscarTrabajoLibre(trabajos,tam);
        if(indice!=-1)
        {
            listMascotas(mascotas, TamMas, colores, tamC,tipos,tamT);
            printf("Ingrese Id de la mascota : \n");
            fflush(stdin);
            scanf("%d", &aux.idMascota);
            while(findMascotaByID(mascotas, TamMas, aux.idMascota)==-1)
            {
                printf("Ingrese un Id valido: \n");
                fflush(stdin);
                scanf("%d", &aux.idMascota);
            }

            mostrarServicios(servicios, TamS);
            printf("Ingrese el servicio: \n");
            fflush(stdin);
            scanf("%d",&aux.idServicio);
            while(aux.idServicio<2000 || aux.idServicio>2002)
            {
                printf("Ingrese un servicio valido: \n");
                fflush(stdin);
                scanf("%d", &aux.idServicio);
            }

            printf("Ingrese la fecha dd/mm/aaaa: \n");
            fflush(stdin);
            while(scanf("%d/%d/%d", &aux.fecha.dia, &aux.fecha.mes,&aux.fecha.anio)!=3)
            {
                printf("Ingrese una fecha valida dd/mm/aaaa: \n");
                fflush(stdin);
            }
            aux.id = *trabajoId;
            (*trabajoId)++;

            trabajos[indice] = aux;
            trabajos[indice].isEmpty = 1;
        }
        else
        {
            printf("No hay lugar\n");
        }
    }
    return todoOk;
}

/** \brief Muestra un trabajo en particular
 *
 * \param trabajos eTrabajo trabajo a mostrar
 * \param mascotas[] eMascota array de mascotas
 * \param tamM int tamaño
 * \param servicios[] eServicio array de servicios
 * \param TamS int tamaño
 * \return int 1 en caso de error
 *
 */
int mostrarTrabajo(eTrabajo trabajos, eMascota mascotas[], int tamM,eServicio servicios[], int TamS)
{
    int todoOk=1;
    if(mascotas!= NULL && tamM>0 && servicios!=NULL && TamS>0)
    {
        char descMascota[20];
        char descServicio[20];
        if(cargarNombreMascota(trabajos.idMascota, mascotas, tamM, descMascota)==0 &&
        cargarDescServicio(trabajos.idServicio, servicios, TamS, descServicio) == 0)
        {
            printf("%d %10s  %15s        %02d/%02d/%d\n\n", trabajos.id, descMascota, descServicio,  trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio);
            todoOk=0;
        }

    }
    return todoOk;
}

/** \brief Muestra todos los trabajos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param mascotas[] eMascota array de mascotas
 * \param tamM int tamaño
 * \param servicios[] eServicio array de servicios
 * \param TamS int tamaño
 * \return int
 *
 */
int mostrarTrabajos(eTrabajo lista[], int tama, eMascota mascotas[], int TamM,eServicio servicios[], int TamS)
{
    int banderaNinguno=0;
    printf("  Id    Mascotas         Sevicio          Fecha         \n");
    printf("------------------------------------------------\n");

    for(int i = 0; i<tama; i++)
    {
        if(lista[i].isEmpty==1)
        {
            mostrarTrabajo(lista[i],mascotas, TamM, servicios, TamS);
            banderaNinguno=1;
        }
    }
    if(banderaNinguno==0)
    {
        printf("\n     No hay ningun trabajo!\n");
    }

    printf("\n");
    return 0;
}

/** \brief Harcodea trabajos
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tam int tamaño del array
 * \param cant int cantidad a hardcodear
 * \param pLegajo int* direccion al Id para asignarles
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int harcodearTrabajos(eTrabajo lista[], int tam, int cant,int* pLegajo)
{
    int todoOk=0;
    int cantidad=0;
    if(lista != NULL && tam > 0 && cant > 0 && pLegajo !=NULL )
    {
        for(int i = 0; i<cant; i++)
        {
            lista[i].id = *pLegajo;
            (*pLegajo)++;
            lista[i].idMascota = idmascotas[i];
            lista[i].idServicio = idServicios[i];
            lista[i].fecha = Fecha[i];
            lista[i].isEmpty=1;
            cantidad++;
        }
    }
    else
    {
        todoOk=1;
    }
    return todoOk;
}
