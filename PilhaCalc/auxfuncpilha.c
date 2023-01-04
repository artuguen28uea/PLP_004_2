#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "auxfuncpilha.h"

// Cria e retorna a pilha
Pilha* cria_pilha(unsigned len)
{
	struct Pilha *pilha = (struct Pilha *)malloc(sizeof(struct Pilha));

	if (!pilha)
		return NULL;

	pilha->topo = -1;
	pilha->len = len;

	pilha->array = (int *)malloc(pilha->len * sizeof(int));

	return pilha;
}

int is_empty(struct Pilha* pilha)
{
	return pilha->topo == -1;
}

// Retorna o char referente ao topo
char peek(struct Pilha* pilha)
{
	return pilha->array[pilha->topo];
}

char pop(struct Pilha *pilha)
{
	if (!is_empty(pilha))
		return pilha->array[pilha->topo--];
	return '$';
}

void push(struct Pilha *pilha, char key)
{
	pilha->array[++pilha->topo] = key;
}

// Verifica se é um número
int is_number(char key)
{
	return key >= '0' && key <= '9';
}

// Função que retorna a precedencia de um determinado operador
int precedencia_operador(char key)
{
	switch (key)
	{
		case '-':
		case '+':
			return 1;

		case '*':
		case '/':
			return 2;

		case '^':
			return 3;
	}
	return -1;
}

// Converte a notação infixa para posfixa de modo a utilizá-la na calculadora de pilha
int infix_postfix(char* exp)
{
	int j;
	struct Pilha* pilha = cria_pilha(strlen(exp));
	if (!pilha)
		return -1;

	// Verificação o tipo de caracter na expressão
	for (int i = 0, j = -1; exp[i]; ++i) 
	{

		if (is_number(exp[i]) && !is_number(exp[i+1])){
			exp[++j] = exp[i];
			exp[++j] = ' ';
		}
        else if(is_number(exp[i]) && is_number(exp[i+1]))
		{
			exp[++j] = exp[i];
		}
		else if (exp[i] == '(')
		{
			push(pilha, exp[i]);
		}
		else if (exp[i] == ')') 
		{
			while (!is_empty(pilha) && peek(pilha) != '(')
				exp[++j] = pop(pilha);
			if (!is_empty(pilha) && peek(pilha) != '(')
				return -1; 
			else
				pop(pilha);
		}
		else if(exp[i] == ' ')
		{
			exp[i] = ' ';
		}
		else 
		{
			while (!is_empty(pilha) && precedent(exp[i]) <= precedent(peek(pilha)))
				exp[++j] = pop(pilha);
			push(pilha, exp[i]);
		}
	}

	while (!is_empty(pilha))
		exp[++j] = pop(pilha);

	exp[++j] = '\0';
}

