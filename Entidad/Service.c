#include "Service.H"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int isValidMensaje(char *mensaje);
static int isValidGravedad(int  gravedad);

Service*service_new(void)
{

    return (Service*) malloc(sizeof(Service));
}

void service_delete(Service*this)
{
    free(this);
}

int service_setMensaje(Service*this,char*mensaje)
{
    int retorno=-1;
    if(this!=NULL && isValidMensaje(mensaje))
    {
        strcpy(this->mensaje,mensaje);
        retorno=0;
    }
    return retorno;
}

int service_getMensaje(Service*this,char*mensaje)
{
    int retorno=-1;
    if(this!=NULL && mensaje!=NULL)
    {
        strcpy(this->mensaje,mensaje);
        retorno=0;
    }
    return retorno;
}

static int isValidMensaje(char *mensaje)
{
    return 1;
}

int service_setGravedad(Service*this,int gravedad)
{
    int retorno=-1;
    if(this!=NULL && isValidGravedad(gravedad))
    {
        this->gravedad=gravedad;
        retorno=0;
    }
    return retorno;
}

int empleado_getGravedad(Service*this,int*gravedad)
{
    int retorno=-1;
    if(this!=NULL && gravedad!=NULL)
    {
        *gravedad=this->gravedad;
        retorno=0;
    }
    return retorno;
}

static int isValidGravedad(int  gravedad)
{
    return 1;
}



int service_compareMensaje(Service* thisA,Service*thisB)
{
    return strcmp(thisA->mensaje,thisB->mensaje);

}

void print_Service(Service*this)
{
    if(this!=NULL)
    {
        printf("\n%s -- %d -- %d\n ",this->mensaje,this->gravedad,this->serviceId);
    }
}

Service* service_newParametros(char* mensaje,int gravedad)
{

    Service*pService=NULL;
    pService=service_new();

    if(pService==NULL ||
        service_setGravedad(pService,gravedad) ||
        service_setMensaje(pService,mensaje))
    {
        service_delete(pService);
        pService=NULL;
    }

    return pService;
}
