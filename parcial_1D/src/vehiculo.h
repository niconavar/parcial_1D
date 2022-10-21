/*
 * vehiculo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_
#include "Tipo.h"

typedef struct
{
	int idVehiculo;
	char descripcion[20];
	int modelo;
	char color[10];
	int tipoId;
	int isEmpty;
}eVehiculo;

int InicializarVehiculo(eVehiculo* lista, int tam);

int BuscarVehiculoLibre(eVehiculo lista[], int tam, int* pIndex);

int AltaVehiculo(eVehiculo* lista, int tam, int* pId, int modelo, char color[], int tipoId);

int MostrarUnVehiculo(eVehiculo lista, eTipo tipos[],int tam);

int MostrarVehiculos(eVehiculo* lista, eTipo tipos[], int tam);

int MostrarVehiculosDeTipo1000(eVehiculo* lista, eTipo tipos[], int tam);
int MostrarVehiculosDeTipo1001(eVehiculo* lista, eTipo tipos[], int tam);
int MostrarVehiculosDeTipo1002(eVehiculo* lista, eTipo tipos[], int tam);

int BuscarVehiculoId(eVehiculo* lista, int tam, int id, int* pIndex);

int BuscarVehiculoTipo(eVehiculo* lista, int tam, int tipoId, int* pIndex);



int EliminarVehiculo(eVehiculo* lista, eTipo tipos[], int tamTipos, int tam);

int OrdenarViajeTipoYDestino(eVehiculo* lista, int tam);

#endif /* VEHICULO_H_ */
