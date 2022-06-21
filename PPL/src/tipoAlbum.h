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

int inicializarTiposAlbum(eTipoAlbum* list, int len);
int hardcodearTiposAlbum(eTipoAlbum* list, int len);
int listarTodosLosTiposAlbune(eTipoAlbum* list, int len);
int listarNoTodosLosTiposAlbune(eTipoAlbum* list, int len, char* descripcion);

#endif /* TIPOALBUM_H_ */
