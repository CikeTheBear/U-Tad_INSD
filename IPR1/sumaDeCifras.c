#include <stdio.h>

int sumaCifras(int numero);


int main () {
    int num;

    do {
        printf("Escriba un numero entero positivo: \n");
        scanf("%d", &num);
    }
    while (num < 0);

    printf("La suma de las cifras del numero %d es: %d\n", num, sumaCifras(num));


    return 0;
}

int sumaCifras(int numero) {
    int suma = 0;

    while (numero != 0) {
        suma = suma + (numero % 10);

        numero = numero / 10;
    }
    return suma;
}