/*
 * ePassenger.c
 *
 *  Created on: 8 may. 2022
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "eStatusFlight.h"
#define LIBRE 1
#define OCUPADO 0
#define LEN_NAME 51
/**
 * @fn int initPassengers(ePassenger[], int)
 * Esta funcion inicializa el array de pasajeros como LIBRES (en 0).
 * @param pasajeros Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros.
 * @return Devuelve -1 para error y 0 si funciono
 */
int initPassengers(ePassenger pasajeros[], int len)
{
	int i;
	int ret = -1;

	if (pasajeros != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			pasajeros[i].isEmpty = LIBRE;
		}
		ret = 0;
	}

	return ret;
}
/**
 * @fn int buscarLibre(ePassenger[], int)
 * @brief Busca un espacio libre en la estructura (array) de pasajeros.
 * @param pasajeros Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros.
 * @return retorna el indice libre o -1 si no hay espacio
 */
int buscarLibre(ePassenger pasajeros[], int len)
{
	int indice = -1;
	int i;

	for(i = 0; i < len; i++)
	{
		if(pasajeros[i].isEmpty == LIBRE)
		{
			indice = i;
			break;
		}
	}

	return indice;
}
/**
 * @fn int addPassengers(ePassenger*, int, int, char[], char[], float, int, int, char[], eTipoDePasajero[], int, eEstadoDeVuelo[], int)
 * @brief Toma todos los datos de un pasajero.
 * @param pasajeros Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros.
 * @param id Variable donde se guarda el id.
 * @param name Variable donde se guarda el name.
 * @param lastName Variable donde se guarda el apellido.
 * @param price Variable donde se guarda el precio
 * @param typePassengers Variable donde se guarda el id de tipo de pasajero
 * @param statusFlight Variable donde se guarda el id el estado del vuelo.
 * @param flycode Variable donde se guarda el codigo de vuelo.
 * @param listaTipos Recibe la estructura de tipos.
 * @param lenTipos Longitud del array de tipos.
 * @param listaEstados Recibe la estructura de estados de pasajeros.
 * @param lenEstados Longitud del array de estados.
 * @return Devuelve -1 si algo falla o 0 si se pudieron tomar TODOS los datos.
 */
int addPassengers(ePassenger* pasajeros, int len, int id, char name[], char lastName[], float price, int typePassengers, int statusFlight, char flycode[], eTipoDePasajero listaTipos[],int lenTipos, eEstadoDeVuelo listaEstados[], int lenEstados)
{
	int indice;
	int ret = -1;
	int flag = 1;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	int typePassengersAux;
	int statusFlightAux;
	char flycodeAux[10];

	indice = buscarLibre(pasajeros, len);

	if(indice != -1 && pasajeros != NULL && len > 0)
	{


		if(tomarString(nameAux, LEN_NAME, "\nIngrese su nombre/s: ", "\nERROR. Ingrese un nombre v%clido\n", 3) == 0)
		{
			if (tomarString(lastNameAux, LEN_NAME, "\nIngrese su apellido/s: ", "\nERROR. Ingrese un nombre v%clido\n", 3) == 0)
			{
				listarTipos(listaTipos, lenTipos);
				if(tomarEntero(&typePassengersAux, "\nIngrese el id del tipo de pasajero que desea: ", "\nERROR. Id no valido.\n", 0, 2, 3) == 0)
				{
					listarEstados(listaEstados, lenEstados);
					if(tomarEntero(&statusFlightAux, "\nIngrese el id del estado de su vuelo: ", "\nERROR id no valido.\n", 0, 2, 3)==0)
					{
						if(tomarFlotante(&priceAux, "\nIngrese el precio del vuelo: ", "\nERROR. Precio no valido(1-500000)\n", 1, 500000, 3) == 0)
						{
							if(validarFlycode(flycodeAux, 10, "\nIngrese el codigo de vuelo : ", "\nERROR. Codigo no valido(0-10 caracteres/solo letras y numeros)\n", 3) != 0)
							{
								flag = 0;
							}
						}
					}
				}
			}
		}

		if(flag == 1)
		{
			id = incrementarPasajerosId();
			pasajeros[indice].idPassenger = id;
			strncpy(pasajeros[indice].name, nameAux, sizeof(pasajeros[indice].name));
			strncpy(pasajeros[indice].lastName, lastNameAux, sizeof(pasajeros[indice].lastName));
			pasajeros[indice].typePassenger = typePassengersAux;
			pasajeros[indice].statusFlight = statusFlightAux;
			pasajeros[indice].price = priceAux;
			strncpy(pasajeros[indice].flycode, flycodeAux, sizeof(pasajeros[indice].flycode));
			pasajeros[indice].isEmpty = OCUPADO;

			ret = 0;

			printf("\n\nCARGA EXITOSA!!!!\n\n");
			system("pause");
		}
		else
		{
			system("cls");
			printf("Agoto el numero de intentos. Volviendo al menu principal.\n\n");
			system("pause");
		}
	}

	return ret;

}
/**
 * @fn int printPassengers(ePassenger*, int, eEstadoDeVuelo*, int, eTipoDePasajero*, int)
 * @brief Imprime todos los pasajeros que esten dados de ALTA.
 * @param list Recibe la estructura de pasajeros.
 * @param length Longitud del array de pasajeros.
 * @param estados Recibe la estructura de estados de pasajeros.
 * @param lenEstados Longitud del array de estados.
 * @param tipos Recibe la estructura de tipos.
 * @param lenTipos Longitud del array de tipos.
 * @return Devuelve 0 por defecto.
 */
