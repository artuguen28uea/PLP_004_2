#ifndef ARV_BINARIA
#define ARV_BINARIA
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;
typedef int CHAVE;

typedef struct aux
{
    CHAVE key;
    struct aux *esq, *dir;
} NO;

typedef NO *PONT;

PONT criar_novo_no(CHAVE key);
int verifica_galho(PONT raiz);
int arvore_vazia(PONT raiz);
bool inserir_auxliar(PONT raiz, CHAVE key);
bool inserir_no(PONT *raiz, CHAVE newKey);
PONT inserir_no_filho(PONT raiz, PONT filho, bool direita);
PONT inserir_chave(PONT raiz, int key);
PONT busca_no(PONT raiz, CHAVE key, PONT *pai);
PONT retorna_arv(PONT raiz, bool direita);
PONT limpa_arvore(PONT raiz);
PONT maior_esquerdo(PONT p, PONT *ant);
bool excluir_chave(PONT *raiz, CHAVE key);
void arvore_em_ordem(PONT raiz);
void imprimir_arvore(PONT raiz);
void arvore_pre_ordem(PONT raiz);
void arvore_pos_ordem(PONT raiz);
void destruir_aux(PONT subRaiz);
void destruir_arvore(PONT *raiz);
void inicializar(PONT *raiz);
int retorna_item(PONT raiz);
int qtd_folhas(PONT raiz);

#endif
