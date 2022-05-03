/*
 * miBiblioteca.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */
#include <stdio.h>
#include <string.h>
#include "miBiblioteca.h"

void mostrarMenu(){
    printf("\nMenu pricipal\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. LISTAR\n");
    printf("6. Salir\n\n");
}

int hardcodearProveedores(eProveedor* list, int len){
	int idAux[5] = {1,2,3,4,5};
	char descripcionAux[5][50] = {"ADECCO","ASE","AVATAR","CLOUDWARE","SAC"};
	int isEmptyAux[5] = {0,0,0,0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < 5; i++){
	        list[i].codigoProveedor = idAux[i];
	        strcpy(list[i].descripcion, descripcionAux[i]);
	        list[i].isEmpty = isEmptyAux[i];
		}
		result = 0;
	}

	result = calcularIntMayor(idAux, 5);

	return result;
}

int hardcodearProductos(eProducto* list, int len){
	int idAux[5] = {1,2,3,4,5};
	char descripcionAux[5][50] = {"PRODUCTO ADECCO","PRODUCTO ASE","PRODUCTO AVATAR","PRODUCTO CLOUDWARE","PRODUCTO SAC"};
	int importeAux[5] = {15000.234,20500.12,2225750.56,55400.78,42600.12};
	int cantidadAux[5] = {5,10,8,2,1};
	int isEmptyAux[5] = {0,0,0,0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < 5; i++){
	        list[i].codigoProducto = idAux[i];
	        strcpy(list[i].descripcion, descripcionAux[i]);
	        list[i].importe = importeAux[i];
	        strcpy(list[i].cantidad, cantidadAux[i]);
	        list[i].isEmpty = isEmptyAux[i];
		}
		result = 0;
	}

	result = calcularIntMayor(idAux, 5);

	return result;
}

int calcularIntMayor(int vec[], int len){
	int result;

	for(int i = 0; i < len; i++){
		if(i == 0){
			result = vec[i];
		}else if(result < vec[i]){
			result = vec[i];
		}
	}

	return result;
}

char pedirUnCaracterAlphaMinuscula(char mensaje[]){
    char result;

    do{
        printf(mensaje);
        fflush(stdin);
        ("%c", &result);
        if(isalpha(result) != 0){
            result = tolower(result);
        }else{
            printf("\nError! Debe ingresar caracteres alfabeticos!\n");
        }
    }while(isalpha(result) != 0);


    return result;
}

void formalizarUnaCadena(char cadena[], int buffer){ // Probar esta nueva funcion!
    for(int i = 0; i < buffer; i++){
        if(i == 0){
            cadena[i] = toupper(cadena[i]);
            //toupper(cadena[i]);
        }else{
            cadena[i] = tolower(cadena[i]);
            //tolower(cadena[i]);
        }
    }
}

void pedirFecha(int* dia, int* mes, int* anio){
	do{
		mes = pedirNumeroEnteroNoNegativo("Ingrese el mes: ");
	}while(dia < 1 || dia > 31);

	switch(mes){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			do{
				dia = pedirNumeroEnteroNoNegativo("Ingrese el dia: ");
				if(dia < 1 || dia > 31){
					printf("ERROR! Ingreso un dia fuera de rango del mes!");
				}
			}while(dia < 1 || dia > 31);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			do{
				dia = pedirNumeroEnteroNoNegativo("Ingrese el dia: ");
				if(dia < 1 || dia > 30){
					printf("ERROR! Ingreso un dia fuera de rango del mes!");
				}
			}while(dia < 1 || dia > 30);
			break;
		case 11:
			do{
				dia = pedirNumeroEnteroNoNegativo("Ingrese el dia: ");
				if(dia < 1 || dia > 29){
					printf("ERROR! Ingreso un dia fuera de rango del mes!");
				}
			}while(dia < 1 || dia > 29);
			break;
		default:
			break;

	}

	anio = pedirNumeroEntero("Ingrese el anio: ");
}











