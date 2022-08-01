/*
 * album.c
 *
 *  Created on: May 2, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "album.h"

int inicializarAlbunes(eAlbum* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].id = 0;
            strcpy(list[i].titulo, " ");
            list[i].fecha.dia = 0;
            list[i].fecha.mes = 0;
            list[i].fecha.anio = -1;
            list[i].importe = -1;
            list[i].isEmpty = 1;
            list[i].artista.id = 0;
            strcpy(list[i].artista.nombre, " ");
            list[i].tipoAlbum.id = 0;
            strcpy(list[i].tipoAlbum.descripcion, " ");
        }
        result = 0;
    }
    return result;
}

int hardcodearAlbunes(eAlbum* list, int len){
	int id[5] = {1,2,3,4,5};
	char titulo[5][50] = {"Lalala","Lelele","Lilili","Lololo","Lululu"};
	int dia[5] = {1,11,2,22,3};
	int mes[5] = {1,11,2,12,3};
	int anio[5] = {2001,2011,2022,2012,2003};
	float importe[5] = {123.22,20234.55,345.66,678.99,987.76};
	int isEmpty[5] = {0,0,0,0,0};
	int idArtista[5] = {1,2,3,4,5};
	char nombreArtista[5][50] = {"Clapton","Armstrong","Beatles","Cash","Jackson"};
	int idTipoAlbum[5] = {1,2,3,2,1};
	char descripcionTipoAlbum[5][50] = {"vinilo","cinta","CD","cinta","vinilo"};
	
	int result = -1;

	if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].id = id[i];
            strcpy(list[i].titulo, titulo[i]);
            list[i].fecha.dia = dia[i];
            list[i].fecha.mes = mes[i];
            list[i].fecha.anio = anio[i];
            list[i].importe = importe[i];
            list[i].isEmpty = isEmpty[i];
            list[i].artista.id = idArtista[i];
            strcpy(list[i].artista.nombre, nombreArtista[i]);
            list[i].tipoAlbum.id = idTipoAlbum[i];
            strcpy(list[i].tipoAlbum.descripcion, descripcionTipoAlbum[i]);
        }
        result = 0;
    }

	result = calcularIntMayor(id, 5);

	return result;
}

int cargarAlbum(eAlbum* list, eTipoAlbum* listTipoAlbum, eArtista* listArtista, int len, int* pId){
	int codigoArtista;
    int id;
    char titulo[51];
    int dia, mes, anio;
    float importe;
    int idArtista;
    char nombreArtista[51];
    int idTipoAlbum;
    char descripcionTipoAlbum[51];
    char respuesta;
    int bandera = 0;



    if(list != NULL && listTipoAlbum != NULL && len > 0){
        do{
            /*if(bandera == 0){
            	id = contadorId;
            }else{
                id++;
            }*/
            
            if(bandera == 0){
                id = *pId;
            }else{
                id = *pId + 1;
                *pId = id;
            }

            PedirNombre("\nIngrese el nombre del Album: ", titulo, 50);
            fflush(stdin);
            formalizarNombre(titulo, strlen(titulo));

            pedirFecha(&dia, &mes, &anio);
            fflush(stdin);

            getNumeroFloat(&importe,"\nIngrese el importe: ", "\nERROR! Valor ingresado invalido\n", 0, 99999, 0, BUFFER_SIZE);
            fflush(stdin);
            
            listarTodosLosArtistas(listArtista, 5);
            getNumeroInt(&idArtista,"\nIngrese el ID del Artista: ", "\nERROR! Valor ingresado invalido\n", 1, 5, 0, BUFFER_SIZE);
            strcpy(nombreArtista, listArtista[idArtista - 1].nombre);

            listarTodosLosTiposAlbune(listTipoAlbum, 3);
            getNumeroInt(&idTipoAlbum,"\nIngrese el ID del Tipo de Album: ", "\nERROR! Valor ingresado invalido\n", 1, 3, 0, BUFFER_SIZE);
            strcpy(descripcionTipoAlbum, listTipoAlbum[idTipoAlbum - 1].descripcion);

            addAlbum(list, len, idArtista, id, titulo, dia, mes, anio, importe, idTipoAlbum, descripcionTipoAlbum, nombreArtista);

            printf("\nDesea cargar otro Album(S/N)?: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            respuesta = tolower(respuesta);
            if(respuesta == 'n'){
            	break;
            }

            bandera = 1;
        }
        while(respuesta != 'n');
    }

    return id;
}

