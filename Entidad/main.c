#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "Service.H"
int main()
{
    Empleado*listaEmpleados[1000];
    Service*listaService[1000];
    int qtyService=0;
    int qtyEmpleados=0;
    int i;
    char auxiliar[50];

    /*for(i=0;i<100;i++)
    {
        sprintf(auxiliar,"juan_%d",i);
        listaEmpleados[i]=empleado_newParametros(auxiliar,"perez",1.45);
        qtyEmpleados++;
    }
    for(i=0;i<qtyEmpleados;i++)
    {
        print_Empleado(listaEmpleados[i]);
    }*/

    /*for(i=0;i<100;i++)
    {
        sprintf(auxiliar,"mensaje de servicio_%d",i);
        listaService[i]=service_newParametros(auxiliar,i);
        qtyService++;
    }
    for(i=0;i<qtyService;i++)
    {
        print_Service(listaService[i]);
    }*/

    void ordenar(Empleado*listaEmpleados[],int limite)
    {
        int flagSwap;
        int i;
        Empleado* auxiliarPuntero;

        do
        {
            flagSwap=0;
            for(i=0;i<limite-1;i++)
            {
                if(empleado_compareNombre(listaEmpleados[i],listaEmpleados[i+1])>0)
                {
                    auxiliarPuntero=listaEmpleados[i];
                    listaEmpleados[i]=listaEmpleados[i+1];
                    listaEmpleados[i+1]=auxiliarPuntero;
                    flagSwap=1;
                }
            }

        }while(flagSwap);
    }


    return 0;
}
