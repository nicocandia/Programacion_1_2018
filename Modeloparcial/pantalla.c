#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#define TRUE 1
#define FALSE 0

static int getString(char* pBuffer, int limite)
{
    char bufferString [4096];
    int retorno = -1;
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString) <= limite)
        {
            strncpy(pBuffer,bufferString,limite);
            retorno = 0;
        }
    }
    return retorno;
}

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos)

{
    int retorno=-1;
    int buffer;
    if( pInt != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getInt(&buffer) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pInt = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

int getInt(int* pBuffer)
{
    char bufferString [4096];
    int retorno = -1;


    if(getString(bufferString,4096) == 0 && verificarArregloSoloNumeros(bufferString)==0)
    {
        *pBuffer = atoi(bufferString);
        retorno = 0;
    }

    return retorno;
}

int dardeAlta(Pantalla*pantalla,int indice,int tamanio)
{
    int dadodeAlta=-1;
    char nombreAuxiliar[50];
    int tipoAuxiliar;
    char direccionAuxiliar[50];
    float precioAuxiliar;

        if(indice>=0 && indice<tamanio)
        {
        printf("\ningrese nombre del producto\n");
        if(getString(nombreAuxiliar,50)==0)
        {
            if(utn_getFloat(&precioAuxiliar,"\n ingrese precio\n","error",0,1000000,3)==0)
            {
            if(utn_getInt(&tipoAuxiliar,"\n ingrese 1 para LCD 0 para LED\n","\n error\n",0,1,3)==0)
            {
                    printf("\n ingrese direccion \n");
                    if(getString(direccionAuxiliar,50)==0)
                    {
                    strncpy(pantalla[indice].nombre,nombreAuxiliar,50);
                    strncpy(pantalla[indice].direccion,direccionAuxiliar,50);
                    pantalla[indice].tipo=tipoAuxiliar;
                    pantalla[indice].precio=precioAuxiliar,
                    pantalla[indice].id=generarID();
                    pantalla[indice].isEmpty=FALSE;
                    dadodeAlta=0;
                    }


        }
        }}
}
return dadodeAlta;
}

void pantalla_Imprimir(Pantalla*pantalla,int indice,int tamanio)
{
    if(indice>=0 && indice<tamanio)
    {
    printf("\n NOMBRE:%s \n DIRECCION:%s \n TIPO:%d\n ID: %d \nISEMPTY: %d",pantalla[indice].nombre,pantalla[indice].direccion,pantalla[indice].tipo,pantalla[indice].id,pantalla[indice].isEmpty);
    }

}

int buscarLugarlibre(Pantalla*pantalla,int tamanio)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<tamanio;i++)
    {
        if(pantalla[i].isEmpty==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}
int generarID()
{
    static int contID=0;

    return contID++;
}

int verificarArregloSoloNumeros(char *pArreglo)
{
    int i=0;
    int retorno=0;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if(auxiliar==' ' || (auxiliar>='a' && auxiliar<='z') || (auxiliar>='A' && auxiliar<='Z') || auxiliar=='.')
            {
                retorno=-1;
                break;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

int inicializarPantalla(Pantalla*pantalla,int tamanio)
{
    int i;
    int retorno=-1;
    if(pantalla!=NULL && tamanio>0)
    {
    for(i=0;i<tamanio;i++)
    {
        pantalla[i].isEmpty=TRUE;
        retorno=0;
    }
    }
    return retorno;
}

int buscarPantallaporid(Pantalla*pantalla,int tamanio,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanio;i++)
    {
        if(pantalla[i].isEmpty==FALSE && pantalla[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int getFloat(float* pBuffer)
{
    char bufferString [4096];
    int retorno = -1;


    if(getString(bufferString,4096) == 0 && verificarArreglosoloFlotantes(bufferString)==0)
    {
        *pBuffer = atof(bufferString);
        retorno = 0;
    }

    return retorno;
}


int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos)

{
    int retorno=-1;
    float buffer;
    if( pFloat != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getFloat(&buffer) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pFloat = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
int verificarArreglosoloFlotantes(char* pBuffer)
{
    int retorno;
    int i=0;
    char auxiliar=pBuffer[i];
    int contadorPunto=0;
    while(auxiliar!='\0')
        {
            if(auxiliar==' ' || (auxiliar>='a' && auxiliar<='z') || (auxiliar>='A' && auxiliar<='Z'))
                {
                    retorno=-1;
                    break;
                }
            if(auxiliar=='.')
                {
                    contadorPunto++;
                }
            if(contadorPunto==1)
                {
                    retorno=0;
                }
            else
                {
                    retorno=-1;
                }
                i++;
                auxiliar=pBuffer[i];
        }
    return retorno;
}

int dardeBaja(Pantalla*pantalla,int indice,int tamanio)
{
    int dadodeBaja=-1;
    char nombreAuxiliar[50];
    int tipoAuxiliar;
    char direccionAuxiliar[50];
    float precioAuxiliar;

        if(indice>=0 && indice<tamanio)
        {
        printf("\ningrese nombre del producto\n");
        if(getString(nombreAuxiliar,50)==0)
        {
            if(utn_getFloat(&precioAuxiliar,"\n ingrese precio\n","error",0,1000000,3)==0)
            {
            if(utn_getInt(&tipoAuxiliar,"\n ingrese 1 para LCD 0 para LED\n","\n error\n",0,1,3)==0)
            {
                    printf("\n ingrese direccion \n");
                    if(getString(direccionAuxiliar,50)==0)
                    {
                    strncpy(pantalla[indice].nombre,nombreAuxiliar,50);
                    strncpy(pantalla[indice].direccion,direccionAuxiliar,50);
                    pantalla[indice].tipo=tipoAuxiliar;
                    pantalla[indice].precio=precioAuxiliar,
                    dadodeBaja=0;
                    }


                }
            }
            }
        }
        return dadodeBaja;
}

