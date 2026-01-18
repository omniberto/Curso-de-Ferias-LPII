#include <stdio.h>
#include <stdlib.h>

/*
    A alocação dinâmica de memória permite que os dados sejam armazenados na memória de forma mutável e variável.
    Permitindo criar arrays, matrizes entre outros tipos de dados de forma pontual, conforme se precisa durante a execução do código.
*/

int main(void) {

    // Inicializando ponteiros para alocação dinâmica
    int *vetor_dinamico;
    int **matriz_dinamica;

    // Variável de tamanho.
    int tamanho = 5;

    // Alocando dados através do malloc
    vetor_dinamico = (int*) malloc (tamanho * sizeof(int)); // malloc (tamanho), sizeof() serve para saber o tamanho que um tipo de dados ocupa na memória
    if (vetor_dinamico == NULL) {
        return 1;
    }

    matriz_dinamica = malloc (tamanho * sizeof(int*));
    if (matriz_dinamica != NULL) {
        for (int i = 0; i < tamanho; i++) {
            matriz_dinamica[i] = calloc (tamanho, sizeof(int)); // calloc inicializa os valores zerados.
            if (matriz_dinamica[i] == NULL) {
                return 2;
            }
            vetor_dinamico[i] = i + 1;
        }
    }

    printf ("Vetor: ");
    for (int i = 0; i < tamanho; i++){
        printf ("%d ", vetor_dinamico[i]);
    }
    printf ("\n");

    printf ("Matriz:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++){
            printf ("%d ", matriz_dinamica[i][j]);
        }
        printf ("\n");
    }

    // Liberar os espaços de memória é essencial quando utilizando alocação dinâmica
    free (vetor_dinamico);
    vetor_dinamico = NULL; // Apontar para NULL aterra os pontieros, garantindo que não haja problemas depois.

    // Numa matriz dinâmica, cada linha precisa ser liberada separadamente.
    for (int i = 0; i < tamanho; i++){
        free (matriz_dinamica[i]);
        matriz_dinamica[i] = NULL;
    }
    free (matriz_dinamica);
    matriz_dinamica = NULL;

    return 0;
}