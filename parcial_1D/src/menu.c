/*
 * menu.c
 *
 *  Created on: 14 oct. 2022
 *      Author: Usuario
 */

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "inputs_validaciones.h"

int Menu()
{
	int opcion;

	PedirNumeroEntero("Ingrese 1 para dar alta vehiculo\n"
			"Ingrese 2 para modificar datos de vehiculo\n"
			"Ingrese 3 para dar de baja vehiculo\n"
			"Ingrese 4 para listar vehiculos\n"
			"Ingrese 5 para listar tipos\n"
			"Ingrese 6 para dar alta hoja de servicio\n"
			"Ingrese 7 para listar hojas de servicio\n"
			"Ingrese 8 para informes\n"
			"Ingrese 9 para salir\n", 1, 9, &opcion);
	return opcion;
}

int SubMenu()
{
	int opcion;

	PedirNumeroEntero("Ingrese 1 para mostrar Vehiculo de un tipo seleccionado\n"
			"Ingrese 2 para mostrar todas las hojas de servicio efectuadas en una fecha seleccionada\n"
			"Ingrese 3 para Informar importe total de las hojas de servicio realizadas en un vehículo seleccionado\n"
			"Ingrese 4 para Informar importe total de todas las hojas de servicio de un tipo en una fecha seleccionada\n"
			"Ingrese 5 para salir\n", 1, 5, &opcion);
	return opcion;
}

int SubMenu2()
{
	int opcion;

	PedirNumeroEntero("Ingrese 1 para SEDAN 3PTAS\n"
			"Ingrese 2 para SEDAN 5PTAS\n"
			"Ingrese 3 para Camioneta", 1, 3, &opcion);
	return opcion;
}
