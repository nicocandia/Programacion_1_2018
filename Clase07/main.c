#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


#define CANTIDAD_EMPLEADOS 6

int main()
{   int i=0;
    int edades[CANTIDAD_EMPLEADOS] = {50,10,30,1,98,22};

    //char nombres[15][50];


    /*int i;
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getFloat(&edades[i],"\nEdad?","\nEdad fuera de rango",1.2,10.4,2)==-1)
        {
            edades[i] = -1;
        }
    }*/
     for(i=0;i<6;i++)
    {
        printf("\n%d\n",edades[i]);
    }
    insertion(edades,6);

    printf("\n ordenado\n");

    for(i=0;i<6;i++)
    {
        printf("\n%d\n",edades[i]);
    }



    return 0;
}

