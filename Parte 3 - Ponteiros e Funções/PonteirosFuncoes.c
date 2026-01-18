#include <stdio.h>
#include <stdlib.h>

double soma(double a, double b){
    return a + b;
}
double subtracao(double a, double b){
    return a - b;
}
double multiplicacao(double a, double b){
    return a * b;
}
double divisao(double a, double b){
    return a / b;
}

int main(void){
    double (**ponteiro_funcoes) (double, double) = malloc(4 * sizeof(double* (double, double)));
    for (int i = 0; i < 4; i++) {
        ponteiro_funcoes[i] = malloc (sizeof(double (double, double)));
    }
    ponteiro_funcoes[0] = &soma;
    ponteiro_funcoes[1] = &subtracao;
    ponteiro_funcoes[2] = &multiplicacao;
    ponteiro_funcoes[3] = &divisao;
    for (int i = 0; i < 4; i++) {
        printf("%lf\n", ponteiro_funcoes[i](2, 4));
    }

    // Liberar o espaço de memória
    for (int i = 0; i < 4; i++) {
        free(ponteiro_funcoes[i]);
    }
    free(ponteiro_funcoes);
    return 0;
}