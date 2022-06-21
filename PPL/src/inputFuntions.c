/*
 * inputFuntions.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "inputFuntions.h"

bool parseInt(char *string, int *integer) {
	/* Tomaremos el tamanio de la cadena. */
	int length = strlen(string);
	/* 'i' sera nuestro index, que ira recorriendo cada uno de los caracteres de la cadena ingresada. */
	int i = 0;
	/* Aquellos caracteres que representan un entero seran guardados aqui. */
	char integer_buffer[BUFFER_SIZE];
	/* Aqui el indice de nuetra "cadena" en construccion. */
	int integer_chars = 0;

	/* Con la funcion "isspace" estaremos comprobando si donde esta parando nuestro indice es un espacio o no. */
	while (isspace(string[i]))
		i++;

	/* Aqui validamos en el caso qe sean espacio en blanco lo que ingreso el usuario*/
	if (length == i)
		return false;

	/* Aqui guradariasmos el signo negativo del entero*/
	if (string[i] == '-') {
		/* Si el simbolo negativo no esta acompaniado de un numero entero, entonces no es valido*/
		integer_buffer[integer_chars] = '-';
		integer_chars++;
		i++;

		/* Si el simbolo negativo no esta acompaniado de un numero entero, entonces no es valido*/
		if (!isdigit(string[i]))
			return false;
	}

	while (i < length && !isspace(string[i])) {
		/* Si encontramos un caracter que no represenata un numero, entonces es invalido */
		if (!isdigit(string[i]))
			return false;

		/* Guarda el numero encontrado en la otra cadena, el buffer */
		integer_buffer[integer_chars] = string[i];
		integer_chars++;
		i++;
	}

	/* Coloca un '\0', para cortar la cadena formada en el buffer */
	integer_buffer[integer_chars] = '\0';

	/* Para avanzar atraves de los caracteres de 'espacio' */
	while (isspace(string[i]))
		i++;

	/* Despues de haber leido el numero, si encuentra un caracter invalido, corta antes de ese caracter */
	if (string[i] != '\0')
		return false;

	/* Transforma la cadena creada en el buffer a un valor entero */
	*integer = atoi(integer_buffer);

	/* Termina el procedimiento */
	return true;
}

bool parseFloat(char *string, float *nfloat) {
	/* Tomaremos el tamanio de la cadena. */
	int length = strlen(string);
	/* 'i' sera nuestro index, que ira recorriendo cada uno de los caracteres de la cadena ingresada. */
	int i = 0;
	/* Aquellos caracteres que representan un entero o un punto, seran guardados aqui. */
	char float_buffer[BUFFER_SIZE];
	/* Aqui el indice de nuetra "cadena" en construccion. */
	int float_chars = 0;
	int floating_point = 0;

	/* Con la funcion "isspace" estaremos comprobando si donde esta parando nuestro indice es un espacio o no. */
	while (isspace(string[i]))
		i++;

	/* Aqui validamos en el caso qe sean espacio en blanco lo que ingreso el usuario*/
	if (length == i){
	    //printf("Entro al if (length == i);\n");
	    return false;
	}


	/* Aqui guradariasmos el signo negativo del entero*/
	if (string[i] == '-') {
		/* Si el simbolo negativo no esta acompaniado de un numero entero, entonces no es valido*/
		float_buffer[float_chars] = '-';
		float_chars++;
		i++;

		/* Si el simbolo negativo no esta acompaniado de un numero entero, entonces no es valido*/
		if (!isdigit(string[i])){
		    //printf("Entro al if (!isdigit(string[i]))\n");
		    return false;
		}
	}

	while (i < length && !isspace(string[i])) {
		/* Si encontramos un caracter que no represenata un numero o un punto, entonces es invalido */
		if(!isdigit(string[i]) && !(string[i] == '.'))
		{
		    //printf("Entro al if (!isdigit(string[i]))\n");
			return false;
		}
		if(string[i] == '.' && floating_point == 1)
		{
		    //printf("Entro al if(string[i] == '.' && floating_point == 1)\n");
		    return false;
		}
		if(string[i] == '.')
		{
		    //printf("Entro al if(string[i] == '.')\n");
		    floating_point = 1;
		}


		/* Guarda el numero encontrado en la otra cadena, el buffer */
		float_buffer[float_chars] = string[i];
		float_chars++;
		i++;
	}

	/* Coloca un '\0', para cortar la cadena formada en el buffer */
	float_buffer[float_chars] = '\0';

	/* Para avanzar atraves de los caracteres de 'espacio' */
	while (isspace(string[i]))
		i++;

	/* Despues de haber leido el numero, si encuentra un caracter invalido, corta antes de ese caracter */
	if (string[i] != '\0'){
	    //printf("Entro en if (string[i] != 'cero, el numero')\n");
		return false;
	}

	/* Transforma la cadena creada en el buffer a un valor entero */
	*nfloat = atof(float_buffer);

	/* Termina el procedimiento */
	return true;
}

