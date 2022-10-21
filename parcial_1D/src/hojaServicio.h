/*
 * hojaServicio.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */

#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_
#include "fecha.h"

typedef struct
{
	int idHoja;
	int vehiculoId;
	char descripcion[30];
	float precioServicio;
	int isEmpty;
	eFecha fecha;
}eHojaServicio;

int InicializarHojaServicio(eHojaServicio* lista, int tam);

int BuscarHojaServicioLibre(eHojaServicio lista[], int tam, int* pIndex);

int MostrarUnaHojaServicio(eHojaServicio lista, eFecha fechas[],int tam);

int MostrarHojasServicios(eHojaServicio* lista, eFecha fechas[], int tam);

#endif /* HOJASERVICIO_H_ */
