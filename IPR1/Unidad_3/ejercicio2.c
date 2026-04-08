/*Carlos De Almeida
Unidad 3 - Ejercicio 2*/

#include <stdio.h>

const char moneda = '$';
const float iva = 16.00;
const float descuento = 10.00;
float subtotal = 0.00;
float total = 0.00;
float precio = 0.00;
int cantidad = 0;
int opcion = 0;
char operacion = '\n';

int main(){
	
	do {
		printf("\n=== RESTAURANTE EL BUEN SABOR ===\n");
		printf("1. Hamburguesa..............$8.50\n");
		printf("2. Pizza...................$12.00\n");
		printf("3. Ensalada.................$6.00\n");
		printf("4. Refresco.................$2.50\n");
		printf("5. Postre...................$4.00\n");
		printf("6. Finalizar pedido.\n");
		printf("\nSeleccione una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
			case 1:
				//Hamburguesa
				precio = 8.5;
				printf("Cantidad de hamburguesas: ");
				scanf("%d", &cantidad);
				if (cantidad > 0) { 
					subtotal += cantidad * precio;
				}
				else {
					printf("\nCantidad inválida.\n");
				}
				break;
			case 2:
				//Pizza
				precio = 12.00;
				printf("Cantidad de pizzas: ");
				scanf("%d", &cantidad);
				if (cantidad > 0) { 
					subtotal += cantidad * precio;
				}
				else {
					printf("\nCantidad inválida.\n");
				}
				break;
			case 3:
				//Ensalada
				precio = 6.00;
				printf("Cantidad de ensaladas: ");
				scanf("%d", &cantidad);
				if (cantidad > 0) { 
					subtotal += cantidad * precio;
				}
				else {
					printf("\nCantidad inválida.\n");
				}
				break;				
			case 4:
				//Refresco
				precio = 2.50;
				printf("Cantidad de refrescos: ");
				scanf("%d", &cantidad);
				if (cantidad > 0) { 
					subtotal += cantidad * precio;
				}
				else {
					printf("\nCantidad inválida.\n");
				}
				break;				
			case 5:
				//Postre
				precio = 4.00;
				printf("Cantidad de postres: ");
				scanf("%d", &cantidad);
				if (cantidad > 0) { 
					subtotal += cantidad * precio;
				}
				else {
					printf("\nCantidad inválida.\n");
				}
				break;				
			case 6:
				//Finalizar
				printf("Gracias por su orden, buen provecho.\n");
					return 0;	
			default:
				printf("Opción no válida. Intente de nuevo.\n");
		} 
		printf("\n¿Desea agregar algo más? (s/n): ");
		scanf(" %c", &operacion);

		
	} while (operacion == 's' || operacion == 'S');
	
	if (subtotal > 50) {
		subtotal = subtotal - (subtotal * (descuento / 100));
	}
	float montoIVA = subtotal * (iva / 100);
	total = subtotal + montoIVA;
	
	printf("\n=== RESUMEN DEL PEDIDO ===\n");
	printf("Subtotal: %c%.2f\n", moneda, subtotal);
	printf("IVA (16%%): +%c%.2f\n", moneda, montoIVA);
	printf("Total a pagar: %c%.2f\n", moneda, total);
	printf("\nGracias por su compra, ¡vuelva pronto!\n");

}