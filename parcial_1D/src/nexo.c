/*
 * nexo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs_validaciones.h"
#include "vehiculo.h"
#include "hojaServicio.h"

int NEXO_AltaHojaServicio(eHojaServicio* lista, int idvehiculo,int tam, int* pId, char descripcion[],
		float precioServicio, int dia, int mes, int anio)
{

	int retorno = 0;
	int indice;
	eHojaServicio auxNuevaHojaServicio;

	if(lista !=NULL && tam>0 && pId !=NULL)
	{
		if(BuscarHojaServicioLibre(lista, tam, &indice))
		{
			if(indice == -1)
			{
				printf("no hay lugar en el sistema\n");
			}
			else
			{
				auxNuevaHojaServicio.vehiculoId = idvehiculo;
				auxNuevaHojaServicio.precioServicio = precioServicio;
				strcpy(auxNuevaHojaServicio.descripcion, descripcion);
				auxNuevaHojaServicio.fecha.dia = dia;
				auxNuevaHojaServicio.fecha.mes = mes;
				auxNuevaHojaServicio.fecha.anio = anio;

				auxNuevaHojaServicio.isEmpty = 0;
				auxNuevaHojaServicio.idHoja = *pId;
				*pId = *pId +1;
				lista[indice] = auxNuevaHojaServicio;
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

int BuscarFecha(eHojaServicio* lista, int tam, int mes, int* pIndex)
{
	int retorno = -1;

	if(lista!=NULL && tam>0 && pIndex!=NULL && mes >=1 && mes <=12)
	{
		*pIndex=-1;

		for(int i = 0; i<tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].fecha.mes == mes)
			{
				*pIndex = i;
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int MostrarHojaServicioEnFecha(eHojaServicio* lista, int tamTipos, int tam, eFecha fechas[])
{
	int retorno = -1;
	int indice;
	int mes;

	if(lista!=NULL && tam>0)
	{
		PedirNumeroEntero("Ingrese mes: \n", 1, 12, &mes);

		if(BuscarFecha(lista, tam, mes, &indice)==1 )
		{
			if(indice == -1)
			{
				printf("--------------------------------------------------\n");
				printf("No hay un vehiculo con ese id %d\n", mes);
				printf("--------------------------------------------------\n");
			}
			else
			{
				MostrarHojasServicios(lista, fechas, tam);
			}
		}
		else
		{
			printf("ocurrio un problema al buscar la fecha.\n");
		}
		retorno = 1;
	}
	return retorno;
}

