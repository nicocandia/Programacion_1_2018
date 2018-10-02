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
    char cuitAuxiliar[13];
    int cantidadDiasauxiliar;
    char tipoArchivoauxiliar[101];


        if(indice>=0 && indice<tamanio)
        {
        if(utn_getCuiloCuit(cuitAuxiliar,13,3,"\nIngrese cuit\n","\nerror\n")==0)
        {
            if(utn_getInt(&cantidadDiasauxiliar,"\ningrese dias\n","\nnerror\n",0,999999999,3)==0)
            {

                    printf("\ntipo de archivo\n");
                    if(getString(tipoArchivoauxiliar,101)==0)
                    {
                        strncpy(publicidad[indice].tipoArchivo,tipoArchivoauxiliar,101);
                        publicidad[indice].cantidadDias=cantidadDiasauxiliar;
                        strncpy(publicidad[indice].cuitCliente,cuitAuxiliar,13);
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
void buscariddePantalla_enPublicidad(char*cuit,int tamanio,Publicidad*publicidades,Pantalla *pantallas)
{
    int i;
    int indice;

    for(i=0;i<tamanio;i++)
    {
        if(strcmp(publicidades[i].cuitCliente,cuit)==0)
        {
            indice=buscarPantallaporid(pantallas,LEN,publicidades[i].idPantalla);//Hacer una funcion que reciba un id de la pantalla e imprimi los datos de dicha pantalla
            pantalla_ImprimirPorIndice(pantallas,indice);
        }
    }

}
int modificar_DatosPublicidad(char *cuit,int id,Publicidad*publicidades)
{
    int i;
    int diasAuxiliar;
    int retorno=-1;

    for(i=0;i<LEN_PUBLICIDAD;i++)
    {
        if(publicidades[i].idPantalla==id && strcmp(publicidades[i].cuitCliente,cuit)==0)
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
        printf("\nCUIT CLIENTE:%s \nDIAS:%d \nTIPO de archivo:%s \nIDPANTALLA:%d \nIDPUBLICIDAD:%d \nISEMPTY:%d \n",publicidades[i].cuitCliente,publicidades[i].cantidadDias,publicidades[i].tipoArchivo,publicidades[i].idPantalla,publicidades[i].idPublicidad,publicidades[i].isEmpty);

        }
    }

}

int dardeBaja_Publicidad(Publicidad*publicidades,char*cuit,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<LEN_PUBLICIDAD;i++)
    {
        if(strcmp(publicidades[i].cuitCliente,cuit)==0 && publicidades[i].idPantalla==id)
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

void imprimirImporte_Facturacionapagar(Publicidad*publicidades,Pantalla*pantallas,char* cuit)
{
    int i;
    float importe;
    float precioPantalla;
    for(i=0;i<LEN_PUBLICIDAD;i++)

        {
            if(strcmp(publicidades[i].cuitCliente,cuit)==0)
                {
                    precioPantalla=devolverPrecio_Pantalla(pantallas,publicidades[i].idPantalla);
                    importe=publicidades[i].cantidadDias*precioPantalla;
                    printf("\nEl importe a pagar de la publicidad con el idPublicidad:%d es de:%.2f\n",publicidades[i].idPublicidad,importe);
                }
        }
}
int verificarExisteCuitPublicidad(Publicidad*publicidad,char*cuit)
{
    int retorno=-1;
    int i;
    for(i=0;i<LEN_PUBLICIDAD;i++)
        {
            if(strcmp(publicidad[i].cuitCliente,cuit)==0 && publicidad[i].isEmpty==FALSE)
                {
                    retorno=0;
                }
        }
    return retorno;
}

int verificarCuitoCuil(char*arreglo)
{
    int retorno;
    int i=0;
    int contadorGuion=0;
    char auxiliar=arreglo[i];
    while(auxiliar!='\0')
        {
            if(!((auxiliar>='0' && auxiliar<='9')|| auxiliar=='-'))
                {
                    retorno=-1;
                    break;
                }
                 if(auxiliar=='-')
                    {
                        contadorGuion++;
                    }
                i++;
                auxiliar=arreglo[i];
            }
    if(contadorGuion==2 && arreglo[0]>='0' && arreglo[1]>=0 && arreglo[2]=='-' && arreglo[12]>=0 && arreglo[11]=='-')
        {
            retorno=0;
        }
    return retorno;
}

int utn_getCuiloCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError)
{
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && verificarCuitoCuil(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}
