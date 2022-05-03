/*
 * album.c
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */

int inicializarAlbunes(eAlbum* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].codigoAlbum = 0;
            strcpy(list[i].titulo, " ");
            list[i].fecha.dia = 0;
            list[i].fecha.mes = 0;
            list[i].fecha.anio = -1;
            list[i].importe = -1;
            list[i].isEmpty = 1;
        }
        result = 0;
    }
    return result;
}

int cargarAlbum(eAlbum list[], int len, int contadorId, int buffer){
    int id;
    char titulo[buffer];
    int dia, mes, anio;
    float importe;
    char respuesta;
    int bandera = 0;



    if(list != NULL && len > 0){
        do{
            id = calcularId(bandera, id, contadorId);

            pedirUnaCadena(titulo, "\nIngrese El titulo del album: ", buffer); // Probar la nueva validacion!
            formalizarUnaCadena(titulo, buffer);// Probar la nueva funcion!

            pedirFecha(&dia, &mes, &anio);

            importe = pedirFlotanteNoNegativo("\nIngrese el importe: ");

            if(addAlbum(list, len, id, titulo, dia, mes, anio, importe) == -1)
            	printf("\nError! Invalid length or NULL pointer, al agregar el album la lista!\n");

            respuesta = pedirUnCaracterAlphaMinuscula("\nDesea cargar otro pasajero(s/n)?: ");// Probar la nueva funcion!
            if(respuesta == 'n')
                break;
            bandera = 1;
        }
        while(respuesta != 'n');
    }
    fflush(stdin);// Hay que realizar pruebas poniedo y sacando esta sentencia, para ver si se repiten "mensajes"...

    return id;
}

int addAlbum(eAlbum* list, int len, int id, char titulo[], int dia, int mes, int anio, float importe){
	int espacioVacio;
	int resultado = -1;

	espacioVacio = buscarEspacioVacio(list, len);

	if(list != 0 && len > 0 && espacioVacio != -1)
	{
		list[espacioVacio].codigoAlbum = id;
	    strcpy(list[espacioVacio].titulo, titulo);
	    list[i].fecha.dia = dia;
	    list[i].fecha.mes = mes;
	    list[i].fecha.anio = anio;
	    list[espacioVacio].importe = importe;
	    list[espacioVacio].isEmpty = 0;
	    resultado = 0;
	}

	return resultado;
}

int modificarAlbum(eAlbum* list, int len, int buffer){
	int idIngresado;
	int index;
	int result = -1;

	if(list != NULL && len > 0){
		do{
			idIngresado = pedirNumeroEnteroNoNegativo("\nIngrese el Codigo de Album que quiere modificar: ");
			if(idIngresado < 1){
				printf("\nError! El Codigo de Album debe ser mayor a cero (0)!\n");
			}else{
				index = findAlbumById(list, len, idIngresado);
				if(index == -1){
					printf("\nError! Invalid length or NULL pointer received or entity not found!\n");
				}else{
					if(menuModificacion(list, index, buffer) == -1) // ------------------------------------------> Esto habria que cambiarlo, 51 por una CONSTANTE...
						printf("\nError! Invalid length or NULL pointer received or entity not found!\n");

				}
			}
		}while(idIngresado < 1 || index == -1);
	}
	return result;
}

int findAlbumById(eAlbum* list, int len, int id){
	int index = -1;

	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if(list[i].codigoAlbum == id){
				index = list[i].codigoAlbum;
				break;
			}
		}
	}

	return index;
}

int menuModificacion(eAlbum* list, int index, int buffer){
	int result = -1;
	int opcionMenu;
	int dia, mes, anio;

	if(list != NULL && index > -1 && buffer > 0){
		do{
			mostarMenuModificacion();
			opcionMenu = pedirNumeroEntero("\tIngrese una opcion del menu de modificacion: ");
			switch(opcionMenu){
				case 1:
					pedirUnaCadenaAlpha(list[index].titulo, "\nIngrese el nuevo nombre del pasajero: ", buffer);// Esto habria que cambiarlo, 51 por una CONSTANTE...
					break;
				case 2:
					pedirFecha(&dia, &mes, &anio);
					list[index].fecha.dia = dia;
					list[index].fecha.mes = mes;
					list[index].fecha.mes = anio;
					break;
				case 3:
					list[index].importe = pedirNumeroFlotante("\nIngrese el nuevo importe: ");
					break;
				default:
					if(opcionMenu < 1 || opcionMenu > 4){
						printf("\nERROR! Debe ingresar una opcion del menu de modificacion!\n");
					}
						system("pause");
						break;
			}
		}while(opcionMenu != 4);
		result = 0;
	}
	return result;
}

void mostarMenuModificacion(){
	printf("\n\tMenu de Modificacion\n");
	printf("\t1. Titulo\n");
	printf("\t2. Fecha\n");
	printf("\t3. Importe\n");
	printf("\t4. Salir\n\n");
}

int darBajaAlbum(eAlbum* list, int len){
	int idIngresado;
	int index;
	int result = -1;

	if(list != NULL && len > 0){
		do{
			idIngresado = pedirNumeroEntero("\nIngrese el Codigo de Album que quiere dar de baja: ");
			if(idIngresado < 1){
				printf("\nError! El Codigo de Album debe ser mayor a cero (0)!\n");
			}else{
				index = findAlbumById(list, len, idIngresado);
				if(index == -1){
					printf("\nError! Invalid length or NULL pointer received or passenger not found!\n");
				}else{
					result = removeAlbum(list, len, idIngresado);
					printf("\nEl Album seleccioando fue dado de baja.\n");
				}
			}
		}while(idIngresado < 1 || index == -1);
	}
	return result;
}

int removeAlbum(eAlbum* list, int len, int id){
	int result = -1;

	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if(list[i].codigoAlbum == id){
				list[i].isEmpty = 1;
				result = 0;
				break;
			}
		}
	}

	return result;
}

