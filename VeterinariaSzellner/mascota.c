#include "mascota.h"
#include "validacion.h"
#include "tipo.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** \brief Inicializa a las mascotas en 0
 *
 * \param eMacota lista array de mascotas
 * \param int tam tamaño
 * \return void
 *
 */

void inicializarMascotas(eMascota lista[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        lista[i].isEmpty = 0;
    }
}

/** \brief Busca un lugar vacio en un array
 *
 * \param lista[] eMascotas array de mascotas
 * \param tam int tamaño
 * \return int devielve la posicion vacio de encontrarla o -1 en caso de que no
 *
 */
int hayLugar(eMascota lista[], int tam)
{
    int bandera=-1;
    for(int i = 0; i<tam; i++)
    {
        if(lista[i].isEmpty==0)
        {
            bandera=i;
            break;
        }
    }
    return bandera;
}



/** \brief Da de alta una nueva mascota
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param pLegajo int* Id a asignar
 * \param Tipos[] eTipo array de tipos
 * \param tamTip int tamaño del array
 * \param colores[] eColor array de colores
 * \param tamC int tamaño de colores
 * \return int 0 en caso de error
 *
 */
int altaMascota(eMascota lista[], int tam, int* pLegajo, eTipo Tipos[], int tamTip, eColor colores[], int tamC)
{
    int todoOk = 0;
    eMascota aux;
    if(lista != NULL && tam > 0 && pLegajo !=NULL)
    {
        printf("***Alta Mascota***\n");
        printf("id: %d\n", *pLegajo);

        int indice = hayLugar(lista,tam);
        if(indice!=-1)
        {
            printf("Ingrese el nombre: \n");
            fflush(stdin);
            gets(aux.nombre);
            while(validarString(aux.nombre, strlen(aux.nombre))==-1 || strlen(aux.nombre)>51)
            {
                printf("Error! Ingrese un nombre valido: \n");
                fflush(stdin);
                gets(aux.nombre);
            }

            mostrarTipo(Tipos, tamTip);
            printf("Ingrese el tipo: \n");
            fflush(stdin);
            while(scanf("%d", &aux.idTipo)!=1 || encontrarTipo(Tipos, tamTip,aux.idTipo)==-1)
            {
                printf("Error! Ingrese un tipo valido: \n");
                fflush(stdin);
            }

            mostrarColores(colores, tamC);
            printf("Ingrese el color: \n");
            fflush(stdin);
            while(scanf("%d", &aux.idColor)!=1 || encontrarColor(colores, tamC, aux.idColor)==-1)
            {
                printf("Error! Ingrese un color valido: \n");
                fflush(stdin);
            }


            validarNum(&aux.edad, "Ingrese la edad\n", "Edad inavalida, ingrese un numero\n");


            aux.id = *pLegajo;
            aux.isEmpty=1;
            (*pLegajo) +=1;
            lista[indice] = aux;

            todoOk=1;
        }
        else
        {
            printf("No hay lugar\n");
        }
    }
    return todoOk;
}


/** \brief muestra una mascota sola con sus datos
 *
 * \param mascota eMascota mascota amostrar
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño del array
 * \return int devuelve 1 en caso de error o 0 en caso de todoOk
 *
 */
int mostraMascota(eMascota mascota, eColor colores[], int tamC, eTipo tipos[],int tamT)
{
    int todoOk=1;
    char descColor[10];
    char descTipo[10];
    if(colores != NULL && tamC>0 && tipos!=NULL && tamT>0)
    {
        if(cargarNombreColor(mascota.idColor, colores, tamC, descColor)==0 &&cargarNombreTipo(mascota.idTipo, tipos, tamT, descTipo)==0)
        {
            printf(" %4d %10s   %10s      %10s        %d  \n"
                   ,mascota.id
                   ,mascota.nombre
                   ,descColor
                   ,descTipo
                   ,mascota.edad);
            todoOk=0;
        }
    }
    return todoOk;
}


