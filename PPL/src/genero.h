/*
 * genero.h
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef GENERO_H_
#define GENERO_H_

#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"

typedef struct{
    int codigoGenero;
    char descripcion[51];
    int isEmpty;
}eGenero;

/** \brief Esta funcion inicializa los valores de todas las entidades, dentro de la lista ingresada.
*   \param list eGenero* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int inicializarGeneros(eGenero* list, int len);

/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list eGenero* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int hardcodearGeneros(eGenero* list, int len);

/** \brief Esta funcion lista todos los generos que estan de alta.
*   \param eGenero* list
*   \param len int
*   return (-1) if [Error if list NULL or if len invalid lenght] - (0) if Ok.
*/
int listarTodosLosGeneros(eGenero* list, int len);

#endif /* GENERO_H_ */
