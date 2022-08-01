#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "artista.h"
#include "album.h"
#include "tipoAlbum.h"
#include "inputFuntions.h"
#include "genero.h"
#include "tipoArtista.h"

int Controller_Inicializadores(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, eTipoArtista* tipoArtistaList, eGenero* generoList, int len);
int Controller_Hardcodeadores(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, eTipoArtista* tipoArtistaList, eGenero* generoList, int* contadorCodigoGenero,
                                                                                                                                                       int* contadorCodigoTipoArtista,
                                                                                                                                                       int* contadorCodigoArtista,
                                                                                                                                                       int* contadorCodigoAlbum,
                                                                                                                                                       int* contadorCodigoTiposAlbum);
int Controller_Altas(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, int* contadorId, int len, int* opcionUnoCargada);
int Controller_Modificaciones(eAlbum* albumList, int len, int* opcionUnoCargada);
int Controller_Baja(eAlbum* albumList, int len, int* opcionUnoCargada);
int Controller_Informes(eAlbum* albumList, int len, int* opcionUnoCargada);
int Controller_Listados(eAlbum* albumList, eGenero* generoList, eTipoArtista* tipoArtistaList, eArtista* artistaList, eTipoAlbum* tiposAlbumList, int len, int* opcionUnoCargada);


#endif /* CONTROLLER_H_ */