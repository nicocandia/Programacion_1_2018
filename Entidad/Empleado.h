#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    int idEmpleado;
    float altura;
}Empleado;

Empleado* empleado_new();
Empleado* empleado_newParametros(char* nombre,char* apellido,float altura);
int empleado_delete(Empleado* this);

int empleado_setNombre(Empleado*this,char*nombre);
int empleado_getNombre(Empleado*this,char*nombre);
//static int isValidNombre(char*nombre);

int empleado_setApellido(Empleado*this,char*apellido);
int empleado_getApellido(Empleado*this,char*apellido);
//static int isValidNombre(char*apellido);

int empleado_setAltura(Empleado*this,float altura);
int empleado_getAltura(Empleado*this,float*altura);
//static int isValidAltura(float altura);

int empleado_compareNombre(Empleado* thisA,Empleado*thisB);
void print_Empleado(Empleado*this);

int empleado_buscarLugarVacio(Empleado*array[],int len);

int empleado_InicializarArray(Empleado*array[],int len);

int empleado_buscarporID(Empleado*array[],int len,int id);

#endif // EMPLEADO_H_INCLUDED
