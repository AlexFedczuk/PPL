/*
 * tipoArtista.c
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */

int inicializarTipoArtistass(eTipoArtista* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].codigoTipoArtistas = 0;
            strcpy(list[i].descripcion, " ");
            list[i].isEmpty = 1;
        }
        result = 0;
    }
    return result;
}

int hardcodearTipoArtistas(eTipoArtista* list, int len){
	int idAux[2] = {1,2};
	char descripcionAux[2][50] = {"Solista","Banda"};
	int isEmptyAux[2] = {0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < 5; i++){
	        list[i].codigoTipoArtistas = idAux[i];
	        strcpy(list[i].descripcion, descripcionAux[i]);
	        list[i].isEmpty = isEmptyAux[i];
		}
		result = 0;
	}

	result = calcularIntMayor(idAux, 2);

	return result;
}