int addAlbum(eAlbum* list, int len, int idArtista, int id, char* titulo, int dia, int mes, int anio, float importe, int idTipoAlbum, char* descripcionTipoAlbum, char* nombreArtista){
	int espacioVacio;
	int resultado = -1;

	espacioVacio = buscarEspacioVacio(list, len);

	if(list != 0 && len > 0 && espacioVacio != -1)
	{
		list[espacioVacio].id = id;
        strcpy(list[espacioVacio].titulo, titulo);
        list[espacioVacio].fecha.dia = dia;
        list[espacioVacio].fecha.mes = mes;
        list[espacioVacio].fecha.anio = anio;
        list[espacioVacio].importe = importe;
        list[espacioVacio].isEmpty = 0;
        list[espacioVacio].artista.id = idArtista;
        strcpy(list[espacioVacio].artista.nombre, nombreArtista);
        list[espacioVacio].tipoAlbum.id = idTipoAlbum;
        strcpy(list[espacioVacio].tipoAlbum.descripcion, descripcionTipoAlbum);
        
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
			getNumeroInt(&idIngresado,"\nIngrese el Codigo de Album que quiere modificar: ", "\nERROR! Valor ingresado invalido\n", 1, 1000, 0, buffer);

			index = findAlbumById(list, len, idIngresado);

			if(index == -1){
				printf("\nError! Invalid length or NULL pointer received or entity not found!\n");
			}else{
				if(menuModificacion(list, index, buffer) == -1) // ------------------------------------------> Esto habria que cambiarlo, 51 por una CONSTANTE...
					printf("\nError! Invalid length or NULL pointer received or entity not found!\n");
				}
		}while(idIngresado < 1 || index == -1);
		result = 0;
	}
	return result;
}

int findAlbumById(eAlbum* list, int len, int id){
	int index = -1;

	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				index = i;
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

	printf("\nindex %d\n", index);

	if(list != NULL && index > -1 && buffer > 0){
		do{
			mostarMenuModificacion();
			getNumeroInt(&opcionMenu,"\tIngrese una opcion del menu de modificacion: ", "\nERROR! Valor ingresado invalido\n", 1, 5, 0, buffer);
			fflush(stdin);

			switch(opcionMenu){
				case 1:
					PedirNombre("\n\tIngrese el nuevo titulo del album: ", list[index].titulo, BUFFER_SIZE);
                    fflush(stdin);
                    formalizarNombre(list[index].titulo, strlen(list[index].titulo));
					break;
				case 2:
					pedirFecha(&dia, &mes, &anio);
					list[index].fecha.dia = dia;
					list[index].fecha.mes = mes;
					list[index].fecha.anio = anio;
					break;
				case 3:
					getNumeroFloat(&list[index].importe,"\n\tIngrese el nuevo importe: ", "\nERROR! Valor ingresado invalido\n", 0, 99999, 0, buffer);
					fflush(stdin);
					break;
				case 4:
					mostrarMenuTiposAlbum();
					getNumeroInt(&list[index].tipoAlbum.id,"\nIngrese el Tipo de Album: ", "\nERROR! Valor ingresado invalido\n", 1, 3, 0, buffer);
					break;
				default:
					if(opcionMenu < 1 || opcionMenu > 5){
						printf("\nERROR! Debe ingresar una opcion del menu de modificacion!\n");
					}
			}
		}while(opcionMenu != 5);
		result = 0;
	}
	return result;
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
			if(list[i].id == id){
				list[i].isEmpty = 1;
				result = 0;
				break;
			}
		}
	}

	return result;
}