int printPassengers(ePassenger* list, int length, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos)
{
	int i;
	int j;
	int k;
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	printf("|Id Pasajero\t|Nombre\t\t|Apellido\t|Precio de Vuelo|Tipo de Pasajero|Codigo de Vuelo|Estado del Vuelo|\n");
	printf("-------------------------------------------------------------------------------------------------------------------");

	for(i = 0; i < length; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			printf("\n|%-15d", list[i].idPassenger);
			printf("|%-15s", list[i].name);
			printf("|%-15s", list[i].lastName);
			printf("|%-15.2f", list[i].price);

			for( j = 0; j < lenTipos; j++)
			{
				if(list[i].typePassenger == tipos[j].typePassenger)
				{
					printf("|%-16s", tipos[j].descripcion);
					break;
				}
			}
			printf("|%-15s", list[i].flycode);

			for( k = 0; k < lenEstados; k++)
			{
				if(list[i].statusFlight == estados[k].statusFlight)
				{
					printf("|%-16s|", estados[k].descripcion);
					break;
				}
			}
		}
	}
	printf("\n-------------------------------------------------------------------------------------------------------------------");


	return 0;
}
/**
 * @fn int findPassengerById(ePassenger*, int, int)
 * @brief Busca un pasajero recibiendo como parámetro de búsqueda su Id.
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros.
 * @param id Recibe id de pasajero a buscar.
 * @return Devuelve 0 por defecto.
 */
int findPassengerById(ePassenger* list, int len,int id)
{
	int indice = -1;
	int i;

	for(i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idPassenger == id)
		{
			indice = i;
			break;
		}
	}

	return indice;
}
/**
 * @fn int removePassenger(ePassenger*, int, int)
 * @brief Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros.
 * @param id Recibe id de pasajero a eliminar.
 * @return Devuelve -1 si no se pudo realizar o caso contrario un 0.
 */
