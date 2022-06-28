/*
 * validaciones..c
 *
 *  Created on: 8 may. 2022
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"



/**
 * @fn short verificarRespuesta(void)
 * Esta funcion toma un caracter y solo permite "s" o "n" como respuesta.
 * @return Devuelve 0 en caso de que la respuesta sea "n" y uno si fue "s".
 */
short verificarRespuesta (void)
{
	char letra;

	printf("\nEst%c seguro?(s/n) ", 160);
	fflush(stdin);
	scanf("%c", &letra);
	letra = toupper(letra);
	while (!((letra=='S')||(letra=='N')))
	{
		printf("\nOpci%cn no v%clida... reintente (s/n) ", 162, 160);
		fflush(stdin);
		scanf("%c", &letra);
		letra = toupper(letra);
	}

	return (letra=='S');
}
/**
 * @fn int getString(char*, int)
 * @brief Busca el enter en una cadena y lo cambia por un '\0'
 * @param cadena  Cadena de caracteres a ser analizada
 * @param len Largo de la cadena.
 * @return Retorna 0 si salio bien o -1 si hubo un error.
 */
static int getString(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}
/**
 * @fn int esNumerica(char*)
 * @brief Verifica si la cadena ingresada es numerica
 * @param cadena Cadena de caracteres a ser analizada
 * @return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es.
 */
static int esNumerica (char* cadena)
{
	int i = 0;
	int ret = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				ret = 0;
				break;
			}
			i++;
		}
	}


	return ret;
}
/**
 * @fn int esFlotante(char*)
 * @brief Verifica si la cadena ingresada es flotante
 * @param cadena cadena Cadena de caracteres a ser analizada
 * @return
 */
static int esFlotante (char* cadena)
{
	int i = 0;
	int ret = 1;
	int flag = 0;


	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				if(cadena[i] == '.' && flag == 0)
				{
					flag = 1;
				}
				else
				{
					ret = 0;
					break;
				}
			}
			i++;
		}
	}

	return ret;
}
/**
 * @fn int getFloat(float*)
 * @brief Toma una cadena de texto y la convierte en flotante.
 * @param pResultado puntero a espacio en memoria donde se guardara el flotante.
 * @return retorna 0 si se pudo tomar el dato, de lo contrario -1.
 */
static int getFloat (float* pResultado)
{
	int ret = -1;
	char numero[64];

	if(getString(numero, sizeof(numero)) == 0 && esFlotante(numero)&& strnlen(numero,sizeof(numero)) > 0)
	{
		*pResultado = atof(numero);
		ret = 0;
	}

	return ret;
}
/**
 * @fn int tomarFlotante(float*, char[], char[], int, int, int)
 * @brief Toma un numero flotante validando que lo sea, dentro de un limite y con cierta cantidad de intentos.
 * @param pResultado puntero a espacio en memoria donde se guardara el flotante.
 * @param mensaje Mensaje que le damos al user para el ingreso.
 * @param mensajeError Mensaje de error que le damos al user si hubo un mal ingreso.
 * @param minimo Limite minimo numerico.
 * @param maximo Limite maximo numerico.
 * @param reintentos Cantidad de intentos
 * @return Retorna -1 si no se pudo tomar el numero o 0 se pudo.
 */
