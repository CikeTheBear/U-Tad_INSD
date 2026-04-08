/*
Carlos De Almeida
Unidad 6 - Ejercicio 2
*/

#include <stdio.h>



// --- Definición de constantes ---

#define LONGITUD_MAX 10



// --- Prototipos de funciones ---

void encolar(int *cola, int *longitud, int longitudArray, int valor);

int desencolar(int *cola, int *longitud);

int mostrarMenuConResultado();

void inicializarArray(int *array, int longitudArray);

void mostrarArray(int *array, int longitudActual);



// --- Función principal ---

int main() {

    int cola[LONGITUD_MAX];
    int longitud = 0;
    int opcion;
    int valor;


    
    inicializarArray(cola, LONGITUD_MAX);



    do {
       
        mostrarArray(cola, longitud);
        
        opcion = mostrarMenuConResultado();

        switch (opcion) {
            case 1: // Encolar
                printf("Introduzca un valor entero a encolar: ");
                scanf("%d", &valor);
                encolar(cola, &longitud, LONGITUD_MAX, valor);
                break;

            case 2: // Desencolar
                valor = desencolar(cola, &longitud);
                if (valor != -1) {
                    printf("Valor desencolado: %d\n", valor);
                    printf("Longitud de la cola: %d\n", longitud);
                }
                break;

            case 3: // Salir
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida.\n");
        }
        printf("\n");

    } while (opcion != 3);

    return 0;
}



// --- Definición de funciones ---

int mostrarMenuConResultado() {
    int opcion;
    printf("Prueba de funcionamiento de la cola.\n");
    printf("1. Encolar\n");
    printf("2. Desencolar\n");
    printf("3. Salir\n");
    printf("Introducir opcion: ");
    scanf("%d", &opcion);
    return opcion;
}



void encolar(int *cola, int *longitud, int longitudArray, int valor) {
    if (*longitud >= longitudArray) {
        printf("Error: La cola está llena.\n");
        return;
    }

    cola[*longitud] = valor;

    (*longitud)++; 
    
    printf("Encolado el valor %d\n", valor);
    printf("Longitud de la cola: %d\n", *longitud);
}



int desencolar(int *cola, int *longitud) {
    if (*longitud == 0) {
        printf("Error: La cola está vacía.\n");
        return -1;
    }

    int elementoRetorno = cola[0];

    for (int i = 0; i < *longitud - 1; i++) {
        cola[i] = cola[i + 1];
    }

    cola[*longitud - 1] = 0;

    (*longitud)--;

    return elementoRetorno;
}



void inicializarArray(int *array, int longitudArray) {
    for (int i = 0; i < longitudArray; i++) {
        array[i] = 0;
    }
}



void mostrarArray(int *array, int longitudActual) {
    printf("[ESTADO COLA]: | ");
    for (int i = 0; i < LONGITUD_MAX; i++) {
        if (i < longitudActual) {
            printf("%d | ", array[i]);
        } else {
            printf("  | ");
        }
    }
    printf("\n");
}