float pedirNumeroFlotante(char mensaje[]) {
	float numero = 0;
	bool parsedCorrect = true;
	char buffer[BUFFER_SIZE];

	do {
		printf("%s",mensaje);
		/* Aqui procedo a guradar la cadena de caracteres que ingreso el usuario. */
		fgets(buffer, BUFFER_SIZE, stdin);

		/* Aqui valido si el procedimiento del "parseFloat" fue un exito o no. */
		parsedCorrect = parseFloat(buffer, &numero);

		/* Si el usuario ingreso "basura" se lo menciono. */
		if (!parsedCorrect)
			printf("ERROR! El valor ingresado debe ser un numero!\n");

	} while (!parsedCorrect);

	return numero;
}

int pedirNumeroEntero(char mensaje[]) {
	setbuf(stdout, NULL);
	int numero = 0;
	bool parsedCorrect = true;
	char buffer[BUFFER_SIZE];

	do {
		printf("%s",mensaje);
		/* Aqui procedo a guradar la cadena de caracteres que ingreso el usuario. */
		fgets(buffer, BUFFER_SIZE, stdin);

		/* Aqui valido si el procedimiento del "parseInt" fue un exito o no. */
		parsedCorrect = parseInt(buffer, &numero);

		/* Si el usuario ingreso "basura" se lo menciono. */
		if (!parsedCorrect)
			printf("ERROR! El valor ingresado debe ser un numero de tipo entero!\n");

	} while (!parsedCorrect);

	return numero;
}

float pedirValorNoNegativo(char mensaje[]){
	float numeroIngresado;

	do{
		numeroIngresado = pedirNumeroFlotante(mensaje);
		if(numeroIngresado < 0){
			printf("ERROR! No puede ingresar un numero negativo!\n");
		}
	}while(numeroIngresado < 0);

	return numeroIngresado;
}

void pedirUnaCadenaAlpha(char cadena[], char mensaje[], int buffer){ // Falta probar y terminar! (Falta poquitooo)
    /*char cadenaAux[buffer];
    int resultIsAlpha;
    int stringLen;

    do{
		printf("%s",mensaje);
		gets(cadenaAux);
		stringLen = strlen(cadenaAux);
		for(int i = 0; i < stringLen; i++)
		{
			resultIsAlpha = isalpha(cadenaAux[i]);
			if(resultIsAlpha == 0){
				printf("\nERROR! No se puede ingresar un caracter no alfabetico o espacios en blanco!\n"); // cambiar alphabeticos por alfabeticos
				break;
			}else{
				strcpy(cadena, cadenaAux);
			}
		}
	}while(resultIsAlpha == 0);*/
}

int removerEspacios(char* cadena)
{
	int i = 0;
	int j = 0;
	int result = -1;

	if(cadena != NULL){
		while(cadena[i])
		{
			if(cadena[i] != ' ')
				cadena[j++] = cadena[i];
			i++;
		}

		cadena[j] = '\0';
		result = 0;
	}

	return result;
}

int getNumeroInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int bufferLenght){
    int retorno = -1;
    int buffer;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 && bufferLenght > 0){
        do{
            printf("%s", mensaje);
            if(getInt(&buffer, bufferLenght) == 0 && buffer >= minimo && buffer <= maximo){
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            reintentos--;
            printf ("%s", mensajeError);
        }while(reintentos != 0);
    }
    return retorno;
}

int getInt(int *pResultado, int bufferLenght){
  int retorno = -1;
  char buffer[bufferLenght];
  if(myGets(buffer, sizeof(buffer)) == 0 && esNumero(buffer)){
      *pResultado = atoi (buffer);
      retorno = 0;
  }
  return retorno;
}

