#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1
#define false 0
#define true 1

int main()
{   char cadena[20];
    printf("\n ingrese cadena:\n");
    gets(cadena);

   /* int edades[CANTIDAD_EMPLEADOS];
    int i;

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"\nnumero?","\nEdad fuera de rango",0,200)==-1)
        {
            edades[i] = DATO_INVALIDO;
        }
    }
    mostrarArray(edades,CANTIDAD_EMPLEADOS);
    */
    if(verificarNumeroTelefono(cadena)==1)
        {
            printf("\n es un numero\n");
        }
    else
        {
            printf("\n no es un numero\n");
        }
    return 0;
}






