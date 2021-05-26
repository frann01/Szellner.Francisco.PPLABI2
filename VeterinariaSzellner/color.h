#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eColor;

#endif // COLOR_H_INCLUDED

int encontrarColor(eColor list[], int len, int id);
int mostrarColores(eColor colores[], int tam);
void mostraColor(eColor color);
int cargarNombreColor(int id, eColor colores[],int tam, char desc[]);
