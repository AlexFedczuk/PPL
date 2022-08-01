/*
 * tipoAlbum.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Alex Yago Fedczuk
 */

#ifndef TIPOALBUM_H_
#define TIPOALBUM_H_

#include <stddef.h>
#include <string.h>
#include "miBiblioteca.h"

typedef struct{
    int id;
    char descripcion[51];
    int isEmpty;
}eTipoAlbum;

/** \brief Esta funcion inicializa los valores de todas las entidades, dentro de la lista ingresada.
*   \param list eTipoAlbum* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int inicializarTiposAlbum(eTipoAlbum* list, int len);

/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list eTipoAlbum* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int hardcodearTiposAlbum(eTipoAlbum* list, int len);

/** \brief Esta funcion lista todos los tipos de Album.
*   \param list eTipoAlbum* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int listarTodosLosTiposAlbune(eTipoAlbum* list, int len);

/** \brief Esta funcion lista todos los tipos de Album, menos el que coincida con la descripcion ingresada por parametros.
*   \param list eTipoAlbum* Pointer to array
*   \param len int Array length
*   \param descripcion char*, descripcion
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int listarNoTodosLosTiposAlbune(eTipoAlbum* list, int len, char* descripcion);

#endif /* TIPOALBUM_H_ */
