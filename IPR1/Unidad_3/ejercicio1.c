/*Carlos De Almeida
Unidad 3 - Ejercicio 1*/

#include <stdio.h>

float saldo = 1000;
const char moneda = '$';
float monto = 0;
int opcion = 0;
char operacion = '\n';


int main(){
	printf("\nHola!, tú saldo es: %c%.2f\n", moneda, saldo);
	
	do {
		printf("\n=== CAJERO AUTOMÁTICO ===\n");
		printf("1. Consultar saldo\n");
		printf("2. Depositar dinero\n");
		printf("3. Retirar dinero\n");
		printf("4. Salir\n");
		printf("Seleccione una opción\n");
		scanf("%d", &opcion);
	
		switch (opcion) {
			case 1:
				printf("Tu saldo es: %c%.2f\n", moneda, saldo);
				break;			
			case 2:
				printf("¿Cuanto dinero quiere depositar?\n");
				scanf("%f", &monto);
				if (monto > 0) {
					saldo += monto;
					printf("Deposito realizado. Tu saldo es: %c%.2f\n", moneda, saldo);
					}
				else{
					printf("Error, monto invalido.");
					}
				break;			
			case 3:
				printf("¿Cuanto dinero quiere retirar?\n");
				scanf("%f", &monto);
				if (monto > saldo) {
					printf("Saldo insuficiente.\n");
				}
				else if (monto <= 0) {
					printf("Error, monto invalido.");
				}
				else {
					saldo -= monto;
					printf("Retiro realizado. Tu saldo es: %c%.2f\n", moneda, saldo);
				}
				break;			
			case 4:
				printf("Gracias por usar nuestros servicios, que tenga buen día.\n");
				return 0;		
			default:
				printf("Error, opción invalida.\n");
		}
		printf("\n¿Desea realizar otra operación? (s/n): ");
		scanf(" %c", &operacion);
	} while (operacion == 's' || operacion == 'S');
}