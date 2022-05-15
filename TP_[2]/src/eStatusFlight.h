/*
 * eStatusFlight.h
 *
 *  Created on: 13 may. 2022
 *      Author: Lucas
 */

#ifndef ESTATUSFLIGHT_H_
#define ESTATUSFLIGHT_H_

typedef struct
{
	int statusFlight;
	char descripcion[51];
}eEstadoDeVuelo;

void llenarEstadosDeVuelo(eEstadoDeVuelo* estados, int len);
void listarEstados (eEstadoDeVuelo* estados, int len);

#endif /* ESTATUSFLIGHT_H_ */
