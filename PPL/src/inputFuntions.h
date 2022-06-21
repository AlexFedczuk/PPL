/*
 * funciones.h
 *
 *  Created on: Apr 11, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef INPUT_FUNTIONS_H_
#define INPUT_FUNTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "miBiblioteca.h"

#define BUFFER_SIZE 4096
// Menues
/**
  @brief Esta funcion se encarga de validar que se ingreso un valor de tipo entero por consola.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Booleano.
*/
bool parseInt(char *string, int *integer);
/**
  @brief Esta funcion se encarga de validar que se ingreso un valor de tipo flotante por consola.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Booleano.
*/
bool parseFloat(char *string, float *nfloat);
/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo flotante.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Flotante.
*/
float pedirNumeroFlotante(char mensaje[]);
/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo entero.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Entero.
*/
int pedirNumeroEntero(char mensaje[]);
/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo entero NO negativo.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Entero NO negativo.
*/
float pedirValorNoNegativo(char mensaje[]);

/** \brief Esta funcion pide por consola una cadena caracteres sin contenido NO alfabetico.
*   \param list Passenger*
*   \param length int
*   \return int*
*/
void pedirUnaCadenaAlpha(char cadena[], char mensaje[], int buffer);

/** \brief Esta funcion elimina los espacios blancos de la cadena ingresada.
*   \param char* cadena
*   \return int Return (-1) if Error [NULL pointer] - (0) if Ok
*/
int removerEspacios(char* cadena);

/**
 * \brief Solicita un numero de tipo entero al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado, Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param mensaje, El mensaje a ser mostardo por consola.
 * \param mensajeError, El mensaje de error a ser mostardo por consola.
 * \param minimo, El numero minimo a ser aceptado por la funcion.
 * \param maximo, El numero maximo a ser aceptado por la funcion.
 * \param reintentos, La cantidad de veces que se le permite ingresar un error al usuario.
 * \param bufferLenght, El tamanio del buffer.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si Ok.
 */
int getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int bufferLenght);

/**
 * \brief Recibe un valor y verifica que sea un entero.
 * \param pResultado, Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param bufferLenght, El tamanio del buffer.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si Ok.
 */
int getInt(int* pResultado, int bufferLenght);

/**
 * \brief Recibe un valor y verifica que sea un numero.
 * \param cadena donde se encuentra el contenido a verificar.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si es invalida la cadena - (1) si esta Ok.
 */
int esNumero(char* cadena);

/**
 * \brief Le en "cadena" hasta que encuentra un '\n' o hasta que haya copiado en "cadena"
 *        un maximo de 'len - 1' caracteres.
 * \param pResultado, Puntero al espacio de memoria donde se copiara la cadena obtenida.
 * \param len, El tamanio de la "cadena".
 * \return Retorna (0).
 */
int myGets(char* cadena, int len);

/**
 * \brief Solicita un numero de tipo entero al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado, Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param mensaje, El mensaje a ser mostardo por consola.
 * \param mensajeError, El mensaje de error a ser mostardo por consola.
 * \param minimo, El numero minimo a ser aceptado por la funcion.
 * \param maximo, El numero maximo a ser aceptado por la funcion.
 * \param reintentos, La cantidad de veces que se le permite ingresar un error al usuario.
 * \param bufferLenght, El tamanio del buffer.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si Ok.
 */
int getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos, int bufferLenght);

/**
 * \brief Recibe un valor y verifica que sea un flotante.
 * \param pResultado, Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param bufferLenght, El tamanio del buffer.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si Ok.
 */
int getFloat(float *pResultado, int bufferLenght);

/**
 * \brief Cuenta cuantos caracteres '.' hay en la cadena.
 * \param cadena, Puntero al espacio de memoria donde se encuentra la cedana.
 * \param len, El tamanio de la "cadena".
 * \return Retorna (-1) ante parametros invalidos - (x numero) segun la cantidad de puntos en la cadena.
 */
int contarPuntosEnString(char* cadena, int len);

/**
 * \brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado, Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param mensaje, El mensaje a ser mostardo por consola.
 * \param mensajeError, El mensaje de error a ser mostardo por consola.
 * \param reintentos, La cantidad de veces que se le permite ingresar un error al usuario.
 * \param bufferLenght, El tamanio del buffer.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si Ok.
 */
int getUnCaracter(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int bufferLenght);

/**
 * \brief Recibe un valor y verifica que sea un caracter.
 * \param pResultado, Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param bufferLenght, El tamanio del buffer.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si Ok.
 */
int getChar(char *pResultado, int bufferLenght);

/**
 * \brief Recibe un valor y verifica que sea un caracter.
 * \param cadena donde se encuentra el contenido a verificar.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si es invalida la cadena - (1) si esta Ok.
 */
int esCaracter(char *cadena);

/** \brief Verifica que lo que se esta pasando por nombreArchivo si es un .csv o un .dat.
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo y su extension.
 * \return Devuelve (-1) si hubo un parametro invalido o si es un archivo con extension invalida - (0) si es un .csv o (1) si es un .dat.
 *
 */
int RevisarFormatoArchivo(char* nombreArchivo);

/**
 * \brief Pide un nombre.
 * \param char* mensjae, direccion de memoria donde se encuentrael mensaje para el usuario.
 * \param char* nombre, direccion de memoria donde se guardara el nombre ingresado.
 * \param int stringLen, tamanio de la cadena permitida.
 * \return Retorna (-1) si se ingresa algun parametro invalido - (0) si Ok.
 */
int PedirNombre(char* mensjae, char* nombre, int stringLen);

#endif /* INPUT_FUNTIONS_H_*/
