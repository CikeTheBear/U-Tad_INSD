#include <stdio.h>

struct direccion {
    char calle[50];
    int numero;
    int cp;
    char provincia[25];
};

struct usuario {
    char nombre[10];
    char apellido[12];
    char identif[9];
    int edad;
    float altura;
    struct direccion dire;
};

int main() {

    struct usuario user = { "Carlos", "De Almeida", "20451847", 34, 1.79, { "Urbanizacion Los Palos Grandes, 4ta avenida", 2, 1060, "Miranda" } };

    printf("[ %s, %s, %s, %d, %.2f, %s, %d, %d, %s ] \n", user.nombre, user.apellido, user.identif, user.edad, user.altura, user.dire.calle, user.dire.numero, user.dire.cp, user.dire.provincia);

    return 0;

}