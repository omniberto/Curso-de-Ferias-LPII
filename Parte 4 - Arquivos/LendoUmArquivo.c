#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE* arquivo;
    arquivo = fopen("exemplo.txt", "r");
    
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    char primeira_linha[100];
    int inteiro;
    float flutuante;
    char caractere, caractere_2;

    fgets(primeira_linha, 100, arquivo);
    fscanf(arquivo, "Aqui um inteiro: %d, um float: %f e um char: %c\n", &inteiro, &flutuante, &caractere);
    caractere_2 = fgetc(arquivo);

    printf("%s", primeira_linha);
    printf("Inteiro: %d, Float: %.2f e Char: %c\n", inteiro, flutuante, caractere);
    printf("%c\n", caractere_2);

    if (fclose(arquivo) == EOF){
        printf("Erro ao fechar o arquivo.\n");
        return - 2;
    }; 

    return 0;
}