/*
 ============================================================================
Nombre del alumno: De Nardo Lucas
División 1°F

Tp n°1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bibliotecaCalculos.h"
#include "bibliotecaTomaDeDatos.h"

#define INTERES 25
#define DESCUENTO 10
#define BTC 4538061.30


int main(void) {

	float kilometros;
	float precioAerolineas;
	float precioLatam;
	int opcion;
	char respuesta;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBtcLatam;
	float precioBtcAerolineas;
	float precioPorKmLatam;
	float precioPorKmAerolineas;
	float diferenciaPrecios;
	int flagKilometros;
	int flagIngresoPreciosLatam;
	int flagIngresoPreciosAerolineas;
	int flagReset = 1;
	int flagPreciosCalculadosLatam;
	int flagPreciosCalculadosAerolineas;


	setbuf(stdout, NULL);

	do{

		if(flagReset == 1)
		{
			flagKilometros=0;
			flagIngresoPreciosAerolineas=0;
			flagIngresoPreciosLatam=0;
			flagPreciosCalculadosLatam = 0;
			flagPreciosCalculadosAerolineas= 0;
			kilometros= 0;
			precioAerolineas=0;
			precioLatam=0;
			flagReset = 0;
		}


		system("cls");
		printf("*****************************MENU PRINCIPAL*****************************\n\n");
		printf("1. Ingresar Kil%cmetros (km = %.1f)\n", 162, kilometros);
		printf("2. Ingresar precio de vuelos (Aerol%cneas = $%.2f y Latam = $%.2f)\n", 162, precioAerolineas, precioLatam);
		printf("3. Calcular los costos\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");

		opcion = tomarEntero("\nElija una opcion: ", "ERROR Ingrese una opcion valida", "Agoto el numero de intentos\n\nEl programa se cerrara\n\n", 1, 6, 3);

		switch(opcion)
		{
			case 0:
				respuesta = 's';
				break;
			case 1:
				kilometros = tomarFlotante("Ingrese la cantidad de kilometros: ", "ERROR. Ingrese una cantidad valida(Entre 1 y 25000)","Agoto el numero de intentos\n\nVolviendo al menu principal...\n\n", 1, 30000, 3);
				if(kilometros != 0)
				{
					flagKilometros=1;
					flagPreciosCalculadosAerolineas = 0;
					flagPreciosCalculadosLatam = 0;
				}
				break;
			case 2:
				if(flagKilometros == 1)
				{
					do
					{
						system("cls");
						printf("*****************************MENU DE PRECIOS*****************************\n\n");
						printf("1) Cargar Precio Aerolineas($%.2f)\n", precioAerolineas);
						printf("2) Cargar Precio Latam($%.2f)\n", precioLatam);
						printf("3) Volver\n");

						opcion = tomarEntero("\nElija una opcion: ", "ERROR Ingrese una opcion valida", "Agoto el numero de intentos\n\nVolviendo al menu principal...\n\n", 1, 3, 3);

						switch(opcion)
						{
							case 0:
								opcion = 3;
								break;
							case 1:
								precioAerolineas = tomarFlotante("\nIngrese el precio de Aerolineas: $", "\nERROR Ingrese un precio valido(Entre 0 y 3M): ","Agoto el numero de intentos\n\nReiniciando Menu De Precios...\n\n" ,1 , 3000000, 3);
								if (precioAerolineas > 0)
								{
									flagIngresoPreciosAerolineas=1;
									flagPreciosCalculadosAerolineas = 0;
								}
								else
								{
									flagIngresoPreciosAerolineas=0;
								}
								break;
							case 2:
								precioLatam = tomarFlotante("\nIngrese el precio de Latam: $","\nERROR Ingrese un precio valido(Entre 0 y 3M): ", "Agoto el numero de intentos\n\nReiniciando Menu De Precios...\n\n", 1, 3000000, 3);
								if (precioLatam > 0)
								{
									flagIngresoPreciosLatam=1;
									flagPreciosCalculadosLatam = 0;
								}
								else
								{
									flagIngresoPreciosLatam=0;
								}
								break;
							case 3:
								if(flagIngresoPreciosAerolineas == 0 && flagIngresoPreciosLatam == 0)
								{
									opcion = 4; //Para no romper el while.
									printf("\n\nDebe ingrear alguno de los precios para poder regresar al menu principal\n\n");
									system("pause");
								}
							break;

						}


					}while (opcion != 3);

				}
				else
				{
					printf("\nERROR. Primero deben ingresarse los kilometros.\n\n");
					system("pause");
				}

				break;

			case 3:

				if(flagIngresoPreciosAerolineas == 1 || flagIngresoPreciosLatam == 1)
				{

					if(flagIngresoPreciosAerolineas == 1)
					{
						precioDebitoAerolineas = calcularDescuento(precioAerolineas, DESCUENTO);
						precioCreditoAerolineas = calcularInteres(precioAerolineas, INTERES);
						precioBtcAerolineas = reglaDeTres(BTC, 1, precioAerolineas);
						precioPorKmAerolineas= reglaDeTres(kilometros, precioAerolineas, 1);


						flagPreciosCalculadosAerolineas = 1;

					}
					if(flagIngresoPreciosLatam == 1)
					{
						precioDebitoLatam = calcularDescuento(precioLatam, DESCUENTO);
						precioCreditoLatam = calcularInteres(precioLatam, INTERES);
						precioBtcLatam = reglaDeTres(BTC, 1, precioLatam);
						precioPorKmLatam = reglaDeTres(kilometros, precioLatam, 1);

						flagPreciosCalculadosLatam = 1;
					}

					if(flagPreciosCalculadosAerolineas == 1 && flagPreciosCalculadosLatam == 1)
					{
						diferenciaPrecios = diferenciaFlotantes(precioLatam, precioAerolineas);
					}

					printf("\nCalculos realizados.\n\n");
					system("pause");
				}
				else
				{
					printf("\nDebe ingresar alguno de los precios para poder calcular los costos.\n\n");
					system("pause");
				}


				break;
			case 4:
				if(flagPreciosCalculadosAerolineas == 1 || flagPreciosCalculadosLatam == 1)
				{
					system("cls");
					printf("*****************************INFORME DE RESULTADOS*****************************");
					printf("\nKMs Ingresados: %.2fkm\n\n", kilometros);
					if (flagPreciosCalculadosLatam == 1)
					{
						printf("Precio Latam: $%.2f\n", precioLatam);
						printf("a) Precio con tarjeta de d%cbito: $%.2f\n", 130, precioDebitoLatam);
						printf("b) Precio con tarjeta de cr%cdito: $%.2f\n",130, precioCreditoLatam);
						printf("c) Precio pagando con Bitcoin: %fBTC\n", precioBtcLatam);
						printf("d) Precio unitario: %.2f\n", precioPorKmLatam);
					}
					if(flagPreciosCalculadosAerolineas == 1)
					{
						printf("\nPrecio Aerolineas: $%.2f\n", precioAerolineas);
						printf("a) Precio con tarjeta de d%cbito: $%.2f\n", 130, precioDebitoAerolineas);
						printf("b) Precio con tarjeta de cr%cdito: $%.2f\n",130, precioCreditoAerolineas);
						printf("c) Precio pagando con Bitcoin: %fBTC\n", precioBtcAerolineas);
						printf("d) Precio unitario: %.2f\n", precioPorKmAerolineas);
					}
					if(flagPreciosCalculadosAerolineas == 1 && flagPreciosCalculadosLatam == 1)
					{
						printf("\nLa diferencia de precios es: $%.2f\n\n", diferenciaPrecios);
					}

					system("pause");
					flagReset = 1;
				}
				else
				{
					printf("\nSe deben calcular los costos antes de mostrarlos...\n\n");
					system("pause");
				}
				break;
			case 5:
				kilometros = 7090;
				precioAerolineas = 162965;
				precioLatam = 159339;
				precioDebitoLatam = calcularDescuento(precioLatam, DESCUENTO);
				precioDebitoAerolineas = calcularDescuento(precioAerolineas, DESCUENTO);

				precioCreditoLatam = calcularInteres(precioLatam, INTERES);
				precioCreditoAerolineas = calcularInteres(precioAerolineas, INTERES);

				precioBtcLatam = reglaDeTres(precioLatam, BTC, 1);
				precioBtcAerolineas=reglaDeTres(precioAerolineas, BTC, 1);

				precioPorKmLatam = reglaDeTres(kilometros, precioLatam, 1);
				precioPorKmAerolineas= reglaDeTres(kilometros, precioAerolineas, 1);

				diferenciaPrecios = diferenciaFlotantes(precioLatam, precioAerolineas);
				system("cls");
				printf("*****************************INFORME DE RESULTADOS*****************************");
				printf("\nKMs Ingresados: %.2fkm\n\n", kilometros);
				printf("Precio Latam: $%.2f\n", precioLatam);
				printf("a) Precio con tarjeta de d%cbito: $%.2f\n", 130, precioDebitoLatam);
				printf("b) Precio con tarjeta de cr%cdito: $%.2f\n",130, precioCreditoLatam);
				printf("c) Precio pagando con Bitcoin: %fBTC\n", precioBtcLatam);
				printf("d) Precio unitario: %.2f\n", precioPorKmLatam);
				printf("\nPrecio Aerolineas: $%.2f\n", precioAerolineas);
				printf("a) Precio con tarjeta de d%cbito: $%.2f\n", 130, precioDebitoAerolineas);
				printf("b) Precio con tarjeta de cr%cdito: $%.2f\n",130, precioCreditoAerolineas);
				printf("c) Precio pagando con Bitcoin: %fBTC\n", precioBtcAerolineas);
				printf("d) Precio unitario: %.2f\n", precioPorKmAerolineas);
				printf("\nLa diferencia de precios es: $%.2f\n\n", diferenciaPrecios);
				system("pause");
				flagReset = 1;
				break;
			case 6:
				respuesta = validarRespuesta("Seguro que desea salir? (s/n): ", "ERROR. Ingrese 's' o 'n': ");
				break;

		}

	}while(respuesta != 's');


	return 0;
}





