/*
 * miBiblioteca.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "proveedores.h"
#include "productos.h"

#define LEN 10

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_

/** \brief Esta funcion muestra el menu de opciones del menu principal..
*   \return void
*/
void mostrarMenu();
/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list eProveedor* Pointer to array of passenger
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int hardcodearProveedores(eProveedor* list, int len);

/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list eProducto* Pointer to array of passenger
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int hardcodearProductos(eProducto* list, int len);

/** \brief Esta funcion devuelve el valor mayor de un vector de enteros.
*   \param int vec
*   \param int len
*   \return Devuelve el mayor valor del vector.
*/
int calcularIntMayor(int vec[], int len);

/** \brief Esta funcion pide la fecha.
*   \param int* dia
*   \param int* mes
*   \param int* anio
*   \return void.
*/
void pedirFecha(int* dia, int* mes, int* anio);
#endif /* MIBIBLIOTECA_H_ */
