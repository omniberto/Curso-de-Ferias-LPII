#include <stdio.h>
#include <stdlib.h>
 
// Struct definindo o nó das listas
typedef struct No {
    int id;
    int valor;
    struct No* prox; // Ponteiro para o próximo termo da lista
} no;

int main(void) {

    /* Inicializando o começo da lista encadeada */
    no* head;
    head = (no*) malloc(sizeof(no));

    /* Em structs alocados dinamicamente, utiliza-se '->' ao inves do '.' */
    head->id = 1;
    head->valor = 1;
    head->prox = NULL;
    
    /* Existem 3 formas de adicionar à lista encadeada.*/

    /* Adicionando no final. Aqui, não se pode perder a referência ao começo, logo, head não pode ser atualizado.*/
    int tamanho = 5;
    no* aux = head; /* Inicializamos então um nó auxiliar que vai guardar o ÚLTIMO TERMO da lista.*/
    // [1]-> temp-> temp1->NULL
    for (int i = 2; i <= tamanho; i++) {

        no* temp = (no*) malloc(sizeof(no));
        temp->id = i; // Definindo o ID
        temp->valor = 2 * i - 1; // Atribuindo um valor, neste caso, qual o iésimo ímpar
        temp->prox = NULL; // Aterrando o ponteiro

        aux->prox = temp; // Atualizando o próximo do ÚLTIMO TERMO da lista
        aux = aux->prox; // Atualizando qual o último termo da lista
    }

    aux = head;
    printf("Adicionando no final:\n");
    for (int i = 0; i < tamanho; i++){
        printf("ID: %d\t Valor: %d\n", aux->id, aux->valor);
        aux = aux->prox;
    }
    
    //[temp] -> 1 -> NULL
    /* Adicionando no ínicio. Aqui, se atualiza a referência ao começo.*/
    for (int i = 1; i <= tamanho; i++) {
        no* temp = (no*) malloc(sizeof(no));
        temp->id = -i; // Definindo o ID
        temp->valor = 2 * (-i) + 1; // Atribuindo um valor
        temp->prox = head; // O próximo do novo nó será o começo da nossa lista
        head = temp; // Atualizando o COMEÇO da lista
    }
    
    printf("\nAdicionando no comeco:\n");
    for (aux = head; aux != NULL; aux = aux->prox){
        printf("ID: %d\t Valor: %d\n", aux->id, aux->valor);
    }

    /* Adicionando no meio. Aqui, se utiliza um condicional para saber quando inserir.*/
    for (no* aux = head; aux != NULL; aux = aux->prox) {
        if (aux->id == -1) {
            // O nó é inicializado antes do laço apenas quando a condição é encontrada
            no* temp = (no*) malloc(sizeof(no));
            temp->id = 0; // Definindo o ID
            temp->valor = 0; // Atribuindo um valor

            temp->prox = aux->prox; // o próximo do novo nó é o próximo termo do nó atual
            aux->prox = temp; // Atualizamos o próximo do atual para ser o novo nó

            break;
        }
    }
    printf("\nAdicionando no meio:\n");
    for (aux = head; aux != NULL; aux = aux->prox){
        printf("ID: %d\t Valor: %d\n", aux->id, aux->valor);
    }

    // Liberando os nós da lista
    for(; head != NULL; head = aux) {
        aux = head->prox;
        free(head);
    }

    //[id, valor, prox: ponteiro] -> [] -> [] -> [] -> NULL

    return 0;
}