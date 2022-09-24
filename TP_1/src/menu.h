/*
 * menu.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Usuario
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief recibe las variables de mantenimiento y contadores de jugadores para poder mostrar en tiempo real, las actualizaciones de costos y jugadores
/// luego dentro de la funcion, tiene un printf con los parametros del menu y la funcion pedir numero entero
///
/// @param costoHospedaje
/// @param costoComida
/// @param costoTransporte
/// @param contArqueros
/// @param contDefensas
/// @param contMediocamp
/// @param contDelanteros
/// @return retorna la opcion elegida por el usuario
int Menu(int costoHospedaje, int costoComida, int costoTransporte, int contArqueros,
		int contDefensas, int contMediocamp, int contDelanteros);

#endif /* MENU_H_ */
