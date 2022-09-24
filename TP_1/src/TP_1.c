/*
 ============================================================================
 Alumno: Nicolás Navarrete
 division: 1 D

Debemos conformar un equipo para competir en el próximo mundial.
La formación del equipo titular será 1-4-4-2 (arquero, defensores, mediocampistas y
delanteros).
Hay que tener presente que no podemos superar la cantidad máxima de 22 jugadores y
no más de dos por posición, es decir, en total deberíamos tener 2 arqueros, 8 defensores,
8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).
Dicho plantel contara con un costo de mantenimiento, que va a estar compuesto por:
Gastos de Transporte, Hospedaje y Comida. El usuario deberá cargar todos los gastos.
Nota: de estos 3 valores surge el gasto de mantenimiento.
Los jugadores pueden desarrollar sus actividades en cualquiera de las 6 confederaciones:
AFC en Asia; CAF en África; CONCACAF en zona del Norte; CONMEBOL en Sudamérica;
UEFA en Europa; OFC en Oceanía;
La composición del menú será:

1. Ingreso de los costos de Mantenimiento.
Nota: El usuario podrá elegir qué gasto desea ingresar.
El programa deberá informar el monto de cada gasto que se haya cargado hasta el momento:
* Costo de hospedaje -> $0
* Costo de comida -> $0
* Costo de transporte -> $0

2. Carga de jugadores:
Nota: Al momento de la carga de datos debemos ingresar número de camiseta, posición,
confederación en la que está jugando.
El usuario podrá elegir qué posición desea ingresar.
El programa deberá informar la cantidad de jugadores en cada posición que se haya cargado hasta
el momento:
* Arqueros -> 0
* Defensores -> 0
* Mediocampistas -> 0
* Delanteros -> 0

3. Realizar todos los cálculos.
Nota: en esta sección solo se calcularan los valores de los datos solicitados, NO se deberán
imprimir, solo informar que se realizaron correctamente los siguientes caculos:
a. Calcular el promedio de jugadores de cada mercado.
b. Calcular el costo de mantenimiento.
c. Si la mayoría del plantel está compuesta por jugadores de la confederación europea el costo
de mantenimiento recibe un aumento del 35%.

4. Informar todos los resultados.
Nota: Se deberá imprimir todos los datos calculados en el punto anterior y si el costo de
mantenimiento recibió un aumento se debe informar el valor original, el valor del aumento
y el valor actualizado con el aumento agregado.
5. Salir.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs_validaciones.h"
#include "Menu.h"

int main(void)
{
	setbuf(stdout,NULL);

	int salir = 0;
	int opcion2;
	int SalirMantenimiento = 0;

	//mantenimiento
	int costoHospedaje = 0;
	int costoComida = 0;
	int costoTransporte = 0;
	int mantenimientoTotal = 0;
	int mantenimientoTotalMod = 0;
	int flagMantenimiento1 = 0;

	//jugadores
	int flagJugadores = 0;
	int jugadoresTotales = 0;
	int numCamiseta;
	int posicion;
	int confederacion;
	int contArqueros = 0;
	int contDefensas = 0;
	int contMediocamp = 0;
	int contDelanteros = 0;
	int totalAFC = 0;
	int totalCAF = 0;
	int totalCONCACAF = 0;
	int totalCONMEBOL = 0;
	int totalUEFA = 0;
	int totalOFC = 0;
	int totalJugadoresConfederaciones = 0;

	float promedioAFC;
	float promedioCAF;
	float promedioCONCACAF;
	float promedioCONMEBOL;
	float promedioUEFA;
	float promedioOFC;

	int aumento;
	int flagAumento = 0;
	int flagCalculo = 0;

	do
	{
		switch(Menu(costoHospedaje, costoComida, costoTransporte, contArqueros, contDefensas, contMediocamp, contDelanteros))
		{
		case 1:

			printf("\n==============================================\nIngreso de costos de mantenimiento\n==============================================\n"
					"costo de hospedaje -> %d\n"
					"costo de comida -> %d\n"
					"costo de transporte -> %d\n", costoHospedaje, costoComida, costoTransporte);

				flagMantenimiento1 = 1;
				do
				{
					PedirNumeroEntero("Ingrese 1 para agregar costo de hospedaje\n"
							"Ingrese 2 para agregar costo de comida\n"
							"Ingrese 3 para agregar costo de transporte\n"
							"Ingrese 4 para volver al menu principal\n", 1, 4, &opcion2);

					switch(opcion2)
					{
					case 1:
						PedirNumeroEntero("Ingrese costo de hospedaje: \n", 1, 99999999, &costoHospedaje);
						break;
					case 2:
						PedirNumeroEntero("Ingrese costo de comida: \n", 1, 99999999, &costoComida);
						break;
					case 3:
						PedirNumeroEntero("Ingrese costo de transporte: \n", 1, 99999999, &costoTransporte);
						break;
					case 4:
						if(costoHospedaje >0 && costoComida >0 && costoTransporte >0)
						{
							SalirMantenimiento = 1;
							printf("\n------------------------------\nvuelta al menu principal\n------------------------------\n");
						}
						else
						{
							printf("\n**************************************************************************************\nIngrese todos los costos de mantenimiento: Hospedaje, Comida y Transporte\n**************************************************************************************\n");
						}

						break;
					}

				}while(SalirMantenimiento != 1);
			break;
		case 2:
			flagJugadores = 1;
			printf("\n==============================================\nCarga de Jugadores\n==============================================\n"
					"Arqueros -> %d\n"
					"defensas -> %d\n"
					"mediocampistas -> %d\n"
					"delanteros -> %d\n", contArqueros, contDefensas, contMediocamp, contDelanteros);
			if(jugadoresTotales < 22)
			{
				PedirNumeroEntero("ingrese numero de camiseta: \n", 1, 99, &numCamiseta);
				PedirNumeroEntero("Ingrese posicion\n"
						"1 para arquero\n"
						"2 para defensor\n"
						"3 para mediocampista\n"
						"4 para delantero\n", 1, 4, &posicion);

				switch(posicion)
				{
					case 1:
						if(contArqueros<2)
						{
							PedirNumeroEntero("Ingrese 1 para seleccionar AFC\n"
									"Ingrese 2 para seleccionar CAF\n"
									"Ingrese 3 para seleccionar CONCACAF\n"
									"Ingrese 4 para seleccionar CONMEBOL\n"
									"Ingrese 5 para seleccionar UEFA\n"
									"Ingrese 6 para seleccionar OFC\n", 1, 6, &confederacion);
							printf("jugador agregado con exito\n");
							contArqueros = contArqueros +1;
						}
						else
						{
							printf("\n************************************\nerror: maxima cantidad de arqueros alcanzada\n************************************\n");
							confederacion = 0; //pongo la variable confederacion en 0 para que no se relacione con ninguna opcion ya que de no ser asi,
							//el jugador no se agregaba pero si seguia sumando +1 a la ultima confederacion agregada
						}
						break;
					case 2:
						if(contDefensas <8)
						{
							PedirNumeroEntero("Ingrese 1 para seleccionar AFC\n"
									"Ingrese 2 para seleccionar CAF\n"
									"Ingrese 3 para seleccionar CONCACAF\n"
									"Ingrese 4 para seleccionar CONMEBOL\n"
									"Ingrese 5 para seleccionar UEFA\n"
									"Ingrese 6 para seleccionar OFC\n", 1, 6, &confederacion);
							printf("jugador agregado con exito\n");
							contDefensas = contDefensas +1;
						}
						else
						{
							printf("\n************************************\nerror: maxima cantidad de defensas alcanzada\n************************************\n");
							confederacion = 0;
						}
						break;
					case 3:
						if(contMediocamp<8)
						{
							PedirNumeroEntero("Ingrese 1 para seleccionar AFC\n"
									"Ingrese 2 para seleccionar CAF\n"
									"Ingrese 3 para seleccionar CONCACAF\n"
									"Ingrese 4 para seleccionar CONMEBOL\n"
									"Ingrese 5 para seleccionar UEFA\n"
									"Ingrese 6 para seleccionar OFC\n", 1, 6, &confederacion);
							printf("jugador agregado con exito\n");
							contMediocamp = contMediocamp +1;
						}
						else
						{
							printf("\n************************************\nerror: maxima cantidad de mediocampistas alcanzada\n************************************\n");
							confederacion = 0;
						}
						break;
					case 4:
						if(contDelanteros<4)
						{
							PedirNumeroEntero("Ingrese 1 para seleccionar AFC\n"
									"Ingrese 2 para seleccionar CAF\n"
									"Ingrese 3 para seleccionar CONCACAF\n"
									"Ingrese 4 para seleccionar CONMEBOL\n"
									"Ingrese 5 para seleccionar UEFA\n"
									"Ingrese 6 para seleccionar OFC\n", 1, 6, &confederacion);
							printf("jugador agregado con exito\n");
							contDelanteros = contDelanteros+1;
						}
						else
						{
							printf("\n************************************\nerror: maxima cantidad de delanteros alcanzada\n************************************\n");
							confederacion = 0;
						}
						break;
				}

				if(contArqueros<=2 && contDefensas <=8 && contMediocamp<=8 && contDelanteros<=4)
				{
					switch(confederacion)
					{
					case 1:
						totalAFC = totalAFC +1;
						break;
					case 2:
						totalCAF = totalCAF+1;
						break;
					case 3:
						totalCONCACAF = totalCONCACAF+1;
						break;
					case 4:
						totalCONMEBOL = totalCONMEBOL +1;
						break;
					case 5:
						totalUEFA = totalUEFA +1;
						break;
					case 6:
						totalOFC = totalOFC+1;
						break;
					}
				}
				jugadoresTotales = contArqueros + contDefensas + contMediocamp + contDelanteros;
			}
			else
			{
				printf("\n****************************************************\nerror: maxima cantidad de jugadores alcanzada (22 jugadores)\n****************************************************\n");
			}
			break;
		case 3:
			if(flagJugadores == 1 && flagMantenimiento1 == 1)
			{
					flagCalculo = 1;
					totalJugadoresConfederaciones = totalAFC + totalCAF + totalCONCACAF + totalCONMEBOL + totalUEFA + totalOFC;

					promedioAFC = ((float)totalAFC*100)/totalJugadoresConfederaciones;
					promedioCAF = ((float)totalCAF*100)/totalJugadoresConfederaciones;
					promedioCONCACAF = ((float)totalCONCACAF*100)/totalJugadoresConfederaciones;
					promedioCONMEBOL = ((float)totalCONMEBOL*100)/totalJugadoresConfederaciones;
					promedioUEFA = ((float)totalUEFA*100)/totalJugadoresConfederaciones;
					promedioOFC = ((float)totalOFC*100)/totalJugadoresConfederaciones;

					mantenimientoTotal = costoHospedaje+ costoComida + costoTransporte;

					if(totalUEFA > totalOFC && totalUEFA > totalCONMEBOL && totalUEFA > totalCONCACAF && totalUEFA > totalCAF && totalUEFA > totalAFC)
					{
						aumento = (mantenimientoTotal*35)/100;
						mantenimientoTotalMod = mantenimientoTotal+aumento;
						flagAumento=1;
					}

					printf("\n==================================\ncalculos realizados\n==================================\n");
			}
			else if (flagJugadores == 1 && flagMantenimiento1 == 0)
			{
				printf("\n--------------------------------------------------------------------\nerror: primero ingrese costos de mantenimiento\n--------------------------------------------------------------------\n");
			}
			else if(flagJugadores == 0 && flagMantenimiento1 == 1)
			{
				printf("\n--------------------------------------------------------------------\nerror: primero ingrese jugadores\n--------------------------------------------------------------------\n");
			}
			else if(flagJugadores == 0 && flagMantenimiento1 == 0)
			{
				printf("\n--------------------------------------------------------------------\nerror: primero ingrese costos de mantenimiento e ingrese jugadores\n--------------------------------------------------------------------\n");
			}
			break;
		case 4:
			if(flagCalculo == 1)
			{
				printf("\n==============================================\nInforme de resultados\n==============================================\n"
						"Porcentaje UEFA: %.2f\n"
						"Porcentaje CONMEBOL: %.2f\n"
						"porcentaje CONCACAF: %.2f\n"
						"porcentaje AFC: %.2f\n"
						"porcentaje OFC: %2.f\n"
						"porcentaje CAF: %2.f\n",promedioUEFA,promedioCONMEBOL,promedioCONCACAF,promedioAFC,promedioOFC,promedioCAF);
				if(flagAumento == 1)
				{
					printf("el costo de mantenimiento era de %d y recibio un aumento de %d,"
							"su nuevo valor es de: %d\n", mantenimientoTotal, aumento,mantenimientoTotalMod);
				}
				else
				{
					printf("el costo de mantenimiento es: %d\n", mantenimientoTotal);
				}
			}
			else
			{
				printf("\n----------------------------------\nprimero realice los calculos\n----------------------------------\n");
			}
			break;
		case 5:
			salir = 1;
			printf("programa finalizado\n");
			break;
		}

	}while(salir!=1);

	return EXIT_SUCCESS;
}
