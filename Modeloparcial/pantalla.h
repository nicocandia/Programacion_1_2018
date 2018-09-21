#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#define TRUE 1
#define FALSE 0
#define LCD 1
#define LED 0
typedef struct
{
    int id;
    char nombre[50];
    char direccion[50];
    int tipo;
    int isEmpty;
    float precio;
}Pantalla;

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos);

int getInt(int* pBuffer);

int dardeAlta(Pantalla *pantalla,int indice,int tamanio);

void pantalla_Imprimir(Pantalla*pantalla,int indice,int tamanio);

int buscarLugarlibre(Pantalla*pantalla,int tamanio);

int generarID();

int verificarArregloSoloNumeros(char *pArreglo);

int inicializarPantalla(Pantalla*pantalla,int tamanio);

int getFloat(float* pBuffer);

int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos);


int verificarArreglosoloFlotantes(char* pBuffer);

int dardeBaja(Pantalla*pantalla,int indice,int tamanio);




#endif // PANTALLA_H_INCLUDED
