#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    float precio;

} eServicio;

#endif // SERVICIO_H_INCLUDED



int menu();
int mostrarServicios(eServicio servicios[], int tam);
void mostrarServicio(eServicio servicio);
int cargarDescServicio(int id, eServicio servicios[],int tam, char desc[]);
int buscarServicio(eServicio servicios[], int tam, int id);
