/*
 * album.h
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
typedef struct{
	int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int codigoAlbum;
    char titulo[51];
    struct eFecha fecha;
    float importe;
    int isEmpty;
}eAlbum;

#ifndef ALBUM_H_
#define ALBUM_H_

/** \brief Esta funcion inicializa los valores de todas las entidades, dentro de la lista ingresada.
*   \param list eAlbum* Pointer to array
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int inicializarAlbunes(eAlbum* list, int len);

/** \brief Esta funcion se encarga de solicitar por la informacion necesaria para la carga de una entidad.
*   \param list eAlbum*
*   \param len int
*   \param contadorId int
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int cargarAlbum(eAlbum list[], int len, int contadorId, int buffer);

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
int addAlbum(eAlbum* list, int len, int id, char titulo[], int dia, int mes, int anio, float importe);

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

#endif /* ALBUM_H_ */
