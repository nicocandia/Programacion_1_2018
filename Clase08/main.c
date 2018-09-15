#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define false 0
#define true 1
#define DATO_INVALIDO -1
typedef struct
{
    char nombre [70];
    int edad;
    char dni[20];
    float altura;
} Persona;

void ImprimirPersona(Persona *persona);
void altaPersona(Persona *persona);
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
    int auxiliarEdad;
    float auxiliarAltura;
    char auxiliarDni[20];
    char auxiliarNombre[70];

    printf("\ningrese nombre de la persona\n");
    fgets(auxiliarNombre,sizeof(auxiliarNombre),stdin);
    if(verificarArregloSoloLetras(auxiliarNombre)==0)
        {
            strncpy(persona->nombre,auxiliarNombre,sizeof(auxiliarNombre));
        }

    printf("\ningrese dni de la persona\n");
    fgets(auxiliarDni,sizeof(auxiliarDni),stdin);
     if(verificarArregloSoloNumeros(auxiliarDni)==0)
        {
            strncpy(persona->dni,auxiliarDni,sizeof(auxiliarDni));
        }

    if(utn_getInt(&auxiliarEdad,"\n ingrese edad de la persona:\n","\nerror ingrese edad\n",0,110,3)==0)
        {
            persona->edad=auxiliarEdad;
        }
    if(utn_getFloat(&auxiliarAltura,"\n ingrese altura\n","\n error, ingrese altura",0,3.00,3)==0)
        {
            persona->altura=auxiliarAltura;
        }
}
