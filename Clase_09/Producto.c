#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include <string.h>
#define false 0
#define true 1
#define DATO_INVALIDO -1


void inicializarEstado(Producto*arreglo,int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        arreglo[i].estado=-1;
    }
}

static int getString(char* pBuffer, int limite);

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

void mostrarArray(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);
    }
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

int verificarArregloAlfanumerica(char *pArreglo)
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

void insertion(int data[],int len)
{
    int i,j;
    int temp;
    for(i=1;i<len;i++)
    {
        temp=data[i];
        j=i-1;
        while(j>=0 && temp<data[j])
        {
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=temp;
    }
}

int dardeAlta(Producto*producto,int indice,int tamanio)
{

    int dadodeAlta=-1;
    char nombreAuxiliar[32];
    char descripcionAuxiliar[128];
    float precioAuxiliar;

        if(indice>=0 && indice<tamanio)
        {
        printf("\ningrese nombre del producto\n");
        if(getString(nombreAuxiliar,32)==0)
        {
            printf("\ningrese descripcion del producto\n");
            if(getString(descripcionAuxiliar,128)==0)
            {
                    if(utn_getFloat(&precioAuxiliar,"\ningrese precio del producto\n","\nerror,ingrese precio\n",0,1000,3)==0)
                {
                    strncpy(producto[indice].nombre,nombreAuxiliar,32);
                    strncpy(producto[indice].descripcion,descripcionAuxiliar,128);
                    producto[indice].precio=precioAuxiliar;
                    producto[indice].ID=generarID();
                    producto[indice].estado=0;
                    dadodeAlta=0;
                }


        }
        }
}
return dadodeAlta;
}

void producto_Imprimir(Producto*producto,int indice,int tamanio)
{
    if(indice>=0 && indice<tamanio)
    {
    printf("\n NOMBRE:%s \n DESCRIPCION:%s \n PRECIO:%.2f\n ID: %d \nESTADO: %d",producto[indice].nombre,producto[indice].descripcion,producto[indice].precio,producto[indice].ID,producto[indice].estado);
    }
    else
    {
        printf("\nerror\n");
    }
}

int devolverIndice_Itemvacio(Producto*producto,int tamanio)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<tamanio;i++)
    {
        if(producto[i].estado==-1)
        {
            retornoIndice=i;
        }
    }
    return retornoIndice;
}
int generarID()
{
    static int contID=-1;
    return contID++;
}

void menu()
{
    printf("\n 1- cargar producto\n");
    printf("\n 2- imprimir lista de productos\n");
    printf("\n 3- modificar producto\n ");
    printf("\n opcion??? \n");
}
void modificarProducto(Producto*producto,int indice)
{
    char nombreAuxiliar[32];
    float precioAuxiliar;
    printf("\ncambiar nombre, nuevo nombre es:\n");
    if(getString(nombreAuxiliar,32)==0)
        {
            if(utn_getFloat(&precioAuxiliar,"\ningrese precio nuevo\n","\nerror,ingrese precio correcto\n",0,3000,3)==0)
                {
                    strncpy(producto[indice].nombre,nombreAuxiliar,32);
                    producto[indice].precio=precioAuxiliar;
                }
        }
}
