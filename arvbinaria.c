#include "arvbinaria.h"

/* Aloca memória para um novo nó*/
PONT criar_novo_no(CHAVE key)
{
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->key = key;
    return novoNo;
}

int verifica_galho(PONT raiz)
{
    if (raiz->esq == NULL)
    {
        return 0;
    }
    else if (raiz->esq != NULL && raiz->dir == NULL)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int arvore_vazia(PONT raiz)
{
    return raiz == NULL;
}


/* Encontrar a posição certa para inserção do nó */
bool inserir_auxliar(PONT raiz, CHAVE key)
{
    if (key < raiz->key)
    {
        if (raiz->esq == NULL)
        {
            raiz->esq = criar_novo_no(key);
            return true;
        }
        else
            return inserir_auxliar(raiz->esq, key);
    }
    else
    {
        if (raiz->dir == NULL)
        {
            raiz->dir = criar_novo_no(key);
            return true;
        }
        else
            return inserir_auxliar(raiz->dir, key);
    }
}

bool inserir_no(PONT *raiz, CHAVE key)
{
    if (*raiz == NULL)
    {
        *raiz = criar_novo_no(key);
        return true;
    }
    else
        return inserir_auxliar(*raiz, key);
}

/* Insere um novo item na árvore binária */
PONT inserir_no_filho(PONT raiz, PONT filho, bool direita)
{
    if (direita == true)
    {
        raiz->esq = filho;
    }
    else
    {
        raiz->dir = filho;
    }

    return raiz;
}

// INSERE VALOR
PONT inserir_chave(PONT raiz, int key)
{
    raiz->key = key;
    return raiz;
}

/* Retorna o nó pai por meio de busca binária */
PONT busca_no(PONT raiz, CHAVE key, PONT *pai)
{
    PONT atual = raiz;
    *pai = NULL;
    while (atual)
    {
        if (atual->key == key)
            return (atual);
        *pai = atual;
        if (key < atual->key)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return (NULL);
}

PONT retorna_arv(PONT raiz, bool direita)
{
    if (direita == false)
    {
        return raiz->esq;
    }
    else
    {
        return raiz->dir;
    }
}

PONT limpa_arvore(PONT raiz)
{
    if (!arvore_vazia(raiz))
    {
        limpa_arvore(raiz->esq);
        limpa_arvore(raiz->dir);
        free(raiz);
    }

    return NULL;
}

PONT maior_esquerdo(PONT p, PONT *ant)
{
    *ant = p;
    p = p->esq;
    while (p->dir)
    {
        *ant = p;
        p = p->dir;
    }
    return (p);
}

/* Exclui a chave com valor igual a key */
bool excluir_chave(PONT *raiz, CHAVE key)
{
    PONT atual, atual_pai, substituto, substituto_pai;

    substituto = NULL;

    atual = busca_no(*raiz, key, &atual_pai);

    if (atual == NULL)
        return false;

    if ((!atual->esq) || (!atual->dir))
    {
        if ((!atual->esq))
            substituto = atual->dir;
        if ((!atual->dir))
            substituto = atual->esq;

        if (atual_pai == NULL) // o excluido a raiz
        {
            *raiz = substituto;
        }
        else
        {
            if (atual_pai->key > key)
                atual_pai->esq = substituto;
            else
                atual_pai->dir = substituto;
        }
        free(atual);
    }
    else
    {
        substituto = maior_esquerdo(atual, &substituto_pai);
        atual->key = substituto->key;
        if (substituto_pai->esq == substituto)
        {
            substituto_pai->esq = substituto->esq;
        }
        else
        {
            substituto_pai->dir = substituto->esq;
        }
        free(substituto);
    }

    return true;
}

/* Exibe arvore Em Ordem */
void arvore_em_ordem(PONT raiz)
{
    if (raiz == NULL)
        return;
    arvore_em_ordem(raiz->esq);
    printf("%d ", raiz->key);
    arvore_em_ordem(raiz->dir);
}

/* Exibe arvore Pre Ordem */
void arvore_pre_ordem(PONT raiz)
{
    if (raiz == NULL)
        return;
    printf("%d ", raiz->key);
    arvore_pre_ordem(raiz->esq);
    arvore_pre_ordem(raiz->dir);
}

void imprimir_arvore(PONT raiz)
{
    printf("<");
    if (!arvore_vazia(raiz))
    {
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            printf("%d", raiz->key);
        }
        else
        {
            printf("%c", raiz->key);
        }
        imprimir_arvore(raiz->esq); 
        imprimir_arvore(raiz->dir); 
    }
    printf(">");
}

/* Exibe arvore Pos Ordem */
void arvore_pos_ordem(PONT raiz)
{
    if (raiz == NULL)
        return;
    arvore_pos_ordem(raiz->esq);
    arvore_pos_ordem(raiz->dir);
    printf("%d ", raiz->key);
}

/* Destroi uma arvore */
void destruir_aux(PONT subRaiz)
{
    if (subRaiz)
    {
        destruir_aux(subRaiz->esq);
        destruir_aux(subRaiz->dir);
        free(subRaiz);
    }
}

/* Libera toda memoria de uma arvore e tornar o valor da raiz nulo */
void destruir_arvore(PONT *raiz)
{
    destruir_aux(*raiz);
    *raiz = NULL;
}

/* Inicializa árvore */
void inicializar(PONT *raiz)
{
    *raiz = NULL;
}

int retorna_item(PONT raiz)
{
    return raiz->key;
}

int qtd_folhas(PONT raiz)
{
    if (arvore_vazia(raiz->esq) && arvore_vazia(raiz->dir))
    {
        return 1;
    }
    else if (!arvore_vazia(raiz->esq) && arvore_vazia(raiz->dir))
    {
        return qtd_folhas(raiz->esq);
    }
    else if (arvore_vazia(raiz->esq) && !arvore_vazia(raiz->dir))
    {
        return qtd_folhas(raiz->dir);
    }

    return qtd_folhas(raiz->esq) + qtd_folhas(raiz->dir);
}