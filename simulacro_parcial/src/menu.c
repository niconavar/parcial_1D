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

	PedirNumeroEntero("Ingrese 1 para dar alta de alta un viaje\n"
			"Ingrese 2 para modificar un viaje\n"
			"Ingrese 3 para dar de baja un viaje\n"
			"Ingrese 4 para listar viajes\n"
			"Ingrese 5 para listar tipos de viaje\n"
			"Ingrese 6 para dar de alta un voucher\n"
			"Ingrese 7 para listar vouchers\n"
			"Ingrese 8 para Mostrar Informes\n"
			"Ingrese 9 para salir\n", 1, 9, &opcion);
	return opcion;
}
