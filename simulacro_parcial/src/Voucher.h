/*
 * Voucher.h
 *
 *  Created on: 14 oct. 2022
 *      Author: Usuario
 */

#ifndef VOUCHER_H_
#define VOUCHER_H_
#include "Fecha.h"

typedef struct
{
	int idVoucher;
	int viajeId;
	char descripcion[30];
	float precioViaje;
	eFecha fecha;
}eVoucher;



#endif /* VOUCHER_H_ */
