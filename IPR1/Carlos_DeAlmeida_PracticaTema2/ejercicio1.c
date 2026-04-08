/*Carlos De Almeida - Tema 2 - Ejercicio 1*/

#include <stdio.h>

int anchoMuro;
int altoMuro;
int anchoLadrillo;
int altoLadrillo;
int cantidadLadrillosVerticales;
int cantidadLadrillosHorizontales;
int cantidadLadrillosTotales;

int main(){
	
	printf("¿Cual es el ancho (En mts) del muro que quiere construir?: ");
	scanf("%d", &anchoMuro);
	
	printf("¿Y cual es el alto (En mts) del muro que quiere construir?: ");
	scanf("%d", &altoMuro);
	
	printf("Ahora, ¿Cual es el ancho (En cm) de los ladrillos que piensa usar?: ");
	scanf("%d", &anchoLadrillo);
	
	printf("¿Y el alto (En cm) de los ladrillos?: ");
	scanf("%d", &altoLadrillo);
	
	
	cantidadLadrillosVerticales = (altoMuro * 100) / altoLadrillo;
	cantidadLadrillosHorizontales = (anchoMuro * 100) / anchoLadrillo;
	
	cantidadLadrillosTotales = cantidadLadrillosVerticales * cantidadLadrillosHorizontales;
	
	
	printf("Para cubrir el muro, se requieren %d ladrillos por fila y %d filas, para un total de %d ladrillos.\n", cantidadLadrillosHorizontales, cantidadLadrillosVerticales, cantidadLadrillosTotales);

	
	return 0;
}