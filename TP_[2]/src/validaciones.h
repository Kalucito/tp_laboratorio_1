/*
 * validaciones.h
 *
 *  Created on: 8 may. 2022
 *      Author: Lucas
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>

int tomarEntero (int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
int tomarString(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int reintentos);
short verificarRespuesta (void);
int tomarFlotante (float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
int validarFlycode(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int reintentos);
int incrementarPasajerosId();
int iniciarMenu (void);
int subMenuInformar(void);
#endif /* VALIDACIONES_H_ */
