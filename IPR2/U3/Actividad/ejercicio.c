/*Carlos De Almeida
Unidad 3 - Ejercicio*/

#include <stdio.h>
#include <stdlib.h>

// Estructuras de datos --------------------------------------------

// Registro de evento de infeccion
typedef struct {
    int fila;
    int columna;
    int dia;
} evento_t;

// Historial de eventos de infeccion
typedef struct {
    evento_t* eventos;
    int cantidad;
} historial_t;


// Prototipos de funciones  --------------------------------------------

char** crearCiudad(int n);
void   rellenaCiudad(char** ciudad, int n, char valor);
void   liberaCiudad(char** ciudad, int n);

void   insertaEvento(historial_t* historial, evento_t nuevoEvento);
void   liberaHistorial(historial_t* historial);

void   infectarPersona(char** ciudad, int n, historial_t* historial, int fila, int col, int diaActual);
void   avanzarDia(char** ciudad, int n, historial_t* historial, int diaActual);

void   mostrarCiudad(char** ciudad, int n);
void   mostrarHistorial(historial_t* historial);


// Funcion main --------------------------------------------

int main(int argc, char* argv[]) {
    int n;
    int diaActual;
    int opcion;
    int fila, col;
    char** ciudad;
    historial_t historial;

    // Validacion del argumento de entrada
    if (argc != 2) {
        printf("Uso: %s <tamanio_ciudad>\n", argv[0]);
        printf("Ejemplo: %s 5\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    if (n <= 0) {
        printf("Error: el tamanio de la ciudad debe ser un numero entero positivo.\n");
        return 1;
    }

    // Inicializacion de la ciudad y el historial
    ciudad = crearCiudad(n);
    if (ciudad == NULL) return 1;

    rellenaCiudad(ciudad, n, 'S');

    historial.eventos  = NULL;
    historial.cantidad = 0;

    diaActual = 0;

    printf("Ciudad de %dx%d creada. Todas las personas estan sanas.\n", n, n);

    //Menu principal
    do {
        printf("\n========== Simulador de infeccion ==========\n");
        printf("  Dia actual: %d\n", diaActual);
        printf("  1. Anadir foco de infeccion\n");
        printf("  2. Avanzar dia\n");
        printf("  3. Mostrar ciudad\n");
        printf("  4. Mostrar historial de infecciones\n");
        printf("  5. Salir\n");
        printf("  Elige una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Error: entrada invalida. Introduce un numero del 1 al 5.\n");
            while (getchar() != '\n');
            opcion = 0;
            continue;
        }

        switch (opcion) {
            case 1:
                printf("  Introduce la fila (0-%d): ", n - 1);
                if (scanf("%d", &fila) != 1) {
                    printf("Error: entrada invalida.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("  Introduce la columna (0-%d): ", n - 1);
                if (scanf("%d", &col) != 1) {
                    printf("Error: entrada invalida.\n");
                    while (getchar() != '\n');
                    break;
                }
                infectarPersona(ciudad, n, &historial, fila, col, diaActual);
                break;

            case 2:
                diaActual++;
                avanzarDia(ciudad, n, &historial, diaActual);
                printf("  -> Dia %d completado.\n", diaActual);
                break;

            case 3:
                mostrarCiudad(ciudad, n);
                break;

            case 4:
                mostrarHistorial(&historial);
                break;

            case 5:
                printf("Saliendo del simulador...\n");
                break;

            default:
                printf("Opcion no valida. Por favor elige entre 1 y 5.\n");
                break;
        }

    } while (opcion != 5);

    // Liberacion memoria reservada dinamicamente
    liberaCiudad(ciudad, n);
    liberaHistorial(&historial);

    return 0;
}


// Implementacion de funciones

// crearCiudad: reserva dinamicamente una matriz de N x N chars.

char** crearCiudad(int n) {
    int i, j;

    char** ciudad = (char**) malloc(sizeof(char*) * n);
    if (ciudad == NULL) {
        printf("Error: no hay memoria suficiente para crear la ciudad.\n");
        return NULL;
    }

    for (i = 0; i < n; i++) {
        ciudad[i] = (char*) malloc(sizeof(char) * n);
        if (ciudad[i] == NULL) {
            printf("Error: no hay memoria suficiente para la fila %d.\n", i);
            for (j = 0; j < i; j++) {
                free(ciudad[j]);
            }
            free(ciudad);
            return NULL;
        }
    }

    return ciudad;
}

// rellenaCiudad: asigna el valor dado a todas las celdas de la ciudad.

void rellenaCiudad(char** ciudad, int n, char valor) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ciudad[i][j] = valor;
        }
    }
}

