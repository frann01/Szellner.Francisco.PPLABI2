#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "informes.h"
#include "color.h"
#include "servicio.h"
#include "mascota.h"
#include "trabajo.h"
#include "validacion.h"

#define TAM 1000
#define TAMT 100
#define TAMTIP 5
#define TAMS 3
#define TAMC 5
int main()
{
    int respuesta;
    char salir;
    int IdMascotas=3000;
    int trabajoId=6000;
    eMascota mascotas[TAM];
    eTrabajo trabajos[TAMT];
    eTipo tipos[TAMTIP]= {{1000, "Ave"}, {1001, "Perro"},{1002, "Gato"},{1003, "Roedor"},{1004, "Pez"}};
    eServicio servicios[TAMS]= {{2000, "Corte", 250}, {2001, "Desparacitado", 300}, {2002, "Castrado", 400}};
    eColor colores[TAMC]= {{5000, "Negro"}, {5001, "Blanco"},{5002, "Gris"},{5003, "Rojo"},{5004, "Azul"}};
    inicializarMascotas(mascotas,TAM);
    inicializarTrabajo(trabajos,TAMT);
    harcodearMascotas(mascotas, TAM, 10, &IdMascotas);
    harcodearTrabajos(trabajos,TAMT,7,&trabajoId);

    do
    {
        respuesta=menu();
        switch(respuesta)
        {
        case 1:

            system("cls");
            altaMascota(mascotas, TAM, &IdMascotas, tipos, TAMTIP, colores, TAMC);
            break;

        case 2:
            if(listaVacia(mascotas, TAM)==-1)
            {
                printf("No hay ninguna mascota ingresado\n");
                printf("Primero ingrese una mascota\n");
            }
            else
            {
                modificarMascota(mascotas,TAM, tipos, TAMTIP, colores, TAMC);
            }

            break;

        case 3:
            if(listaVacia(mascotas, TAM)==-1)
            {
                printf("No hay ninguna mascota ingresada\n");
                printf("Primero ingrese una mascota\n");
            }
            else
            {
                bajaMascota(mascotas, TAM, tipos, TAMTIP, colores, TAMC);
            }

            break;

        case 4:
            listMascotas(mascotas, TAM, colores, TAMC, tipos, TAMT);
            break;

        case 5:
            mostrarTipo(tipos, TAMTIP);
            break;

        case 6:
            mostrarColores(colores, TAMC);
            break;

        case 7:
            mostrarServicios(servicios, TAMS);
            break;

        case 8:
            altaTrabajo(trabajos, TAMT, mascotas,TAM, servicios, TAMS, &trabajoId, colores,TAMC, tipos,TAMTIP);
            break;

        case 9:
            mostrarTrabajos(trabajos, TAMT, mascotas, TAM, servicios, TAMS);
            break;

        case 10:
            system("cls");
            printf(" ***Informes*** \n");
            printf("----------------\n");
            char volver='n';
            do
            {
                switch(menuInformes())
                {
                case 1:
                    mascotasPorColorSeleccionado(colores, TAMC, mascotas, TAM, tipos, TAMTIP);
                    break;

                case 2:
                    mascotasPorTipoSeleccionado(colores, TAMC, mascotas, TAM, tipos, TAMTIP);
                    break;

                case 3:
                    mascotasMenorEdad(mascotas, TAM, colores, TAMC, tipos, TAMTIP);
                    break;

                case 4:
                    mascotasPorTipo(mascotas, TAM, colores, TAMC, tipos, TAMTIP);
                    break;

                case 5:
                    mascotasPorColorYTipo(colores, TAMC, mascotas, TAM, tipos, TAMTIP);
                    break;

                case 6:
                    coloresMayorCantidad(mascotas, TAM, colores, TAMC, tipos, TAMTIP);
                    break;

                case 7:
                    trabajosDeMascotaSeleccionada(mascotas, TAM, tipos,TAMTIP, colores,TAMC, trabajos, TAMT, servicios, TAMS);
                    break;

                case 8:
                    totalTrabajoMascota(mascotas, TAM, tipos,TAMTIP, colores,TAMC, trabajos, TAMT, servicios, TAMS);
                    break;

                case 9:
                    mascotasPorServicio(mascotas, TAM, trabajos, TAMT, servicios, TAMS);
                    break;

                case 10:
                    listraServiciosFecha(mascotas, TAM, servicios, TAMS, trabajos, TAMT);
                    break;

                case 11:
                    printf("Seguro desea volver?\n");
                    fflush(stdin);
                    volver = getchar();
                    while(validarSN(volver)== -1)
                    {
                        printf("Por favor ingrese s/n\n");
                        fflush(stdin);
                        volver = getchar();
                    }
                    break;

                default:
                    printf("Opcion incorrecta!\n");
                }
                system("pause");
                fflush(stdin);
                system("cls");
            }
            while(volver!='s');
            break;

        case 11:
            printf("Seguro desea salir? s/n\n");
            fflush(stdin);
            salir = getchar();
            while(validarSN(salir)== -1)
            {
                printf("Por favor ingrese s/n\n");
                fflush(stdin);
                salir = getchar();
            }
            break;

        default:
            printf("Opcion incorrecta!\n");
        }
        system("pause");
        fflush(stdin);
        system("cls");

    }
    while(salir != 's');
    return 0;
}
