#include "mascota.h"
#include "trabajo.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

int menuInformes();
int mascotasPorColorSeleccionado(eColor colores[], int tamC, eMascota mascotas[], int tam, eTipo tipos[],int tamT);
int mascotasPorColorYTipo(eColor colores[], int tamC, eMascota mascotas[], int tam, eTipo tipos[],int tamT);
void totalTrabajoMascota(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamC,eTrabajo trabajos[], int tamt, eServicio servicios[], int tamS);
int mascotasPorTipoSeleccionado(eColor colores[], int tamC, eMascota mascotas[], int tam, eTipo tipos[],int tamT);
int mascotasPorTipo(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);
int mascotasMenorEdad(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);
int coloresMayorCantidad(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);
void trabajosDeMascotaSeleccionada(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamC,eTrabajo trabajos[], int tamt, eServicio servicios[], int tamS);
void mascotasPorServicio(eMascota lista[], int tam, eTrabajo trabajos[], int tamt, eServicio servicios[], int tamS);
int listraServiciosFecha(eMascota lista[], int tam, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT);