int removePassenger(ePassenger* list, int len, int id)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].idPassenger == id)
			{
				list[i].isEmpty = LIBRE;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
/**
 * @fn int modificarPasajero(ePassenger*, int, eEstadoDeVuelo*, int, eTipoDePasajero*, int)
 * @brief Permite modificar ciertos objetos de un pasajero.
 * @param list Recibe la estructura de pasajeros.
 * @param length Longitud del array de pasajeros.
 * @param estados Recibe la estructura de estados de pasajeros.
 * @param lenEstados Longitud del array de estados.
 * @param tipos Recibe la estructura de tipos.
 * @param lenTipos Longitud del array de tipos.
 * @return Devuelve -1 si no se pudo realizar o caso contrario un 0.
 */
int modificarPasajero(ePassenger* list, int length, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos)
{
	int ret=-1;
	int id;
	int opcion;
	int index;

	printPassengers(list, length, estados, lenEstados, tipos, lenTipos);
	tomarEntero(&id, "\nIngrese el id del pasajero que desea modificar: ", "\nERROR. Id no valido.\n", 1000, 4000, 3);

	index = findPassengerById(list, length, id);

	if(index != -1)
	{
		do
		{
			system("cls");
			printf("*****************************MENU MODIFICAR*****************************\n" );
			printf("\n1.Nombre\n");
			printf("2.Apellido\n");
			printf("3.Precio\n");
			printf("4.Tipo de pasajero\n");
			printf("5.Codigo de Vuelo\n");
			printf("6.Salir\n");

			if(tomarEntero(&opcion, "\nQue desea modificar?", "\nERROR. Opcion no valida\n", 1, 6, 3) != 0)
			{
				printf("\n\nAgoto el numero de intentos.\n\n");
				system("pause");
				fflush(stdin);
			}


			switch(opcion)
			{
			case 1:
				tomarString(list[index].name, LEN_NAME, "\nIngrese el nuevo nombre: ", "\nERROR. Nombre no valido.\n", 3);
				ret = 0;
				break;
			case 2:
				tomarString(list[index].lastName, LEN_NAME, "\nIngrese el nuevo apellido: ", "\nERROR. Apellido no valido.\n", 3);
				ret = 0;
				break;
			case 3:
				tomarFlotante(&list[index].price, "\nIngrese el nuevo precio: ", "\nERROR. Precio no valido.\n", 1, 500000, 3);
				ret = 0;
				break;
			case 4:
				listarTipos(tipos, lenTipos);
				tomarEntero(&list[index].typePassenger, "\nIngrese el id del nuevo tipo de pasajero: ", "\nERROR. Tipo de pasajero no valido.\n", 0, 2, 3);
				ret = 0;
				break;
			case 5:
				validarFlycode(list[index].flycode, 10, "\nIngrese el nuevo codigo de vuelo: ", "\nERROR. Codigo ingresado no valido.\n", 3);
				ret = 0;
				break;
			case 6:
				if(!verificarRespuesta())
				{
					opcion= -1;
				}
				break;
			}

		}while(opcion != 6);
	}
	else
	{
		printf("\nERROR. No se encontro el id...\n\n");
		system("pause");
	}


	return ret;
}
/**
 * @fn int bajaLogica(ePassenger*, int, eEstadoDeVuelo*, int, eTipoDePasajero*, int)
 * @brief Realiza una baja logica, estableciendo como LIBRE el isEmpty de un pasajero.
 * @param list Recibe la estructura de pasajeros.
 * @param length Longitud del array de pasajeros.
 * @param estados Recibe la estructura de estados de pasajeros.
 * @param lenEstados Longitud del array de estados.
 * @param tipos Recibe la estructura de tipos.
 * @param lenTipos Longitud del array de tipos.
 * @return Devuelve -1 si no se pudo realizar o caso contrario un 0.
 */
int bajaLogica (ePassenger* list,  int length, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos)
{
	int ret = -1;
	int id;

	printPassengers(list, length, estados, lenEstados, tipos, lenTipos);
	tomarEntero(&id, "\nIngrese el pasajero que desea eliminar: ", "\nERROR. numero no valido.\n", 1000, 4000, 3);

	if(findPassengerById(list, length, id) != -1)
	{
		removePassenger(list, length, id);
		ret = 0;
	}
	else
	{
		printf("\nERROR. No se encontro el id...\n\n");
		system("pause");
	}

	return ret;
}
/**
 * @fn void cargaForzada(ePassenger*, int)
 * @brief Realiza una carga forzada de 5 pasajeros.
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros.
 */
void cargaForzada(ePassenger* list, int len)
{
	int i;
	ePassenger pasajeros[5] = {
								{incrementarPasajerosId(), "Alejandro", "Fernandez", 20000, "98SDVS", 0, 2, OCUPADO},
								{incrementarPasajerosId(), "Lucas", "De Nardo", 2231.3, "IOMIO12", 2, 1, OCUPADO},
								{incrementarPasajerosId(), "Cristian", "Mendez", 18723, "ALKJ2", 1, 0, OCUPADO},
								{incrementarPasajerosId(), "Lautaro", "Martinez", 1923, "JI123", 2, 1, OCUPADO},
								{incrementarPasajerosId(), "Julian", "Carraro", 12093, "KJL12M", 0, 0, OCUPADO}
								};

	for(int i = 0; i< len; i++)
	{
		removePassenger(list, len, i);
	}

	if(list != NULL)
	{
		for(i = 0; i < 5; i++)
		{
			list[i] = pasajeros[i];
		}
	}
	system("cls");
	printf("Carga Realizada con exito.\n\n");
	system("pause");

}
/**
 * @fn int sortPassengers(ePassenger*, int, int)
 * @brief Ordena los pasajeros por el apellido y si son iguales por tipo de pasajero (segun el id).
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros.
 * @param order Si recibe 1 ordena de forma ascendente y si recibe 0 de forma descendente.
 * @return Retorna -1 si algo fallo o 0 si se pudo realizar.
 */
int sortPassengers(ePassenger* list, int len, int order)
{
	int ret;
	ePassenger aux;

	if(len > 0 && list != NULL)
	{
		if(order == 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == OCUPADO)
				{
					for(int j = 1; j < len; j++)
					{
						if(stricmp(list[i].lastName, list[j].lastName) != 0)
						{
							if(stricmp(list[i].lastName, list[j].lastName) > 0)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
						else
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
			ret = 0;
		}
		else
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == OCUPADO)
				{
					for(int j = 1; j < len; j++)
					{
						if(stricmp(list[i].lastName, list[j].lastName) != 0)
						{
							if(stricmp(list[i].lastName, list[j].lastName) < 0)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
						else
						{
							if(list[i].typePassenger < list[j].typePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
			ret = 0;
		}
	}

	return ret;
}
/**
 * @fn int sortPassengersByCode(ePassenger*, int, int)
 * @brief Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros
 * @param order Si recibe 1 ordena de forma ascendente y si recibe 0 de forma descendente.
 * @return Retorna -1 si algo fallo o 0 si se pudo realizar.
 */
int sortPassengersByCode(ePassenger* list, int len, int order)
{
	int ret;
	ePassenger aux;

	if(len > 0 && list != NULL)
	{
		if(order == 0)
		{
			for(int i = 0; i < len+1; i++)
			{
				if(list[i].isEmpty == OCUPADO)
				{
					for(int j = 1; j < len; j++)
					{
						if(stricmp(list[i].flycode, list[j].flycode) < 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			ret = 0;
		}
		else
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == OCUPADO)
				{
					for(int j = 1; j < len; j++)
					{
						if(stricmp(list[i].flycode, list[j].flycode) > 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			ret = 0;
		}
	}

	return ret;
}
/**
 * @fn void informar(ePassenger*, int, eEstadoDeVuelo*, int, eTipoDePasajero*, int)
 * @brief Esta funcion tiene multiples opciones para informar diferentes cosas.
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros
 * @param estados Recibe la estructura de estados de pasajeros.
 * @param lenEstados Longitud del array de estados.
 * @param tipos Recibe la estructura de tipos.
 * @param lenTipos Longitud del array de tipos.
 */
void informar(ePassenger* list,  int len, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos)
{
	int opcion;
	int subOpcion;
	int subOpcion2;
	int subOpcion3;
	float totalPrecios;
	float promedioPrecio;
	int contadorEncimaPromedio;

	do
	{
		opcion= subMenuInformar();

		switch(opcion)
		{
		case 1:
			do
			{
				printf("1. Orden Descendete\n");
				printf("2. Orden Ascendente\n");
				printf("3.Salir");

				tomarEntero(&subOpcion, "\nElija una opcion: ", "\n\nERROR. Opcion no valida\n", 1, 3, 3);

				switch(subOpcion)
				{
				case 1:
					printf("Orden Descendete\n\n");
					sortPassengers(list, len, 0);
					printPassengers(list, len, estados, lenEstados, tipos, lenTipos);
					printf("\n\n");
					system("pause");
					break;
				case 2:
					printf("Orden Ascendente\n\n");
					sortPassengers(list, len, 1);
					printPassengers(list, len, estados, lenEstados, tipos, lenTipos);
					printf("\n\n");
					system("pause");
					break;
				case 3:
					break;
				}

			}while(subOpcion != 3);

			break;
		case 2:
			totalPrecios = precioTotal(list, len);
			promedioPrecio = sacarPromedio(list, len);
			contadorEncimaPromedio = encimaDelPromedio(list, len);
			system("cls");
			printf("La suma de precios total es: %.2f\n", totalPrecios);
			printf("El promedio de precios es: %.2f\n", promedioPrecio);
			printf("Hay %d precios por encima del promedio.\n\n", contadorEncimaPromedio);
			system("pause");
			break;
		case 3:
			do
			{
				system("cls");
				printf("1. Listar por codigo de vuelo.\n");
				printf("2. Listar vuelos activos.\n");
				printf("3. Salir.");

				tomarEntero(&subOpcion2, "\nElija una opcion: ", "\n\nERROR. Opcion no valida\n", 1, 3, 3);

				switch(subOpcion2)
				{
				case 1:

					printf("\n\n1. Orden Ascendente\n");
					printf("2. Orden Descendete\n");
					tomarEntero(&subOpcion3, "\nElija una opcion: ", "\n\nERROR. Opcion no valida\n", 1, 3, 3);

					switch(subOpcion3)
					{


					case 1:
						sortPassengersByCode(list, len, 0);
						printPassengers(list, len, estados, lenEstados, tipos, lenTipos);
						printf("\n\n");
						system("pause");
						break;
					case 2:
						sortPassengersByCode(list, len, 1);
						printPassengers(list, len, estados, lenEstados, tipos, lenTipos);
						printf("\n\n");
						system("pause");
						break;


					}
					break;


				case 2:
					listarVuelosActivos(list, len, estados, lenEstados, tipos, lenTipos);
					printf("\n\n");
					system("pause");
					break;


				case 3:
					break;
				}
			}
			while(subOpcion2 != 3);
			break;

		case 4:
			if(!verificarRespuesta())
			{
				opcion= -1;
			}
			break;
		}
	}
	while(opcion != 4);

}
/**
 * @fn float sacarPromedio(ePassenger*, int)
 * @brief Esta funcion saca el promedio de precios del total de pasaron de ALTA.
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros
 * @return Retorna el promedio realizado.
 */
float sacarPromedio(ePassenger* list,  int len)
{
	float promedio;
	int contador=0;
	float totalPrecios;

	totalPrecios= precioTotal(list, len);

	for(int i=0; i< len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			contador++;
		}
	}

	promedio= totalPrecios/contador;

	return promedio;
}
/**
 * @fn float precioTotal(ePassenger*, int)
 * @brief Esta funcion saca el total sumado de precios de alta.
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros
 * @return Retorna el Precio Total.
 */
float precioTotal(ePassenger* list,  int len)
{
	float precioTotal=0;

	for(int i = 0; i< len;i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			precioTotal += list[i].price;
		}
	}

	return precioTotal;
}
/**
 * @fn int encimaDelPromedio(ePassenger*, int)
 * @brief Cuenta la cantidad de pasajeros con precios por encima del promedio.
 * @param list Recibe la estructura de pasajeros.
 * @param len Longitud del array de pasajeros
 * @return Retorna la cantidad de pasajeros encima del promedio.
 */
int encimaDelPromedio(ePassenger* list,  int len)
{
	int contador=0;
	float promedio;

	promedio = sacarPromedio(list, len);

	for(int i=0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].price > promedio)
		{
			contador++;
		}
	}

	return contador;
}
/**
 * @fn void listarVuelosActivos(ePassenger*, int, eEstadoDeVuelo*, int, eTipoDePasajero*, int)
 * @brief Lista los vuelos que tienen como estado activos y que estan de alta.
 * @param list Recibe la estructura de pasajeros.
 * @param length Longitud del array de pasajeros
 * @param estados Recibe la estructura de estados de pasajeros.
 * @param lenEstados Longitud del array de estados.
 * @param tipos Recibe la estructura de tipos.
 * @param lenTipos Longitud del array de tipos.
 */
void listarVuelosActivos(ePassenger* list, int length, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos)
{
	int flag = 0;

	for(int i=0; i < length; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].statusFlight == 0)
		{
			flag = 1;
			printf("\n|%-15d", list[i].idPassenger);
			printf("|%-15s", list[i].name);
			printf("|%-15s", list[i].lastName);
			printf("|%-15.2f", list[i].price);

			for(int j = 0; j < lenTipos; j++)
			{
				if(list[i].typePassenger == tipos[j].typePassenger)
				{
					printf("|%-16s", tipos[j].descripcion);
					break;
				}
			}
			printf("|%-15s", list[i].flycode);

			for(int k = 0; k < lenEstados; k++)
			{
				if(list[i].statusFlight == estados[k].statusFlight)
				{
					printf("|%-16s|", estados[k].descripcion);
					break;
				}
			}
		}
	}
	if(flag == 0)
	{
		printf("\nNo hay vuelos activos.\n");
	}
}
