#include <stdio.h>
#include <string.h>

#define MAX_WORD 100
#define MAX_VOTANTES 100000
#define MAX_CANDIDATOS 100

typedef struct
{
    long votos;
    char nombre[MAX_WORD];
} Candidato;

int main()
{
    Candidato candidatos[MAX_CANDIDATOS];
    long i, j;
    int encontrado = 0;
    char candidato_temp[MAX_WORD];
    long n_candidatos = MAX_CANDIDATOS + 1, n_votantes = MAX_VOTANTES + 1;

    while (n_candidatos > MAX_CANDIDATOS || n_candidatos <= 0)
    {
        printf("Introduce el numero de candidatos (1 - %d): ", MAX_CANDIDATOS);
        scanf(" %ld", &n_candidatos);
        if (n_candidatos > MAX_CANDIDATOS || n_candidatos <= 0)
        {
            printf("El numero debe estar entre 1 y %d.\n", MAX_CANDIDATOS);
        }
    }

    for (i = 0; i < n_candidatos; i++)
    {
        printf("Introduce el nombre del candidato %ld: ", i + 1);
        scanf(" %99s", candidatos[i].nombre);
        candidatos[i].votos = 0;

        encontrado = 0;
        for (j = 0; j < i; j++)
        {
            if (strcmp(candidatos[j].nombre, candidatos[i].nombre) == 0)
            {
                printf("  ¡Candidato ya registrado! Intentalo de nuevo.\n");
                encontrado = 1;
                break;
            }
        }

        if (encontrado)
        {
            i--;
        }
        else
        {
            printf("  '%s' registrado correctamente.\n", candidatos[i].nombre);
        }
    }

    while (n_votantes > MAX_VOTANTES || n_votantes <= 0)
    {
        printf("Introduce el numero de votantes (1 - %d): ", MAX_VOTANTES);
        scanf(" %ld", &n_votantes);
        if (n_votantes > MAX_VOTANTES || n_votantes <= 0)
        {
            printf("El numero debe estar entre 1 y %d.\n", MAX_VOTANTES);
        }
    }

    for (i = 0; i < n_votantes; i++)
    {
        encontrado = 0;
        while (!encontrado)
        {
            printf("Votante %ld, introduce el nombre de tu candidato: ", i + 1);
            scanf(" %99s", candidato_temp);
            for (j = 0; j < n_candidatos; j++)
            {
                if (strcmp(candidato_temp, candidatos[j].nombre) == 0)
                {
                    candidatos[j].votos++;
                    encontrado = 1;
                    printf("  Voto agregado a '%s'.\n", candidatos[j].nombre);
                    break;
                }
            }
            if (!encontrado)
            {
                printf("  Candidato no encontrado. Prueba de nuevo.\n");
            }
        }
    }

    long max_votos = 0;
    for (i = 0; i < n_candidatos; i++)
    {
        if (candidatos[i].votos > max_votos)
            max_votos = candidatos[i].votos;
    }

    printf("\nResultados:\n");
    for (i = 0; i < n_candidatos; i++)
    {
        printf("%s: %ld votos\n", candidatos[i].nombre, candidatos[i].votos);
    }
    printf("\nGanador/es:\n");
    int n_ganadores = 0;
    for (i = 0; i < n_candidatos; i++)
    {
        if (candidatos[i].votos == max_votos)
        {
            printf("%s con %ld votos\n", candidatos[i].nombre, max_votos);
            n_ganadores++;
        }
    }
    if (n_ganadores > 1)
    {
        printf("Hay un empate entre %d candidatos!\n", n_ganadores);
    }
    return 0;
}