int tomarFlotante (float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int ret = -1;
	float numero;

	while(reintentos > 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getFloat(&numero) == 0)
		{
			if(numero >= minimo && numero <= maximo)
			{
				*pResultado = numero;
				ret = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}


	return ret;
}
/**
 * @fn int getInt(int*)
 * @brief Toma una cadena de texto y la convierte en int.
 * @param pResultado Puntero a espacio en memoria donde se guardara el numero.
 * @return retorna 0 si se pudo tomar el dato, de lo contrario -1.
 */
static int getInt (int* pResultado)
{
	int ret = -1;
	char numero[64];

	if(getString(numero, sizeof(numero)) == 0 && esNumerica(numero) && strnlen(numero,sizeof(numero)) > 0)
	{
		*pResultado = atoi(numero);
		ret = 0;
	}

	return ret;
}
/**
 * @fn int tomarEntero(int*, char[], char[], int, int, int)
 * @brief Toma un numero entero validando que lo sea, dentro de un limite y con cierta cantidad de intentos.
 * @param pResultado puntero a espacio en memoria donde se guardara el entero.
 * @param mensaje Mensaje que le damos al user para el ingreso.
 * @param mensajeError Mensaje de error que le damos al user si hubo un mal ingreso.
 * @param minimo Limite minimo numerico.
 * @param maximo Limite maximo numerico.
 * @param reintentos Cantidad de intentos
 * @return Retorna -1 si no se pudo tomar el numero o 0 se pudo.
 */
int tomarEntero (int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int ret = -1;
	int numero;

	while(reintentos > 0)
	{
		reintentos--;

		printf("%s", mensaje);
		if(getInt(&numero) == 0)
		{
			if(numero >= minimo && numero <= maximo)
			{
				*pResultado = numero;
				ret = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}


	return ret;
}
/**
 * @fn int esNombre(char*, int)
 * @brief Verifica que la cadena ingresada sea un nombre.
 * @param cadena Cadena a analizar
 * @param longitud Longitud de la cadena.
 * @return Retorna 1 si la cadena respeta los paramtros o 0 si no es un nombre valido.
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] != ' ') )|| (cadena[i] == ' ' && cadena[i+1] == ' ') || (cadena[0] == ' '))
			{
					retorno = 0;
					break;
			}
		}
	}
	return retorno;
}
/**
 * @fn int esFlycode(char*, int)
 * @brief  Verifica que la cadena ingresada sea un flycode valido.
 * @param cadena Cadena a analizar
 * @param longitud Longitud de la cadena.
 * @return Retorna 1 si la cadena respeta los paramtros o 0 si no es un nombre valido.
 */
static int esFlycode(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * @fn int getNombre(char*, int)
 * @brief Toma la cadena, verifica y copia en una variable.
 * @param pResultado  puntero a espacio en memoria donde se guardara el nombre.
 * @param longitud Largo de la cadena.
 * @return Retorna 0 si se guardo el nombre o -1 si hubo error.
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * @fn int tomarString(char*, int, char*, char*, int)
 * @brief Toma una cadena de texto validando que tenga solo letras y espacios con cierta cantidad de intentos.
 * @param pResultado puntero a espacio en memoria donde se guardara la cadena.
 * @param tamanio Tamaño del array.
 * @param mensaje Mensaje que le damos al user para el ingreso.
 * @param mensajeError Mensaje de error que le damos al user si hubo un mal ingreso.
 * @param reintentos Cantidad de intentos
 * @return retorna 0 si se pudo completar la toma de datos o -1 si fallo.
 */
int tomarString(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < tamanio && strnlen(bufferString,sizeof(bufferString)) > 0)
		{
			strncpy(pResultado,bufferString,tamanio);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/**
 * @fn int getFlycode(char*, int)
 * @brief Toma la cadena, verifica y copia en una variable.
 * @param pResultado  puntero a espacio en memoria donde se guardara el codigo de vuelo.
 * @param longitud Largo de la cadena.
 * @return Retorna 0 si se guardo el nombre o -1 si hubo error.
 */
static int getFlycode(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlycode(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<=longitud && strnlen(buffer,sizeof(buffer)) > 0)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * @fn int validarFlycode(char*, int, char*, char*, int)
 * @brief Esta funciona valida que el flycode este bien ingresado y tiene un limite de reintentos.
 * @param pResultado puntero al espacio de memoria donde se copiara el codigo de vuelo validado.
 * @param tamanio El tamaño del array.
 * @param mensaje Mensaje que le daremos para el ingreso.
 * @param mensajeError Mensaje que le daremos al user si ingresa algo mal.
 * @param reintentos Establecemos la cantidad de intentos que tendra el usuario si ingresa mal.
 * @return Retorna 0 si el dato fue obtenido o -1 si fallo.
 */
int validarFlycode(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFlycode(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) <= tamanio )
		{
			strncpy(pResultado,bufferString,tamanio);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/**
 * @fn int incrementarPasajerosId()
 * @brief Incremente un numero que servira para pasar como id de los pasajeros.
 * @return Retorna la id,
 */
int incrementarPasajerosId()
{
    static int id = 1000;
    id++;

    return id;
}
/**
 * @fn int iniciarMenu(void)
 * @brief Inicia el meni Principal y toma una respuesta ya validada.
 * @return retorna la opcion seleccionada por el user.
 */
int iniciarMenu (void)
{
	int opcion;

	system("cls");

	printf("*****************************MENU PRINCIPAL*****************************\n\n");
	printf("1. ALTA \n");
	printf("2. MODIFICAR \n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("5. CARGA FORZADA\n");
	printf("6. SALIR\n");


	if(tomarEntero(&opcion, "\nElija una opcion: ", "\nOpcion ingresada no valida. ", 1, 6, 3) == -1)
	{
		printf("\n\nAgoto el numero de intentos.\n\n");
		system("pause");
		fflush(stdin);
	}

	system("cls");

	return opcion;
}
/**
 * @fn int subMenuInformar(void)
 * @brief Inicia el submenu de informe y toma una respuesta ya validada
 * @return retorna la opcion seleccionada por el user.
 */
int subMenuInformar(void)
{
	int opcion;
	system("cls");
	printf("*****************************MENU INFORMAR*****************************\n\n");
	printf("1. Listado de los pasajeros ordenados alfabeticamente por apellido y tipo de pasajero. \n");
	printf("2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
	printf("3. Listado de los pasajeros por codigo de vuelo y estados de vuelos ACTIVO.\n");
	printf("4. SALIR\n");

	if(tomarEntero(&opcion, "\nElija una opcion: ", "\nOpcion ingresada no valida. ", 1, 6, 3) == -1)
	{
		printf("\n\nAgoto el numero de intentos.\n\n");
		system("pause");
		fflush(stdin);
	}

	system("cls");


	return opcion;
}







