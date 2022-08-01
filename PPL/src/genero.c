/*
 * genero.c
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "genero.h"

int inicializarGeneros(eGenero* list, int len){
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

int hardcodearGeneros(eGenero* list, int len){
	int id[5] = {1,2,3,4,5};
	char descripcion[5][50] = {"Blues","Jazz","Rock","Country","Disco"};
	int isEmpty[5] = {0,0,0,0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < 5; i++){
	        list[i].id = id[i];
	        strcpy(list[i].descripcion, descripcion[i]);
	        list[i].isEmpty = isEmpty[i];
		}
		result = 0;
	}

	result = calcularIntMayor(id, 5);

	return result;
}

int listarTodosLosGeneros(eGenero* list, int len){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Generos\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
				printf("Codigo de Genero: %4d, Descripcion: %51s\n",list[i].id,list[i].descripcion);
		}
		result = 0;
	}
	return result;
}


