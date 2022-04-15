/*
 * bibliotecaTomaDeDatos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bibliotecaTomaDeDatos.h"

/**
 * Esta funci�n muestra un mensaje para pedir una respuesta de 's' (si) o 'n' (no)
 * en minuscula y un mensaje de error en caso de un mal ingreso del usuario.
 * @param mensaje Indicamos el mensaje de pedido.
 * @param mensajeError Indicamos el mensaje de error.
 * @return Devuelve 's' o 'n'
 */
char validarRespuesta(char mensaje[], char mensajeError[])
{
    char ret;

	printf("%s", mensaje);
	ret = tomarLetraMinuscula();

	while(ret != 's' && ret != 'n')
	{
		printf("%s", mensajeError);
		ret = tomarLetraMinuscula();
	}

    return ret;
}

/**
 * Esta funcion pide una letra y la convierte en minuscula
 * @return devuelve una letra min�scula
 */
char tomarLetraMinuscula(void)
{
    char ret;

    fflush(stdin);
	scanf("%c", &ret);
	ret = tolower(ret);

	return ret;
}

/**
 * Esta funci�n toma un numero flotante y verifica que este dentro de un rango m�nimo y m�ximo, tambi�n
 * verifica el n�mero de intentos.
 * @param mensaje Indicamos el mensaje de pedido.
 * @param mensajeError Indicamos el mensaje de error en caso de un mal ingreso.
 * @param mensajeSinReintentos Indicamos un mensaje de agotamiento de intentos.
 * @param min Establecemos el m�nimo n�mero a ingresar.
 * @param max Establecemos el m�ximo n�mero a ingresar.
 * @param intentos Establecemos una cantidad de intentos m�xima para el usuario.
 * @return Devuelve un n�mero flotante dentro de los parametros indicados.
 */
float tomarFlotante (char mensaje[], char mensajeError[], char mensajeSinReintentos[], float min, float max, int intentos)
{
	float aux;
	float retorno;

	while(intentos > 0)
	{

		printf("%s", mensaje);

		if(scanf("%f", &aux) == 1)
		{
			if(aux >= min && aux <= max)
			{
				retorno = aux;
				break;
			}
		}

			printf("%s\n\n", mensajeError);
			intentos--;

	}

	if(intentos == 0)
	{
		retorno = 0;
		system("cls");
		printf("%s", mensajeSinReintentos);
		system("pause");
	}

	return retorno;
}

/**
 * Esta funci�n toma un numero entero y verifica que este dentro de un rango m�nimo y m�ximo, tambi�n
 * verifica el n�mero de intentos.
 * @param mensaje Indicamos el mensaje de pedido.
 *
 * @param mensajeError Indicamos el mensaje de error en caso de un mal ingreso.
 * @param mensajeSinReintentos Indicamos un mensaje de agotamiento de intentos.
 * @param min Establecemos el m�nimo n�mero a ingresar.
 * @param max Establecemos el m�ximo n�mero a ingresar.
 * @param intentos Establecemos una cantidad de intentos m�xima para el usuario.
 * @return Devuelve un n�mero entero dentro de los parametros indicados.
 */
int tomarEntero (char mensaje[], char mensajeError[], char mensajeSinReintentos[], int min, int max, int intentos)
{
	int aux;
	int retorno;

	while(intentos > 0)
	{

		printf("%s", mensaje);

		if(scanf("%d", &aux) == 1)
		{
			if(aux >= min && aux <= max)
			{
				retorno = aux;
				break;
			}
		}
			printf("%s\n\n", mensajeError);
			intentos--;

	}

	if(intentos == 0)
	{
		retorno = 0;
		system("cls");
		printf("%s", mensajeSinReintentos);
		system("pause");
	}

	return retorno;
}

