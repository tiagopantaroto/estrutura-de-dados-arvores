#include <stdio.h>
#include <stdlib.h>
#include "arvore-tad.h"
#include "pilha-arvore-tad.h"

void exibirArvoreCopilot(Tree *raiz);
void criarArvoreNaMao();

int main() {

    //criarArvoreNaMao();
    Tree *raiz = NULL;
    /*
    inserirABB(&raiz, 20);
    inserirABB(&raiz, 10);
    inserirABB(&raiz, 12);
    inserirABB(&raiz, 13);
    inserirABB(&raiz, 4);
    inserirABB(&raiz, 400);
    inserirABB(&raiz, 200);
    inserirABB(&raiz, 500);
    */


    Pilha *p;
    init(&p);
    printf("\nEsta vazia? %d", pilhaEstaVazia(p));
    Tree *n1 = criarNo(100);
    Tree *n2 = criarNo(200);
    Tree *n3 = criarNo(400);
    push(&p, n1);
    push(&p, n2);
    push(&p, n3);
    pop(p);
    printf("\nPilha = ");
    exibirPilha(p);



    //exibirArvoreCopilot(raiz);


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


void exibirArvoreCopilot(Tree *raiz) {
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
