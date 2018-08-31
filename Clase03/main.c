#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int edad;

    if(utn_getEntero(&edad,"\ningrese edad ","\nerror ingrese en el rango indicado",3,199,0) == 0)
    {
        printf("La edad es: %d",edad);
    }

    return 0;
}



