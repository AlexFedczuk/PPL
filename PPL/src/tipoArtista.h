/*
 * tipoArtista.h
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "miBiblioteca.h"

typedef struct{
    int codigoTipoArtista;
    char descripcion[51];
    int isEmpty;
}eTipoArtista;

#ifndef TIPOARTISTA_H_
#define TIPOARTISTA_H_

/** \brief Esta funcion inicializa los valores de todas las entidades, dentro de la lista ingresada.
*   \param list eTipoArtista* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int inicializarTipoArtistass(eTipoArtista* list, int len);

/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list eTipoArtista* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int hardcodearTipoArtistas(eTipoArtista* list, int len);

#endif /* TIPOARTISTA_H_ */
