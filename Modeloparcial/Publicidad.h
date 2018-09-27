#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

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


#endif // PUBLICIDAD_H_INCLUDED