int buscarEspacioVacio(eAlbum* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            if(list[i].isEmpty == 1)
            {
                result = i;
                break;
            }else{
                result = -2;
            }
        }
    }

    return result; // -1 si el puntero es NULL o LEN invalido, -2 si no hay espacios vacios. Si hay espacio, devuelvo el indice [i] de esa ubicacion.
}

float calcularTotalImportesAlbumes(eAlbum* list, int len){
    float acumulador = -1;

    if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
		    if(list[i].isEmpty == 0)
                acumulador = acumulador + list[i].importe;
        }
	}
    return acumulador;
}

float calcularPromedio(eAlbum* list, int len, float total){
    float promedio = -1;
    int contador = 0;

    if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
		    if(list[i].isEmpty == 0)
		        contador++;
        }

        if(contador != 0)
            promedio = total / contador;
	}

    return promedio;
}

int contarMayorAPromedio(eAlbum* list, int len, float promedio){
    int contador = 0;

    if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
		    if(list[i].isEmpty == 0 && list[i].importe > promedio){
		        contador++;
		    }
        }
	}
    return contador;
}

int contarTodosLosAlbunesMenoresAnio(eAlbum* list, int len, int anio){
	int contador = 0;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].fecha.anio < anio) {
			    contador++;
			}
		}
	}
	return contador;
}

int listarTodosLosAlbunes(eAlbum* list, int len){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes (dd/mm/aaaa)\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0){
			    printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f, Tipo de Album: %51s\n",list[i].id,
			                                                                                                             list[i].titulo,
			                                                                                                             list[i].fecha.dia,
			                                                                                                             list[i].fecha.mes,
			                                                                                                             list[i].fecha.anio,
			                                                                                                             list[i].importe, 
			                                                                                                             list[i].tipoAlbum.descripcion);
			}
		}
		result = 0;
	}
	return result;
}

int listarTodosLosAlbunesMenoresAnio(eAlbum* list, int len, int anio){
	int result = -1;
	int bandera = 0;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes menores a el anio %d (dd/mm/aaaa)\n", anio);
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].fecha.anio < anio){
			    bandera = 1;
			    printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[i].id,
			                                                                                        list[i].titulo,
			                                                                                        list[i].fecha.dia,
			                                                                                        list[i].fecha.mes,
			                                                                                        list[i].fecha.anio,
			                                                                                        list[i].importe);
			}
		}
		
		if(bandera == 0){
		    printf("No hay ningun Album menor a el anio %d\n", anio);
		}
		result = 0;
	}
	return result;
}

int listarTodosLosAlbunesMayoresPromedioImporte(eAlbum* list, int len, float importe){
	int result = -1;
	int bandera = 0;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes mayores al promedio %8.2f de importes\n", importe);
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].importe > importe){
			    bandera = 1;
			    printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[i].id,
			                                                                                        list[i].titulo,
			                                                                                        list[i].fecha.dia,
			                                                                                        list[i].fecha.mes,
			                                                                                        list[i].fecha.anio,
			                                                                                        list[i].importe);
			}
		}
		
		if(bandera == 0){
		    printf("No hay ningun Album mayor con un importe mayor a %.2f\n", importe);
		}
		
		result = 0;
	}
	return result;
}

int listarTodosLosAlbunesAnioDeterminado(eAlbum* list, int len, int anio){
	int result = -1;
	int bandera = 0;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes publicados el anio %d (dd/mm/aaaa)\n", anio);
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].fecha.anio == anio){
			    bandera = 1;
			    printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[i].id,
			                                                                                        list[i].titulo,
			                                                                                        list[i].fecha.dia,
			                                                                                        list[i].fecha.mes,
			                                                                                        list[i].fecha.anio,
			                                                                                        list[i].importe);
			}
		}
		
		if(bandera == 0){
		    printf("No hay ningun Album publicado el anio %d.\n", anio);
		}
		
		result = 0;
	}
	return result;
}

