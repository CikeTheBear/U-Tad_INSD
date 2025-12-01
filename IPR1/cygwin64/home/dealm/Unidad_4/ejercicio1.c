/*Carlos De Almeida
Unidad 4 - Ejercicio 1*/

#include <stdio.h>

//---VARIABLES GLOBALES---

int calificacion1, calificacion2, calificacion3;
float promedio;
char otroAlumno;

//---PROTOTIPOS DE FUNCIONES---

int validarCalificacion(int *calificacion);

float calcularPromedio();

void mostrarResultado();

//---FUNCION MAIN---

int main()
{
    do
    {
        printf("=== CALCULO DE PROMEDIO ===\n");

        printf("Ingrese la calificacion 1 (0 a 10): ");
        validarCalificacion(&calificacion1);

        printf("Ingrese la calificacion 2 (0 a 10): ");
        validarCalificacion(&calificacion2);

        printf("Ingrese la calificacion 3 (0 a 10): ");
        validarCalificacion(&calificacion3);

        calcularPromedio();
        mostrarResultado();

        printf("Desea evaluar otro estudiante? (s/n): ");
        scanf(" %c", &otroAlumno);

    } while (otroAlumno == 'S' || otroAlumno == 's');

    return 0;
}

//---DEFINICION DE FUNCIONES---

int validarCalificacion(int *calificacion)
{
    scanf("%d", &*calificacion);

    while (*calificacion < 0 || *calificacion > 10)
    {
        printf("Calificacion invalida. Ingrese una calificacion entre 0 y 10: ");
        scanf("%d", &*calificacion);
    }

    return *calificacion;
}

float calcularPromedio()
{
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3.0;
    return promedio;
}

void mostrarResultado()
{
    printf("Promedio final: %.2f\n", promedio);

    if (promedio >= 6.0)
    {
        printf("Estado: APROBADO\n");
    }
    else
    {
        printf("Estado: REPROBADO\n");
    }
}