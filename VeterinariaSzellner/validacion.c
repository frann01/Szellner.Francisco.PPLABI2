#include "validacion.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/** \brief valida que una valor dado sea un numero y lo guarda en una variable fuera de la funcion
 *
 * \param pResultado float* variable donde se guarda el numero
 * \param mensaje char* mensaje que pide el valor
 * \param mensajeError char* mensaje en caso de que el valor no sea un numero
 * \return void
 *
 */
void validarNum(int* pResultado, char* mensaje, char* mensajeError)
{
    int num;
    printf(mensaje);
    fflush(stdin);
    while(scanf("%d", &num)!=1)
    {
        printf(mensajeError);
        fflush(stdin);
    }
    *pResultado = num;
}

/** \brief Valida que un valor ingresado sea float y numero muestra los mensajes correspondientes
 *
 * \param pResultado float* direccion a guardar el dato
 * \param mensaje char* mansaje pidiendo el dato
 * \param mensajeError char* mensaje en caso de error
 * \return void
 *
 */
void validarFLoat(float* pResultado, char* mensaje, char* mensajeError)
{
    float num;
    printf(mensaje);
    fflush(stdin);
    while(scanf("%f", &num)!=1)
    {
        printf(mensajeError);
        fflush(stdin);
    }
    *pResultado = num;
}


/** \brief toma una cadena de caracteres y valida que todos lo sean
 *
 * \param cadena[] char cadena a validar
 * \param tam int tamaño de la cadena
 * \return int devuelve -1 si hay un valor que no sea un caracter
 *
 */
int validarString(char cadena[], int tam)
{
    int todoOk=0;

    for(int i = 0; i<tam ; i++)
    {
        cadena[i]=tolower(cadena[i]);
        if(cadena[i]<97 || cadena[i]>122)
        {
            todoOk=-1;
        }
    }
    return todoOk;
}

/** \brief valida que un caracter sea s/n
 *
 * \param simbolo charsimbolo a analizar
 * \return int devuelve 0 en caso de que lo sea
 *
 */
int validarSN(char simbolo)
{
    int todoOk=-1;
    simbolo=tolower(simbolo);
    if(simbolo=='s' || simbolo == 'n')
    {
        todoOk=0;
    }
    return todoOk;
}


/** \brief valida que un array de caracteres contenga solo numeros
 *
 * \param cadena[] char array a validar
 * \param tam int tamañp de dicho array
 * \return int devuelve -1 en caso de que haya un caracter diferente
 *
 */
int validarNumString(char cadena[], int tam)
{
    int todoOk=0;

    for(int i = 0; i<tam ; i++)
    {
        if(cadena[i] < 48 || cadena[i]>57)
        {
            todoOk=-1;
        }
    }
    return todoOk;
}
