#include <stdio.h>
#include <stdlib.h>

int fibonacci(int termo){
    if (termo <= 1) { // Caso base 
        return 1;
    }
    return(fibonacci(termo - 1) + fibonacci(termo - 2));
}

int main(void){
    printf("Fibonacci: %d", fibonacci(10));
    return 0;
}