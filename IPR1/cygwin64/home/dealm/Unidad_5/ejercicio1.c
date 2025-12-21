/*
Carlos De Almeida
Unidad 5 - Ejercicio 1
*/

#include <stdio.h>



// --- Definición de constantes ---

#define MAX 50
#define LONG_MIN 8
#define LONG_MAX 15



// --- Prototipos de funciones ---

int leerCadena (char cadena[], int tam);

int tamCadena (char cadena[]);

int cadena2Mayusculas(char cadena[]);

int cadenasIguales(char cadena1[], char cadena2[]);

int generarPassword(char cadena[]);

int limpiarBuffer();



// --- Función principal ---

int main() {
	
	char password[MAX];
	char intento[MAX];
	int opcion = 0;
	int passwordValido = 0;
	
	do {
		printf("\n");
		printf("=== MENU ===\n");

		if (!passwordValido) {
			printf("1. Genera un password\n");
		}

		else {
			printf("1. Cambiar tu password\n");
		}
		
		printf("2. Introduce tu password\n");
		printf("3. Salir\n");
		printf("\n");
		printf("Seleccione una opcion: ");

		
		scanf("%d",&opcion);


		limpiarBuffer();


		switch (opcion) {

			case 1:
				while (generarPassword(password) == 0){
					// Repetir hasta que se genere un password válido
				}
				printf("\n");
				printf("Password generado correctamente.\n");
				passwordValido = 1;
				break;

			case 2:
				if (passwordValido == 0) {
					printf("\n");
					printf("Primero debes generar un password valido.\n");
					break;
				}
				else {
					printf("\n");
					printf("Introduce tu password: ");
					leerCadena(intento, MAX);

					if (cadenasIguales(password, intento) == 1) {
						printf("\n");
						printf("Password correcto. Acceso concedido.\n");
					} 
					else {
						printf("\n");
						printf("Password incorrecto. Acceso denegado.\n");
					}
				}
				break;

			case 3:
				printf("\n");
				printf("Saliendo del programa\n");
				printf("\n");
				break;

			default:
				printf("\n");
				printf("¡ERROR! - Opción inválida. Intente nuevamente.\n");
		}
	}

		
	while (opcion != 3);


	return 0;
}



// --- Definición de funciones ---

int leerCadena (char cadena[], int tam) {
	int i = 0;
	char c;

	c = getchar();

	while (c != '\n' && i < tam - 1) {
		cadena[i] = c;
		i++;
		c = getchar();
	}

	cadena[i] = '\0';

	if (c != '\n') {
		limpiarBuffer();
	}

	return i;
}


int cadena2Mayusculas(char cadena[]) {
	
	int cont = 0;
	int i = 0;

	while (cadena[i] != '\0') {
		if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
			cont++;
		}
		i++;
	}

	return (cont >= 2);

}


int cadenasIguales(char cadena1[], char cadena2[]) {
	
	int i = 0;
	
	while (cadena1[i] != '\0' && cadena2[i] != '\0') {
		if (cadena1[i] != cadena2[i]) {
			return 0;
		}
		i++;
	}

	if (cadena1[i] == '\0' && cadena2[i] == '\0') {
		return 1;
	} 
	
	else {
		return 0;
	}

}
	

int tamCadena (char cadena[]) {
	
	int i = 0;
	
	while (cadena[i] != '\0') {
		i++;
	}

	return i;

}


int generarPassword(char cadena[]) {
	
	char passwordTemporal[MAX];
	
	printf("\n");
	printf("Introduce un password entre 8 y 15 caracteres y al menos dos mayusculas: ");
	leerCadena(passwordTemporal, MAX);

	int longitud = tamCadena(passwordTemporal);

	if (longitud < LONG_MIN || longitud > LONG_MAX) {
		printf("\n");
		printf("¡ERROR! - El password debe tener entre 8 y 15 caracteres.\n");
		return 0;
	}

	if (cadena2Mayusculas(passwordTemporal) == 0) {
		printf("\n");
		printf("¡ERROR! - El password debe tener al menos dos mayusculas.\n");
		return 0;
	}

	int i = 0;
	while (passwordTemporal[i] != '\0') {
		cadena[i] = passwordTemporal[i];
		i++;
	}

	cadena[i] = '\0';

	return 1;

}


int limpiarBuffer() {
	
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
	return 0;

}