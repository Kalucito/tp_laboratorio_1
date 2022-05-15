/*
 * eTipoDePasajero.h
 *
 *  Created on: 13 may. 2022
 *      Author: Lucas
 */

#ifndef ETIPODEPASAJERO_H_
#define ETIPODEPASAJERO_H_

typedef struct
{
	int typePassenger;
	char descripcion[51];
}eTipoDePasajero;


void llenarTipos(eTipoDePasajero* tipos, int len);
void listarTipos (eTipoDePasajero* tipos, int len);



#endif /* ETIPODEPASAJERO_H_ */
