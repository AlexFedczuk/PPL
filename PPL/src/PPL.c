/*
 ============================================================================
 Name        : PPL.c
 Author      : Alex Yago Fedczuk
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	    int opcionMenu;
	    int opcionUnoCargada;
	    int contadorIdProveedores;
	    int contadorIdProductos;

	    eGenero generoList[LEN];
	    eTipoArtista tipoArtistaList[LEN];
	    eArtista artistaList[LEN];
	    eAlbum albumList[LEN];

	    opcionUnoCargada = 0;
	    contadorCodigoGenero = 0;
	    contadorCodigoTipoArtista = 0;
	    contadorCodigoArtista = 0;
	    contadorCodigoAlbum = 0;

	    if(inicializarGeneros(generoList, LEN) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Generos!\n");// listo, falta probar
	    if(inicializarTipoArtistas(tipoArtistaList, 2) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Tipo de Artistas!\n");// listo, falta probar
	    if(inicializarArtistas(artistaList, LEN) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Artistas!\n");// listo, falta probar
	    if(inicializarAlbunes(albumList, LEN) == -1)
	    	printf("\nError! Invalid length or NULL pointer, al inicializar la lista de Albunes!\n");// listo, falta probar

	    contadorCodigoGenero = hardcodearGeneros(generoList, LEN);// listo, falta probar
	    contadorCodigoTipoArtista = hardcodearTipoArtistas(tipoArtistaList, 2);// listo, falta probar
	    contadorCodigoArtista = hardcodearArtistas(artistaList, LEN);// listo, falta probar
	    contadorCodigoAlbum = hardcodearAlbunes(albumList, LEN);// listo, falta probar

	    if(contadorCodigoGenero == -1)
	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Generos!\n");// listo, falta probar
	    if(contadorCodigoTipoArtista == -1)
	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Tipo de Artistas!\n");// listo, falta probar
	    if(contadorCodigoArtista == -1)
	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Artistas!\n");// listo, falta probar
	    if(contadorCodigoAlbum == -1)
	    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de Albunes!\n");// listo, falta probar

	    do{
	        mostrarMenu();// listo, falta probar
	        opcionMenu = pedirNumeroEntero("Ingrese una opcion del menu principal: ");

	        switch(opcionMenu)
	        {
	            case 1:
	            	if(buscarEspacioVacio(albumList, LEN) != -2){
	            		contadorCodigoAlbum++;
	            		contadorCodigoAlbum = cargarAlbum(albumList, LEN, contadorCodigoAlbum);// listo, falta probar

	            		opcionUnoCargada = 1;
	            	}else{
	            		printf("\nERROR! Ya no quedan espacios en el programa para ingresar mas altas a la lista!\n");
	            	}

	                break;
	            case 2:
	            	if(opcionUnoCargada == 1){
	            		printPassenger(albumList, LEN);
	            		if(modificarAlbum(albumList, LEN) == -1)// Falta pulir la carga de pasajeros, mirar el desarrollo de la funcion!
	            		            printf("\nError! Invalid length or NULL pointer, al querer ingresar a la opcion 2 del Menu Principal!\n");
	            	}else{
	            	    printf("\nERROR! Se debe realizar una alta para realizar una modificacion!\n");
	            	}
	            	break;
	            case 3:
	                if(opcionUnoCargada == 1){
	                	//printPassenger(passengerList, LEN);
	                	darBajaAlbum(albumList, LEN);
	                }else{
	                	printf("\nERROR! Se debe realizar una alta para realizar una baja!\n");
	                }
	                break;
	            case 4:
	            	//printPassenger(passengerList, LEN);
	            	if(opcionUnoCargada == 1){
	            		//printPassenger(passengerList, LEN);
	            	}else{
	            		printf("\nERROR! Se debe realizar una alta para realizar un informe!\n");
	            	}
	                break;
	            case 5:
	            	//printPassenger(passengerList, LEN);
	            	if(opcionUnoCargada == 1){
	            	   printPassenger(passengerList, LEN);
	            	}else{
	            	   printf("\nERROR! Se debe realizar una alta para realizar un informe!\n");
	            	}
	            	break;
	            default:
	            	if(opcionMenu < 1 || opcionMenu > 6)
	            		printf("\nERROR! Debe ingresar una opcion del menu principal!\n");
	                system("pause");
	                system("cls");// Por alguna razon, no la reconoce la funcion...
	                break;
	        }
	    }while(opcionMenu != 6);

	    return 0;
}
