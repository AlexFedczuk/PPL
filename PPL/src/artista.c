/*
 * artista.c
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */

int inicializarArtistas(eArtista* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].codigoArtista = 0;
            strcpy(list[i].nombre, " ");
            list[i].isEmpty = 1;
        }
        result = 0;
    }
    return result;
}

int hardcodearArtistas(eArtista* list, int len){
	int idAux[5] = {1,2,3,4,5};
	char descripcionAux[5][50] = {"Clapton","Armstrong","Beatles","Cash","Jackson"};
	int isEmptyAux[5] = {0,0,0,0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < 5; i++){
	        list[i].codigoArtista = idAux[i];
	        strcpy(list[i].nombre, descripcionAux[i]);
	        list[i].isEmpty = isEmptyAux[i];
		}
		result = 0;
	}

	result = calcularIntMayor(idAux, 5);

	return result;
}


