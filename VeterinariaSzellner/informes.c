#include "informes.h"
#include "mascota.h"
#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/** \brief Presenta el menu de informes
 *
 * \return int devuelve la respuesta del usuario
 *
 */
int menuInformes()
{
    int respuesta;
    printf("***Informes*** \n\n");
    printf("1) Mascotas por color seleccionado\n");
    printf("2) Mascotas por tipo seleccionado\n");
    printf("3) Mascotas de menor edad\n");
    printf("4) Mascotas por tipo\n");
    printf("5) Contar mascotas de un color y tipo\n");
    printf("6) Colores con mayor cantidad de mascotas\n");
    printf("7) Trabajos de una mascota\n");
    printf("8) Importe de trabajos de una mascota\n");
    printf("9) Servicios por fecha y mascotas\n");
    printf("10) Servicios Por fecha\n");
    printf("11) Salir \n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &respuesta);
    fflush(stdin);
    return respuesta;
}


/** \brief Pide el id de un color y muestra las macotas de ese color
 *
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño del array
 * \return int 0 en caso de error 1 en caso de todoOK
 *
 */
int mascotasPorColorSeleccionado(eColor colores[], int tamC, eMascota mascotas[], int tam, eTipo tipos[],int tamT)
{
    int respuesta;
    int bandera=0;
    int todoOk=0;
    if(mascotas != NULL && tam > 0 && colores !=NULL && tamC>0 && tipos !=NULL && tamT>0)
    {
        mostrarColores(colores, tamC);
        printf("Que color desea ver?\n");
        fflush(stdin);
        scanf("%d", &respuesta);
        while(encontrarColor(colores, tamC, respuesta)==-1)
        {
            printf("Error, Ingrese un color valido\n");
            fflush(stdin);
            scanf("%d", &respuesta);
        }

        printf("Codigo    Nombre         Color            Tipo      Edad      \n");
        printf("---------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].idColor == respuesta && mascotas[i].isEmpty == 1)
            {
                mostraMascota(mascotas[i],colores, tamC, tipos, tamT);
                bandera=1;
                todoOk=1;
            }
        }
        if(bandera==0)
        {
            printf("No hay mascotas de este color\n");
            todoOk=1;
        }
        printf("-------------------------------------------------------- \n");
    }
    return todoOk;
}


/** \brief Pide un color y un tipo y cuenta cuantas mascotas comparten esas caracteristicas
 *
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño del array
 * \return int 0 en caso de error 1 en caso de todoOk
 *
 */
int mascotasPorColorYTipo(eColor colores[], int tamC, eMascota mascotas[], int tam, eTipo tipos[],int tamT)
{
    int respuesta;
    int respuestaTipo;
    int todoOk=0;
    int contador=0;
    if(mascotas != NULL && tam > 0 && colores !=NULL && tamC>0 && tipos !=NULL && tamT>0)
    {
        mostrarColores(colores, tamC);
        printf("Que color desea ver?\n");
        fflush(stdin);
        scanf("%d", &respuesta);
        while(encontrarColor(colores, tamC, respuesta)==-1)
        {
            printf("Error, Ingrese un color valido\n");
            fflush(stdin);
            scanf("%d", &respuesta);
        }

        mostrarTipo(tipos, tamT);
        printf("Que tipo desea ver?\n");
        fflush(stdin);
        scanf("%d", &respuestaTipo);
        while(encontrarTipo(tipos, tamT, respuestaTipo)==-1)
        {
            printf("Error, Ingrese un Tipo valido\n");
            fflush(stdin);
            scanf("%d", &respuestaTipo);
        }


        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].idColor == respuesta && mascotas[i].isEmpty == 1 && mascotas[i].idTipo == respuestaTipo)
            {
                contador++;
                todoOk=1;
            }
        }
        if(contador==0)
        {
            printf("No hay mascotas de este color y Tipo\n");
            todoOk=1;
        }
        else
        {
            printf("Hay %d mascotas de este color y Tipo\n", contador);
            todoOk=1;
        }
        printf("-------------------------------------------------------- \n");
    }
    return todoOk;
}


/** \brief Pide el Id de una mascota y muestra el total de los serviciops que se le hicieron
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param tipos[] eTipo array de tipos
 * \param tamTip int tamaño del array
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamt int tamaño del array
 * \param servicios[] eServicio array de servicios
 * \param tamS int tamaño del array
 * \return void
 *
 */
