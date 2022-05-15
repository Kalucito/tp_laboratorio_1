/*
 * eTipoDePasajero.c
 *
 *  Created on: 13 may. 2022
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "ArrayPassenger.h"
#include "eTipoDePasajero.h"
#include "eStatusFlight.h"

/**
 * @fn void llenarTipos(eTipoDePasajero*, int)
 * @brief Hardcodea los tipos de pasajeros.
 * @param tipos Recibe la estructura de tipos de pasajeros por referencia.
 * @param len Longitud de la estructura de tipos de pasajeros.
 */
void llenarTipos(eTipoDePasajero* tipos, int len)
{
	int i;
	eTipoDePasajero lista[3] = {
								{0, "Clase Ejecutiva"},
								{1, "Primera Clase"},
								{2, "Economica"}
								};

	for(i = 0; i < len; i++)
	{
		tipos[i] = lista[i];
	}

}
/**
 * @fn void listarTipos(eTipoDePasajero*, int)
 * @brief  Lista los tipos de pasajeros disponibles con sus respectivos ids.
 * @param tipos Recibe la estructura de tipos de pasajeros por referencia.
 * @param len Longitud de la estructura de tipos de pasajeros.
 */
void listarTipos (eTipoDePasajero* tipos, int len)
{
	int i;

	printf("\n----------------------------\nId\tTipo De Pasajero\n----------------------------");

	for(i = 0; i < len; i++)
	{
		printf("\n%d\t%s\n", tipos[i].typePassenger, tipos[i].descripcion);
	}

	printf("----------------------------\n");

}


