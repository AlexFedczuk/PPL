/*
 * tipoAlbum.c
 *
 *  Created on: Jun 20, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "tipoAlbum.h"

int inicializarTiposAlbum(eTipoAlbum* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].id = 0;
            strcpy(list[i].descripcion, " ");
            list[i].isEmpty = 1;
        }
        result = 0;
    }
    return result;
}

int hardcodearTiposAlbum(eTipoAlbum* list, int len){
	int idAux[3] = {1, 2, 3};
	char descripcionAux[3][50] = {"vinilo","cinta","CD"};
	int isEmptyAux[3] = {0,0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
	        list[i].id = idAux[i];
	        strcpy(list[i].descripcion, descripcionAux[i]);
	        list[i].isEmpty = isEmptyAux[i];
		}
		result = 0;
	}

	result = calcularIntMayor(idAux, 3);

	return result;
}

int listarTodosLosTiposAlbune(eTipoAlbum* list, int len){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Tipos de Albunes\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
				printf("Codigo de Tipo de Album: %4d, Descripcion: %51s\n",list[i].id,list[i].descripcion);
		}
		result = 0;
	}
	return result;
}

int listarNoTodosLosTiposAlbune(eTipoAlbum* list, int len, char* descripcion){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Tipos de Albunes\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && strcmp(list[i].descripcion, descripcion))
				printf("Codigo de Tipo de Album: %4d, Descripcion: %51s\n",list[i].id,list[i].descripcion);
		}
		result = 0;
	}
	return result;
}