void totalTrabajoMascota(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamC,eTrabajo trabajos[], int tamt, eServicio servicios[], int tamS)
{
    int legajo;
    int bandera=0;
    float acumulador=0;
    listMascotas(lista, tam, colores, tamC,tipos, tamTip);
    printf("Ingrese el id de la mascota:");
    scanf("%d", &legajo);
    int indice = findMascotaByID(lista, tam,legajo);
    while(findMascotaByID(lista, tam,legajo)==-1)
    {
        printf("Ingrese un ID correcto\n");
        scanf("%d", &legajo);
    }

    for(int i=0; i<tamt; i++)
    {
        if(trabajos[i].idMascota==legajo)
        {
            for(int j=0; j<tamC; j++)
            {
                if(trabajos[i].idServicio==servicios[j].id)
                {
                    acumulador+=servicios[j].precio;
                    bandera=1;
                }
            }
        }
    }
    if(bandera==0)
    {
        printf("Esta mascota no registra trabajos\n");
    }
    else
    {
        printf("El total de los trabajos de %s es $%.2f\n", lista[indice].nombre, acumulador);
    }
}

/** \brief
 *
 * \param colores[] eColor
 * \param tamC int
 * \param mascotas[] eMascota
 * \param tam int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int
 *
 */
int mascotasPorTipoSeleccionado(eColor colores[], int tamC, eMascota mascotas[], int tam, eTipo tipos[],int tamT)
{
    int respuesta;
    int bandera=0;
    int todoOk=0;
    if(mascotas != NULL && tam > 0 && colores !=NULL && tamC>0 && tipos !=NULL && tamT>0)
    {
        mostrarTipo(tipos, tamT);
        printf("Que tipo desea ver?\n");
        fflush(stdin);
        scanf("%d", &respuesta);
        while(encontrarTipo(tipos, tamT, respuesta)==-1)
        {
            printf("Error, Ingrese un tipo valido\n");
            fflush(stdin);
            scanf("%d", &respuesta);
        }

        printf("Codigo    Nombre         Color            Tipo      Edad      \n");
        printf("---------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].idTipo == respuesta && mascotas[i].isEmpty == 1)
            {
                mostraMascota(mascotas[i],colores, tamC, tipos, tamT);
                bandera=1;
                todoOk=1;
            }
        }
        if(bandera==0)
        {
            printf("No hay mascotas de este tipo\n");
            todoOk=1;
        }
        printf("-------------------------------------------------------- \n");
    }
    return todoOk;
}

/** \brief Pide el Id de un tipo y muestra las mascotas de ese tipo
 *
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño del array
 * \return int 1 en caso de error 0 en caso de todoOk
 *
 */
int mascotasPorTipo(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int bandera;
    int todoOk=1;
    if(colores != NULL && tam > 0 && mascotas !=NULL && tamC>0 && tipos !=NULL && tamT>0)
    {

        for(int j=0; j<tamT; j++)
        {
            bandera=0;
            printf("%s:\n",tipos[j].descripcion);
            printf("Codigo    Nombre         Color            Tipo      Edad      \n");
            printf("-------------------------------------------------------\n");

            for(int i = 0; i<tam; i++)
            {
                if(mascotas[i].isEmpty==1 && mascotas[i].idTipo == tipos[j].id)
                {
                    mostraMascota(mascotas[i],colores, tamC, tipos, tamT);
                    todoOk=0;
                    bandera=1;
                }
            }
            if(bandera==0)
            {
                printf("\n     No hay ninguna mascota!\n");
                todoOk=0;
            }

            printf("\n");
            printf("--------------------------------------------------------\n");
        }
    }
    return todoOk;
}

int mascotasMenorEdad(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int bandera=0;
    int banderaEdades=0;
    int menorEdad;
    int todoOk=0;
    int edades[tam];
    if(colores != NULL && tam > 0 && mascotas !=NULL && tamC>0&& tipos !=NULL && tamT>0)
    {
        for(int i = 0; i<tam; i++)
        {
            if(mascotas[i].isEmpty==1)
            {
                edades[i] = mascotas[i].edad;
                todoOk=0;
                bandera=1;
            }
        }
        if(bandera==0)
        {
            printf("\n     No hay ninguna mascota!\n");
            todoOk=0;
        }
        else
        {
            for(int h = 0; h<tam; h++)
            {
                if((banderaEdades==0 || edades[h] < menorEdad) && mascotas[h].isEmpty==1)
                {
                    menorEdad = mascotas[h].edad;
                    banderaEdades=1;
                }
            }
            printf("Las mascotas con menor edad son: ");
            for(int y = 0; y<tam; y++)
            {
                if( mascotas[y].edad == menorEdad)
                {
                   printf("%s\n", mascotas[y].nombre);
                }
            }
        }
    }
    return todoOk;
}

/** \brief Muestra el color con la mayor cantidad de mascotas
 *
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño del array
 * \return int 1 en caso de error 0 en caso de todoOk
 *
 */
