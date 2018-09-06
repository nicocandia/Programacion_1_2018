#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5


int mostrarArray(int *pArray,int limite);
int calcularMaximo(int *pArray,int limite,int *pMaximo);

int main()
{
    int edades [CANTIDAD_EMPLEADOS];
    int i;
    int maximo;

    for(i=0;i<CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],"\n edad?","\n edad fuera de rango",2,200,0)==-1)
        {
            edades[i]=-1;
        }
    }

    //mostrarArray(&edades,CANTIDAD_EMPLEADOS);
    //mostrarArray(edades +2,CANTIDAD_EMPLEADOS-2);

    calcularMaximo(edades,CANTIDAD_EMPLEADOS,&maximo);

    printf("\n maximo: %d", maximo);



    return 0;
}

int mostrarArray(int *pArray,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        printf("\n Index:[%d]-Value: %d - Add: %p ",i,pArray[i],&pArray[i]);
    }
    return 0;
}

 int calcularMaximo(int *pArray,int limite,int *pMaximo)
{
    int i;
    int Edadmaxima;

    Edadmaxima=pArray[0];
    for(i=0;i<limite;i++)
    {
        if(pArray[i]>Edadmaxima)
        {
            Edadmaxima=pArray[i];
        }
    }
    *pMaximo=Edadmaxima;
    return 0;
}
