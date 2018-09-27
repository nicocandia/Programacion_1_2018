#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Publicidad.h"
#include "pantalla.h"
#define TRUE 1
#define FALSE 0

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
int buscariddePantalla_enPublicidad(int cuit,int tamanio,Publicidad*publicidad)
{
    int i;
    int retorno=-1;

    for(i=0;i<tamanio;i++)
    {
        if(publicidad[i].cuitCliente==cuit)
        {
            //Hacer una funcion que reciba un id de la pantalla e imprimi los datos de dicha pantalla
        }
    }
}

