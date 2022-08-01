#include "Controller.h"

int Controller_Inicializadores(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, eTipoArtista* tipoArtistaList, eGenero* generoList, int len){
    int retorno = -1;
    
    if(albumList != NULL && tipoAlbumList != NULL && artistaList != NULL && tipoArtistaList != NULL && generoList != NULL && len > 0){
        inicializarGeneros(generoList, 5);
        inicializarTipoArtistas(tipoArtistaList, 2);
        inicializarArtistas(artistaList, 5);
        inicializarAlbunes(albumList, len);
        inicializarTiposAlbum(tipoAlbumList, 3);
        retorno = 0;
    }
    
    return retorno;
}

int Controller_Hardcodeadores(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, eTipoArtista* tipoArtistaList, eGenero* generoList, int* contadorCodigoGenero,
                                                                                                                                                       int* contadorCodigoTipoArtista,
                                                                                                                                                       int* contadorCodigoArtista,
                                                                                                                                                       int* contadorCodigoAlbum,
                                                                                                                                                       int* contadorCodigoTiposAlbum){
    int retorno = -1;
    
    if(albumList != NULL && tipoAlbumList != NULL && artistaList != NULL && tipoArtistaList != NULL && generoList != NULL){
        *contadorCodigoGenero = hardcodearGeneros(generoList, 5);
        *contadorCodigoTipoArtista = hardcodearTipoArtistas(tipoArtistaList, 2);
        *contadorCodigoArtista = hardcodearArtistas(artistaList, 5);
        *contadorCodigoAlbum = hardcodearAlbunes(albumList, 5);
        *contadorCodigoTiposAlbum = hardcodearTiposAlbum(tipoAlbumList, 3);
        retorno = 0;
    }
    
    return retorno;
}

int Controller_Altas(eAlbum* albumList, eTipoAlbum* tipoAlbumList, eArtista* artistaList, int* contadorId, int len, int* opcionUnoCargada){
    int retorno = -1;
    
    if(albumList != NULL && tipoAlbumList != NULL && artistaList != NULL && len > 0 && contadorId != NULL && opcionUnoCargada != NULL){
        if(buscarEspacioVacio(albumList, len) != -2){
            cargarAlbum(albumList, tipoAlbumList, artistaList, len, contadorId);
            *opcionUnoCargada = 1;
            retorno = 0;
        }else{
            printf("\nERROR! Ya no quedan espacios en el programa para ingresar mas altas a la lista!\n");
            retorno = 1;
        }
    }
    
    return retorno;
}

int Controller_Modificaciones(eAlbum* albumList, int len, int* opcionUnoCargada){
    int retorno = -1;
    
    if(albumList != NULL && len > 0 && opcionUnoCargada != NULL){
        if(*opcionUnoCargada == 1){
            listarTodosLosAlbunes(albumList, len);
            modificarAlbum(albumList, len, BUFFER_SIZE);
            retorno = 0;
        }else{
            printf("\nERROR! Se debe realizar una alta para realizar una modificacion!\n");
            retorno = 1;
        }
    }
    
    return retorno;
}

int Controller_Baja(eAlbum* albumList, int len, int* opcionUnoCargada){
    int retorno = -1;
    
    if(albumList != NULL && len > 0 && opcionUnoCargada != NULL){
        if(*opcionUnoCargada == 1){
            listarTodosLosAlbunes(albumList, len);
            darBajaAlbum(albumList, len);
            retorno = 0;
        }else{
            printf("\nERROR! Se debe realizar una alta para realizar una baja!\n");
            retorno = 1;
        }
    }
    
    return retorno;
}

int Controller_Informes(eAlbum* albumList, int len, int* opcionUnoCargada){
    int retorno = -1;
    float totalImportes;
    float promedioImportes;
    int cantidadAlbunesMayorPromedio;
    int albunesMenores;
    
    if(albumList != NULL && len > 0 && opcionUnoCargada != NULL){
        if(*opcionUnoCargada == 1){
            // A.
            totalImportes = calcularTotalImportesAlbumes(albumList, len);
            printf("\nTotal de los importes: %.2f\n", totalImportes);
            promedioImportes = calcularPromedio(albumList, len, totalImportes);
            printf("Promedio de los importes: %.2f\n", promedioImportes);
            cantidadAlbunesMayorPromedio = contarMayorAPromedio(albumList, len, promedioImportes);
            printf("Cantidad de albunes que superan el promedio de importes: %d\n", cantidadAlbunesMayorPromedio);
            // B.
            albunesMenores = contarTodosLosAlbunesMenoresAnio(albumList, len, 2000);
            printf("Cantidad de albunes cuya fecha de publicacion es menor a 1/1/2000: %d\n", albunesMenores);
            retorno = 0;
        }else{
            printf("\nERROR! Se debe realizar una alta para realizar un informe!\n");
            retorno = 1;
        }
    }
    
    return retorno;
}

int Controller_Listados(eAlbum* albumList, eGenero* generoList, eTipoArtista* tipoArtistaList, eArtista* artistaList, eTipoAlbum* tiposAlbumList, int len, int* opcionUnoCargada){
    int retorno = -1;
    float albumMasCaro;
    
    if(albumList != NULL && generoList != NULL && tipoArtistaList != NULL && artistaList != NULL && tiposAlbumList  != NULL && len > 0 && opcionUnoCargada != NULL){
        if(*opcionUnoCargada == 1){
            // A. ok
            listarTodosLosGeneros(generoList, 5);
            // B. ok
            listarTodosLosTiposArtista(tipoArtistaList, 2);
            // C. ok
            listarTodosLosArtistas(artistaList, 5);
            // D. ok
            listarTodosLosAlbunes(albumList, LEN);
            // E. (menor a mayor ok)
            ordenarAlbunesImporteTitulo(albumList, LEN);
            listarTodosLosAlbunes(albumList, LEN);
            // F. ok
            listarTodosLosAlbunesMenoresAnio(albumList, LEN, 2000);
            // G. ok
            albumMasCaro = calcularAlbumMasCaro(albumList, LEN);
            listarTodosLosAlbunesMayoresPromedioImporte(albumList, LEN, albumMasCaro);
            // H. ok
            listarAlbunesDeArtistas(albumList, artistaList, LEN, 5);
            // I. ok
            listarTodosLosAlbunesAnioDeterminado(albumList, LEN, 2003);
            // J. ok
            listarTodosLosAlbunesMasCaros(albumList, LEN, albumMasCaro);
            // PARTE 2
            // ok
            listarTodosLosTiposAlbune(tiposAlbumList, 3);
            // ok
            listarNoTodosLosTiposAlbune(tiposAlbumList, 3, "vinilo");
            // ok
            listarAlbumesViniloArtista(albumList, tiposAlbumList, LEN);
            retorno = 0;
        }else{
            printf("\nERROR! Se debe realizar una alta para realizar un listado!\n");
            retorno = 1;
        }
    }
    
    return retorno;
}
