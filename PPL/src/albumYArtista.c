/*
 * albumYArtista.c
 *
 *  Created on: May 3, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "albumYArtista.h"

int listarTodosLosAlbumesCadaArtista(eAlbum* listAlbum, eArtista* listArtista,int lenAlbum, int lenArtista){
	int result = -1;

	if(listAlbum != NULL && lenAlbum > 0 && listArtista != NULL && lenArtista > 0){
		printf("\nTodos los Albumes de cada Artista\n");
		for(int j = 0; j < lenArtista; j++){
		    if(listArtista[j].isEmpty == 0){
		        printf("Codigo de Artista: %4d, Nombre: %51s\n",listArtista[j].codigoArtista,listArtista[j].nombre);
		        listarTodosLosAlbumesDeterminados(listAlbum, listArtista, lenAlbum, j);
		    }
		}
		result = 0;
	}
	return result;
}

int listarTodosLosAlbumesDeterminados(eAlbum* listAlbum, eArtista* listArtista, int lenAlbum, int index){
    int result = -1;

    if(listAlbum != NULL && lenAlbum > 0 && listArtista != NULL){
        for(int i = 0; i < lenAlbum; i++){
    	    if(listAlbum[i].isEmpty == 0 && listAlbum[index].codigoArtista == listArtista[i].codigoArtista) {
        	    printf("\tCodigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",listAlbum[i].codigoAlbum,listAlbum[i].titulo,listAlbum[i].fecha.dia,listAlbum[i].fecha.mes,listAlbum[i].fecha.anio,listAlbum[i].importe);
        	}
        }
    }

    return result;
}


