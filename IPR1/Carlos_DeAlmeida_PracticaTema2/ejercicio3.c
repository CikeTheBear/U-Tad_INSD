/*Carlos De Almeida - Tema 2 - Ejercicio 3*/

#include <stdio.h>

int duracionEnSegundos;
int horas;
int minutos;
int segundos;

int main(){
	
	printf("Cuantos segundos quieres convertir?: ");
	scanf("%d", &duracionEnSegundos);
		
		
	horas = duracionEnSegundos / 3600;
	int resto = duracionEnSegundos % 3600;
	minutos = resto / 60;
	segundos = resto % 60;
	
	
	printf("El tiempo es: %d hora(s), %d minuto(s) y %d segundo(s).\n", horas, minutos, segundos);
	
	
	return 0;
}