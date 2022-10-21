/*
 ============================================================================
 Name        : simulacro_parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Viaje.h"
#include "inputs_validaciones.h"

#define TAM_VIAJE 10
#define TAM_TIPOS 3

int main(void)
{
	setbuf(stdout, NULL);

	char salir = 'n';
	int proxIdViaje = 1;
	char destino[20];
	int cantidadPasajeros;
	int tipoViaje;

	eViaje lista[TAM_VIAJE];

	eTipo tipos[TAM_TIPOS] =
	{
			{1000,"AEREO"},
			{1001,"TERRESTRE"},
			{1002,"MARITIMO"}
	};

	IniciarViaje(lista, TAM_VIAJE);

	do
	{
		switch(Menu())
		{
		case 1:

			PedirCadena(destino, "Ingrese destino:\n", 20);
			PedirNumeroEntero("Ingrese cantidad de pasajeros:\n", 1, 10, &cantidadPasajeros);
			PedirNumeroEntero("Ingrese tipo de viaje\n"
					"1000 AEREO\n"
					"1001 TERRESTRE\n"
					"1002 MARITIMO\n", 1000, 1002, &tipoViaje);

			AltaViaje(lista, TAM_VIAJE, &proxIdViaje, destino, cantidadPasajeros, tipoViaje);
			break;
		case 2:
			ModificarViaje(lista, TAM_VIAJE, tipos, TAM_TIPOS);
			break;
		case 3:
			EliminarViaje(lista, tipos, TAM_TIPOS, TAM_VIAJE);
			break;
		case 4:
			OrdenarViajeTipoYDestino(lista, TAM_VIAJE, 1);
			MostrarViajes(lista, tipos, TAM_VIAJE);
			break;
		case 5:
			ListarTipos(tipos, TAM_TIPOS);
			break;
		case 6:
			MostrarViajes(lista, tipos, TAM_VIAJE);
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			salir = 's';
			printf("programa finalizado\n");
			break;
		}
	}while(salir != 's');


	return EXIT_SUCCESS;
}
