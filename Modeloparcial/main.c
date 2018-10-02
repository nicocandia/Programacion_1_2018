#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "Publicidad.h"
#include <string.h>
#define LEN_PANTALLAS 100
#define LEN_PUBLICIDAD 1000
#define TAMANIO_CUIT 13

int main()
{
    Pantalla pantallas[LEN_PANTALLAS];
    Publicidad publicidades[LEN_PUBLICIDAD];
    inicializarPublicidad(publicidades,LEN_PUBLICIDAD);
    inicializarPantalla(pantallas,LEN_PANTALLAS);

    int opcion;
    int indice;
    int id;
    char cuit[TAMANIO_CUIT];

    printf("\n <<<<<<BIENVENIDO>>>>>>\n");
    do
        {
            if(utn_getInt(&opcion,"\n1-DAR DE ALTA PANTALLA \n\n2-MODIFICAR DATOS DE PANTALLA \n\n3-DAR DE BAJA PANTALLA \n\n4-CONTRATAR UNA PUBLICIDAD\n\n5-MODIFICAR CONDICIONES DE PUBLICACION\n\n6-CANCELAR CONTRATACION\n\n7-CONSULTAR FACTURACION\n\n8-LISTAR PUBLICIDADES\n\n9-LISTAR PANTALLAS\n\nOPCION??\n","\nError,opcion invalida\n",1,11,3)==0)
                {
                    switch(opcion)
                    {
                    case 1:
                        indice=buscarLugarlibre(pantallas,LEN_PANTALLAS);
                        if(indice>=0)
                            {
                                if(dardeAlta(pantallas,indice,LEN_PANTALLAS)==0)
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
                                indice=buscarPantallaporid(pantallas,LEN_PANTALLAS,id);
                                if(indice>=0)
                                    {
                                        if(modificarDatos_Pantalla(pantallas,LEN_PANTALLAS,indice)==0)
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
                                                indice=buscarPantallaporid(pantallas,LEN_PANTALLAS,id);
                                                if(indice>=0)
                                                {
                                                    if(dardeBaja_Pantalla(pantallas,id,LEN_PANTALLAS)==0 && eliminarPantalla_ytodasSuscontrataciones(publicidades,id)==0)
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
                        if(pantalla_Imprimir(pantallas,LEN_PANTALLAS)==0)
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
                        if(utn_getCuiloCuit(cuit,TAMANIO_CUIT,3,"\nIngrese cuit del cliente\n","\nError")==0)
                        {   if(verificarExisteCuitPublicidad(publicidades,cuit)==0)
                            {
                            buscariddePantalla_enPublicidad(cuit,LEN_PUBLICIDAD,publicidades,pantallas);
                            if(utn_getInt(&id,"\nIngrese id de la pantalla\n","error",0,99,3)==0)
                            {
                                if(modificar_DatosPublicidad(cuit,id,publicidades)==0)
                                {
                                    printf("\nSe han modificado los dias\n");
                                }
                                else
                                {printf("\nNo se pudieron modificar los datos\n");}
                            }
                            }else{printf("\nNo existe cuit registrado");}
                        }
                        break;

                    case 6:
                    if(utn_getCuiloCuit(cuit,TAMANIO_CUIT,3,"\nIngrese cuit del cliente\n","\nError")==0)
                        {   if(verificarExisteCuitPublicidad(publicidades,cuit)==0)
                            {
                            buscariddePantalla_enPublicidad(cuit,LEN_PUBLICIDAD,publicidades,pantallas);
                            if(utn_getInt(&id,"\nIngrese id de la pantalla\n","error",0,99,3)==0)
                            {
                                if(dardeBaja_Publicidad(publicidades,cuit,id)==0)
                                {
                                    printf("\nSe ha dado de baja la contratacion\n");
                                }
                                else
                                    {printf("\nNo se pudieron modificar los datos\n");}
                            }
                            else{printf("\nNo se pudo cargar id\n");}
                        }else{printf("\nNo existe cuit registrado");}
                        }
                        else{printf("\nNo se pudo cargar cuit\n");}
                        break;

                    case 8:
                        listar_Publicidades(publicidades);
                        break;

                    case 7:
                        if(utn_getCuiloCuit(cuit,TAMANIO_CUIT,3,"\nIngrese cuit del cliente\n","\nError")==0)
                        {
                            if(verificarExisteCuitPublicidad(publicidades,cuit)==0)
                                {
                                    imprimirImporte_Facturacionapagar(publicidades,pantallas,cuit);
                                }
                            else{printf("\nNo existe cuit registrado");}
                        }
                    break;

                    case 9:
                    pantalla_Imprimir(pantallas,LEN_PANTALLAS);
                    break;
                        }
                        }
                }while(opcion!=11);
    return 0;
}
