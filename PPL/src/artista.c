/*
 * artista.c
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "artista.h"

int inicializarArtistas(eArtista* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].id = 0;
            strcpy(list[i].nombre, " ");
            list[i].isEmpty = 1;
        }
        result = 0;
    }
    return result;
}

int hardcodearArtistas(eArtista* list, int len){
	int id[5] = {1,2,3,4,5};
	char nombre[5][50] = {"Clapton","Armstrong","Beatles","Cash","Jackson"};
	int isEmpty[5] = {0,0,0,0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
	        list[i].id = id[i];
	        strcpy(list[i].nombre, nombre[i]);
	        list[i].isEmpty = isEmpty[i];
		}
		result = 0;
	}

	result = calcularIntMayor(id, 5);

	return result;
}

int listarTodosLosArtistas(eArtista* list, int len){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Artistas\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
				printf("Codigo de Artista: %4d, Nombre: %51s\n",list[i].id,list[i].nombre);
		}
		result = 0;
	}
	return result;
}
