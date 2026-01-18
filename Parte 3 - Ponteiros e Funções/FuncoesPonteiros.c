#include <stdio.h>
#include <stdlib.h>
 
int* criarVetorSequencial(int ini, int fim) {
    if (fim < ini) {
        return NULL;
    }
    int *vetor = (int*) malloc((fim - ini + 1) * sizeof(int));
    for (int i = ini; i <= fim; i++) {
        vetor[i] = i;
    }
    return vetor;
}

void mostrarVetor(int* vetor, int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if(i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void trocar(int *a, int *b) {
    int aux = *b;
    *b = *a;
    *a = aux;

}
int main (void) {

    int *vetor = criarVetorSequencial(0, 5);
    mostrarVetor(vetor, 6);
    free(vetor);

    int a = 5, b = 6;
    printf("a: %d, b: %d\n", a, b);
    trocar(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    
    return 0;
}