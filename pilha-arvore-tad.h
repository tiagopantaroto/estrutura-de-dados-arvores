#include <stdio.h>

struct pilha {
    Tree *no;
    Tree *prox;
};

typedef struct pilha Pilha;

void init(Pilha **p) {
    *p = NULL;
}

int pilhaEstaVazia(Pilha *p) {
    return p == NULL || p->no == NULL;
}

void push(Pilha **p, Tree *no) {
    Pilha *aux = (Pilha *) malloc(sizeof(Pilha));
    aux->no = no;
    aux->prox = NULL;
    if (pilhaEstaVazia(*p)) {
        *p = aux;
    }
    else {
        aux->prox = *p;
        *p = aux;
    }
}

Tree *pop(Pilha **p) {
    Tree *aux = NULL;
    if (!arvoreEstaVazia(*p)) {
        aux = (*p)->no;
        *p = (*p)->prox;
    }

    return aux;
}

void exibirPilha(Pilha *p) {
    Pilha *aux = p;
    while (aux != NULL) {
        printf(" %d ", aux->no->info);
        aux = aux->prox;
    }
}
