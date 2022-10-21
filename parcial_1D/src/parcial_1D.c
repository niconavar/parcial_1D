/*
 ============================================================================
Alumno: Nicolas Navarrete
Division: 1 D

MENU DE OPCIONES:
A. ALTA VEHICULO
B. MODIFICAR VEHICULO: Se ingresará el idVehiculo, permitiendo en un submenú modificar:
● descripcion
● precioServicio
C. BAJA VEHICULO: Se ingresará el id del vehículo y se realizará una baja lógica.
D. LISTAR VEHICULOS: Hacer un único listado de todos los vehículos ordenados por tipo y por
descripción.
E. LISTAR TIPOS
F. ALTA HOJA DE SERVICIO: Se dará de alta cada ocurrencia de la hoja de Servicio pidiéndole al
usuario que elija un vehículo.
G. LISTAR HOJAS DE SERVICIO
H. INFORMES
1- Mostrar vehículos de un tipo seleccionado
2- Mostrar todas las hojas de servicio efectuadas en una fecha seleccionada
3- Informar importe total de las hojas de servicio realizadas en un vehículo
seleccionado
4- Informar importe total de todas las hojas de servicio de un tipo en una fecha
seleccionada
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs_validaciones.h"
#include "menu.h"
#include "vehiculo.h"
#include "nexo.h"

#define TAM_VEHICULO 10
#define TAM_TIPOS 3
#define TAM_HOJA_SERVICIO 10

int main(void)
{
	setbuf(stdout,NULL);

	char salir = 'n';
	int proxIdVehiculo = 1;
	int proxIdHojaServicio = 20000;
	int modelo;
	char color[10];
	int tipoId;
	int indice;
	int tipoIdBuscar;

	char descripcionHojaServicio[30];
	float precioServicio;
	int dia;
	int mes;
	int anio;

	eVehiculo lista[TAM_VEHICULO];
	eFecha fechas[10];
	eHojaServicio listaHojas[TAM_HOJA_SERVICIO];

	eTipo tipos[TAM_TIPOS] =
	{
			{1000,"SEDAN 3PTAS"},
			{1001,"SEDAN 5PTAS"},
			{1002,"CAMIONETA"}
	};

	InicializarVehiculo(lista, TAM_VEHICULO);

	InicializarHojaServicio(listaHojas, TAM_HOJA_SERVICIO);

	do
	{
		switch(Menu())
		{
			case 1:
				PedirNumeroEntero("Ingrese modelo: \n", 1990, 2022, &modelo);
				PedirCadena(color, "Ingrese color del vehiculo\n", 10);
				PedirNumeroEntero("Ingrese el tipo de vehiculo\n"
						"1000 para sedan 3ptas\n"
						"1001 para sedan 5ptas\n"
						"1002 para camioneta\n", 1000, 1002, &tipoId);
				AltaVehiculo(lista, TAM_VEHICULO, &proxIdVehiculo, modelo, color, tipoId);
				break;
			case 2:
				EliminarVehiculo(lista, tipos, TAM_TIPOS, TAM_VEHICULO);
				break;
			case 3:
				break;
			case 4:
				MostrarVehiculos(lista, tipos, TAM_VEHICULO);
				break;
			case 5:
				ListarTipos(tipos, TAM_TIPOS);
				break;
			case 6:
				PedirNumeroEntero("Ingrese id:\n", 1, 10, &tipoIdBuscar);
				if(BuscarVehiculoId(lista, TAM_VEHICULO, tipoIdBuscar, &indice)==1)
				{
					if(indice == -1)
					{
						printf("--------------------------------------------------\n");
						printf("No hay un viaje con id: %d\n", tipoIdBuscar);
						printf("--------------------------------------------------\n");
					}
					else
					{
						PedirCadena(descripcionHojaServicio, "Ingrese descripcion: \n", 30);
						PedirFloatP("Ingrese precios de hoja de servicio: \n", &precioServicio, 99999, 1);
						PedirNumeroEntero("Ingrese dia: \n", 1, 31, &dia);
						PedirNumeroEntero("Ingrese mes: \n", 1, 12, &mes);
						PedirNumeroEntero("Ingrese año: \n", 2021, 2022, &anio);
						NEXO_AltaHojaServicio(listaHojas, tipoIdBuscar, TAM_VEHICULO, &proxIdHojaServicio, descripcionHojaServicio, precioServicio, dia, mes, anio);
					}
				}

				break;
			case 7:
				MostrarHojasServicios(listaHojas, fechas, 10);
				break;
			case 8:
				switch(SubMenu())
				{
					case 1:
						switch(SubMenu2())
						{
						case 1:
							MostrarVehiculosDeTipo1000(lista, tipos, TAM_VEHICULO);
							break;
						case 2:
							MostrarVehiculosDeTipo1001(lista, tipos, TAM_VEHICULO);
							break;
						case 3:
							MostrarVehiculosDeTipo1002(lista, tipos, TAM_VEHICULO);
							break;
				}
					break;
				case 2:
					MostrarHojaServicioEnFecha(lista, TAM_TIPOS, 10, fechas);
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				}
				break;
			case 9:
				salir = 's';
				break;

		}

	}while(salir != 's');

	return EXIT_SUCCESS;
}
