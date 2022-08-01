/*
 * album.h
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef ALBUM_H_
#define ALBUM_H_

#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#include "inputFuntions.h"
#include "artista.h"
#include "tipoAlbum.h"

typedef struct{
	int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char titulo[51];
    eFecha fecha;
    float importe;
    eArtista artista;
    eTipoAlbum tipoAlbum;
    
    int isEmpty;
}eAlbum;

/** \brief Esta funcion inicializa los valores de todas las entidades, dentro de la lista ingresada.
*   \param list eAlbum* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int inicializarAlbunes(eAlbum* list, int len);

int hardcodearAlbunes(eAlbum* list, int len);

/** \brief Esta funcion se encarga de solicitar por la informacion necesaria para la carga de una entidad.
*   \param list eAlbum*
*   \param len int
*   \param contadorId int
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int cargarAlbum(eAlbum* list, eTipoAlbum* listTipoAlbum, eArtista* listArtista, int len, int* pId);

/** \brief Esta funcion se encarga de agregar una alta a la lista.
*   \param list eAlbum*
*   \param len int
*   \param id int
*   \param char titulo[]
*   \param int dia
*   \param int mes
*   \param int anio
*   \param float importe
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int addAlbum(eAlbum* list, int len, int idArtista, int id, char* titulo, int dia, int mes, int anio, float importe, int idTipoAlbum, char* descripcionTipoAlbum, char* nombreArtista);

/** \brief Esta funcion se encarga de modificar una entidad.
*   \param list eAlbum*
*   \param len int
*   \param buffer int
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int modificarAlbum(eAlbum* list, int len, int buffer);

/** \brief find an entity by Id en returns the index position in array.
*   \param list eAlbum*
*   \param len int
*   \param id int
*   \return Return entity index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*/
int findAlbumById(eAlbum* list, int len, int id);

/** \brief Esta funcion se encarga de realizar la modificacion de una entidad en la lista.
* 	\param list eAlbum*
* 	\param index int
* 	\param buffer int
* 	\return int Return (-1) if Error [NULL pointer or invalid index or if invalid buffer] - (0) if Ok*
*/
int menuModificacion(eAlbum* list, int index, int buffer);

/** \brief Esta funcion muestra el menu de opciones del menu de modificaciones..
*   \return void
*/
void mostarMenuModificacion();

/** \brief Esta funcion se encarga de dar de baja una entidad en la lista.
* \param list eAlbum*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
*         find a entity - (0) if Ok*
*/
int darBajaAlbum(eAlbum* list, int len);

/** \brief Remove a Entity by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
*         find a entity] - (0) if Ok
*
*/
int removeAlbum(eAlbum* list, int len, int id);

/** \brief Esta funcion busca en la lista ingresada, si hay espacio vacios, para ingresar un ingreso en el mismo, por ejemplo.
*   \param list eAlbum* Pointer to array of passenger
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer], (-2) si no hay espacios diponibles en la lista - (0) if Ok
*/
int buscarEspacioVacio(eAlbum* list, int len); // Listo.

/** \brief Esta funcion calcula el total de los precios de una lista de entidades.
*   \param list eAlbum* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el total de los precios de una lista de entidades.
*/
float calcularTotalImportesAlbumes(eAlbum* list, int len);

/** \brief Esta funcion calcula el promedio de los precios de una lista de entidades.
*   \param list eAlbum* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el promedio de los precios de una lista de entidades.
*/
float calcularPromedio(eAlbum* list, int len, float total);

/** \brief Esta funcion cuenta cuantas entidades dentro de una lista superan el promedio.
*   \param list eAlbum* Pointer to array
*   \param len int Array length
*   \param promedio float
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el total de entidades que superan el promedio.
*/
int contarMayorAPromedio(eAlbum* list, int len, float promedio);

/*
	brief Esta funcion devuelve la cantidad de albumes menores a x anio.
	params eAlbum* list
	params int len
	params int anio
	return (-1) if [Error if list NULL or if len invalid lenght] - The number of albums that are less than a x year old.
*/
int contarTodosLosAlbunesMenoresAnio(eAlbum* list, int len, int anio);

/*
	brief Esta funcion lista todos los Albunes que estan de alta.
	params eAlbum* list
	params int len
	return (-1) if [Error if list NULL or if len invalid lenght] - (0) if Ok.
*/
int listarTodosLosAlbunes(eAlbum* list, int len);

/*
	brief Esta funcion lista todos los Albunes que son anteriores a x anio.
	params eAlbum* list
	params int len
	params int anio
	return (-1) if [Error if list NULL or if len invalid lenght] - (0) if Ok.
*/
int listarTodosLosAlbunesMenoresAnio(eAlbum* list, int len, int anio);

/*
	brief Esta funcion lista todos los Albunes que son mayores a x importe.
	params eArtista* list
	params int len
	params float promedio
	return (-1) if [Error if list NULL or if len invalid lenght] - (0) if Ok.
*/
int listarTodosLosAlbunesMayoresPromedioImporte(eAlbum* list, int len, float importe);

/*
	brief Esta funcion lista todos los Albunes que son de un anio x.
	params eAlbum* list
	params int len
	params int anio
	return (-1) if [Error if list NULL or if len invalid lenght] - (0) if Ok.
*/
int listarTodosLosAlbunesAnioDeterminado(eAlbum* list, int len, int anio);

/*
	brief Esta funcion lista todos los Albunes que tienen el mismo importe igual al numero por parametros.
	params eAlbum* list
	params int len
	params float numero
	return (-1) if [Error if list NULL or if len invalid lenght] - (0) if Ok.
*/
int listarTodosLosAlbunesMasCaros(eAlbum* list, int len, float numero);

/*
	brief Esta funcion calcula el album con el importe mas caro.
	params eAlbum* list
	params int len
	return (-1) if [Error if list NULL or if len invalid lenght] - the price of the most expensive album if Ok.
*/
float calcularAlbumMasCaro(eAlbum* list, int len);

/*
	brief Ordena la lista por importe y titulo.
	params eAlbum* list
	params int len
	return (-1) if [Error if list NULL or if len invalid lenght] - the price of the most expensive album if Ok.
*/
int ordenarAlbunesImporteTitulo(eAlbum* list, int len);

/*
	brief Lista los albunes de los artistas.
	params eAlbum* list
	params int len
	return (-1) if [Error if list NULL or if len invalid lenght] - the price of the most expensive album if Ok.
*/
int listarAlbunesDeArtistas(eAlbum* list, eArtista* list2, int len, int len2);

/*
	brief Lista los albunes de Vinilo con sus Artistas determinados.
	params eAlbum* list
	params int len
	return (-1) if [Error if list NULL or if len invalid lenght] - the price of the most expensive album if Ok.
*/
int listarAlbumesViniloArtista(eAlbum* list, eTipoAlbum* list2, int len);

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

#endif /* ALBUM_H_ */
