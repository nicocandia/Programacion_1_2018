#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


/**
    utn_getEntero : pide un entero al usuario
    @param pEdad: puntero a edad
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max);

int calcularMaximoArray(int* pArray, int limite, int* pMaximo);

int initArray(int* pArray, int limite, int valor);



#endif // UTN_H_INCLUDED