int esNumero(char *cadena){
  int retorno = 1;
  int i = 0;
  int bandera;

  bandera = contarPuntosEnString(cadena, strlen(cadena));

  if(cadena != NULL){
    if(cadena[i] == '-'){
        i = 1;
    }
    for(; cadena[i] != '\0'; i++){
        if((cadena[i] > '9' || cadena[i] < '0') && cadena[i] != '.'){
            retorno = 0;
            break;
        }

        if(cadena[i] == '.'){
            if(!(bandera < 2 && (cadena[i - 1] >= '0' && cadena[i - 1] <= '9') && (cadena[i + 1] >= '0' && cadena[i + 1] <= '9'))){
                retorno = 0;
                break;
            }
        }

    }
  }
  else{
    retorno = -1;
  }
  return retorno;
}

int myGets (char *cadena, int len){
  int retorno = 0;

  if(cadena != NULL && len > 0){
      fgets(cadena, len, stdin);
      cadena[strlen(cadena) - 1] = '\0';
  }

  return retorno;
}

int getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, int bufferLenght){
  int retorno = -1;
  float buffer;
  if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
      do{
    	  printf("%s", mensaje);
    	  if(getFloat(&buffer, bufferLenght) == 0 && buffer >= minimo && buffer <= maximo){
    	      *pResultado = buffer;
    	      retorno = 0;
    	      break;
    	  }
    	  reintentos--;
    	  printf ("%s", mensajeError);
        }while(reintentos != 0);
    }
  return retorno;
}

int getFloat(float *pResultado, int bufferLenght){
  int retorno = -1;
  char buffer[bufferLenght];
  if(myGets(buffer, sizeof(buffer)) == 0 && esNumero(buffer)){
      *pResultado = atof(buffer);
      retorno = 0;
  }
  return retorno;
}

int contarPuntosEnString(char* cadena, int len){
    int retorno = -1;
    int contador = 0;

    if(cadena != NULL && len > 0){
        for(int i = 0; i < len; i++){
            if(cadena[i] == '.'){
                contador++;
            }
        }
        retorno = contador;
    }

    return retorno;
}

int getUnCaracter(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int bufferLenght){
    int retorno = -1;
    char buffer[bufferLenght];

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0 && bufferLenght > 0){
        do{
            printf("%s", mensaje);
            if(getChar(buffer, bufferLenght) == 0){
                *pResultado = buffer[0];
                retorno = 0;
                break;
            }
            reintentos--;
            printf ("%s", mensajeError);
        }while(reintentos != 0);
    }
    return retorno;
}

int getChar(char *pResultado, int bufferLenght){
  int retorno = -1;
  char buffer[bufferLenght];

  if(myGets(buffer, sizeof(buffer)) == 0 && esCaracter(buffer) && strlen(buffer) == 1){
      *pResultado = buffer[0];
      retorno = 0;
  }

  return retorno;
}

int esCaracter(char *cadena){
  int retorno = 1;
  int i = 0;

  if(cadena != NULL){
    for(; cadena[i] != '\0'; i++){
        if(cadena[i] <= '9' && cadena[i] >= '0'){
            retorno = 0;
            break;
        }
    }
  }else{
    retorno = -1;
  }

  return retorno;
}

int RevisarFormatoArchivo(char* nombreArchivo){
    int retorno = -1;
    int len;
    char auxVector[5];
    int j = 0;
    
    if(nombreArchivo != NULL){
        len = strlen(nombreArchivo);
        //printf("\n");
        for(int i = len - 4; i < len; i++){
            //printf("nombreArchivo[%d] = %c\n",i, *(nombreArchivo + i));
            auxVector[j] = *(nombreArchivo + i);
            j++;
        }
        
        /*len = strlen(auxVector);
        printf("\n");
        for(int i = 0; i < len; i++){
            printf("auxVector[%d] = %c\n",i, auxVector[i]);
        }*/
        
        if(strcmp(auxVector, ".csv") == 0){
            //printf("\nEs un archivo tipo texto: .csv\n");
            retorno = 0;
        }else{
            if(strcmp(auxVector, ".dat") == 0){
                //printf("\nEs un archivo tipo binario: .dat\n");
                retorno = 1;
            }else{
                printf("\nERROR! No es un archivo tipo texto, ni binario!\n");
            }
        }
    }
    
    return retorno;
}

int PedirNombre(char* mensjae, char* nombre, int stringLen){
    int retorno = -1;
    
    if(mensjae != NULL && nombre != NULL && stringLen > 0){
        printf("%s", mensjae);
        myGets(nombre, stringLen);
        formalizarNombre(nombre, strlen(nombre));
    }
    
    return retorno;
}


