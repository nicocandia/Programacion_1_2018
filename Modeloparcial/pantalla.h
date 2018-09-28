#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
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

int pantalla_Imprimir(Pantalla*pantalla,int tamanio);

int buscarLugarlibre(Pantalla*pantalla,int tamanio);

int generarID();

int verificarArregloSoloNumeros(char *pArreglo);

int inicializarPantalla(Pantalla*pantalla,int tamanio);

int getFloat(float* pBuffer);

int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos);


int verificarArreglosoloFlotantes(char* pBuffer);

int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int modificarDatos_Pantalla(Pantalla*pantalla,int tamanio,int indice);

int dardeBaja_Pantalla(Pantalla*pantalla,int id,int tamanio);

int buscarPantallaporid(Pantalla*pantalla,int tamanio,int id);

int getString(char* pBuffer, int limite);

void pantalla_ImprimirPorIndice(Pantalla*pantalla,int indice);

#endif // PANTALLA_H_INCLUDED
