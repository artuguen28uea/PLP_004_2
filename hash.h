#ifndef TABELA_HASH
#define TABELA_HASH
#include <stdio.h>
#include <stdlib.h>

#define LEN 30

typedef struct hash
{
    int key;
    int value;
} hash;

typedef struct tabelahash
{
    int len;
    int max;
    hash **data;

} tabelahash;

void cria_tabela();
int hash_code(int chave);
void inserir(hash *nodo);
hash* buscar_elemento(int chave);
void imprimir_tabela();

hash tabelaHash[LEN];

#endif
