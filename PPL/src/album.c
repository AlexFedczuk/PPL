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
            list[i].codigoAlbum = 0;
            strcpy(list[i].titulo, " ");
            list[i].fecha.dia = 0;
            list[i].fecha.mes = 0;
            list[i].fecha.anio = -1;
            list[i].importe = -1;
            list[i].isEmpty = 1;
            list[i].codigoArtista = 0;
            list[i].idTipoAlbum = 0;
        }
        result = 0;
    }
    return result;
}

int cargarAlbum(eAlbum* list, int len, int contadorId, int buffer){
	int codigoArtista;
    int id;
    char titulo[buffer];
    int dia, mes, anio;
    float importe;
    int tipoAlbum;
    char respuesta;
    int bandera = 0;



    if(list != NULL && len > 0){
        do{
        	getNumeroInt(&codigoArtista,"\nIngrese el Codigo del Artista al que pertenecera este Album: ", "\nERROR! Valor ingresado invalido\n", 0, 5, 0, buffer);
        	fflush(stdin);

            if(bandera == 0){
            	id = contadorId;
            }else{
                id++;
            }

            PedirNombre("\nIngrese el nombre del pasajero: ", titulo, 50);
            fflush(stdin);
            formalizarNombre(titulo, strlen(titulo));

            pedirFecha(&dia, &mes, &anio);
            fflush(stdin);

            getNumeroFloat(&importe,"\nIngrese el importe: ", "\nERROR! Valor ingresado invalido\n", 0, 99999, 0, buffer);
            fflush(stdin);

            mostrarMenuTiposAlbum();
            getNumeroInt(&tipoAlbum,"\nIngrese el Tipo de Album: ", "\nERROR! Valor ingresado invalido\n", 1, 3, 0, buffer);

            if(addAlbum(list, len, codigoArtista, id, titulo, dia, mes, anio, importe, tipoAlbum) == -1)
            	printf("\nError! Invalid length or NULL pointer, al agregar el album la lista!\n");

            printf("\nDesea cargar otro pasajero(S/N)?: ");
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

int addAlbum(eAlbum* list, int len, int codigoArtista, int id, char titulo[], int dia, int mes, int anio, float importe, int tipoAlbum){
	int espacioVacio;
	int resultado = -1;

	espacioVacio = buscarEspacioVacio(list, len);

	if(list != 0 && len > 0 && espacioVacio != -1)
	{
		list[espacioVacio].codigoArtista = codigoArtista;
		list[espacioVacio].codigoAlbum = id;
	    strcpy(list[espacioVacio].titulo, titulo);
	    list[espacioVacio].fecha.dia = dia;
	    list[espacioVacio].fecha.mes = mes;
	    list[espacioVacio].fecha.anio = anio;
	    list[espacioVacio].importe = importe;
	    list[espacioVacio].idTipoAlbum = tipoAlbum;
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
			if(list[i].codigoAlbum == id){
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
					pedirUnaCadenaAlpha(list[index].titulo, "\n\tIngrese el nuevo titulo del album: ", buffer);// Esto habria que cambiarlo, 51 por una CONSTANTE...
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
					getNumeroInt(&list[index].idTipoAlbum,"\nIngrese el Tipo de Album: ", "\nERROR! Valor ingresado invalido\n", 1, 3, 0, buffer);
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
			if(list[i].codigoAlbum == id){
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

int listarTodosLosAlbunes(eAlbum* list, eTipoAlbum* list2, int len){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes (dd/mm/aaaa)\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
				printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f, Tipo de Album: %51s\n",list[i].codigoAlbum,list[i].titulo,list[i].fecha.dia,list[i].fecha.mes,list[i].fecha.anio,list[i].importe, list2[list[i].idTipoAlbum - 1].descripcion);
		}
		result = 0;
	}
	return result;
}

int listarTodosLosAlbunesMenoresAnio(eAlbum* list, int len, int anio){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes menores a el anio %d (dd/mm/aaaa)\n", anio);
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].fecha.anio < anio) {
			    printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[i].codigoAlbum,list[i].titulo,list[i].fecha.dia,list[i].fecha.mes,list[i].fecha.anio,list[i].importe);
			}
		}
		result = 0;
	}
	return result;
}

int listarTodosLosAlbunesMayoresPromedioImporte(eAlbum* list, int len, float importe){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes mayores al promedio %8.2f de importes\n", importe);
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].importe < importe) {
			    printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[i].codigoAlbum,list[i].titulo,list[i].fecha.dia,list[i].fecha.mes,list[i].fecha.anio,list[i].importe);
			}
		}
		result = 0;
	}
	return result;
}

int listarTodosLosAlbunesAnioDeterminado(eAlbum* list, int len, int anio){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes publicados el anio %d (dd/mm/aaaa)\n", anio);
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].fecha.anio == anio) {
			    printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[i].codigoAlbum,list[i].titulo,list[i].fecha.dia,list[i].fecha.mes,list[i].fecha.anio,list[i].importe);
			}
		}
		result = 0;
	}
	return result;
}

int listarTodosLosAlbunesMasCaros(eAlbum* list, int len, float numero){
	int result = -1;

	if(list != NULL && len > 0){
		printf("\nTodos los Albunes mas caros\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].importe == numero)
				printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[i].codigoAlbum,list[i].titulo,list[i].fecha.dia,list[i].fecha.mes,list[i].fecha.anio,list[i].importe);
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

int listarAlbunesDeArtistas(eAlbum* list, eArtista* list2, int len){
	int retorno = -1;

	if(list != NULL && list2 != NULL && len > 0){
		printf("\nTodos los álbumes de cada artista\n");

		for(int i = 0; i < len; i++){
			if(list2[i].isEmpty == 0){
				printf("\nArtista: %s\n",list2[i].nombre);

				for(int j = i + 1; j < len; j++){
					if(list2[i].codigoArtista == list[j].codigoArtista){
						printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f\n",list[j].codigoAlbum,list[j].titulo,list[j].fecha.dia,list[j].fecha.mes,list[j].fecha.anio,list[j].importe);
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
		printf("\nTodos los Tipos de Albunes\n");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].idTipoAlbum == 2)
				printf("Codigo de Album: %4d, Titulo: %51s, Fecha: %02d/%02d/%4d, Importe: %8.2f, Tipo de Album: %51s\n",list[i].codigoAlbum,list[i].titulo,list[i].fecha.dia,list[i].fecha.mes,list[i].fecha.anio,list[i].importe, list2[list[i].idTipoAlbum - 1].descripcion);
		}
		result = 0;
	}
	return result;
}
