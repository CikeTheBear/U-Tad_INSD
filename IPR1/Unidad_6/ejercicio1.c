/*
Carlos De Almeida
Unidad 6 - Ejercicio 1
*/

#include <stdio.h>



// --- Definición de constantes ---

#define MAX_ALUMNOS 20
#define MAX_NOMBRE 30
#define ASIGNATURAS 3



// --- Prototipos de funciones ---

void leeCadena(char cadena[], int tam);

void ingresarNotas(char nombresAlumnos[][MAX_NOMBRE], float notasAlumnos[][ASIGNATURAS], int numalumnos, int numAsignaturas);

int calcular_mejor_promedio(float notasAlumnos[][ASIGNATURAS], int numalumnos, int numAsignaturas, float* mejor_promedio);



// --- Función principal ---

int main() {

	int numEstudiantes;
    char nombres[MAX_ALUMNOS][MAX_NOMBRE];
    float notas[MAX_ALUMNOS][ASIGNATURAS];
    float mejor_promedio_valor = 0.0;
    int indice_mejor_alumno;



    do {
        printf("Ingrese el número de estudiantes (máximo %d): ", MAX_ALUMNOS);
        scanf("%d", &numEstudiantes);
        
        while(getchar() != '\n'); 

        if (numEstudiantes < 1 || numEstudiantes > MAX_ALUMNOS) {
            printf("Número inválido. Vuelve a intentarlo.\n");
        }
    } while (numEstudiantes < 1 || numEstudiantes > MAX_ALUMNOS);



    for(int i = 0; i < numEstudiantes; i++) {
        printf("Nombre del estudiante %d: ", i + 1);
        leeCadena(nombres[i], MAX_NOMBRE);
    }



    ingresarNotas(nombres, notas, numEstudiantes, ASIGNATURAS);



    indice_mejor_alumno = calcular_mejor_promedio(notas, numEstudiantes, ASIGNATURAS, &mejor_promedio_valor);



    printf("\n--- RESULTADO ---\n");
    printf("El mejor alumno es: %s con un promedio de notas de %.2f\n", nombres[indice_mejor_alumno], mejor_promedio_valor);
    printf("Sus notas son:\n");
    printf("IPR1: %.2f\n", notas[indice_mejor_alumno][0]);
    printf("LMDI: %.2f\n", notas[indice_mejor_alumno][1]);
    printf("LRSO: %.2f\n", notas[indice_mejor_alumno][2]);

    return 0;
}



// --- Definición de funciones ---

void leeCadena(char cadena[], int tam) {
    int c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < tam - 1) {
            cadena[i] = (char)c;
            i++;
        }
    }
    cadena[i] = '\0';
}



void ingresarNotas(char nombresAlumnos[][MAX_NOMBRE], float notasAlumnos[][ASIGNATURAS], int numalumnos, int numAsignaturas) {
    char *materias[] = {"IPR1", "LMDI", "LRSO"};
    
    for (int i = 0; i < numalumnos; i++) {
        for (int j = 0; j < numAsignaturas; j++) {
            printf("Ingrese la de %s del alumno %s: ", materias[j], nombresAlumnos[i]);
            scanf("%f", &notasAlumnos[i][j]);
        }
    }
}



int calcular_mejor_promedio(float notasAlumnos[][ASIGNATURAS], int numalumnos, int numAsignaturas, float* promedio_notas) {
    int indice_mejor = 0;
    float max_promedio = -1.0;

    for (int i = 0; i < numalumnos; i++) {
        float suma = 0;
        for (int j = 0; j < numAsignaturas; j++) {
            suma += notasAlumnos[i][j];
        }
        float promedio_actual = suma / numAsignaturas;

        if (promedio_actual > max_promedio) {
            max_promedio = promedio_actual;
            indice_mejor = i;
        }
    }

    *promedio_notas = max_promedio;
    
    return indice_mejor;
}