/*
 * tipo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int idTipo;
	char descripcion[30];
}eTipo;

int ListarTipos(eTipo tipos[], int tam);

int CargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
#endif /* TIPO_H_ */
