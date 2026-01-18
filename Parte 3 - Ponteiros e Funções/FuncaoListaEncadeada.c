#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id;
    int valor;
    struct No* prox;
} no;

no* criarNo(int id, int valor, no* prox){
    no *novo = (no*) malloc(sizeof(no));
    novo->id = id;
    novo->valor = valor;
    novo->prox = prox;
    return novo;
}

no* adicionaInicio(no* head, no* novo){
    novo->prox = head;
    return novo;
}

void adicionaFim(no* head, no* novo){
    if (head == NULL){
        head = novo;
    }
    no* aux = head;
    for(;aux->prox != NULL; aux = aux->prox);
    aux->prox = novo;
}

void adicionaFimRecursivo(no* head, no* novo){
    if(head == NULL){
        head = novo;
        return;
    }
    else if(head->prox == NULL){
        head->prox = novo;
        return;
    }
    adicionaFimRecursivo(head->prox, novo);
}

no* adicionaMeio(no* head, no* novo, int id){
    if (head == NULL){
        head = novo;
    }
    for (no* aux = head; aux != NULL; aux = aux->prox){
        if((aux->id == id)||(aux->prox == NULL)){
            novo->prox = aux->prox;
            aux->prox = novo;
            break;
        }
    }
    return head;
}

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

void mostraLista(no* head){
    for(no* aux = head; aux != NULL; aux = aux->prox) {
        printf("ID: %d, Valor: %d\n", aux->id, aux->valor);
    }
}

void mostraListaRecursiva(no* head){
    if(head == NULL){
        return;
    }
    printf("ID: %d, Valor: %d\n", head->id, head->valor);
    mostraListaRecursiva(head->prox);
}

void liberaLista(no* head){
    for(no* aux = head; head != NULL; head = aux) {
        aux = head->prox;
        free(head);
    }
    head = NULL;
}

void liberaListaRecursiva(no* head){
    if(head == NULL)
        return;
    liberaListaRecursiva(head->prox);
    free(head);
    head = NULL;
}

int main(void){

    no* head = criarNo(0, 0, NULL);
    mostraLista(head);
    liberaLista(head);
    printf("\n");

    head = criarNo(0, 0, NULL);
    head = adicionaInicio(head, criarNo(2, 2, NULL));
    mostraListaRecursiva(head);
    printf("\n");

    head = adicionaMeio(head, criarNo(1, 1, NULL), 2);
    mostraListaRecursiva(head);
    printf("\n");

    head = adicionaMeioRecursivo(head, criarNo(3, 3, NULL), 1);
    mostraListaRecursiva(head);
    printf("\n");

    liberaListaRecursiva(head);
    return 0;
}