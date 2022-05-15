/*
 * eStatusFlight.c
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
 * @fn void llenarEstadosDeVuelo(eEstadoDeVuelo*, int)
 * @brief Hardcodea los estado de pasajeros.
 * @param estados Recibe la estructura de estado de pasajeros por referencia.
 * @param len Longitud de la estructura de estado de pasajeros.
 */
void llenarEstadosDeVuelo(eEstadoDeVuelo* estados, int len)
{
	int i;
	eEstadoDeVuelo lista[3] = {
								{0, "Activo"},
								{1, "Demorado"},
								{2, "Cancelado"}
								};

	for(i = 0; i < len; i++)
	{
		estados[i] = lista[i];
	}


}
/**
 * @fn void listarEstados(eEstadoDeVuelo*, int)
 * @brief  Lista los tipos de pasajeros disponibles con sus respectivos ids.
 * @param estados Recibe la estructura de estado de pasajeros por referencia.
 * @param len Longitud de la estructura de estado de pasajeros.
 */
void listarEstados (eEstadoDeVuelo* estados, int len)
{
	int i;

	printf("\n----------------------------\nId\tEstados De vuelo\n----------------------------");

	for(i = 0; i < len; i++)
	{
		printf("\n%d\t%s\n", estados[i].statusFlight, estados[i].descripcion);
	}

	printf("----------------------------\n");

}

