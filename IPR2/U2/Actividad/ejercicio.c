/*Carlos De Almeida
Unidad 2 - Ejercicio 1*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estructuras de datos --------------------------------------------
typedef enum Elemento_t
{
    FUEGO = 1,
    HIELO = 2
} Elemento_t;

typedef enum Unidad_t
{
    J = 1,
    KJ = 2
} Unidad_t;

typedef enum OpcionTurno_t
{
    ATACAR = 1,
    RECARGAR = 2,
    ESTADO = 3
} OpcionTurno_t;

typedef struct Mago_t
{
    char nombre[10 + 1];
    int potencia;
    Elemento_t elemento;
    int vida;
    int energia;
} Mago_t;

typedef struct ConversionInfo_t
{
    double energia;
    Unidad_t unidadEntrada;
    Unidad_t unidadSalida;
} ConversionInfo_t;

// Prototipos de funciones  --------------------------------------------
double convertir_energia(ConversionInfo_t conversion);

int calcular_danio(Mago_t atacante);

Mago_t construir_mago(char *arg);

Unidad_t definir_unidad(char *arg);

void turno_jugador(Mago_t *jugador, Mago_t *maquina, Unidad_t unidad);

void turno_maquina(Mago_t *jugador, Mago_t *maquina);

void mostrar_estado(Mago_t *mago, Unidad_t unidad);

void recargar(Mago_t *mago);

// Funcion main --------------------------------------------
int main(int argc, char *argv[])
{
    // Comprobacion de cantidad de argumentos
    if (argc != 4)
    {
        printf("Numero incorrecto de argumentos.\n");
        printf("Saliendo del programa.\n");
        return 1;
    }

    srand(time(NULL));

    Mago_t jugador = construir_mago(argv[1]);
    Mago_t maquina = construir_mago(argv[2]);
    Unidad_t unidad = definir_unidad(argv[3]);

    // Inicio del Combate --
    while (jugador.vida > 0 && maquina.vida > 0)
    {
        turno_jugador(&jugador, &maquina, unidad);
        if (maquina.vida <= 0)
            break;
        turno_maquina(&jugador, &maquina);
    }

    // Fin del combate --
    printf("=== fin del duelo ===\n");
    if (jugador.vida <= 0)
    {
        printf("ganador: %s\n", maquina.nombre);
    }
    else
    {
        printf("ganador: %s\n", jugador.nombre);
    }

    return 0;
}

double convertir_energia(ConversionInfo_t conversion)
{
    double energia;

    if (conversion.unidadEntrada == conversion.unidadSalida)
    {
        energia = conversion.energia;
    }

    else if (conversion.unidadEntrada == J)
    {
        energia = conversion.energia / 1000;
    }

    else
    {
        energia = conversion.energia * 1000;
    }

    return energia;
}

int calcular_danio(Mago_t atacante)
{
    int danio;

    switch (atacante.elemento)
    {
    case FUEGO:
        danio = atacante.potencia + 5;
        break;

    case HIELO:
        danio = atacante.potencia * 2;
        break;

    default:
        danio = 0;
        break;
    }

    return danio;
}

Mago_t construir_mago(char *arg)
{

    char nombre[11];
    int potencia;
    char elemento_str[6];

    sscanf(arg, "%[^,],%d,%[^,]", nombre, &potencia, elemento_str);

    if (potencia <= 0)
    {
        printf("Error: la potencia debe ser un numero positivo.\n");
        exit(1);
    }
    Mago_t mago;

    int i = 0;
    while (nombre[i] != '\0')
    {
        mago.nombre[i] = nombre[i];
        i++;
    }
    mago.nombre[i] = '\0';

    mago.potencia = potencia;

    if (elemento_str[0] == 'f' || elemento_str[0] == 'F')
    {
        mago.elemento = FUEGO;
    }
    else if (elemento_str[0] == 'h' || elemento_str[0] == 'H')
    {
        mago.elemento = HIELO;
    }
    else
    {
        printf("Error: elemento invalido '%s'. Use fuego o hielo.\n", elemento_str);
        exit(1);
    }

    mago.vida = 100;
    mago.energia = 500;

    return mago;
}

Unidad_t definir_unidad(char *arg)
{

    Unidad_t unidad;

    if (arg[0] == 'J' || arg[0] == 'j')
    {
        unidad = J;
    }
    else if (arg[0] == 'k' || arg[0] == 'K')
    {
        unidad = KJ;
    }
    else
    {
        printf("Error: unidad invalida. Use J o kJ.\n");
        exit(1);
    }

    return unidad;
}

void turno_jugador(Mago_t *jugador, Mago_t *maquina, Unidad_t unidad)
{
    int opcion;
    int opcion_valida = 0;

    while (!opcion_valida)
    {
        printf("--- turno de %s ---\n", jugador->nombre);
        printf("Que accion quieres realizar:\n");
        printf("1. Atacar:\n");
        printf("2. Recargar energias:\n");
        printf("3. Ver estado:\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case ATACAR:
            if (jugador->energia >= 100)
            {
                int danio = calcular_danio(*jugador);
                maquina->vida -= danio;
                jugador->energia -= 100;
                printf("%s ataca y hace %d de danio.\n", jugador->nombre, danio);
                opcion_valida = 1;
            }
            else
            {
                printf("No tienes energia suficiente para atacar, recarga.\n");
            }
            break;

        case RECARGAR:
            recargar(jugador);
            opcion_valida = 1;
            break;

        case ESTADO:
            printf("--- estado ---\n");
            mostrar_estado(jugador, unidad);
            mostrar_estado(maquina, unidad);
            printf("--------------\n");
            break;

        default:
            printf("Opcion invalida, intenta de nuevo\n");
            opcion_valida = 0;
            break;
        }
    }
}

void turno_maquina(Mago_t *jugador, Mago_t *maquina)
{
    int probabilidad = rand() % 100;

    printf("turno de %s\n", maquina->nombre);

    if (probabilidad < 60)
    {
        if (maquina->energia >= 100)
        {
            int danio = calcular_danio(*maquina);
            jugador->vida -= danio;
            maquina->energia -= 100;
            printf("%s ataca y hace %d de danio.\n", maquina->nombre, danio);
        }
        else
        {
            recargar(maquina);
        }
    }
    else
    {
        recargar(maquina);
    }
}

void mostrar_estado(Mago_t *mago, Unidad_t unidad)
{

    ConversionInfo_t info;
    double energia_convertida;
    char *elemento_str;

    info.energia = mago->energia;
    info.unidadEntrada = J;
    info.unidadSalida = unidad;
    energia_convertida = convertir_energia(info);

    if (mago->elemento == FUEGO)
    {
        elemento_str = "fuego";
    }
    else
    {
        elemento_str = "hielo";
    }

    printf("nombre: %s | vida: %d | energia: %.2f %s | elemento: %s | potencia: %d\n", mago->nombre, mago->vida, energia_convertida, unidad == J ? "J" : "kJ", elemento_str, mago->potencia);
}

void recargar(Mago_t *mago)
{
    mago->energia += 150;
    if (mago->energia > 500)
    {
        mago->energia = 500;
    }
    printf("%s recarga energia.\n", mago->nombre);
}