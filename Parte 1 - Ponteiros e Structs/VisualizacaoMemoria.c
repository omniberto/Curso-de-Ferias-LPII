#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int a = 0, b = 1;
    int *ponteiro_a = &a, *ponteiro_b = &b, *array, *post_array;
    int *ponteiro_para_si_mesmo, **aux;
    aux = &ponteiro_para_si_mesmo;
    ponteiro_para_si_mesmo = aux;

    printf("Espaco de memoria de a: 0x%x\n", ponteiro_a);
    printf("Espaco de memoria de b: 0x%x\n", ponteiro_b);
    printf("Tamanho de um int em Hexadecimal: 0x%x\n", sizeof(int));
    printf("Ponteiro auto referenciado: 0x%x 0x%x\n", ponteiro_para_si_mesmo, *ponteiro_para_si_mesmo);

    array = (int*) malloc(4 * sizeof(int));
    post_array = (int*) malloc(2 * sizeof(int));

    printf("Endereco do array: 0x%x ou %d\n", array, array);
    printf("Endereco do pos array: 0x%x ou %d\n", post_array, post_array);
    printf("Quatro inteiros ocupariam: 0x%x ou %d\n", 4 * sizeof(int), 4 * sizeof(int));
    printf("Enderecos do array:\n");
    for (int i = 0; i < 4; i++){
        printf("%d - 0x%x\n", i, &array[i]);
    }
    printf("0x%x\n", &array[3] + 4);

    ponteiro_a = NULL;
    ponteiro_b = NULL;
    aux = NULL;
    ponteiro_para_si_mesmo = NULL;
    free(array);
    free(post_array);
    return 0;
}