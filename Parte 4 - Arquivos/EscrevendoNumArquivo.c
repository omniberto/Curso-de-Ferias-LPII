#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE* arquivo;
    arquivo = fopen("exemplo.txt", "w");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    fputs("Esta e a linha inicial do arquivo!\n", arquivo);
    fprintf(arquivo, "Aqui um inteiro: %d, um float: %f e um char: %c\n", 0, 3.14, 'c');
    fputc('x', arquivo);

    if (fclose(arquivo) == EOF){
        printf("Erro ao fechar o arquivo.\n");
        return - 2;
    }; 

    return 0;
}