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

void initArray(int* pArray, int limite, int valor);

int mostrarArray(int* pArray, int limite);

int getInt(int* pResultado);

void ordenarArreglo(int *pArray,int limite,int flagMayorMenor);

int verificarArregloSoloLetras(char *pArreglo);

int verificarCadenaAlfanumerica(char *pArreglo);

int verificarNumeroTelefono(char *pArreglo);




#endif // UTN_H_INCLUDED
