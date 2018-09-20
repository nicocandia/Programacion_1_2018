#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
typedef struct
{
    char nombre[32];
    char descripcion[128];
    float precio;
    int estado;
    int ID;
}Producto;

void inicializarEstado(Producto*arreglo,int tamanio);

int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos);

void mostrarArray(int* pArray, int limite);

int calcularMaximoArray(int* pArray, int limite, int* pMaximo);

void initArray(int* pArray, int limite, int valor);

void ordenarArreglo(int *pArray,int limite,int flagMayorMenor);

int verificarArregloSoloLetras(char *pArreglo);

int verificarArregloAlfanumerica(char *pArreglo);

int verificarNumeroTelefono(char *pArreglo);

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos);

void insertion(int data[],int len);

int verificarArreglosoloFlotantes(char* pBuffer);

int getFloat(float* pBuffer);

int verificarArregloSoloNumeros(char *pArreglo);

int getInt(int* pBuffer);

int dardeAlta(Producto*Producto,int indice,int tamanio);

void producto_Imprimir(Producto*producto,int indice,int tamanio);

int devolverIndice_Itemvacio(Producto*producto,int tamanio);

int generarID();

void menu();

void modificarProducto(Producto*producto,int indice);

#endif // PRODUCTO_H_INCLUDED