int coloresMayorCantidad(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int bandera=0;
    int banderaColores=0;
    int mayorCant;
    int todoOk=1;
    int coloresCant[tamC];
    if(colores != NULL && tam > 0 && mascotas !=NULL && tamC>0&& tipos !=NULL && tamT>0)
    {
        for(int j = 0; j<tamC; j++)
        {
            coloresCant[j]=0;
        }

        for(int i = 0; i<tam; i++)
        {
            if(mascotas[i].isEmpty==1)
            {
                bandera=1;
                switch(mascotas[i].idColor)
                {
                case 5000:
                    coloresCant[0]++;
                    break;

                case 5001:
                    coloresCant[1]++;
                    break;

                case 5002:
                    coloresCant[2]++;
                    break;

                case 5003:
                    coloresCant[3]++;
                    break;

                case 5004:
                    coloresCant[4]++;
                    break;
                }
            }
        }

        if(bandera==0)
        {
            printf("\n     No hay ninguna mascota!\n");
            todoOk=0;
        }
        else
        {
            for(int h = 0; h<tamC; h++)
            {
                if(banderaColores==0 || coloresCant[h] > mayorCant)
                {
                    mayorCant = coloresCant[h];
                    banderaColores=1;
                }
            }
            printf("\n Los colores con mayor cantidad son:    \n");
            for(int y = 0; y<tamC; y++)
            {
                if( coloresCant[y] == mayorCant)
                {
                    todoOk=0;
                    printf("%s\n", colores[y].descripcion);
                }
            }
        }
    }
    return todoOk;
}

/** \brief Pide el Id de una mascota y muestra los trabajos de esa mascota
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param tipos[] eTipo array de tipos
 * \param tamTip int tamaño del array
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamt int tamaño del array
 * \param servicios[] eServicio array de servicios
 * \param tamS int tamaño del array
 * \return void
 *
 */
void trabajosDeMascotaSeleccionada(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamC,eTrabajo trabajos[], int tamt, eServicio servicios[], int tamS)
{
    int legajo;
    int bandera=0;
    listMascotas(lista, tam, colores, tamC,tipos, tamTip);
    printf("Ingrese el id de la mascota:");
    scanf("%d", &legajo);
    while(findMascotaByID(lista, tam,legajo)==-1)
    {
        printf("Ingrese un ID correcto\n");
        scanf("%d", &legajo);
    }

    printf("  Id    Mascotas         Sevicio          Fecha         \n");
    printf("------------------------------------------------\n");
    for(int i=0; i<tamt; i++)
    {
        if(trabajos[i].idMascota==legajo)
        {
            mostrarTrabajo(trabajos[i], lista, tam, servicios, tamS);
            bandera=1;
        }
    }
    if(bandera==0)
    {
        printf("Esta mascota no registra trabajos\n");
    }
}

/** \brief Pide el Id de un servicio y muestra las mascota y la fecha en la que se realizo ese servicio
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaños del array
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamt int tamaños del array
 * \param servicios[] eServicio array de servicios
 * \param tamS int tamaños del array
 * \return void
 *
 */
void mascotasPorServicio(eMascota lista[], int tam, eTrabajo trabajos[], int tamt, eServicio servicios[], int tamS)
{
    int legajo;
    int bandera=0;
    mostrarServicios(servicios, tamS);
    printf("Ingrese el id del servicio:");
    scanf("%d", &legajo);
    while(buscarServicio(servicios, tamS, legajo)==-1)
    {
        printf("Ingrese un ID correcto\n");
        scanf("%d", &legajo);
    }

    printf("  Id    Mascota         Sevicio          Fecha         \n");
    printf("------------------------------------------------\n");
    for(int i=0; i<tamt; i++)
    {
        if(trabajos[i].idServicio==legajo)
        {
            mostrarTrabajo(trabajos[i], lista, tam, servicios, tamS);
            bandera=1;
        }
    }
    if(bandera==0)
    {
        printf("No hubo trabajos de este servicio\n");
    }
}

/** \brief Pide una fecha y muestra los servicos que se realizaron en ese dia
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param servicios[] eServicio array de servicios
 * \param tamS int tamaño del array
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamT int tamaños del array
 * \return int 1 en caso de error 0 en caso de todoOk
 *
 */
int listraServiciosFecha(eMascota lista[], int tam, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT)
{
    eFecha aux;
    int bandera=0;
    int todoOk=1;
    if(lista != NULL && tam > 0 && servicios !=NULL && tamS>0 && trabajos !=NULL && tamT > 0)
    {
        printf("Ingrese la fecha a consultar dd/mm/aaaa: \n");
        fflush(stdin);
        while(scanf("%d/%d/%d", &aux.dia, &aux.mes,&aux.anio)!=3)
        {
            printf("Ingrese una fecha valida dd/mm/aaaa: \n");
            fflush(stdin);
        }

        printf("  Id    Mascota         Sevicio          Fecha         \n");
        printf("------------------------------------------------\n");

        for(int i =0; i<tamT ; i++)
        {
            if(aux.dia == trabajos[i].fecha.dia && aux.mes==trabajos[i].fecha.mes && aux.anio == trabajos[i].fecha.anio && trabajos[i].isEmpty==1)
            {
                todoOk=0;
                mostrarTrabajo(trabajos[i],lista, tam, servicios, tamS);
                bandera=1;
            }
        }
        if(bandera==0)
        {
            printf("Esta fecha no tiene trabajos\n");
            todoOk=0;
        }
    }
    return todoOk;
}
