#include <stdio.h>
#include <stdlib.h>
#include "arvore-tad.h"

void exibirArvoreCopilot(struct no *raiz);
void criarArvoreNaMao();

int main() {
    criarArvoreNaMao();
}

void criarArvoreNaMao() {
    // Aqui criarei uma árvore sem utilizar nenhuma função, exceto a criarNo().
    // A árvore criada terá a estrutura: (20 (10) (2 (17) (22 (39))))
    Tree *no20 = criarNo(20);
    Tree *no10 = criarNo(10);
    Tree *no2 = criarNo(2);
    Tree *no17 = criarNo(17);
    Tree *no22 = criarNo(22);
    Tree *no39 = criarNo(39);

    no20->esq = no10;
    no20->dir = no2;
    no2->esq = no17;
    no2->dir = no22;
    no22->esq = no39;

    exibirArvoreCopilot(no20);
}


void exibirArvoreCopilot(struct no *raiz) {
    if (raiz == NULL) return;

    printf("(%d", raiz->info);

    if (raiz->esq != NULL || raiz->dir != NULL) {
        if (raiz->esq != NULL) {
            printf(" ");
            exibirArvoreCopilot(raiz->esq);
        }

        if (raiz->dir != NULL) {
            printf(" ");
            exibirArvoreCopilot(raiz->dir);
        }
    }

    printf(")");
}

/*
void exibirArvoreCOPILOT(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info); // Exibe o valor do nó atual
        exibirArvoreCOPILOT(raiz->esq);    // Exibe a subárvore esquerda
        exibirArvoreCOPILOT(raiz->dir);    // Exibe a subárvore direita
    }
}
*/