/** \brief Muestra todas las mascotas de forma encolumnada
 *
 * \param list[] eMascota array de mascotas a mostrar
 * \param len int tamaño del array
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño del array
 * \return int devuelve -1 en caso de error y 0 en caso de todoOk
 *
 */
int listMascotas(eMascota list[], int len, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk=-1;
    int banderaNinguno=0;
    ordenarMascotas(list, len);
    if(list != NULL && len > 0)
    {
        printf("Codigo    Nombre         Color            Tipo      Edad      \n");
        printf("-------------------------------------------------------\n");

        for(int i = 0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                mostraMascota(list[i],colores, tamC, tipos, tamT);
                todoOk=0;
                banderaNinguno=1;
            }
        }
        if(banderaNinguno==0)
        {
            printf("\n     No hay ninguna mascota!\n");
            todoOk=0;
        }

        printf("\n");
    }
    return todoOk;
}


/** \brief Busca una mascota por su ID
 *
 * \param list[] eMascota
 * \param len int tamaño del array
 * \param id int Id a buscar
 * \return int -1 en caso de error o la posicion de la mascota en el array
 *
 */
int findMascotaByID(eMascota list[], int len, int id)
{
    int bandera=-1;
    for(int i = 0; i<len; i++)
    {
        if(list[i].id==id && list[i].isEmpty==1)
        {
            bandera=i;
            break;
        }
    }
    return bandera;
}


/** \brief Pide el id de una mascota y la modifica segun lo que ingrese el usuario
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param Tipos[] eTipo array de tipos
 * \param tamTip int tamaño del array
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \return void
 *
 */
void modificarMascota(eMascota lista[], int tam, eTipo Tipos[], int tamTip, eColor colores[], int tamC)
{
    int opcioncodigo; //legajo
    int mascotaAModificar; //posicion del empleado
    int datoAModificar;
    char salir='s';
    eMascota aux;
    printf("Modificar mascota\n");
    listMascotas(lista, tam, colores,tamC, Tipos, tamTip);
    printf("Ingrese el ID de la mascota: \n");
    fflush(stdin);
    scanf("%d", &opcioncodigo);
    while(findMascotaByID(lista, tam, opcioncodigo)==-1)
    {
        printf("No hay ninguna mascota con ese ID, ingrese uno correcto: \n");
        fflush(stdin);
        scanf("%d", &opcioncodigo);
    }
    mascotaAModificar = findMascotaByID(lista, tam, opcioncodigo);
    aux = lista[mascotaAModificar];
    system("cls");


    do
    {
        printf("Que dato desea modificar? \n");
        printf("1) Tipo \n");
        printf("2) Edad\n");;
        fflush(stdin);
        scanf("%d", &datoAModificar);
        system("cls");
        while(datoAModificar>2 || datoAModificar<1)
        {
            printf("Ingrese una opcion valida! \n");
            fflush(stdin);
            scanf("%d", &datoAModificar);
            system("cls");
        }

        switch(datoAModificar)
        {
        case 1:
            printf("Cambiar Tipo \n");
            mostrarTipo(Tipos, tamTip);
            printf("Ingrese el tipo: \n");
            fflush(stdin);
            while(scanf("%d", &aux.idTipo)!=1 || encontrarTipo(Tipos, tamTip,aux.idTipo)==-1)
            {
                printf("Error! Ingrese un tipo valido: \n");
                fflush(stdin);
            }
            break;

        case 2:
            printf("Cambiar Edad \n");
            validarNum(&aux.edad, "Ingrese la edad\n", "Edad inavalida, ingrese un numero\n");
            break;

            break;


        default:
            printf("Opcion invalida!\n");
        }

        printf("Quiere cambiar otro dato?s/n\n");
        fflush(stdin);
        salir = getchar();
        while(validarSN(salir)==-1)
        {
            printf("Por favor ingrese s/n\n");
            fflush(stdin);
            salir = getchar();
        }
        system("cls");
    }
    while(salir != 'n');
    printf("Desea guardar los datos?s/n\n");
    fflush(stdin);
    scanf("%c", &salir);
    while(validarSN(salir)==-1)
        {
            printf("Por favor ingrese s/n\n");
            fflush(stdin);
            salir = getchar();
        }

    if(salir=='s')
    {
        lista[mascotaAModificar] = aux;
        printf("Cambios guardados\n");
    }
    else
    {
        printf("Cambios eliminados\n");
    }

}


