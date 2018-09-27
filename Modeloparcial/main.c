#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "Publicidad.h"
#include <string.h>
#define LEN 100
#define LEN_PUBLICIDAD 1000
int main()
{
    Pantalla pantallas[LEN];
    Publicidad publicidades[LEN_PUBLICIDAD];
    inicializarPublicidad(publicidades,LEN_PUBLICIDAD);
    inicializarPantalla(pantallas,LEN);

    int opcion;
    int indice;
    int id;
    int cuit;

    printf("\n <<<<<<BIENVENIDO>>>>>>\n");
    do
        {
            if(utn_getInt(&opcion,"\n1-DAR DE ALTA PANTALLA \n\n2-MODIFICAR DATOS DE PANTALLA \n\n3-DAR DE BAJA PANTALLA \n\n4-MOSTRAR\n\nOPCION??\n","\nError,opcion invalida\n",1,11,3)==0)
                {
                    switch(opcion)
                    {
                    case 1:
                        indice=buscarLugarlibre(pantallas,LEN);
                        if(indice>=0)
                            {
                                if(dardeAlta(pantallas,indice,LEN)==0)
                                    {
                                        printf("\nAlta exitosa\n");
                                    }
                                    else
                                        {printf("\nNo se pudo cargar pantalla\n");}
                            }else
                            {printf("\nEl id no existe\n");}
                            break;

                    case 2:
                        if(utn_getInt(&id,"\nIngrese numero id\n","\nError no es un id correcto\n",0,99,3)==0)
                            {
                                indice=buscarPantallaporid(pantallas,LEN,id);
                                if(indice>=0)
                                    {
                                        if(modificarDatos_Pantalla(pantallas,LEN,indice)==0)
                                            {
                                                printf("\nSe modificaron los datos correctamente\n");
                                            }
                                            else{printf("\nNo se modificaron los datos correctamente\n");}
                                    }
                                    else{printf("\nID no existe\n");}
                            }
                            else{printf("\nNo se pudo cargar id");}
                            break;

                    case 3:
                        if(utn_getInt(&id,"\nIngrese id de la pantalla a dar de baja\n","\nerror id no valido\n",0,99,3)==0)
                                            {
                                                indice=buscarPantallaporid(pantallas,LEN,id);
                                                if(indice>=0)
                                                {
                                                    if(dardeBaja_Pantalla(pantallas,id,LEN)==0)
                                                        {
                                                            printf("\nSe ha dado de baja la pantalla\n");
                                                        }
                                                        else
                                                        {
                                                                printf("\nError,no se pudo dar de baja la pantalla");
                                                        }

                                                }
                                                else
                                                {
                                                    printf("\nEl id no existe\n");
                                                }
                                           }
                                           else{printf("\nNo se pudo cargar id\n");}
                                           break;
                    case 4:
                        if(pantalla_Imprimir(pantallas,LEN)==0)
                        {
                        if(utn_getInt(&id,"\nIngrese numero id de la pantalla\n","\nError no es un id correcto\n",0,99,3)==0)
                        {
                            indice=buscarLugarlibre_Publicidad(publicidades,LEN_PUBLICIDAD);
                            if(indice>=0)
                            {
                                printf("\nHay lugar disponible\n");
                                if(dardeAlta_Publicidad(publicidades,indice,LEN_PUBLICIDAD,id)==0)
                                {
                                    printf("\nSe dio de alta la publicidad\n");
                                }
                                else{printf("\nNo se pudo dar de alta la publicidad\n");}
                            }
                            else{printf("\nNo hay lugar disponible para publicidades\n");}
                        }
                        else{printf("\nDato no valido\n");}

                        }
                        else{printf("\nNo hay nada registrado\n");}
                        break;

                    case 5:
                        if(utn_getInt(&cuit,"\nIngrese cuit del cliente\n","\nError",0,999999999,3)==0)
                        {

                        }
                        break;
                        }

                        }
                }while(opcion!=11);
    return 0;
}
