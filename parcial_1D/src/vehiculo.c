/*
 * vehiculo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs_validaciones.h"
#include "vehiculo.h"

int InicializarVehiculo(eVehiculo* lista, int tam)
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

int BuscarVehiculoLibre(eVehiculo lista[], int tam, int* pIndex)
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

int AltaVehiculo(eVehiculo* lista, int tam, int* pId, int modelo, char color[], int tipoId)
{
	int retorno = 0;
	int indice;
	eVehiculo auxNuevoVehiculo;

	if(lista !=NULL && tam>0 && pId !=NULL)
	{
		if(BuscarVehiculoLibre(lista, tam, &indice))
		{
			if(indice == -1)
			{
				printf("no hay lugar en el sistema\n");
			}
			else
			{

				auxNuevoVehiculo.modelo = modelo;
				strcpy(auxNuevoVehiculo.color, color);
				auxNuevoVehiculo.tipoId = tipoId;

				auxNuevoVehiculo.isEmpty = 0;
				auxNuevoVehiculo.idVehiculo = *pId;
				*pId = *pId +1;
				lista[indice] = auxNuevoVehiculo;
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

int MostrarUnVehiculo(eVehiculo lista, eTipo tipos[],int tam)
{
	int retorno = 0;
	char descripcion[30];

	if(tipos != NULL && tam >0)
	{
		CargarDescripcionTipo(tipos, tam, lista.tipoId, descripcion);
		printf("   %4d	         %4d	   %10s	        %10s\n",lista.idVehiculo,lista.modelo,
				lista.color,descripcion);
		retorno = 1;
	}
	return retorno;
}

int MostrarVehiculos(eVehiculo* lista, eTipo tipos[], int tam)
{

	   int retorno = 0;
	   int flag =0;
	    if(lista != NULL && tam > 0)
	    {
	        printf("                 *** Listado de vehiculos ***\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        printf("     id        \tmodelo      \tcolor   \ttipo de vehiculo\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        for(int i=0; i < tam; i++)
	        {
	        	if(!lista[i].isEmpty)
	        	{
	        		MostrarUnVehiculo(lista[i], tipos, tam);
	        		flag++;
	        	}
	        }
	        if(flag==0)
	        {
	        	printf("no hay vehiculos en el sistema\n");
	        }
	        printf("\n\n");
	        retorno = 1;
	    }
	    return retorno;
}

int BuscarVehiculoId(eVehiculo* lista, int tam, int id, int* pIndex)
{
	int retorno = -1;

	if(lista!=NULL && tam>0 && pIndex!=NULL && id >0)
	{
		*pIndex=-1;

		for(int i = 0; i<tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idVehiculo == id)
			{
				*pIndex = i;
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int EliminarVehiculo(eVehiculo* lista, eTipo tipos[], int tamTipos, int tam)
{
	int retorno = -1;
	int indice;
	char confirma;
	int idList;

	if(lista!=NULL && tam>0)
	{
		MostrarVehiculos(lista, tipos, tam);
		PedirNumeroEntero("Ingrese numero de ID: \n", 1, 2000, &idList);

		if(BuscarVehiculoId(lista, tam, idList, &indice)==1)
		{
			if(indice == -1)
			{
				printf("--------------------------------------------------\n");
				printf("No hay un vehiculo con ese id %d\n", idList);
				printf("--------------------------------------------------\n");
			}
			else
			{
				MostrarUnVehiculo(lista[indice], tipos, tam);
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
			printf("ocurrio un problema al buscar el vehiculo.\n");
		}
		retorno = 1;
	}
	return retorno;

}



int MostrarVehiculosDeTipo1000(eVehiculo* lista, eTipo tipos[], int tam)
{

	   int retorno = 0;
	   int flag =0;
	    if(lista != NULL && tam > 0 && tipos != NULL)
	    {
	        printf("                 *** Listado de vehiculos ***\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        printf("     id        \tmodelo      \tcolor   \ttipo de vehiculo\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        for(int i=0; i < tam; i++)
	        {
	        	if(!lista[i].isEmpty)
	        	{
	        		if(lista[i].tipoId == 1000)
	        		{
		        		MostrarUnVehiculo(lista[i], tipos, tam);
	        		}
	        		flag++;
	        	}
	        }
	        if(flag==0)
	        {
	        	printf("no hay vehiculos en el sistema\n");
	        }
	        printf("\n\n");
	        retorno = 1;
	    }
	    return retorno;
}

int MostrarVehiculosDeTipo1001(eVehiculo* lista, eTipo tipos[], int tam)
{

	   int retorno = 0;
	   int flag =0;
	    if(lista != NULL && tam > 0 && tipos != NULL)
	    {
	        printf("                 *** Listado de vehiculos ***\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        printf("     id        \tmodelo      \tcolor   \ttipo de vehiculo\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        for(int i=0; i < tam; i++)
	        {
	        	if(!lista[i].isEmpty)
	        	{
	        		if(lista[i].tipoId == 1001)
	        		{
		        		MostrarUnVehiculo(lista[i], tipos, tam);
	        		}
	        		flag++;
	        	}
	        }
	        if(flag==0)
	        {
	        	printf("no hay vehiculos en el sistema\n");
	        }
	        printf("\n\n");
	        retorno = 1;
	    }
	    return retorno;
}

int MostrarVehiculosDeTipo1002(eVehiculo* lista, eTipo tipos[], int tam)
{
	   int retorno = 0;
	   int flag =0;
	    if(lista != NULL && tam > 0 && tipos != NULL)
	    {
	        printf("                 *** Listado de vehiculos ***\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        printf("     id        \tmodelo      \tcolor   \ttipo de vehiculo\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        for(int i=0; i < tam; i++)
	        {
	        	if(!lista[i].isEmpty)
	        	{
	        		if(lista[i].tipoId == 1002)
	        		{
		        		MostrarUnVehiculo(lista[i], tipos, tam);
	        		}
	        		flag++;
	        	}
	        }
	        if(flag==0)
	        {
	        	printf("no hay vehiculos en el sistema\n");
	        }
	        printf("\n\n");
	        retorno = 1;
	    }
	    return retorno;
}