/** \brief devuelve si un array de mascotas esta vacio
 *
 * \param lista[] eMasccotas array a buscar
 * \param tam int tamaño del array
 * \return int -1 en caso de estar vacio 0 en caso de que no
 *
 */
int listaVacia(eMascota lista[], int tam)
{
    int bandera=-1;
    for(int i = 0; i<tam; i++)
    {
        if(lista[i].isEmpty==1)
        {
            bandera=i;
            break;
        }
    }
    return bandera;
}



/** \brief Pregunta por el ID de una mascota y cambia el valor de su isEmpty a 0
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param Tipos[] eTipo array de tipos
 * \param tamTip int  tamaño del array
 * \param colores[] eColor array de colores
 * \param tamC int tamaño del array
 * \return intdevuelve 1 en caso de error y 0 en caso de todoOK
 *
 */
int bajaMascota(eMascota lista[], int tam, eTipo Tipos[], int tamTip, eColor colores[], int tamC)
{
    int todoOk=1;
    int opcionLegajo;
    int mascotaABaja;
    char resBaja;
    printf("Baja Mascota\n");
    listMascotas(lista, tam, colores, tamC, Tipos, tamTip);
    printf("Ingrese el ID de la mascota: \n");
    fflush(stdin);
    scanf("%d", &opcionLegajo);

    mascotaABaja = findMascotaByID(lista, tam, opcionLegajo);
    while(mascotaABaja==-1)
    {
        printf("No hay ninguna mascota con este ID %d \n", opcionLegajo);
        printf("Ingrese el ID de la mascota: \n");
        fflush(stdin);
        scanf("%d", &opcionLegajo);
    }

    printf("Seguro desea dar de baja a esta mascota? s/n \n");
    fflush(stdin);
    scanf("%c", &resBaja);
    while(validarSN(resBaja)==-1)
    {
        printf("Por favor ingrese s/n\n");
        fflush(stdin);
        resBaja = getchar();
    }

    if(resBaja=='s')
    {
        lista[mascotaABaja].isEmpty=0;
        printf("Baja exitosa\n");
    }
    else
    {
        printf("Baja cancelada\n");
    }

    return todoOk;
}

int cargarNombreMascota(int id, eMascota mascotas[],int tam, char desc[])
{
    int todoOk =1;
    if(mascotas != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].id==id)
            {
                strcpy(desc, mascotas[i].nombre);
                todoOk=0;
                break;
            }
        }
    }
    return todoOk;
}

/** \brief Ordena las mascotas por nombre y apellido
 *
 * \param lista[] eMascotas array de mascotas
 * \param tam int tamaño
 * \return int 1 em caso de error o en caso de TodoOk
 *
 */
int ordenarMascotas(eMascota lista[], int tam)
{
    int todoOk=1;
    eMascota Aux;
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i< tam-1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(lista[i].nombre, lista[j].nombre)> 0)
                {
                    Aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=Aux;
                    todoOk=0;
                }
            }
        }
    }
    return todoOk;
}


/** \brief hardcodea mascotas para facilitar el testing
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param cant int cantidad de mascotas a harcodear
 * \param pLegajo int* direccion al ID a asignar
 * \return int devuelve 0 encaso de todoOK y 1 en caso de error
 *
 */
int harcodearMascotas(eMascota lista[], int tam, int cant,int* pLegajo)
{
    int todoOk=0;
    int cantidad=0;
    if(lista != NULL && tam > 0 && cant > 0 && pLegajo !=NULL )
    {
        for(int i = 0; i<cant; i++)
        {
            lista[i].id = *pLegajo;
            (*pLegajo)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].idTipo = tipos[i];
            lista[i].idColor = colores[i];
            lista[i].edad = edades[i];
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
