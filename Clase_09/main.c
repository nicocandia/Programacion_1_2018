#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include <string.h>
#define CANTIDAD 200
int main()
{
    int opcion;
    int id;
    Producto productos[CANTIDAD];
    inicializarEstado(productos,CANTIDAD);
    do{
        menu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            if(dardeAlta(productos,1,CANTIDAD)==0 )
                {
                    printf("\n se cargo correctamente\n");
                }
                else
                    {printf("\n no se cargo correctamente\n");}
            break;

        case 2:
            producto_Imprimir(productos,1,CANTIDAD);
            break;

        case 3:

            if(utn_getInt(&id,"\n ingrese ID\n","\nerror\n",0,199,3)==0)
            {

            int i;
            for(i=0;i<CANTIDAD;i++)
                {
                    if(productos[i].ID==id && productos[i].estado==0)
                        {
                            modificarProducto(productos,i);
                            break;
                        }
                }}
            break;
        }
    }while(opcion!=0);
    return 0;
}
