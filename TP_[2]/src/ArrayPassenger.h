

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "eTipoDePasajero.h"
#include "eStatusFlight.h"
#include "eStatusFlight.h"

typedef struct
{
	int idPassenger;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

int buscarLibre(ePassenger pasajeros[], int len);
int initPassengers(ePassenger pasajeros[], int len);
int addPassengers(ePassenger* pasajeros, int len, int id, char name[], char lastName[], float price, int typePassengers, int statusFlight, char flycode[], eTipoDePasajero listaTipos[],int lenTipos, eEstadoDeVuelo listaEstados[], int lenEstados);
int printPassengers(ePassenger* list, int length, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos);
int findPassengerById(ePassenger* list, int len,int id);
int removePassenger(ePassenger* list, int len, int id);
int modificarPasajero(ePassenger* list, int length, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos);
int bajaLogica (ePassenger* list,  int length, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos);
void cargaForzada(ePassenger* list, int len);
int sortPassengers(ePassenger* list, int len, int order);
int sortPassengersByCode(ePassenger* list, int len, int order);
void informar(ePassenger* list,  int len, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos);
float precioTotal(ePassenger* list,  int len);
float sacarPromedio(ePassenger* list,  int len);
int encimaDelPromedio(ePassenger* list,  int len);
void listarVuelosActivos(ePassenger* list, int length, eEstadoDeVuelo* estados, int lenEstados, eTipoDePasajero* tipos, int lenTipos);
#endif /* ARRAYPASSENGER_H_ */
