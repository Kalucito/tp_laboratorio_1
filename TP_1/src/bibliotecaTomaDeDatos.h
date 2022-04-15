/*
 * bibliotecaTomaDeDatos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Lucas
 */

#ifndef BIBLIOTECATOMADEDATOS_H_
#define BIBLIOTECATOMADEDATOS_H_

char tomarLetraMinuscula(void);
char validarRespuesta(char mensaje[], char mensajeError[]);
float tomarFlotante (char mensaje[], char mensajeError[], char mensajeSinReintentos[], float min, float max, int intentos);
int tomarEntero (char mensaje[], char mensajeError[], char mensajeSinReintentos[], int min, int max, int intentos);


#endif /* BIBLIOTECATOMADEDATOS_H_ */
