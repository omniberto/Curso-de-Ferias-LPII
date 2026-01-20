#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó
typedef struct No {
    int id;
    int valor;
    struct No* prox;
} no;

// Função utilizada para criar um nó
no* criarNo(int id, int valor, no* prox){
    no *novo = (no*) malloc(sizeof(no));
    novo->id = id;
    novo->valor = valor;
    novo->prox = prox;
    return novo;
}
// Função para adicionar um novo nó no começo da lista encadeada - Aqui precisamos receber qual o novo nó inicial da lista.
no* adicionaInicio(no* head, no* novo) {
    novo->prox = head;
    return novo;
}
// Função para adicionar o nó no final da lista - Aqui retornaremos o nó inicial caso ele tenha sido modificado.
no* adicionaFim(no* head, no* novo) {
    if (head == NULL) {
        head = novo;
    }
    else {
        no* aux = head;
        for(;aux->prox != NULL; aux = aux->prox);
        aux->prox = novo;
    }
    return head;
}
// Função para adicionar o nó no final da lista de forma recursiva.
no* adicionaFimRecursivo(no* head, no* novo) {
    if (head == NULL) {
        return novo;
    }
    head->prox = adicionaFimRecursivo(head->prox, novo);
    return head;
}
// Função para adicionar o nó no meio, depois que o id é encontrado. Caso não seja encontrado é adicionado no final da lista.
no* adicionaMeio(no* head, no* novo, int id){
    if (head == NULL){
        head = novo;
    }
    else{
        for (no* aux = head; aux != NULL; aux = aux->prox){
            if((aux->id == id) || (aux->prox == NULL)){
                novo->prox = aux->prox;
                aux->prox = novo;
                break;
            }
        }
    }
    return head;
}
// Função para adicionar o nó no meio recursivamente, depois que o id é encontrado.
no* adicionaMeioRecursivo(no* head, no* novo, int id){
    if (head == NULL){
        return novo;
    }
    else if (head->id == id) {
        novo->prox = head->prox;
        head->prox = novo;
        return head;
    }
    head->prox = adicionaMeioRecursivo(head->prox, novo, id);
    return head;
}
// Procedimento para percorrer a lista e mostrar de forma formatada.
void mostraLista(no* head){
    for(no* aux = head; aux != NULL; aux = aux->prox) {
        printf("ID: %d, Valor: %d\n", aux->id, aux->valor);
    }
}
// Procedimento para percorrer a lista recursivamente e mostrar de forma formatada.
void mostraListaRecursiva(no* head){
    if(head == NULL){
        return;
    }
    printf("ID: %d, Valor: %d\n", head->id, head->valor);
    mostraListaRecursiva(head->prox);
}
// Função para liberar a lista, retornando NULL como aterramento.
no* liberaLista(no* head){
    for(no* aux = head; head != NULL; head = aux) {
        aux = head->prox;
        free(head);
    }
    return NULL;
}
// Função para liberar a lista recursivamente, retornando NULL como aterramento.
no* liberaListaRecursiva(no* head){
    if(head == NULL)
        return NULL;
    head->prox = liberaListaRecursiva(head->prox);
    free(head);
    return NULL;
}

int main(void){

    no* head = criarNo(0, 0, NULL);
    mostraLista(head);
    head = liberaLista(head);
    if(head == NULL){
        printf("Liberado com Sucesso!\n");
    }
    printf("\n");

    printf("Adiciona no inicio:\n");
    head = criarNo(0, 0, NULL);
    head = adicionaInicio(head, criarNo(2, 2, NULL));
    mostraListaRecursiva(head);
    printf("\n");

    printf("Adiciona no meio:\n");
    head = adicionaMeio(head, criarNo(1, 1, NULL), 2);
    mostraListaRecursiva(head);
    printf("\n");

    printf("Adiciona no meio recursivamente:\n");
    head = adicionaMeioRecursivo(head, criarNo(3, 3, NULL), 1);
    mostraListaRecursiva(head);
    printf("\n");

    printf("Adiciona no fim:\n");
    head = adicionaFim(head, criarNo(4, 4, NULL));
    mostraListaRecursiva(head);
    printf("\n");
    
    printf("Adiciona no fim recursivamente:\n");
    head = adicionaFimRecursivo(head, criarNo(5, 5, NULL));
    mostraLista(head);
    printf("\n");

    head = liberaListaRecursiva(head);
    if(head == NULL)
        printf("Liberado com sucesso!");

    return 0;
}