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
        if (n_candidatos > MAX_CANDIDATOS || n_candidatos <= 0){
            printf("El numero debe estar entre 1 y %d.\n", MAX_CANDIDATOS);
        }
    }

    for (i = 0; i < n_candidatos; i++)
    {
        printf("Introduce el nombre del candidato %d: ", i + 1);
        scanf(" %s", candidatos[i].nombre);
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
            printf("Votante %d, introduce el nombre de tu candidato: ", i + 1);
            scanf(" %s", candidato_temp);
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

    printf("\n========== RESULTADOS ==========\n");

    for (i = 0; i < n_candidatos - 1; i++)
    {
        for (j = 0; j < n_candidatos - 1 - i; j++)
        {
            if (candidatos[j].votos < candidatos[j + 1].votos)
            {
                Candidato temp = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n_candidatos; i++)
    {
        printf("  %d. %-20s %ld votos\n", i + 1, candidatos[i].nombre, candidatos[i].votos);
    }

    printf("\n=================================\n");
    long max_votos = candidatos[0].votos;
    int n_ganadores = 0;
    for (i = 0; i < n_candidatos; i++)
    {
        if (candidatos[i].votos == max_votos)
        {
            n_ganadores++;
        }
        else
        {
            break;
        }
    }

    if (n_ganadores == 1)
    {
        printf("  GANADOR: %s con %ld votos.\n", candidatos[0].nombre, max_votos);
    }
    else
    {
        printf("  EMPATE entre %d candidatos con %ld votos:\n", n_ganadores, max_votos);
        for (i = 0; i < n_ganadores; i++)
        {
            printf("    - %s\n", candidatos[i].nombre);
        }
    }
    printf("=================================\n");

    return 0;
}