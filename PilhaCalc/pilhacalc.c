#include "auxfuncpilha.h"

No* empilhar(No *pilha, float num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->prox = pilha;
        return novo;
    }
    return NULL;
}

No *desempilhar(No **topo)
{

    No *aux = *topo;
    if (aux == NULL)
    {
        printf("PILHA VAZIA!");
        return NULL;
    }
    else
    {
        aux = *topo;
        *topo = (*topo)->prox;
        return aux;
    }
}

float operacao(float a, float b, char x){
    switch(x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
    }
}

float calcula_expressao(char exp[]){
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(exp, " ");
    while(pt){
        if (pt[0] == '/' || pt[0] == '*' || pt[0] == '+' || pt[0] == '-' )
        {
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = operacao(n2->valor, n1->valor, pt[0]);
            pilha = empilhar(pilha, num);
            free(n1);
            free(n2);
        }
        else if(pt[0] == ' '){
            desempilhar(&pilha);
        }
        else{
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = desempilhar(&pilha);
    num = n1->valor;
    free(n1);
    return num;

}

int main(){
    char expressao[50];
    printf("Digite a expressao numerica: %s\n", expressao);
    scanf("%[^\n]s", expressao);
        
    infix_postfix(expressao);
    //printf("%s\n", expressao);
    printf("\nResultado: %f", calcula_expressao(expressao));
}