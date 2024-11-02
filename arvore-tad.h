
struct no {
    int info;
    struct no *esq, *dir;
};

typedef struct no Tree;

Tree* criarNo(int info) {
    Tree *no = (Tree*) malloc(sizeof(Tree));
    no->info = info;
    no->esq = no->dir = NULL;
    return no;
}