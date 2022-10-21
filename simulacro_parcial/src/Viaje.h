/*
 * Viaje.h
 *
 *  Created on: 14 oct. 2022
 *      Author: Usuario
 */

#ifndef VIAJE_H_
#define VIAJE_H_
#include "Tipo.h"

typedef struct
{
	int idViaje;
	char destino[20];
	int cantidadPasajeros;
	int tipoId;
	int isEmpty;
}eViaje;

int IniciarViaje(eViaje* lista, int tam);

int BuscarViajeLibre(eViaje lista[], int tam, int* pIndex);

int AltaViaje(eViaje* lista, int tam, int* pId, char destino[], int cantidadPasajeros, int tipoViaje);

int MostrarUnViaje(eViaje lista, eTipo tipos[],int tam);

int MostrarViajes(eViaje* lista, eTipo tipos[], int tam);

int EncontrarViajeId(eViaje* lista, int tam, int id, int* pIndex);

int ModificarViaje(eViaje lista[], int tam, eTipo tipos[], int tamTipos);

int EliminarViaje(eViaje* lista, eTipo tipos[], int tamTipos, int tam);

int OrdenarViajeTipoYDestino(eViaje* lista, int tam, int CriterioOrdenamiento);

#endif /* VIAJE_H_ */
