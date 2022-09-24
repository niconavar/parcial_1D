/*
 * inputs_validaciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */

#ifndef INPUTS_VALIDACIONES_H_
#define INPUTS_VALIDACIONES_H_

/// @brief esta funcion pide un string al usuario
///
/// @param cadena = variable donde se guardara la cadena
/// @param mensaje = mensaje para pedir al usuario el ingreso del string
/// @param tam = tamaño de cadena
/// @return retorna 1 si la tarea se realizo correctamente
int PedirCadena(char cadena[], char mensaje[], int tam);

/// @brief pide un entero al usuario y lo valida, recibe un mensaje, un parametro minimo a ingresar y uno maximo y la variable puntero para guardar el numero
///		   utiliza la funcion validar entero
/// @param mensaje
/// @param minimo
/// @param maximo
/// @param pNumero
/// @return retorna 0 si se realizo correctamente la tarea, sino -1 en caso de haber un error
int PedirNumeroEntero(char mensaje[], int minimo, int maximo, int *pNumero);

/// @brief valida que el dato ingresado sea un entero, que no contegan puntos, espacios o caracteres letra
///
/// @param cadena
/// @return retorna 0 si se realizo correctamente la tarea
int ValidarEntero(char* cadena);

/// @brief pide un float al usuario y lo valida, recibe un mensaje, un parametro minimo a ingresar y uno maximo y la variable puntero para guardar el numero
///		   utiliza la funcion validar float
/// @param mensaje
/// @param numeroF
/// @param max
/// @param min
/// @return retorna 0 si se realizo correctamente la tarea
int PedirFloatP(char mensaje[], float* numeroF, float max, float min);

/// @brief valida que el dato ingresado sea un float, que no contegan puntos, espacios o caracteres letra
///
/// @param stringRecibido
/// @return retorna 0 si se realizo correctamente la tarea
int ValidarFloat(char* stringRecibido);

#endif /* INPUTS_VALIDACIONES_H_ */
