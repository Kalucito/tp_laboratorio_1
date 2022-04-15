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
 * Esta funci�n devuelve el porcentaje que le indiquemos de un n�mero.
 * @param numeroDestino Este es el n�mero del cual sacaremos el porcentaje.
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
 * Esta funci�n calcular� el interes que le indiquemos de un n�mero y se lo SUMAR�.
 * @param numeroDestino N�mero al que deseamos hacerle el inter�s.
 * @param interes Porcentaje de interes que deseamos.
 * @return Devuelve un dato de tipo float con el inter�s a�adido.
 */
float calcularInteres(float numeroDestino, float interes)
{
	float numeroConInteres;

	numeroConInteres = calcularPorcentaje(numeroDestino, interes) + numeroDestino;

	return numeroConInteres;
}

/**
 * Esta funci�n calcular� el descuento que le indiquemos de un n�mero y se lo RESTAR�.
 * @param numeroDestino N�mero al que deseamos hacer el descuento.
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
 * Esta funci�n es una regla de tres que nos permite averiguar una incognita.
 * @param numeroUno Por este n�mero se van a dividir la multiplicaci�n de los otros dos datos.
 * @param numeroDos Este n�mero se multiplicara por la variable numeroTres.
 * @param numeroTres Este n�mero se multiplicara por la variable numeroDos.
 * @return Devuelve un dato tipo float con el resultado de la incognita
 */
float reglaDeTres(float numeroUno,float numeroDos, float numeroTres)
{
	float resultado;

	resultado = numeroDos * numeroTres / numeroUno;

	return resultado;
}

/**
 * Esta es una funci�n que se encargar de sacar la diferencia entre dos n�meros,
 * verificando antes cual es mayor para as� no retornar un resultado negativo
 * @param numeroUno	Primer n�mero.
 * @param numeroDos Segundo n�mero.
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

