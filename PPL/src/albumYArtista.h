/*
 * albumYArtista.h
 *
 *  Created on: May 3, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef ALBUMYARTISTA_H_
#define ALBUMYARTISTA_H_

#include <stdlib.h>
#include "album.h"
#include "artista.h"

/*
	brief Esta funcion se encarga de llamar la lista todos los Albumes de cada Artista.
	params listAlbum* list
	params eArtista* list
	params int lenAlbum
	params int lenArtista
	return (-1) if [Error if list NULL or if len invalid lenght] - (0) if Ok.
*/
int listarTodosLosAlbumesCadaArtista(eAlbum* listAlbum, eArtista* listArtista, int lenAlbum, int lenArtista);// Voy a necesitar un ID que identifique entre dos identidades eAlbum -> eArtista.

/*
	brief Esta funcion lista todos los Albumes de cada Artista.
	params listAlbum* list
	params eArtista* list
	params int lenAlbum
	params int lenArtista
	params int index
	return (-1) if [Error if list NULL or if len invalid lenght] - (0) if Ok.
*/
int listarTodosLosAlbumesDeterminados(eAlbum* listAlbum, eArtista* listArtista,int lenAlbum, int index);// Voy a necesitar un ID que identifique entre dos identidades eAlbum -> eArtista

#endif /* ALBUMYARTISTA_H_ */
