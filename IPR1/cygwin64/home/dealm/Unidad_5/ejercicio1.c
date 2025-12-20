#include <stdio.h>



//Constantes

#define TAM = 15



//Prototipos de funciones

int leerCadena (char cadena[], int tam);

int generaPassword(char cadena[]);

int cadena2Mayusculas(char cadena[]);

int cadenasIguales(char cadena1[], char cadena2[]);

int tamCadena (char cadena[]);



//Función principal

int main() {
	
	int opcion = 0;
	
	
	do {
		printf("MENU: \n");
		printf("1. GENERA UN PASSWORD\n");
		printf("2. INTRODUCIR TU PASSWORD\n");
		printf("3. SALIR\n");
		
		scanf("%d",&opcion);
	}
	while (opcion != 3);
	
	printf("%d", opcion);
	
}



//Definición de funciones

int leerCadena (char cadena[], int tam) {
	
}

int generaPassword(char cadena[]) {

}

int cadena2Mayusculas(char cadena[]) {

}

int cadenasIguales(char cadena1[], char cadena2[]) {

}

int tamCadena (char cadena[]) {

}













// PSEUDOCODIGO
/*
BUCLE MIENTRAS OPCION SEA DISTINTA A 3 O 1 O 2
MOSTRAR ("MENU: ")
MOSTRAR ("1. GENERA PASSWORD")
MOSTRAR ("2. INTRODUCIR PASSWORD")
MOSTRAR ("3. SALIR")
MOSTRAR ("SELECCIONE UNA OPCION")
FIN BUCLE

SI OPCION = 1
	MOSTRAR ("INTRODUCE UN PASSWORD ENTRE 8 Y 15 CARACTERES Y AL MENOS UNA MAYUSCULA: ")
	SWITCH
		CASO 1 EL PASSWORD DEBE TENER AL MENOS UNA MAYUSCULA
			MOSTRAR ("EL PASSWORD DEBE TENER AL MENOS UNA MAYUSCULA")
		CASO 2 EL PASSWORD DEBE TENER ENTRE 8 Y 15 CARACTERES
			MOSTRAR ("EL PASSWORD DEBE TENER ENTRE 8 Y 15 CARACTERES")
		CASO 3 PASSWORD ACEPTADO
			MOSTRAR ("PASSWORD ACEPTADO")
			
			
			
			
			
			
			
			
			
			
*/