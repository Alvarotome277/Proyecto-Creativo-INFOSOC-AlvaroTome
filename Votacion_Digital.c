#include <stdio.h>
#include <string.h>
#define MAX_WORD 100
#define MAX_VOTANTES 100000
#define MAX_CANDIDATOS 100
typedef struct {
long votos;
char nombre[MAX_WORD]
}Candidato;




int main(){
Candidato candidatos[MAX_CANDIDATOS];
int i, encontrado = 0, j;
char candidato_temp[MAX_WORD];
long n_candidatos = MAX_CANDIDATOS + 1, n_votantes = MAX_VOTANTES + 1;
while (n_candidatos > MAX_CANDIDATOS)
{
    printf ("Introduce el numero (menor que %ld) de candidatos : ", MAX_CANDIDATOS);
    scanf (" %ld", &n_candidatos);
    if (n_candidatos > MAX_CANDIDATOS)
    {
        printf("El numero de candidatos tiene que ser menor que %ld", MAX_CANDIDATOS);
    }
    
}


for ( i = 0; i < n_candidatos; i++)
{
    printf ("Introduce el nombre del candidato %ld: ",i + 1);
    scanf (" %s", candidatos[i].nombre);
    candidatos[i].votos = 0;
    for ( j = 0; j < i; j++)
    {
        if (strcmp(candidatos[j].nombre, candidatos[i].nombre) == 0)
        {
            printf (" Candidato ya registrado\n");
            i--;
            encontrado = 1;
        }
        else if ((j == i - 1 && encontrado == 0 )||( j == 0 && encontrado == 0)){
        printf ("%s Introducido a la votacion\n", candidatos[i].nombre);
        }
    }
    
    
    
}
while (n_votantes > MAX_VOTANTES)
{
    printf ("Introduce el numero (menor que %ld) de votantes: ", MAX_VOTANTES );
    scanf (" %ld" , &n_votantes);
    if (n_votantes > MAX_VOTANTES)
    {
        printf("El numero de votantes tiene que ser menor que %ld", MAX_VOTANTES);
    }
    
}
for ( i = 0; i < n_votantes; i++)
{
    encontrado = 0;
    while (encontrado == 0)
    {
    printf ("Introduce el nombre del candidato, eres el votante numero %ld: ",i + 1);
    scanf (" %s", candidato_temp);
    for ( i = 0; i < n_candidatos; i++)
        {
            if (strcmp (candidato_temp, candidatos[i].nombre) == 0)
            {
                candidatos[i].votos ++;
                encontrado = 1;
                printf("Voto añadido a %s", candidatos[i].nombre);
            }
            else if ( i == n_candidatos - 1 && encontrado == 0){
                printf (" Candidato no encontrado");
            }
        }    
    }
}



    
}