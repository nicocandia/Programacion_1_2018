#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#define CANTIDAD 200
int main()
{
    Producto productos[CANTIDAD];
    inicializarEstado(productos,CANTIDAD);

    if(dardeAlta(productos,5,CANTIDAD)!=0)
    {
       printf("error");
    }else
    {
        producto_Imprimir(productos,-3,CANTIDAD);
    }

    return 0;
}
