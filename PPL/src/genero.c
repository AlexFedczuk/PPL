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
            list[i].codigoGenero = 0;
            strcpy(list[i].descripcion, " ");
            list[i].isEmpty = 1;
        }
        result = 0;
    }
    return result;
}

int hardcodearGeneros(eGenero* list, int len){
	int idAux[5] = {1,2,3,4,5};
	char descripcionAux[5][50] = {"Blues","Jazz","Rock","Country","Disco"};
	int isEmptyAux[5] = {0,0,0,0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < 5; i++){
	        list[i].codigoGenero = idAux[i];
	        strcpy(list[i].descripcion, descripcionAux[i]);
	        list[i].isEmpty = isEmptyAux[i];
		}
		result = 0;
	}

	result = calcularIntMayor(idAux, 5);

	return result;
}

int listarTodosLosGeneros(eGenero* list, int len){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Generos\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
				printf("Codigo de Genero: %4d, Descripcion: %51s\n",list[i].codigoGenero,list[i].descripcion);
		}
		result = 0;
	}
	return result;
}


