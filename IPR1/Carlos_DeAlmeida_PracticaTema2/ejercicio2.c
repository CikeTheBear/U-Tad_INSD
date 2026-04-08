/*Carlos De Almeida - Tema 2 - Ejercicio 2*/

#include <stdio.h>

float distancia;
float velocidad;
float tiempo;
int tiempoEnMinutos;
int minutos;
int horas;

int main(){
	
	printf("¿A cuantos km queda tu destino?: ");
	scanf("%f", &distancia);
	
	printf("¿A cuantos km/h te vas a mover:? ");
	scanf("%f", &velocidad);
	
	
	tiempo = distancia/velocidad;
	tiempoEnMinutos = (int)(tiempo * 60);
	minutos = tiempoEnMinutos % 60;
	horas = tiempoEnMinutos / 60;
	
	
	printf("El tiempo que tardaras en llegar es de %d horas y %d minutos\n", horas, minutos);
	
	
	return 0;
}