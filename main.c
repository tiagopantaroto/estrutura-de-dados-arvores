#include <stdio.h>
#include <stdlib.h>
#include "arvore-tad.h"
#include "pilha-arvore-tad.h"

void exibirArvoreCopilot(Tree *raiz);

void criarArvoreNaMao();

Tree *elementoDoTopoDaPilha(Pilha *p);

void preOrdemI(Tree *raiz);

void inOrdemI(Tree *raiz);

void nivelDoNo(Tree *raiz, int info, int *nivel);

Tree *retornarPaiDoNo(Tree *raiz, int info);

int main() {
    //criarArvoreNaMao();
    Tree *raiz = NULL;
    Pilha *p;

    inserirABB(&raiz, 20);
    inserirABB(&raiz, 10);
    inserirABB(&raiz, 5);
    inserirABB(&raiz, 12);
    inserirABB(&raiz, 8);
    inserirABB(&raiz, 400);

    Tree *pai = retornarPaiDoNo(raiz, 400);
    if(pai != NULL)
        printf("\npai = %d", pai->info);
    else
        printf("\npai = NULL");
    //exibirArvoreCopilot(raiz);
}

Tree *retornarPaiDoNo(Tree *raiz, int info) {
    Tree *pai, *no;
    pai = NULL;
    no = raiz;
    int encontrou = 0;
    while (encontrou == 0 && no != NULL) {
        if (no->info == info)
            encontrou = 1;
        else {
            pai = no;
            if (info > no->info)
                no = no->dir;
            else
                no = no->esq;
        }
    }

    return pai;
}

void nivelDoNo(Tree *raiz, int info, int *nivel) {
    int encontrou = 0;
    Tree *no = raiz;
    int nivelAtual = 1;
    while (encontrou == 0 && no != NULL) {
        if (no->info == info) {
            *nivel = nivelAtual;
            encontrou = 1;
        } else {
            if (info > no->info)
                no = no->dir;
            else
                no = no->esq;
            nivelAtual++;
        }
    }
}

void preOrdemI(Tree *raiz) {
    if (!arvoreEstaVazia(raiz)) {
        Tree *no = raiz; // Só criei essa variável para usar outro nome, ficar mais fácil de entender
        Pilha *p;
        init(&p);
        push(&p, no);
        while (!pilhaEstaVazia(p)) {
            no = pop(&p);
            printf("%d ", no->info);

            if (no->dir != NULL)
                push(&p, no->dir);
            if (no->esq != NULL)
                push(&p, no->esq);
        }
    }
}

void inOrdemI(Tree *raiz) {
    if (!arvoreEstaVazia(raiz)) {
        Pilha *p;
        init(&p);
        Tree *no = raiz;

        while (!pilhaEstaVazia(p) || no != NULL) {
            while (no != NULL) {
                push(&p, no);
                no = no->esq;
            }

            no = pop(&p);
            printf("%d ", no->info);
            no = no->dir;
        }
    }
}

Tree *elementoDoTopoDaPilha(Pilha *p) {
    if (!pilhaEstaVazia(p))
        return p->no;
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
