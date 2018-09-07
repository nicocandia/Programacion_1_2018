#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1
#define false 0
#define true 1


static int getInt(int* pResultado);
static int esNumero(char *pArray);


int utn_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max)
{
    int retorno = -1;
    int auxiliarEdad;

    for(;reintentos > 0;reintentos--)
    {
        printf(msg);
        if(getInt(&auxiliarEdad) == 0)
        {
            if(auxiliarEdad >= min && auxiliarEdad < max)
            {
                *pEdad = auxiliarEdad;
                retorno = 0;
                break;
            }
            else
            {
                printf(msgErr);
            }
        }
        else
        {
            printf(msgErr);
            __fpurge(stdin);
        }
    }
    return retorno;
}






static int getInt(int* pResultado)
{   /*
    int aux;
    int ret=-1;
    if(scanf("%d",pResultado) == 1){
        *pResultado=aux;
        ret=0;
        }
    return ret;
    */
    char cadena[64];
    int retorno;
    scanf("%s",cadena);

    // validar
    if(esNumero(cadena)==0)
    {
        int auxiliar=atoi(cadena);
        *pResultado=auxiliar;
        retorno =0;
    }
    printf("%s",cadena);

    return retorno;;

}

static int esNumero(char *pArray)
{
    int retorno=0;
    char aux;
    int i=0;
    aux=pArray[i];
    while(aux!=0)
    {
        printf("\nchar: %d\n",aux);

        if( aux<48 || aux>58 )
        {
            retorno=-1;
            break;
        }
        i++;
        aux=pArray[i];
    }

    return retorno;
}

int mostrarArray(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);

    }
    return 0;
}

int calcularMaximoArray(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limite > 0)
    {

        for(i=0;i<limite;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int initArray(int* pArray, int limite, int valor)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}

void ordenarArreglo(int *pArray,int limite,int flagMayorMenor)
{
    int flagnoTerminedeOrdenar=1;
    int aux;

    while(flagnoTerminedeOrdenar==1)
    {
        flagnoTerminedeOrdenar=0;
        for(i=0;i<limite-1;i++)
        {
            if((flagMayorMenor==1 && pArray[i]>pArray[i+1]) || (flagMayorMenor==0 && pArray[i]<pArray[i+1]))
            {
                aux=pArray[i];
                pArray[i]=pArray[i+1];
                pArray[i+1]=aux;
                flagnoTerminedeOrdenar=1;
            }
        }
    }
}


