#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Publicidad.h"
#include "pantalla.h"
#define TRUE 1
#define FALSE 0
#define LEN 100
#define LEN_PUBLICIDAD 1000

int dardeAlta_Publicidad(Publicidad*publicidad,int indice,int tamanio,int id)
{
    int dadodeAlta=-1;
    int cuitAuxiliar;
    int cantidadDiasauxiliar;
    char tipoArchivoauxiliar[101];


        if(indice>=0 && indice<tamanio)
        {
        if(utn_getInt(&cuitAuxiliar,"\nIngrese cuit\n","\nerror\n",0,999999999,3)==0)
        {
            if(utn_getInt(&cantidadDiasauxiliar,"\ningrese dias\n","\nnerror\n",0,999999999,3)==0)
            {

                    printf("\ntipo de archivo\n");
                    if(getString(tipoArchivoauxiliar,101)==0)
                    {
                        strncpy(publicidad[indice].tipoArchivo,tipoArchivoauxiliar,101);
                        publicidad[indice].cantidadDias=cantidadDiasauxiliar;
                        publicidad[indice].cuitCliente=cuitAuxiliar;
                        publicidad[indice].idPantalla=id;
                        publicidad[indice].isEmpty=FALSE;
                        publicidad[indice].idPublicidad=generarID();
                        dadodeAlta=0;
                    }


        }
        }}

return dadodeAlta;
}

int inicializarPublicidad(Publicidad*publicidad,int tamanio)
{
    int i;
    int retorno=-1;
    if(publicidad!=NULL && tamanio>0)
    {
    for(i=0;i<tamanio;i++)
    {
        publicidad[i].isEmpty=TRUE;
        retorno=0;
    }
    }
    return retorno;
}

int buscarLugarlibre_Publicidad(Publicidad*publicidad,int tamanio)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<tamanio;i++)
    {
        if(publicidad[i].isEmpty==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}
void buscariddePantalla_enPublicidad(int cuit,int tamanio,Publicidad*publicidades,Pantalla *pantallas)
{
    int i;
    int indice;

    for(i=0;i<tamanio;i++)
    {
        if(publicidades[i].cuitCliente==cuit)
        {
            indice=buscarPantallaporid(pantallas,LEN,publicidades[i].idPantalla);//Hacer una funcion que reciba un id de la pantalla e imprimi los datos de dicha pantalla
            pantalla_ImprimirPorIndice(pantallas,indice);
        }
    }

}
int modificar_DatosPublicidad(int cuit,int id,Publicidad*publicidades)
{
    int i;
    int diasAuxiliar;
    int retorno=-1;

    for(i=0;i<LEN_PUBLICIDAD;i++)
    {
        if(publicidades[i].idPantalla==id && publicidades[i].cuitCliente==cuit)
        {

            if(utn_getInt(&diasAuxiliar,"\nIngrese dias a modificar\n","\nError dias no validos",0,999999999,3)==0)
            {
                publicidades[i].cantidadDias=diasAuxiliar;
                retorno=0;
                break;
            }
        }
    }
return retorno;
}

void listar_Publicidades(Publicidad*publicidades)
{
    int i;
    for(i=0;i<LEN_PUBLICIDAD;i++)
    {
        if(publicidades[i].isEmpty==FALSE)
        {
        printf("\nCUIT CLIENTE:%d \nDIAS:%d \nTIPO de archivo:%s \nIDPANTALLA:%d \nIDPUBLICIDAD:%d \nISEMPTY:%d \n",publicidades[i].cuitCliente,publicidades[i].cantidadDias,publicidades[i].tipoArchivo,publicidades[i].idPantalla,publicidades[i].idPublicidad,publicidades[i].isEmpty);

        }
    }

}

int dardeBaja_Publicidad(Publicidad*publicidades,int cuit,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<LEN_PUBLICIDAD;i++)
    {
        if(publicidades[i].cuitCliente==cuit && publicidades[i].idPantalla==id)
        {
            publicidades[i].isEmpty=TRUE;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int eliminarPantalla_ytodasSuscontrataciones(Publicidad*publicidades,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<LEN_PUBLICIDAD;i++)
    {
        if(publicidades[i].idPantalla==id)
        {
            publicidades[i].isEmpty=TRUE;
            retorno=0;
        }
    }
    return retorno;
}

