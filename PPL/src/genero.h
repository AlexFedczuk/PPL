/*
 * genero.h
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "miBiblioteca.h"

typedef struct{
    int codigoGenero;
    char descripcion[51];
    int isEmpty;
}eGenero;

#ifndef GENERO_H_
#define GENERO_H_

/** \brief Esta funcion inicializa los valores de todas las entidades, dentro de la lista ingresada.
*   \param list eGenero* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int inicializarArtistas(eGenero* list, int len);

/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list eGenero* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int hardcodearGeneros(eGenero* list, int len);

#endif /* GENERO_H_ */
