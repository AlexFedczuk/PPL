#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "artista.h"
#include "album.h"
#include "tipoAlbum.h"
#include "inputFuntions.h"
#include "genero.h"
#include "tipoArtista.h"

/** \brief Se encarga de llamar aquellas funciones necesarias para realizar la inicializacion de todos los listados.
*   \param albumList Pointer to array
*   \param tipoAlbumList Pointer to array
*   \param artistaList Pointer to array
*   \param tipoArtistaList Pointer to array
*   \param generoList Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int Controller_Inicializadores(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, eTipoArtista* tipoArtistaList, eGenero* generoList, int len);

/** \brief Se encarga de llamar aquellas funciones necesarias para Hardcodear los listados.
*   \param albumList Pointer to array
*   \param tipoAlbumList Pointer to array
*   \param artistaList Pointer to array
*   \param tipoArtistaList Pointer to array
*   \param generoList Pointer to array
*   \param contadorCodigoGenero Pointer to ID counter
*   \param contadorCodigoTipoArtista Pointer to ID counter
*   \param contadorCodigoArtista Pointer to ID counter
*   \param contadorCodigoAlbum Pointer to ID counter
*   \param contadorCodigoTiposAlbum Pointer to ID counter
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int Controller_Hardcodeadores(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, eTipoArtista* tipoArtistaList, eGenero* generoList, int* contadorCodigoGenero,
                                                                                                                                                       int* contadorCodigoTipoArtista,
                                                                                                                                                       int* contadorCodigoArtista,
                                                                                                                                                       int* contadorCodigoAlbum,
                                                                                                                                                       int* contadorCodigoTiposAlbum);

/** \brief Se encarga de llamar aquellas funciones necesarias para realizar altas de Albumes.
*   \param albumList Pointer to array
*   \param tipoAlbumList Pointer to array
*   \param artistaList Pointer to array
*   \param tipoArtistaList Pointer to array
*   \param contadorId Pointer to ID counter
*   \param len int Array length
*   \param opcionUnoCargada Pointer to Flag
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int Controller_Altas(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, int* contadorId, int len, int* opcionUnoCargada);

/** \brief Se encarga de llamar aquellas funciones necesarias para realizar modificaciones de Albumes.
*   \param albumList Pointer to array
*   \param len int Array length
*   \param opcionUnoCargada Pointer to Flag
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int Controller_Modificaciones(eAlbum* albumList, int len, int* opcionUnoCargada);

/** \brief Se encarga de llamar aquellas funciones necesarias para realizar Bajas de Albumes.
*   \param albumList Pointer to array
*   \param len int Array length
*   \param opcionUnoCargada Pointer to Flag
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int Controller_Baja(eAlbum* albumList, int len, int* opcionUnoCargada);

/** \brief Se encarga de llamar aquellas funciones necesarias para realizar un Informe.
*   \param albumList Pointer to array
*   \param len int Array length
*   \param opcionUnoCargada Pointer to Flag
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int Controller_Informes(eAlbum* albumList, int len, int* opcionUnoCargada);

/** \brief Se encarga de llamar aquellas funciones necesarias para realizar todos los Listados.
*   \param albumList Pointer to array
*   \param generoList Pointer to array
*   \param artistaList Pointer to array
*   \param tipoArtistaList Pointer to array
*   \param len int Array length int* 
*   \param opcionUnoCargada Pointer to Flag
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int Controller_Listados(eAlbum* albumList, eGenero* generoList, eTipoArtista* tipoArtistaList, eArtista* artistaList, eTipoAlbum* tiposAlbumList, int len, int* opcionUnoCargada);

#endif /* CONTROLLER_H_ */