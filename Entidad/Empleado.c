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

int empleado_delete(Empleado*this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        free(this);
        retorno=0;
    }
 return retorno;
 return retorno;
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
        strcpy(nombre,this->nombre);
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

int empleado_buscarLugarVacio(Empleado*array[],int len)
{
    int i;
    int retorno=-1;

    if(array!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(array[i]==NULL)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int empleado_InicializarArray(Empleado*array[],int len)
{

    int retorno=-1;
    int i;

    if (array!=NULL)
    {
        retorno=0;
        for(i=0;i<len;i++)
        {
            array[i]=NULL;

        }
    }

    return retorno;
}

int empleado_buscarporID(Empleado*array[],int len,int id)
{
    int retorno=-1;
    int i;
    Empleado*aux;

    for(i=0;i<len;i++)
    {
        aux=array[i];
        if(aux!=NULL && aux->idEmpleado==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
