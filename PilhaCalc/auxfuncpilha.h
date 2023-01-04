#ifndef AUX_FUNC_PILHA
#define AUX_FUNC_PILHA

#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
	int topo;
	unsigned len;
	int* array;
}Pilha;

typedef struct no
{
	float valor;
	struct no *prox;
} No;

Pilha *cria_pilha(unsigned capacity);
int is_empty(struct Pilha*stack);
int is_number(char ch);
int precedencia_operador(char ch);
int infix_postfix(char* exp);
char pop(struct Pilha*stack);
char peek(struct Pilha*stack);
void push(struct Pilha*stack, char op);

#endif