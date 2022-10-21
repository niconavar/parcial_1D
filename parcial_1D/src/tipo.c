/*
 * tipo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ListarTipos(eTipo tipos[], int tam)
{
	int retorno = 0;

	if(tipos != NULL && tam > 0)
	{
		printf("Lista de tipos de vehiculos\n");
		printf("   id      descripcion\n");
		printf("-------------------------------------\n");

		for(int i=0; i<tam; i++)
		{
			printf("    %4d       %10s\n",tipos[i].idTipo, tipos[i].descripcion);
		}
		retorno = 1;
	}
	return retorno;
}

int CargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
	int retorno = 0;

	if(tipos != NULL && tam > 0 && id >= 1000 && id <= 1002 && descripcion != NULL)
	{
		for(int i = 0; i < tam ; i++)
		{
			if(tipos[i].idTipo == id)
			{
				strcpy(descripcion, tipos[i].descripcion);
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

