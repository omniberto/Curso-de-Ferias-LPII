#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE* arquivo;
    arquivo = fopen("exemplo.txt", "a");
    
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    fputs("\nEsta é a última linha do código!\n", arquivo);

    if (fclose(arquivo) == EOF){
        printf("Erro ao fechar o arquivo.\n");
        return - 2;
    }; 

    return 0;
}