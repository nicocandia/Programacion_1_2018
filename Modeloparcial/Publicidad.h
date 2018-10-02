#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED
#include "pantalla.h"
typedef struct
{
    int idPantalla;
    int idPublicidad;
    int isEmpty;
    char cuitCliente[13];
    int cantidadDias;
    char tipoArchivo[101];
}Publicidad;

int dardeAlta_Publicidad(Publicidad*publicidad,int indice,int tamanio,int id);

int inicializarPublicidad(Publicidad*publicidad,int tamanio);

int buscarLugarlibre_Publicidad(Publicidad*publicidad,int tamanio);

void buscariddePantalla_enPublicidad(char *cuit,int tamanio,Publicidad*publicidades,Pantalla *pantallas);

int modificar_DatosPublicidad(char *cuit,int id,Publicidad*publicidades);

void listar_Publicidades(Publicidad*publicidades);

int dardeBaja_Publicidad(Publicidad*publicidades,char *cuit,int id);

int eliminarPantalla_ytodasSuscontrataciones(Publicidad*publicidades,int id);

void imprimirImporte_Facturacionapagar(Publicidad*publicidades,Pantalla*pantallas,char *cuit);

int verificarExisteCuitPublicidad(Publicidad*publicidad,char* cuit);

int verificarCuitoCuil(char*arreglo);

int utn_getCuiloCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);
#endif // PUBLICIDAD_H_INCLUDED
