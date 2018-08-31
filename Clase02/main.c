#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[10];
    int numeroMinimo;
    int numeroMaximo;
    int i;
    float promedio;
    int acumulaNumero;
    acumulaNumero=0;
    for(i=0;i<10;i++)
    {
        printf("ingrese numero %d\n",i+1);
        scanf("%d",&numeros[i]);

        if(i==0)
        {
            numeroMaximo=numeros[i];
            numeroMinimo=numeros[i];
        }
        else if(numeros[i]>numeroMaximo)
        {
            numeroMaximo=numeros[i];
        }
        else if(numeros[i]<numeroMinimo)
        {
            numeroMinimo=numeros[i];
        }
            acumulaNumero=acumulaNumero+numeros[i];
        }
        promedio=(float)acumulaNumero/10;
        printf("el numero maximo es %d y el numero minimo es %d\n",numeroMaximo,numeroMinimo);
        printf ("el promedio es: %f",promedio);
        return 0;
}
