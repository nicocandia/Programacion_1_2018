#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
typedef struct
{
    int gravedad;
    char mensaje[65];
    int serviceId;

}Service;

Service*service_new(void);

void service_delete(Service*this);

int service_setMensaje(Service*this,char*mensaje);

int service_getMensaje(Service*this,char*mensaje);

int service_setGravedad(Service*this,int gravedad);

int empleado_getGravedad(Service*this,int*gravedad);

int service_compareMensaje(Service* thisA,Service*thisB);

void print_Service(Service*this);

Service* service_newParametros(char* mensaje,int gravedad);
#endif // SERVICE_H_INCLUDED
