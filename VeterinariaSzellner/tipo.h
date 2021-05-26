#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

#endif // TIPO_H_INCLUDED


void mostraTipo(eTipo tipo);
int encontrarTipo(eTipo list[], int len, int id);
int mostrarTipo(eTipo tipos[], int tam);
int cargarNombreTipo(int id, eTipo tipos[],int tam, char desc[]);
