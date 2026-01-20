#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Struct se refere a uma estrutura de dados criada pelo próprio usuário.
    Os structs permitem que informações referentes ao mesmo tipo de um objeto esteja dentro de uma mesma variável.
*/

// Criando struct
struct estrutura_simples {
    int numero;
    char palavra[50];
};

// Utilizando typedef
typedef struct {
    int numero;
    char palavra[50];
} estrutura_simples_2;

typedef struct {
    int numero;
    char letra;
} estrutura_simples_3;

int main(void) {
    // Inicializando struct com valores pós declaração
    struct estrutura_simples novo_struct;
    novo_struct.numero = 2;
    strcpy(novo_struct.palavra, "teste");
    printf("Struct 1: %d - %s\n", novo_struct.numero, novo_struct.palavra);

    // Inicializando struct com valores na declaração (Se o struct não tiver uma string)
    estrutura_simples_3 novo_struct3 = {1, 'a'};
    printf("Struct 3: %d - %c\n", novo_struct3.numero, novo_struct3.letra);

    // Atribuindo valores para um struct por entrada
    estrutura_simples_2 novo_struct2;
    printf("Digite um numero: ");
    scanf("%d", &novo_struct2.numero);
    fflush(stdin);
    printf("Digite uma frase: ");
    scanf("%[^\n]s", novo_struct2.palavra);
    printf("Struct 2: %d - %s\n", novo_struct2.numero, novo_struct2.palavra);

    return 0;
}
