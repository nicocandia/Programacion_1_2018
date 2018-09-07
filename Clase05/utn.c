#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


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

        if(  aux<48 || aux>58 )
        {
            retorno=-1;
            break;
        }
        i++;
        aux=pArray[i];
    }

    return retorno;
}


