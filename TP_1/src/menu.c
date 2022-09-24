/*
 * menu.c
 *
 *  Created on: 19 sep. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "inputs_validaciones.h"

int Menu(int costoHospedaje, int costoComida, int costoTransporte, int contArqueros,
		int contDefensas, int contMediocamp, int contDelanteros)
{
	int opcion = 0;

	printf("\n======================================================\nIngrese 1 para ingresar costos de mantenimiento\n"
			"costo de hospedaje -> %d\n"
			"costo de comida -> %d\n"
			"costo de transporte -> %d\n======================================================\n"
			"Ingrese 2 para cargar jugador\n"
			"Arqueros -> %d\n"
			"defensas -> %d\n"
			"mediocampistas -> %d\n"
			"delanteros -> %d\n======================================================\n", costoHospedaje, costoComida, costoTransporte, contArqueros, contDefensas, contMediocamp, contDelanteros);
	PedirNumeroEntero("Ingrese 3 para realizar calculos\n"
			"Ingrese 4 para informar resultados\n"
			"Ingrese 5 para salir\n", 1, 5, &opcion);

	return opcion;
}
