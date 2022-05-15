/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "validaciones.h"
#include "eTipoDePasajero.h"
#include "eStatusFlight.h"
#define LEN_PASSENGERS 2000
#define LEN_NAME 51
#define LEN_TIPOS 3
#define LEN_ESTADOS 3




int main(void) {

	setbuf(stdout, NULL);

	ePassenger pasajeros[LEN_PASSENGERS];
	eTipoDePasajero listaTipos[LEN_TIPOS];
	eEstadoDeVuelo listaEstados[LEN_ESTADOS];
	int opcion;
	int idPassenger=0;
	char name[51];
	char lastName[51];
	float price=0;
	char flycode[10];
	int typePassenger=0;
	int statusFlight=0;
	int contadorPasajeros = 0;

	initPassengers(pasajeros, LEN_PASSENGERS);
	llenarEstadosDeVuelo(listaEstados, LEN_TIPOS);
	llenarTipos(listaTipos, LEN_ESTADOS);

	do
	{

		opcion = iniciarMenu();


		switch(opcion)
		{
		case 1:
			if(addPassengers(pasajeros, LEN_PASSENGERS, idPassenger, name, lastName, price, typePassenger, statusFlight, flycode, listaTipos ,LEN_TIPOS, listaEstados, LEN_ESTADOS)==0)
			{
				contadorPasajeros++;
			}
			break;
		case 2:
			if(contadorPasajeros > 0)
			{
				if(modificarPasajero(pasajeros, LEN_PASSENGERS, listaEstados, LEN_ESTADOS, listaTipos, LEN_TIPOS) == 0)
				{
					printf("\nCambios guardados...\n\n");
					system("pause");
				}
			}
			else
			{
			printf("\nDebe dar de ALTA algun pasajero antes de acceder al menu de modificaciones.\n\n");
			system("pause");
			}
				break;
		case 3:
			if(contadorPasajeros > 0)
			{
				if(bajaLogica(pasajeros, LEN_PASSENGERS, listaEstados, LEN_ESTADOS, listaTipos, LEN_TIPOS)==0)
				{
					printf("\nEliminado con exito\n\n");
					contadorPasajeros--;
					system("pause");
				}
			}
			else
			{
				printf("\nDebe dar de ALTA algun pasajero antes de realizar una baja.\n\n");
				system("pause");
			}
				break;
		case 4:
			if(contadorPasajeros > 0)
			{
				informar(pasajeros, LEN_PASSENGERS, listaEstados, LEN_ESTADOS, listaTipos, LEN_TIPOS);
			}
				break;
		case 5:
			printf("\nSi realiza la carga forazada con datos cargados se pederan.\n");
			if(verificarRespuesta())
			{
				cargaForzada(pasajeros, LEN_PASSENGERS);
				contadorPasajeros = 5;
			}
				break;
		case 6:
			if(!verificarRespuesta())
			{
				opcion= -1;
			}
			break;
		}

	}while(opcion != 6);


	return 0;
}


