/*
 * bibliotecaCalculos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaCalculos.h"

/**
 * Esta función devuelve el porcentaje que le indiquemos de un número.
 * @param numeroDestino Este es el número del cual sacaremos el porcentaje.
 * @param porcentaje Este es el porcentaje que deseamos sacar.
 * @return Devuelve un dato de tipo float con el resultado.
 */
float calcularPorcentaje (float numeroDestino, float porcentaje)
{
	float total;

	total = numeroDestino * porcentaje /100;
	return total;
}

/**
 * Esta función calculará el interes que le indiquemos de un número y se lo SUMARÁ.
 * @param numeroDestino Número al que deseamos hacerle el interés.
 * @param interes Porcentaje de interes que deseamos.
 * @return Devuelve un dato de tipo float con el interés añadido.
 */
float calcularInteres(float numeroDestino, float interes)
{
	float numeroConInteres;

	numeroConInteres = calcularPorcentaje(numeroDestino, interes) + numeroDestino;

	return numeroConInteres;
}

/**
 * Esta función calculará el descuento que le indiquemos de un número y se lo RESTARÁ.
 * @param numeroDestino Número al que deseamos hacer el descuento.
 * @param interes Porcentaje de descuento que deseamos.
 * @return Devuelve un dato de tipo float con el descuento hecho.
 */
float calcularDescuento(float numeroDestino, float interes)
{
	float numeroConInteres;

	numeroConInteres = numeroDestino - calcularPorcentaje(numeroDestino, interes);

	return numeroConInteres;
}

/**
 * Esta función es una regla de tres que nos permite averiguar una incognita.
 * @param numeroUno Por este número se van a dividir la multiplicación de los otros dos datos.
 * @param numeroDos Este número se multiplicara por la variable numeroTres.
 * @param numeroTres Este número se multiplicara por la variable numeroDos.
 * @return Devuelve un dato tipo float con el resultado de la incognita
 */
float reglaDeTres(float numeroUno,float numeroDos, float numeroTres)
{
	float resultado;

	resultado = numeroDos * numeroTres / numeroUno;

	return resultado;
}

/**
 * Esta es una función que se encargar de sacar la diferencia entre dos números,
 * verificando antes cual es mayor para así no retornar un resultado negativo
 * @param numeroUno	Primer número.
 * @param numeroDos Segundo número.
 * @return Devuelve un dato tipo float con resultado de la diferencia.
 */
float diferenciaFlotantes(float numeroUno, float numeroDos)
{
	float diferencia;


	if(numeroUno > numeroDos)
	{
		diferencia = numeroUno - numeroDos;
	}
	else
	{
		diferencia = numeroDos - numeroUno;
	}

	return diferencia;
}

