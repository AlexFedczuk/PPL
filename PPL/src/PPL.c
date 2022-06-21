/*
 ============================================================================
 Name        : PPL.c
 Author      : Alex Yago Fedczuk
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "genero.h"
#include "tipoArtista.h"
#include "artista.h"
#include "album.h"
#include "tipoAlbum.h"

#define BUFFER 51

int main(void){
	setbuf(stdout, NULL);

	    int opcionMenu;
	    int opcionUnoCargada;
	    int contadorCodigoGenero;
	    int contadorCodigoTipoArtista;
	    int contadorCodigoArtista;
	    int contadorCodigoAlbum;
	    int contadorCodigoTiposAlbum;
	    float albumMasCaro;
	    float totalImportes;
	    float promedioImportes;
	    int cantidadAlbunesMayorPromedio;
	    int albunesMenores;

	    eGenero generoList[LEN];
	    eTipoArtista tipoArtistaList[LEN];
	    eArtista artistaList[LEN];
	    eAlbum albumList[LEN];
	    eTipoAlbum tiposAlbumList[LEN];

	    opcionUnoCargada = 0;
	    contadorCodigoGenero = 0;
	    contadorCodigoTipoArtista = 0;
	    contadorCodigoArtista = 0;
	    contadorCodigoAlbum = 0;
	    contadorCodigoTiposAlbum = 0;

	    if(inicializarGeneros(generoList, LEN) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Generos!\n");
	    if(inicializarTipoArtistas(tipoArtistaList, 2) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Tipo de Artistas!\n");
	    if(inicializarArtistas(artistaList, LEN) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Artistas!\n");
	    if(inicializarAlbunes(albumList, LEN) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Albunes!\n");
	    if(inicializarTiposAlbum(tiposAlbumList, LEN) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Tipos de Albunes!\n");

	    contadorCodigoGenero = hardcodearGeneros(generoList, LEN);
	    contadorCodigoTipoArtista = hardcodearTipoArtistas(tipoArtistaList, 2);
	    contadorCodigoArtista = hardcodearArtistas(artistaList, LEN);
	    //contadorCodigoAlbum = hardcodearAlbunes(albumList, LEN);
	    contadorCodigoTiposAlbum = hardcodearTiposAlbum(tiposAlbumList, LEN);

	    if(contadorCodigoGenero == -1)
	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Generos!\n");
	    if(contadorCodigoTipoArtista == -1)
	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Tipo de Artistas!\n");
	    if(contadorCodigoArtista == -1)
	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Artistas!\n");
	    if(contadorCodigoAlbum == -1)
	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Albunes!\n");
	    if(contadorCodigoTiposAlbum == -1)
	    	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Albunes!\n");

	    do{
	        mostrarMenu();
	        getNumeroInt(&opcionMenu,"\nIngrese una opcion del menu principal: ", "\nERROR! Valor ingresado invalido\n", 1, 6, 0, BUFFER);
	        fflush(stdin);

	        switch(opcionMenu)
	        {
	            case 1:
	            	if(buscarEspacioVacio(albumList, LEN) != -2){
	            		contadorCodigoAlbum++;
	            		contadorCodigoAlbum = cargarAlbum(albumList, LEN, contadorCodigoAlbum, BUFFER);
	            		opcionUnoCargada = 1;
	            	}else{
	            		printf("\nERROR! Ya no quedan espacios en el programa para ingresar mas altas a la lista!\n");
	            	}

	                break;
	            case 2:
	            	if(opcionUnoCargada == 1){
	            		listarTodosLosAlbunes(albumList, tiposAlbumList, LEN);
	            		if(modificarAlbum(albumList, LEN, BUFFER) == -1)
	            		            printf("\nError! Invalid length or NULL pointer, al querer ingresar a la opcion 2 del Menu Principal!\n");
	            	}else{
	            	    printf("\nERROR! Se debe realizar una alta para realizar una modificacion!\n");
	            	}
	            	break;
	            case 3:
	                if(opcionUnoCargada == 1){
	                	listarTodosLosAlbunes(albumList, tiposAlbumList, LEN);
	                	darBajaAlbum(albumList, LEN);
	                }else{
	                	printf("\nERROR! Se debe realizar una alta para realizar una baja!\n");
	                }
	                break;
	            case 4:
	            	if(opcionUnoCargada == 1){
	            		// A.
	            		totalImportes = calcularTotalImportesAlbumes(albumList, LEN);
	            		printf("\nTotal de los importes: %.2f\n", totalImportes);
	            		promedioImportes = calcularPromedio(albumList, LEN, totalImportes);
	            		printf("Promedio de los importes: %.2f\n", promedioImportes);
	            		cantidadAlbunesMayorPromedio = contarMayorAPromedio(albumList, LEN, promedioImportes);
	            		printf("Cantidad de albunes que superan el promedio de importes: %d\n", cantidadAlbunesMayorPromedio);
	            		// B.
	            		albunesMenores = contarTodosLosAlbunesMenoresAnio(albumList, LEN, 2000);
						printf("Cantidad de albunes cuya fecha de publicaci�n es menor a 1/1/2000: %d\n", albunesMenores);

	            	}else{
	            		printf("\nERROR! Se debe realizar una alta para realizar un informe!\n");
	            	}
	                break;
	            case 5:
	            	if(opcionUnoCargada == 1){
	            		// A.
	            		listarTodosLosGeneros(generoList, LEN);
	            		// B.
	            		listarTodosLosTiposArtista(tipoArtistaList, LEN);
	            		// C.
	            		listarTodosLosArtistas(artistaList, LEN);
	            		// D.
	            		listarTodosLosAlbunes(albumList, tiposAlbumList, LEN);
	            		// E.
	            		ordenarAlbunesImporteTitulo(albumList, LEN);
	            		listarTodosLosAlbunes(albumList, tiposAlbumList, LEN);
	            		// F.
	            		listarTodosLosAlbunesMenoresAnio(albumList, LEN, 2000);
	            		// G.
	            		albumMasCaro = calcularAlbumMasCaro(albumList, LEN);
	            		listarTodosLosAlbunesMayoresPromedioImporte(albumList, LEN, albumMasCaro);
	            		// H.
	            		listarAlbunesDeArtistas(albumList, artistaList, LEN);
	            		// I.
	            		listarTodosLosAlbunesAnioDeterminado(albumList, LEN, 2000);
	            		// J.
	            		listarTodosLosAlbunesMasCaros(albumList, LEN, albumMasCaro);
	            		// PARTE 2
	            		listarTodosLosTiposAlbune(tiposAlbumList, LEN);
	            		listarNoTodosLosTiposAlbune(tiposAlbumList, LEN, "vinilo");
	            		listarAlbumesViniloArtista(albumList, tiposAlbumList, LEN);
	            	}
	            	break;
	            default:
	            	if(opcionMenu < 1 || opcionMenu > 6)
	            		printf("\nERROR! Debe ingresar una opcion del menu principal!\n");
	                //system("pause");
	                //system("cls");// Por alguna razon, no la reconoce la funcion...
	                break;
	        }
	    }while(opcionMenu != 6);

	    return 0;
}
