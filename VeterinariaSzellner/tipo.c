#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** \brief Busca un tipo por su ID y devuelve su posicion en el array
 *
 * \param list[] eTipo array de tipos
 * \param len int tamaño del array
 * \param id int Id del tipo a buscar
 * \return int -1 en caso de no encontrarlo o la posicion en caso de que si
 *
 */
int encontrarTipo(eTipo list[], int len, int id)
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



/** \brief Muestra un tipo solo
 *
 * \param tipo eTipo tipo a mostrar
 * \return void
 *
 */
void mostraTipo(eTipo tipo)
{
    printf("%d     %10s    \n", tipo.id, tipo.descripcion);
}


/** \brief Muestra los tipos de forma encolumnada
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int tamaño del array
 * \return int 0 en caso de error 1 en caso de todoOK
 *
 */
int mostrarTipo(eTipo tipos[], int tam)
{
    int todoOk=0;
    printf("ID         Descripcion    \n");
    printf("-----------------------\n");
    for(int i=0; i<tam; i++)
    {
        mostraTipo(tipos[i]);
        todoOk=1;
    }
    return todoOk;
}

/** \brief Busca un tipo por su ID y carga su descripcion en una variable
 *
 * \param id int ID del tipo a buscar
 * \param tipos[] eTipo array de tipos
 * \param tam int tamaño del array
 * \param desc[] char variable donde se guardara la descripcion
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int cargarNombreTipo(int id, eTipo tipos[],int tam, char desc[])
{
    int todoOk =1;
    if(tipos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id==id)
            {
                strcpy(desc, tipos[i].descripcion);
                todoOk=0;
                break;
            }
        }
    }
    return todoOk;
}
