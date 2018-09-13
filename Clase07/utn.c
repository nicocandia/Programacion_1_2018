#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int isFloat(char* pBuffer)
{
    return 1;
}

static int getString()
{
    char bufferString [4096];
    __fpurge(stdin);
    fgets(bufferString,sizeof(bufferString),stdin);
    if(bufferString[strlen(bufferString)-1]=='\n')
    {
        buffer[strlen(buffer)-1]='\0';
    }
}


static int getFloat(float* pBuffer)
{
    char bufferString [5];
    int retorno = -1;


    if(getString(bufferString) == 0 && isFloat(bufferString))
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




















