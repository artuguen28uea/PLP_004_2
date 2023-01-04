#include <stdio.h>
#include <stdlib.h>
#include "../arvbinaria.h"

int get_pos(char *str, int codigo)
{
    int aux = codigo;
    if (str[codigo + 1] != '(' && str[codigo + 1] != ')')
    {
        aux = get_pos(str, codigo + 1);
    }
    return aux;
}

int get_num(char *str, int inicio, int fim)
{
    int num = 0, aux = 1;
    if (inicio != fim)
    {
        for (int i = fim; i >= inicio; i--)
        {
            aux = 1;
            for (int j = 0; j <= (fim - i - 1); j++)
            {
                aux = aux * 10;
            }
            num += (str[i] - 48) * aux;
        }
    }
    else
    {
        num = str[inicio] - 48;
    }

    return num;
}

int construir_arvore(char *str, PONT expressao, int codigo)
{

    if (str[codigo] == '(')
    {
        PONT novaArv = criar_novo_no('f');

        if (verifica_galho(expressao) == 0)
        {
            expressao = inserir_no_filho(expressao, novaArv, true);
        }
        else
        {
            expressao = inserir_no_filho(expressao, novaArv, false);
        }
        codigo = construir_arvore(str, novaArv, codigo + 1);
    }
    else if (str[codigo] == ')')
    {
        return codigo;
    }
    else if (str[codigo] >= '0' && str[codigo] <= '9')
    {
        int final = get_pos(str, codigo);
        int num = get_num(str, codigo, final);

        codigo = final;
        inserir_chave(expressao, num);
    }
    else
    {
        inserir_chave(expressao, str[codigo]);
    }

    if (codigo < strlen(str))
    {
        construir_arvore(str, expressao, codigo + 1);
    }
}

int calculo_arvore(PONT expressao)
{
    int resultExp = retorna_item(expressao);
    int resultado = 0;

    if (resultExp == '+' || resultExp == '-' || resultExp == '*' || resultExp == '/')
    {
        PONT arvEsquerda = retorna_arv(expressao, false);
        PONT arvDireita = retorna_arv(expressao, true);

        int esq = retorna_item(arvEsquerda);
        int dir = retorna_item(arvDireita);

        if (esq == '+' || esq == '-' || esq == '*' || esq == '/')
        {
            if (qtd_folhas(arvEsquerda) > 1)
            {
                esq = calculo_arvore(arvEsquerda);
            }
        }
        if (dir == '+' || dir == '-' || dir == '*' || dir == '/')
        {
            if (qtd_folhas(arvDireita) > 1)
            {
                dir = calculo_arvore(arvDireita);
            }
        }

        // Operadores matemáticos
        if (resultExp == '+')
        {
            resultado = resultado + (esq + dir);
        }
        else if (resultExp == '-')
        {
            resultado = resultado + (esq - dir);
        }
        else if (resultExp == '*')
        {
            resultado = resultado + (esq * dir);
        }
        else
        {
            resultado = resultado + (esq / dir);
        }

        return resultado;
    }

    return resultExp;
}

char* ler_expressao(FILE *fp)
{
    char linha[50];
    char *entrada;

    fscanf(fp, "%s", linha);
    entrada = strdup(linha);

    return entrada;
}

int main()
{
    FILE *fp;

    fp = fopen("input.txt", "r");

    if (fp != NULL)
    {
        while (!feof(fp))
        {
            char *entrada = ler_expressao(fp);
            PONT expressao = criar_novo_no('p'); 

            construir_arvore(entrada, expressao, 1);

            imprimir_arvore(expressao);
            printf("\n");

            int resultado = calculo_arvore(expressao);
            printf("Resultado: %d\n", resultado);

            free(entrada);
            limpa_arvore(expressao);
        }
    }
    else
    {
        printf("Arquivo não existe!\n");
    }
    fclose(fp);
    return 0;
}
