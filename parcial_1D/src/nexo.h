/*
 * nexo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "vehiculo.h"
#include "hojaServicio.h"

int NEXO_AltaHojaServicio(eHojaServicio* lista, int idvehiculo,int tam, int* pId, char descripcion[],
		float precioServicio, int dia, int mes, int anio);

int ModificarVehiculo(eVehiculo lista[], int tam, eTipo tipos[], int tamTipos);

int BuscarFecha(eHojaServicio* lista, int tam, int mes, int* pIndex);

#endif /* NEXO_H_ */
