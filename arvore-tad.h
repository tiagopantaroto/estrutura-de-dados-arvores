struct no {
    int info;
    struct no *esq, *dir;
};

typedef struct no Tree;

Tree *criarNo(int info) {
    Tree *no = (Tree *) malloc(sizeof(Tree));
    no->info = info;
    no->esq = no->dir = NULL;
    return no;
}

void inserirABB(Tree **raiz, int info) {
    if (*raiz == NULL) {
        *raiz = criarNo(info);
    } else {
        Tree *aux = *raiz;
        int inseriu = 0;
        while (inseriu == 0) {
            if (aux->info > info) {
                if (aux->esq == NULL) {
                    aux->esq = criarNo(info);
                    inseriu = 1;
                } else {
                    aux = aux->esq;
                }
            } else {
                if (aux->dir == NULL) {
                    aux->dir = criarNo(info);
                    inseriu = 1;
                } else {
                    aux = aux->dir;
                }
            }
        }
    }
}

void inserirABBR(Tree **raiz, int info) {
    if (*raiz == NULL) {
        *raiz = criarNo(info);
    } else {
        if ((*raiz)->info > info)
            inserirABBR(&((*raiz)->esq), info);
        else
            inserirABBR(&((*raiz)->dir), info);
    }
}

int arvoreEstaVazia(Tree *raiz) {
    return raiz == NULL;
}


/* Pré-ordem: imprime, desce para a esquerda, imprime, desce para esquerda até conseguir.
 * Quando chegar num nó que não possui filho à esquerda, imprime o da direita e verifica se ele possui filho à esquerda.
 * Se possuir, imprime o da esquerda e vai descendo nele imprimindo todos à esquerda.
 * Repetir os passos.
 *
 * Ou seja:
 * 1- Imprime (como é passada a raiz, então ela será imprimida primeiramente)
 * 2- Vai para o nó da esquerda. Se ele for diferente de null, imprime.
 * 3- Repete o passo 2 até que o nó da esquerda seja null.
 * 4- Vai para o nó da direita do nó atual. Se ele for diferente de null, imprime.
 * 5- Repete o passo 2 e 3.
 * */

void preOrdemR(Tree *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        preOrdemR(raiz->esq);
        preOrdemR(raiz->dir);
    }
}


/* Em-ordem: desce o mais à esquerda que conseguir, imprime, vai um para a direita e volta a descer para a esquerda.
 * 1- Desce para a esquerda até chegar num null.
 * 2- Imprime o anterior (que não é null).
 * 3- Vai para o nó da direita do que foi imprimido.
 * 4- Se ele não for null, faz o passo 1.
 * 5- Faz o passo 2 e 3.
 * 6- Vai repetindo.
 * */

void inOrdemR(Tree *raiz) {
    if (raiz != NULL) {
        inOrdemR(raiz->esq);
        printf("%d ", raiz->info);
        inOrdemR(raiz->dir);
    }
}

/*
 * Pós-ordem: desce o mais à esquerda, imprime, sobe um, desce para a direita, desce o mais à esquerda e assim vai.
 */

void posOrdemR(Tree *raiz) {
    if(raiz != NULL) {
        posOrdemR(raiz->esq);
        posOrdemR(raiz->dir);
        printf("%d ", raiz->info);
    }
}

int alturaDaArvore(Tree *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int alturaEsquerda = alturaDaArvore(raiz->esq);
        int alturaDireita = alturaDaArvore(raiz->dir);
        if (alturaEsquerda > alturaDireita)
            return alturaEsquerda + 1;
        else
            return alturaDireita + 1;
    }
}

int quantidadeDeNos(Tree *raiz) {
    if(raiz == NULL)
        return 0;
    else {
        int quantidade = quantidadeDeNos(raiz->esq);
        quantidade += quantidadeDeNos(raiz->dir);
        return quantidade + 1;
    }
}

void procurarNo(Tree *raiz, int valorProcurado, Tree** noProcurado) {
    if(raiz != NULL) {
        if(raiz->info == valorProcurado)
            *noProcurado = raiz;
        else {
            procurarNo(raiz->esq, valorProcurado, noProcurado);
            procurarNo(raiz->dir, valorProcurado, noProcurado);
        }
    }
}