int listarTodosLosAlbunesMasCaros(eAlbum* list, int len, float numero){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes mas caros %f\n", numero);
		for(int i = 0; i < len; i++){
			if(list[i].importe >= numero){
			    printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[i].id,
				                                                                                    list[i].titulo,
				                                                                                    list[i].fecha.dia,
				                                                                                    list[i].fecha.mes,
				                                                                                    list[i].fecha.anio,
				                                                                                    list[i].importe);
			}
		}
		result = 0;
	}
	return result;
}

float calcularAlbumMasCaro(eAlbum* list, int len){
	float mayor;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0){
			    if(i == 0 || mayor < list[i].importe){
			        mayor = list[i].importe;
			    }
			}
		}
	}else{
	    mayor = -1;
	}

	return mayor;
}

int ordenarAlbunesImporteTitulo(eAlbum* list, int len){
	int retorno = -1;
	eAlbum auxAlbum;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			for(int j = i + 1; j < len; j++){
				if(list[i].importe > list[j].importe){
					auxAlbum = list[i];
					list[i] = list[j];
					list[j] = auxAlbum;
				}else{
					if(list[i].importe == list[j].importe){
						if(strcmp(list[i].titulo, list[j].titulo) < 0){
							auxAlbum = list[i];
							list[i] = list[j];
							list[j] = auxAlbum;
						}
					}
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int listarAlbunesDeArtistas(eAlbum* list, eArtista* list2, int len, int len2){
	int retorno = -1;

	if(list != NULL && list2 != NULL && len > 0){
		printf("\nTodos los Albumes de cada artista");

		for(int i = 0; i < len2; i++){
			if(list2[i].isEmpty == 0){
				printf("\nArtista: %s\n", list2[i].nombre);
				for(int j = 0; j < len; j++){
					if(list2[i].id == list[j].id){
						printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[j].id,
						                                                                                    list[j].titulo,
						                                                                                    list[j].fecha.dia,
						                                                                                    list[j].fecha.mes,
						                                                                                    list[j].fecha.anio,
						                                                                                    list[j].importe);
					}
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int listarAlbumesViniloArtista(eAlbum* list, eTipoAlbum* list2, int len){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes de Vinilo\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].tipoAlbum.id == 1)
				printf("Codigo de Album: %4d, Titulo: %20s, Fecha: %02d/%02d/%4d, Importe: %8.2f, Tipo de Album: %10s\n", list[i].id,
				                                                                                                          list[i].titulo,
				                                                                                                          list[i].fecha.dia,
				                                                                                                          list[i].fecha.mes,
				                                                                                                          list[i].fecha.anio,
				                                                                                                          list[i].importe,
				                                                                                                          list[i].tipoAlbum.descripcion);
		}
		result = 0;
	}
	return result;
}

int listarTodosLosAlbumesCadaArtista(eAlbum* listAlbum, eArtista* listArtista,int lenAlbum, int lenArtista){
	int result = -1;

	if(listAlbum != NULL && lenAlbum > 0 && listArtista != NULL && lenArtista > 0){
		printf("\nTodos los Albumes de cada Artista\n");
		for(int j = 0; j < lenArtista; j++){
		    if(listArtista[j].isEmpty == 0){
		        printf("Codigo de Artista: %4d, Nombre: %51s\n",listArtista[j].id, listArtista[j].nombre);
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
    	    if(listAlbum[i].isEmpty == 0 && listAlbum[index].id == listArtista[i].id) {
        	    printf("\tCodigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n", listAlbum[i].id,
        	                                                                                           listAlbum[i].titulo,
        	                                                                                           listAlbum[i].fecha.dia,
        	                                                                                           listAlbum[i].fecha.mes,
        	                                                                                           listAlbum[i].fecha.anio,
        	                                                                                           listAlbum[i].importe);
        	}
        }
    }

    return result;
}
