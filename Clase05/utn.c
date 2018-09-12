#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1
#define false 0
#define true 1

static int esNumero(char *pArray);


int utn_getEntero(int* pEntero,int reintentos,char* msg,
                          char*msgErr,int min, int max)
{
    int retorno = -1;
    int auxiliarEntero;

    for(;reintentos > 0;reintentos--)
    {
        printf(msg);
        if(getInt(&auxiliarEntero) == 0)
        {
            if(auxiliarEntero >= min && auxiliarEntero < max)
            {
                *pEntero = auxiliarEntero;
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
            fflush(stdin);
        }
    }
    return retorno;
}

int getInt(int* pResultado)
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
    int retorno=-1;
    scanf("%s",cadena);

    // validar
    if(esNumero(cadena)==0)
    {
        int auxiliar=atoi(cadena);
        *pResultado=auxiliar;
        retorno=0;
    }
    return retorno;
}

static int esNumero(char *pArray)
{
    int retorno=0;
    char aux;
    int i=0;
    aux=pArray[i];
    while(aux!='\0')
    {
        if( aux<'0' || aux>'9' )
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

void initArray(int* pArray, int limite, int valor)
{
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
}
}

void ordenarArreglo(int *pArray,int limite,int flagMayorMenor)
{
    int flagnoTerminedeOrdenar=1;
    int aux;
    int i;

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

int verificarArregloSoloLetras(char *pArreglo)
{
    int i=0;
    int retorno=1;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if((auxiliar!=' ')&&(auxiliar<'a' || auxiliar>'z') && (auxiliar<'A' || auxiliar>'Z' ))
            {
                retorno=0;
                break;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

int verificarCadenaAlfanumerica(char *pArreglo)
{
    int i=0;
    int retorno=1;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if((auxiliar==' ')&&(auxiliar<'a' || auxiliar>'z') && (auxiliar<'A' || auxiliar>'Z' )&&(auxiliar<'0'|| auxiliar>'9'))
            {
                retorno=0;
                break;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

int verificarNumeroTelefono(char *pArreglo)
{
    int i=0;
    int retorno;
    int contarGuion=0;;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if((auxiliar==' ')&&(auxiliar<'a' || auxiliar>'z') && (auxiliar<'A' || auxiliar>'Z' )&&(auxiliar<'0'|| auxiliar>'9'))
            {
                retorno=0;
                break;
            }
        if(auxiliar=='-')
            {
                contarGuion++;
            }
        if(contarGuion==1)
            {
                retorno=1;
            }
        else
            {
                retorno=0;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

