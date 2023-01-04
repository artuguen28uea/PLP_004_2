#include "arvbinaria.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void calculadora_arvore(int entradas[])
{
    PONT raiz;

    inicializar(&raiz);
    for (int i = 0; entradas[i] != '\0'; i++)
    {
        inserir_no(&raiz, entradas[i]);
    }

    printf("\n ");
    printf("Calculadora - Árvore Binária\n");
    arvore_em_ordem(raiz);
    printf("\n \tRemovendo o 7...\n");
    excluir_chave(&raiz, 7);
    arvore_em_ordem(raiz);
}

void calculadora_pilha(int entradas[])
{
    printf("\n ");
    printf("Calculadora - Pilha\n");
    nodo *topo = cria_nodo(entradas[0]);
    for (int i = 1; entradas[i] != '\0'; i++)
    {
        empilha(&topo, cria_nodo(entradas[i]));
    }
    imprime_pilha(&topo);
}


int main()
{
    // Leitura de arquivo
    int entradas[50];
    int i = 0;
    FILE *file;

    if ((file = fopen("entrada.txt", "r")))
    {
        while (fscanf(file, "%d", &entradas[i]) != EOF)
        {
            i++;
        }
        fclose(file);
        entradas[i] = '\0';
    } 
    else 
    {
        printf("Arquivo não carregado!\n");
        return 0;
    }

    calculadora_arvore(entradas);
    calculadora_pilha(entradas);
    
}