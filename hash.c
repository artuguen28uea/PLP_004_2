#include "hash.h"

void cria_tabela()
{
    for(int i = 0; i < LEN; i++)
        tabelaHash[i].key = -99;
}

int hash_code(int chave)
{
    return chave % LEN;
}


void inserir(hash *nodo)
{

    int indice = hash_code((*nodo).key);
    while(tabelaHash[indice].key != -1)
        indice = hash_code(indice + 1);
    tabelaHash[indice] = (*nodo);
}

hash* buscar_elemento(int chave)
{
    int indice = hash_code(chave);
    while(tabelaHash[indice].key != -1){
        if(tabelaHash[indice].key == chave)
            return &tabelaHash[indice];
        else
            indice = hash_code(indice + 1);
    }
    return NULL;
}

void imprimir_tabela()
{
    printf("\nTABELA HASH\n");
    for(int i = 0; i < LEN; i++){
        if(tabelaHash[i].key != -1)
            printf("%2d = %3d \t", i, tabelaHash[i].key, tabelaHash[i].key);
        else
            printf("%2d =\n", i);
    }
}

int main() 
{
    int op, chave;
    hash *p;
    cria_tabela();
    imprimir_tabela();
    return 0;
}