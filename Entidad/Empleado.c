#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidNombre(char *nombre);
static int isValidAltura(float altura);
static int isValidApellido(char* apellido);

Empleado*empleado_new(void)
{

    return (Empleado*) malloc(sizeof(Empleado));
}

void empleado_delete(Empleado*this)
{
    free(this);
}

int empleado_setNombre(Empleado*this,char*nombre)
{
    int retorno=-1;
    if(this!=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int empleado_getNombre(Empleado*this,char*nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

static int isValidNombre(char *nombre)
{
    return 1;
}

int empleado_setAltura(Empleado*this,float altura)
{
    int retorno=-1;
    if(this!=NULL && isValidAltura(altura))
    {
        this->altura=altura;
        retorno=0;
    }
    return retorno;
}

int empleado_getAltura(Empleado*this,float*altura)
{
    int retorno=-1;
    if(this!=NULL && altura!=NULL)
    {
        *altura=this->altura;
        retorno=0;
    }
    return retorno;
}

int empleado_setApellido(Empleado*this,char*apellido)
{
    int retorno=-1;
    if(this!=NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int empleado_getApellido(Empleado*this,char*apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

static int isValidAltura(float altura)
{
    return 1;
}

static int isValidApellido(char* apellido)
{
    return 1;
}

int empleado_compareNombre(Empleado* thisA,Empleado*thisB)
{
    return strcmp(thisA->nombre,thisB->nombre);

}

void print_Empleado(Empleado*this)
{
    if(this!=NULL)
    {
        printf("\n%s -- %s -- %f -- %d\n ",this->nombre,this->apellido,this->altura,this->idEmpleado);
    }
}

Empleado* empleado_newParametros(char* nombre,char* apellido,float altura)
{
    //Empleado*this=NULL;
    Empleado*pEmpleado=NULL;
    pEmpleado=empleado_new();

    if(pEmpleado==NULL ||
        empleado_setNombre(pEmpleado,nombre)||
        empleado_setApellido(pEmpleado,apellido)||
        empleado_setAltura(pEmpleado,altura))
    {
        empleado_delete(pEmpleado);
        pEmpleado=NULL;
    }

    return pEmpleado;
}
