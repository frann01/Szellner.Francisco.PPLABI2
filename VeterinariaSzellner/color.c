#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Busca un color por ID
 *
 * \param list[] eColor array de colores
 * \param len int tamaño del array
 * \param id int Id a buscar
 * \return int -1 en caso de error
 *
 */
int encontrarColor(eColor list[], int len, int id)
{
    int bandera=-1;
    for(int i = 0; i<len; i++)
    {
        if(list[i].id==id)
        {
            bandera=i;
            break;
        }
    }
    return bandera;
}

/** \brief Mustra los datos de un color solo
 *
 * \param color eColor color a mostrar
 * \return void
 *
 */
void mostraColor(eColor color)
{
    printf("%d     %10s    \n", color.id, color.descripcion);
}


/** \brief muestra todos los colores
 *
 * \param colores[] eColor array de colores
 * \param tam int tamañod del array
 * \return int 0 en casdo de error 1 en caso de TodoOk
 *
 */
int mostrarColores(eColor colores[], int tam)
{
    int todoOk=0;
    printf("ID         Descripcion    \n");
    printf("-----------------------\n");
    for(int i=0; i<tam; i++)
    {
        mostraColor(colores[i]);
        todoOk=1;
    }
    return todoOk;
}

/** \brief Busca un color por su ID y carga su descripcion en una variable
 *
 * \param id int ID del color a buscar
 * \param colores[] eColor array de colores
 * \param tam int tamaño del array
 * \param desc[] char variable donde se guardara la descripcion
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int cargarNombreColor(int id, eColor colores[],int tam, char desc[])
{
    int todoOk =1;
    if(colores != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(colores[i].id==id)
            {
                strcpy(desc, colores[i].descripcion);
                todoOk=0;
                break;
            }
        }
    }
    return todoOk;
}
