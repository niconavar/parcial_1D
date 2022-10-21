/*
 * Viaje.c
 *
 *  Created on: 14 oct. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs_validaciones.h"
#include "Viaje.h"

#define ASC 1
#define DESC 0

int IniciarViaje(eViaje* lista, int tam)
{
	int retorno = 0;

	if(lista != NULL && tam >0)
	{
		for(int i=0; i <tam; i++)
		{
			lista[i].isEmpty = 1;
		}
	}
	return retorno;
}

int BuscarViajeLibre(eViaje lista[], int tam, int* pIndex)
{
	int retorno = -1;

	if(lista!=NULL && tam>0 && pIndex!=NULL)
	{
		*pIndex=-1; //no hay lugar

		for(int i = 0; i<tam; i++)
		{
			if(lista[i].isEmpty == 1)
			{
				*pIndex = i;
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int AltaViaje(eViaje* lista, int tam, int* pId, char destino[], int cantidadPasajeros, int tipoViaje)
{
	int retorno = 0;
	int indice;
	eViaje auxNuevoViaje;

	if(lista !=NULL && tam>0 && pId !=NULL)
	{
		if(BuscarViajeLibre(lista, tam, &indice))
		{
			if(indice == -1)
			{
				printf("no hay lugar en el sistema\n");
			}
			else
			{

				strcpy(auxNuevoViaje.destino, destino);
				auxNuevoViaje.cantidadPasajeros = cantidadPasajeros;
				auxNuevoViaje.tipoId = tipoViaje;

				auxNuevoViaje.isEmpty = 0;
				auxNuevoViaje.idViaje = *pId;
				*pId = *pId +1;
				lista[indice] = auxNuevoViaje;
				printf("entro al guardado de datos\n");
				retorno = 1;
			}
		}
		else
		{
			printf("ocurrio un error con los parametros\n");
		}
	}

	return retorno;
}

int MostrarUnViaje(eViaje lista, eTipo tipos[],int tam)
{
	int retorno = 0;
	char descripcion[30];

	if(tipos != NULL && tam >0)
	{
		CargarDescripcionTipo(tipos, tam, lista.tipoId, descripcion);
		printf("   %4d	    %10s	         %4d		            %10s\n",lista.idViaje,lista.destino,
				lista.cantidadPasajeros,descripcion);
		retorno = 1;
	}
	return retorno;
}

int MostrarViajes(eViaje* lista, eTipo tipos[], int tam)
{

	   int retorno = 0;
	   int flag =0;
	    if(lista != NULL && tam > 0)
	    {
	        printf("                 *** Listado de viajes ***\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        printf("     id        \tdestino      \tcantidad de pasajeros   \ttipo de viaje\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        for(int i=0; i < tam; i++)
	        {
	        	if(!lista[i].isEmpty)
	        	{
	        		MostrarUnViaje(lista[i], tipos, tam);
	        		flag++;
	        	}
	        }
	        if(flag==0)
	        {
	        	printf("no hay viajes en el sistema\n");
	        }
	        printf("\n\n");
	        retorno = 1;
	    }
	    return retorno;
}

int EncontrarViajeId(eViaje* lista, int tam, int id, int* pIndex)
{
	int retorno = -1;

	if(lista!=NULL && tam>0 && pIndex!=NULL && id >0)
	{
		*pIndex=-1;

		for(int i = 0; i<tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idViaje == id)
			{
				*pIndex = i;
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}




int ModificarViaje(eViaje lista[], int tam, eTipo tipos[], int tamTipos)
{
	int retorno = -1;
	int indice;
	int id;
	int opcion;
	char auxCadena[100];
	char salir = 'n';

	if(lista!=NULL && tam>0 && tipos!=NULL && tamTipos>0)
	{
		MostrarViajes(lista, tipos, tam);
		PedirNumeroEntero("Ingrese ID: ", 1, 2000, &id);

		if(EncontrarViajeId(lista, tam, id, &indice)== 1)
		{
			if(indice == -1)
			{
				printf("--------------------------------------------------\n");
				printf("No hay un viaje con id: %d\n", id);
				printf("--------------------------------------------------\n");
			}
			else
			{
				MostrarUnViaje(lista[indice], tipos, tam);
				printf("\nIngrese una opcion: \n");
				do
				{
					PedirNumeroEntero("Ingrese 1 para modificar destino: \n"
							"Ingrese 2 para modificar cantidad de pasajeros: \n"
							"Ingrese 3 para salir: \n", 1, 3, &opcion);

					switch(opcion)
					{
						case 1:
							PedirCadena(auxCadena, "ingrese destino: \n", 20);
							strcpy(lista[indice].destino, auxCadena);
							printf("------------------------------------\n");
							printf("Modificacion realizada con exito\n");
							printf("------------------------------------\n");
							break;
						case 2:
							PedirNumeroEntero("Ingrese cantidad de pasajeros: \n", 1, 20, &lista[indice].cantidadPasajeros);
							break;
						case 3:
							printf("------------------------------------\n");
							printf("finaliza modificacion\n");
							printf("------------------------------------\n");
							salir = 's';
							break;
					}
				}while(salir !='s');
			}
		}
		else
		{
			printf("--------------------------------------------------\n");
			printf("ocurrio un problema al buscar el viaje.\n");
			printf("--------------------------------------------------\n");
		}
		retorno = 1;
	}
	return retorno;
}

int EliminarViaje(eViaje* lista, eTipo tipos[], int tamTipos, int tam)
{
	int retorno = -1;
	int indice;
	char confirma;
	int idList;

	if(lista!=NULL && tam>0)
	{
		MostrarViajes(lista, tipos, tam);
		PedirNumeroEntero("Ingrese numero de ID: \n", 1, 2000, &idList);

		if(EncontrarViajeId(lista, tam, idList, &indice)== 1)
		{
			if(indice == -1)
			{
				printf("--------------------------------------------------\n");
				printf("No hay un viaje con ese id %d\n", idList);
				printf("--------------------------------------------------\n");
			}
			else
			{
				MostrarUnViaje(lista[indice], tipos, tam);
				printf("Confirma baja?: s/n");
				fflush(stdin);
				scanf("%c", &confirma);

				if(confirma != 'S' && confirma != 's')
				{
					printf("--------------------------------------------------\n");
					printf("Baja cancelada por el usuario\n");
					printf("--------------------------------------------------\n");
				}
				else
				{
					lista[indice].isEmpty = 1; //baja logica
					printf("--------------------------------------------------\n");
					printf("baja realizada con exito\n");
					printf("--------------------------------------------------\n");
					retorno = 1;
				}
			}
		}
		else
		{
			printf("ocurrio un problema al buscar el viaje.\n");
		}
		retorno = 1;
	}
	return retorno;
}

int OrdenarViajeTipoYDestino(eViaje* lista, int tam, int CriterioOrdenamiento)
{
	int retorno = 0;
	eViaje auxViaje;

	if(lista != NULL && tam >0)
	{
		for(int i=0; i <tam-1; i++)
		{
			for(int j= i+1 ; j<tam; j++)
			{

				if((strcmp(lista[i].destino, lista[j].destino)==0 && (lista[i].tipoId > lista[j].tipoId && CriterioOrdenamiento == ASC))
					|| (strcmp(lista[i].destino, lista[j].destino)>0 && strcmp(lista[i].destino, lista[j].destino)>0))
				{
					auxViaje = lista[i];
					lista[i] = lista[j];
					lista[j] = auxViaje;
				}
			}
		}
		retorno = 1;
	}

	return retorno;
}
