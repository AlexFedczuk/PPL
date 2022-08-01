/*
 * tipoArtista.c
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "tipoArtista.h"

int inicializarTipoArtistas(eTipoArtista* list, int len){
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

int hardcodearTipoArtistas(eTipoArtista* list, int len){
	int id[2] = {1,2};
	char descripcion[2][50] = {"Solista","Banda"};
	int isEmpty[2] = {0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
	        list[i].id = id[i];
	        strcpy(list[i].descripcion, descripcion[i]);
	        list[i].isEmpty = isEmpty[i];
		}
		result = 0;
	}

	result = calcularIntMayor(id, 2);

	return result;
}

int listarTodosLosTiposArtista(eTipoArtista* list, int len){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Tipos Artistas Musicales\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
				printf("Codigo de Tipo Artistas: %4d, Descripcion: %51s\n",list[i].id,list[i].descripcion);
		}
		result = 0;
	}
	return result;
}


