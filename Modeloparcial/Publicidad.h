#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED
#include "pantalla.h"
typedef struct
{
    int idPantalla;
    int idPublicidad;
    int isEmpty;
    int cuitCliente;
    int cantidadDias;
    char tipoArchivo[101];
}Publicidad;

int dardeAlta_Publicidad(Publicidad*publicidad,int indice,int tamanio,int id);

int inicializarPublicidad(Publicidad*publicidad,int tamanio);

int buscarLugarlibre_Publicidad(Publicidad*publicidad,int tamanio);

void buscariddePantalla_enPublicidad(int cuit,int tamanio,Publicidad*publicidades,Pantalla *pantallas);

int modificar_DatosPublicidad(int cuit,int id,Publicidad*publicidades);

void listar_Publicidades(Publicidad*publicidades);

int dardeBaja_Publicidad(Publicidad*publicidades,int cuit,int id);

int eliminarPantalla_ytodasSuscontrataciones(Publicidad*publicidades,int id);
#endif // PUBLICIDAD_H_INCLUDED
