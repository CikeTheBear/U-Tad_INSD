/*Carlos De Almeida
Unidad 4 - Ejercicio 2*/

#include <stdio.h>

//---PROTOTIPOS DE FUNCIONES---

void leerRango(int *inicio, int *fin);
int esPrimo(int n);
void mostrarPrimos(int inicio, int fin);

//---FUNCION MAIN---

int main()
{
    int inicio, fin;

    printf("\n=== NUMEROS PRIMOS EN UN RANGO ===\n");
    leerRango(&inicio, &fin);

    mostrarPrimos(inicio, fin);

    return 0;
}

//---DEFINICION DE FUNCIONES---

void leerRango(int *inicio, int *fin)
{
    int valido = 0;

    do
    {
        printf("Ingrese el inicio del rango (entero positivo): ");
        scanf("%d", &*inicio);

        printf("Ingrese el fin del rango (entero positivo): ");
        scanf("%d", &*fin);

        if (*inicio > 0 && *fin > 0 && *inicio < *fin)
        {
            valido = 1;
        }
        else
        {
            printf("Rango invalido. Asegurese de que ambos numeros sean positivos y que el inicio sea menor que el fin.\nIntente de nuevo.\n");
        }

    } while (valido == 0);
}

int esPrimo(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void mostrarPrimos(int inicio, int fin)
{
    int contador = 0;

    printf("\nNumeros primos entre %d y %d:\n", inicio, fin);

    for (int i = inicio; i <= fin; i++)
    {
        if (esPrimo(i))
        {
            printf("%d ", i);
            contador++;
        }
    }
    printf("\n");

    if (contador == 0)
    {
        printf("No se encontraron numeros primos en el rango dado.\n");
    }
    else
    {
        printf("Total de numeros primos encontrados: %d\n", contador);
    }
}