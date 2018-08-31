#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[3];
    int numeroMaximo;
    int numeroMinimo;
    int i;
    for (i=0;i<3;i++)
    {   printf("ingrese numero: %d\n",i+1);
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
        else if (numeros[i]<numeroMinimo)
            {
                numeroMinimo=numeros[i];
            }
    }
        printf("el numero maximo es %d y el numero minimo es %d\n",numeroMaximo,numeroMinimo);
    for(i=0;i<3;i++)
    {
            if(numeros[i]>numeroMinimo && numeros[i]<numeroMaximo)
                {
                    printf("el numero medio es: %d\n",numeros[i]);
                    break;
                }
    }
    if(i==3)
    {
        printf("no hay numero medio\n");
    }
    return 0;
}
