/*
 * hojaServicio.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs_validaciones.h"
#include "hojaServicio.h"

int InicializarHojaServicio(eHojaServicio* lista, int tam)
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

int BuscarHojaServicioLibre(eHojaServicio lista[], int tam, int* pIndex)
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

int MostrarUnaHojaServicio(eHojaServicio lista, eFecha fechas[],int tam)
{
	int retorno = 0;

	if(fechas != NULL && tam >0)
	{
		printf("   %4d	         %10s	   %4.2f   %d/%d/%d\n",lista.idHoja,lista.descripcion,
				lista.precioServicio,lista.fecha.dia, lista.fecha.mes, lista.fecha.anio);
		retorno = 1;
	}
	return retorno;
}

int MostrarHojasServicios(eHojaServicio* lista, eFecha fechas[], int tam)
{

	   int retorno = 0;
	   int flag =0;
	    if(lista != NULL && tam > 0)
	    {
	        printf("                 *** Listado de hojas de servicio ***\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        printf("     id        \tdescripcion      \tprecio   \tfecha\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	        for(int i=0; i < tam; i++)
	        {
	        	if(!lista[i].isEmpty)
	        	{
	        		MostrarUnaHojaServicio(lista[i], fechas, tam);
	        		flag++;
	        	}
	        }
	        if(flag==0)
	        {
	        	printf("no hay hojas de servicio en el sistema en el sistema\n");
	        }
	        printf("\n\n");
	        retorno = 1;
	    }
	    return retorno;
}
