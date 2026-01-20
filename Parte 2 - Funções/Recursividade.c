#include <stdio.h>
#include <stdlib.h>

/*
    Funções recursivas chamam à si mesmas, de modo a operar até que um caso final seja atingido.
    Funções recursivas possuem uma formatação básica e precisam ter:
    - Caso(s) Base: Condição final onde a execução da recursão é finalizada por completo.
    - Chamada da função: Chama-se novamente a função, desta vez com algum dos paramêtros tendo seu valor afetado.
    Recursão é muito útil em certos casos, entretanto, existe uma alta propensão à overflow.
*/

int fibonacci(int termo){
    if (termo <= 1) { // Caso base.
        return 1; // Finalização da chamada da função.
    }
    return(fibonacci(termo - 1) + fibonacci(termo - 2)); // Chamada da função.
}

int main(void){
    printf("Fibonacci: %d", fibonacci(5));
    return 0;
}