// liberaCiudad: libera toda la memoria reservada para la ciudad.

void liberaCiudad(char** ciudad, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(ciudad[i]);
    }
    free(ciudad);
}



// insertaEvento: anade un nuevo evento al historial.

void insertaEvento(historial_t* historial, evento_t nuevoEvento) {
    evento_t* aux = (evento_t*) realloc(historial->eventos,
                    sizeof(evento_t) * (historial->cantidad + 1));

    if (aux == NULL) {
        printf("Error: no hay memoria para guardar el evento de infeccion.\n");
        return;
    }

    historial->eventos = aux;
    historial->eventos[historial->cantidad] = nuevoEvento;
    historial->cantidad++;
}

// liberaHistorial: libera el array dinamico de eventos del historial.

void liberaHistorial(historial_t* historial) {
    free(historial->eventos);
    historial->eventos = NULL;
    historial->cantidad = 0;
}


// infectarPersona: infecta a la persona en (fila, col) si esta sana.

void infectarPersona(char** ciudad, int n, historial_t* historial,
                     int fila, int col, int diaActual) {
    if (fila < 0 || fila >= n || col < 0 || col >= n) {
        printf("Error: coordenadas (%d, %d) fuera de los limites (0 a %d).\n",
               fila, col, n - 1);
        return;
    }

    if (ciudad[fila][col] != 'S') {
        printf("La persona en (%d, %d) no esta sana (estado actual: '%c'). "
               "No se puede infectar.\n", fila, col, ciudad[fila][col]);
        return;
    }

    ciudad[fila][col] = 'I';

    evento_t evento;
    evento.fila    = fila;
    evento.columna = col;
    evento.dia     = diaActual;

    insertaEvento(historial, evento);

    printf("Persona en (%d, %d) infectada el dia %d.\n", fila, col, diaActual);
}

// avanzarDia: aplica las reglas de propagacion de la infeccion para un dia.

void avanzarDia(char** ciudad, int n, historial_t* historial, int diaActual) {
    int i, j;

    // Matriz auxiliar para registrar las nuevas infecciones del dia
    char** auxiliar = crearCiudad(n);
    if (auxiliar == NULL) return;
    rellenaCiudad(auxiliar, n, 'S');

    // Deteccion de vecinos infectados
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ciudad[i][j] == 'S') {
                int tieneVecinoInfectado = 0;

                if (i > 0   && ciudad[i-1][j] == 'I') tieneVecinoInfectado = 1;
                if (i < n-1 && ciudad[i+1][j] == 'I') tieneVecinoInfectado = 1;
                if (j > 0   && ciudad[i][j-1] == 'I') tieneVecinoInfectado = 1;
                if (j < n-1 && ciudad[i][j+1] == 'I') tieneVecinoInfectado = 1;

                if (tieneVecinoInfectado) {
                    auxiliar[i][j] = 'I';
                }
            }
        }
    }

    // Actualizacion del tablero
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ciudad[i][j] == 'I') {
                ciudad[i][j] = 'R';
            }
            if (auxiliar[i][j] == 'I') {
                ciudad[i][j] = 'I';

                evento_t evento;
                evento.fila    = i;
                evento.columna = j;
                evento.dia     = diaActual;
                insertaEvento(historial, evento);
            }
        }
    }

    liberaCiudad(auxiliar, n);
}


// mostrarCiudad: imprime el estado actual de la ciudad en formato de cuadricula.

void mostrarCiudad(char** ciudad, int n) {
    int i, j;
    printf("\n--- Estado actual de la ciudad ---\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("[%c] ", ciudad[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
}

// mostrarHistorial: imprime todos los eventos de infeccion registrados.

void mostrarHistorial(historial_t* historial) {
    int i;
    printf("\n--- Historial de infecciones (%d registros) ---\n",
           historial->cantidad);
    if (historial->cantidad == 0) {
        printf("Aun no se han registrado infecciones.\n");
    } else {
        for (i = 0; i < historial->cantidad; i++) {
            printf("  Dia %2d | Fila: %2d | Columna: %2d\n",
                   historial->eventos[i].dia,
                   historial->eventos[i].fila,
                   historial->eventos[i].columna);
        }
    }
    printf("----------------------------------------------\n");
}
