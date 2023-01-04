#include "pilha.h"

nodo * cria_nodo(int valor)
{
	nodo *p;
	p = (nodo *) malloc (sizeof(nodo));
	p->valor = valor;
	p->prox = NULL;
	return p;
}

void empilha(nodo **topo, nodo *no)
{
	if(*topo == NULL){
		*topo = no;
	}else{
		no->prox = *topo;
		*topo = no;
	}
}

nodo * push(nodo **topo, nodo *no)
{
	if(*topo == NULL){
		*topo = no;
	}else{
		no->prox = *topo;
		*topo = no;
	}
	return *topo;
}

nodo * push_int(nodo **topo, int valor)
{
	nodo * no = cria_nodo(valor);
	if(*topo == NULL){
		*topo = no;
	}else{
		no->prox = *topo;
		*topo = no;
	}
	return *topo;
}

nodo * empilha_pont(nodo **topo, nodo *no)
{
	if(*topo == NULL){
		*topo = no;
	}else{
		no->prox = *topo;
		*topo = no;
	}
	return *topo;
}

int desempilha(nodo **topo)
{
	nodo *aux = *topo;
	int valor;
	if(aux == NULL){
		printf("PILHA VAZIA!");
		return -999;
	}else{
		valor = aux->valor;
		aux = *topo;
		*topo = (*topo)->prox;
		free(aux);
		return valor;
	}
}

nodo * pop(nodo **topo)
{
	nodo *aux = *topo;
	if(aux == NULL){
		printf("PILHA VAZIA!");
		return NULL;
	}else{		
		aux = *topo;
		*topo = (*topo)->prox;		
		return aux;
	}
}


void imprime_pilha(nodo **topo)
{	
	nodo *pilha_temp = NULL;
	int value;
	
	if (*topo == NULL)
		printf("PILHA VAZIA!");

	while(*topo != NULL){
		value = desempilha_nodo(topo);
		empilha_nodo(&pilha_temp,cria_nodo(value));
		printf("%d - ",value);		
	}
	while(pilha_temp != NULL){
		value = desempilha_nodo(&pilha_temp);
		empilha_nodo(topo,cria_nodo(value));		
	}
}