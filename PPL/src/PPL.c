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
#include "Controller.h"

#define BUFFER 51

int main(void){
    setbuf(stdout, NULL);
    
    int opcionMenu;
    int opcionUnoCargada = 0;
    int contadorCodigoGenero;
    int contadorCodigoTipoArtista;
    int contadorCodigoArtista;
    int contadorCodigoAlbum = 0;
    int contadorCodigoTiposAlbum;
    
    eGenero generoList[5];
    eTipoArtista tipoArtistaList[2];
    eArtista artistaList[5];
    eAlbum albumList[LEN];
    eTipoAlbum tiposAlbumList[3];
    
    Controller_Inicializadores(albumList, tiposAlbumList, artistaList, tipoArtistaList, generoList, LEN);
    
    Controller_Hardcodeadores(albumList, tiposAlbumList, artistaList, tipoArtistaList, generoList, &contadorCodigoGenero, 
                                                                                                   &contadorCodigoTipoArtista, 
                                                                                                   &contadorCodigoArtista, 
                                                                                                   &contadorCodigoAlbum, 
                                                                                                   &contadorCodigoTiposAlbum);
    
    do{
        mostrarMenu();
        getNumeroInt(&opcionMenu,"\nIngrese una opcion del menu principal: ", "\nERROR! Valor ingresado invalido\n", 1, 6, 0, BUFFER_SIZE);
        fflush(stdin);
        
        if(contadorCodigoAlbum = 5){
            opcionUnoCargada = 1;
        }
        
        switch(opcionMenu)
        {
            case 1:
                Controller_Altas(albumList, tiposAlbumList, artistaList, &contadorCodigoAlbum, LEN, &opcionUnoCargada);
                break;
            case 2:
                Controller_Modificaciones(albumList, LEN, &opcionUnoCargada);
                break;
            case 3:
                Controller_Baja(albumList, LEN, &opcionUnoCargada);
                break;
            case 4:
                Controller_Informes(albumList, LEN, &opcionUnoCargada);
                break;
            case 5:
                Controller_Listados(albumList, generoList, tipoArtistaList, artistaList, tiposAlbumList, LEN, &opcionUnoCargada);
                break;
            default:
                break;
        }
    }while(opcionMenu != 6);
    
    return 0;
}
