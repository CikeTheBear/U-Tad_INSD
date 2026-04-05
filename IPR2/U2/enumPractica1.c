#include <stdio.h>

enum menu_items { ADD = 1, DELETE = 2, EDIT = 3, EXIT = 4 };

void imprime_menu(enum menu_items sel);



int main() {

    enum menu_items selection;

    printf("---Selecciona una de las opciones---\n1. Agregar\n2. Borrar\n3. Editar \n4. Salir\n\nSu opcion: ");
    scanf("%d", &selection);

    switch (selection) {
        case ADD:
            imprime_menu(selection);
        break;

        case DELETE:
            imprime_menu(selection);
        break;

        case EDIT:
            imprime_menu(selection);
        break;

        case EXIT:
            printf("Adios y muchas gracias");
        break;

        default:
            printf("Opcion invalida");
        break;
    }

    return 0;
}

void imprime_menu(enum menu_items sel) {
    int res;
    res = sel;
    printf("Usted ha seleccionado la opcion %d del menu\n", res);
}