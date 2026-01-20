#include <stdio.h>
#include <stdlib.h>

/*
    Parâmetros são valores repassados pra funções e procedimentos para ser utilizado durante a sua execução.
*/

// Procedimento utilizando paramêtros
void printfmod_procedimento(int val){
    printf("Recebi: %d\n", val);
}

// Função utilizando paramêtros
int printfmod_funcao(int val){
    int quad = val * val;
    printf("Retornarei: %d\n", quad);
    return quad;
}

int main(void){
    printfmod_procedimento(2);
    printfmod_funcao(2);
    return 0;
}