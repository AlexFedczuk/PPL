/*
 * artista.h
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */

typedef struct{
    int codigoArtista;
    char nombre[51];
    int isEmpty;
}eArtista;

#ifndef ARTISTA_H_
#define ARTISTA_H_

/** \brief Esta funcion inicializa los valores de todas las entidades, dentro de la lista ingresada.
*   \param list eArtista* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int inicializarArtistas(eArtista* list, int len);

/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list eArtista* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int hardcodearArtistas(eArtista* list, int len);

#endif /* ARTISTA_H_ */
