#include <stdio.h>
#include <stdlib.h>

/*
    Ponteiros são variáveis utilizadas para se referir à endereços de memória
    Um ponteiro sempre terá o mesmo tamanho, independente do tipo de dado que aponte.
*/

int main(void) {
    // Inicializando variáveis
    int numero = 0, numero_2 = 1;

    // Utilizanndo ponteiros para armazenar os endereços de memória
    int *ponteiro = &numero;
    int **ponteiro_de_ponteiro = &ponteiro;

    printf("Numero: %d\nEndereco: 0x%x\nPonteiro: 0x%x\nPonteiro de ponteiros: 0x%x\n", numero, &numero, ponteiro, ponteiro_de_ponteiro);
    printf("Numero via ponteiro: %d\nNumero via ponteiro de ponteiros: %d\n", *ponteiro, **ponteiro_de_ponteiro);
    printf("Endereco 1: 0x%x\nEndereco 2: 0x%x", &numero, &numero_2);

    /*  NULL representa um vazio, podendo ser utilizado para inicializar um ponteiro quando não se tem um endereço definido 
        ou para terminar um ponteiro ao final da execução do código por questões de segurança e memória.
    */
    ponteiro = NULL;
    ponteiro_de_ponteiro = NULL;

    return 0;
}