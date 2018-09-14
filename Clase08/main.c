#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    char nombre [70];
    int edad;
    char dni[20];
    float altura;
} Persona;

void altaPersona(Persona *persona);
void ImprimirPersona(Persona *persona);

int main()
{
    Persona persona;
   /* Persona persona;
    persona.edad=9;
    persona.altura=1.90;
    //fgets(persona.nombre,sizeof(persona.nombre),stdin); OK
    strncpy(persona.nombre,"juan",70);
    strncpy(persona.dni,"14589764",20);


    //persona.nombre="juan"; NOOOOO*/
    altaPersona(&persona);
    ImprimirPersona(&persona);
    return 0;
}

void ImprimirPersona(Persona *persona)
{
    printf("\nedad: %d\nnombre: %s\nDNI: %s \naltura: %.2f\n ",persona->edad,persona->nombre,persona->dni,persona->altura);
    // per->edad=99 SI
    // per.edad=99 NO
}

void altaPersona(Persona *persona)
{
    printf("\ningrese Nombre de la persona\n");
    fgets(persona->nombre,sizeof(persona->nombre),stdin);

    printf("\ningrese dni de la persona\n");
    fgets(persona->dni,sizeof(persona->dni),stdin);

}
