#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMVET 1024
#define VETSIZE 100
#define LOOP 1024

void insertion_sort(int *a)
{
    int i, j, tmp;

    for (i = 1; i < VETSIZE; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0 && tmp < a[j]; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
}

int main(int argc, char **argv)
{
    int loop_interno;
    FILE *salvar_tempo;
    salvar_tempo = fopen("tempos em c.txt", "w");
    
    for (loop_interno = 0; loop_interno < LOOP; loop_interno++)
    {
        clock_t inicio = clock();
        int vet[VETSIZE];
        double tempo;
        srand(time(NULL));

        for (int i = 0; i < NUMVET; i++)
        {
            for (int j = 0; j < VETSIZE; j++)
            {
                vet[j] = rand() % 101;
            }

            insertion_sort(vet);

            /*for (int j = 0; j < VETSIZE; j++)
            {
                printf("%d ", vet[j]);
            }
            printf("\n");*/
        }
        clock_t fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo de execucao em segundos: %.3f\n", tempo);
        fprintf(salvar_tempo, "%.3f\n", tempo);
    }
    fclose(salvar_tempo);
    return 0;
}
