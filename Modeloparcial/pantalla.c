#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#define TRUE 1
#define FALSE 0
#define LEN_PANTALLAS 100
#define LEN_PUBLICIDAD 1000
static int isLetras(char*pBuffer);
int getString(char* pBuffer, int limite)
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
        if(utn_getLetras(nombreAuxiliar,50,3,"\ningrese nombre\n","\nerror\n")==0)
        {
            if(utn_getFloat(&precioAuxiliar,"\ningrese precio\n","error",0,1000000,3)==0)
            {
            if(utn_getInt(&tipoAuxiliar,"\ningrese 1 para LCD 0 para LED\n","\n error\n",0,1,3)==0)
            {
                    printf("\ningrese direccion \n");
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

int pantalla_Imprimir(Pantalla*pantalla,int tamanio)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanio;i++)
        {
            if(pantalla[i].isEmpty==FALSE)
                {
                    printf("\nNOMBRE:%s \nDIRECCION:%s \nTIPO:%d \nID:%d \nPRECIO:%.2f \nISEMPTY:%d \n",pantalla[i].nombre,pantalla[i].direccion,pantalla[i].tipo,pantalla[i].id,pantalla[i].precio,pantalla[i].isEmpty);
                    retorno=0;
                }
        }
        return retorno;
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

int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError)
{
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && isLetras(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}
static int isLetras(char*pBuffer){
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL){
        do{
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer)){
            retorno=0;
        }
    }
    return retorno;
}

int modificarDatos_Pantalla(Pantalla*pantalla,int tamanio,int indice)
 {
     int retorno=-1;
     int opcion;
     char nombreAuxiliar[50];
     char direccionAuxiliar[50];
     float precioAuxiliar;
     int tipoAuxiliar;

     if (indice>=0 && indice<tamanio)
        {
            if(utn_getInt(&opcion,"\nIngrese:\n1 para modificar nombre\n2 para modificar direccion\n3 para modificar precio\n4 para modificar tipo\n","\Error, ingrese opcion valida\n",1,4,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            if(utn_getLetras(nombreAuxiliar,50,3,"\nIngrese nuevo nombre\n","\nError, nombre no valido")==0)
                                {
                                    strncpy(pantalla[indice].nombre,nombreAuxiliar,50);
                                    retorno=0;
                                }
                            break;

                        case 2:
                            printf("\n ingrese nueva direccion\n");
                            if(getString(direccionAuxiliar,50)==0)
                                {
                                    strncpy(pantalla[indice].direccion,direccionAuxiliar,50);
                                    retorno=0;
                                }
                            break;

                        case 3:
                            if(utn_getFloat(&precioAuxiliar,"\nIngrese nuevo precio\n","\nError salario no valido\n",0,10000000,3)==0)
                                {
                                    pantalla[indice].precio=precioAuxiliar;
                                    retorno=0;
                                }
                            break;

                        case 4:
                            if(utn_getInt(&tipoAuxiliar,"\nIngrese nuevo tipo\n","\nError sector no valido",0,1,3)==0)
                                {
                                    pantalla[indice].tipo=tipoAuxiliar;
                                    retorno=0;
                                }
                            break;

                    }
                }
        }

     return retorno;
 }

 int dardeBaja_Pantalla(Pantalla*pantalla,int id,int tamanio)
{
    int i=0;
    int retorno=-1;
    if(pantalla!=NULL && id>=0)
        {
            for (i=0;i<tamanio;i++)
                {
                    if(pantalla[i].id==id)
                        {
                            pantalla[i].isEmpty=TRUE;
                            retorno=0;
                            break;
                        }
                }
        }
        return retorno;
}

void pantalla_ImprimirPorIndice(Pantalla*pantalla,int indice)
{
    printf("\nNOMBRE:%s \nDIRECCION:%s \nTIPO:%d \nID:%d \nPRECIO:%.2f \nISEMPTY:%d \n",pantalla[indice].nombre,pantalla[indice].direccion,pantalla[indice].tipo,pantalla[indice].id,pantalla[indice].precio,pantalla[indice].isEmpty);

}

int devolverPrecio_Pantalla(Pantalla*pantallas,int id)
{
    int precio=-1;
    int i;
    for(i=0;i<LEN_PANTALLAS;i++)
        {
            if(pantallas[i].id==id)
                {
                    precio=pantallas[i].precio;
                    break;
                }
        }
        return precio;
}
