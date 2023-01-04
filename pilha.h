#ifndef PILHA
#define PILHA

#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
	int valor;
	struct NODO *prox;
}nodo;


nodo * cria_nodo(int valor);
void empilha(nodo **topo, nodo *no);
nodo * empilha_pont(nodo **topo, nodo *no);
nodo * push(nodo **topo, nodo *no);
nodo *push_int(nodo **topo, int valor);
int desempilha(nodo **topo);
nodo * pop(nodo **topo);
void imprime_pilha(nodo **topo);

#endif