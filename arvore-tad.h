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
        while(inseriu == 0) {
            if(aux->info > info) {
                if(aux->esq == NULL) {
                    aux->esq = criarNo(info);
                    inseriu = 1;
                } else {
                    aux = aux->esq;
                }
            } else {
                if(aux->dir == NULL) {
                    aux->dir = criarNo(info);
                    inseriu = 1;
                } else {
                    aux = aux->dir;
                }
            }
        }

    }
}
