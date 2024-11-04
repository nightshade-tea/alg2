#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avalia.h"

/* Operações aritméticas */
#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define EXP '^'
#define MOD '%'

/*
 * Verifica se o item é um operador (+, -, *, /, ^, %).
 *
 * Um item é um operador quando é uma string com apenas um caractere, o qual
 * deve representar alguma das operações aritméticas definidas.
 *
 * Retorno: 1 se é um operador ou 0 se não é um operador. Em caso de erro
 * retorna 0.
 */
static int eh_operador(const char *item)
{
    if (item == NULL || strlen(item) != 1)
        return 0;

    switch (item[0]) {
    case ADD:
    case SUB:
    case MUL:
    case DIV:
    case EXP:
    case MOD:
        return 1;
    }

    return 0;
}

/*
 * Verifica se o item é um operando (número).
 *
 * Um item é um operando quando é uma string que representa um número válido,
 * podendo conter casas decimais.
 *
 * Considera-se que a string é um número válido se a função strtod() conseguir
 * convertê-la para um número, sem sobra de caracteres.
 *
 * Retorno: 1 se é um operando ou 0 se não é um operando. Em caso de erro
 * retorna 0.
 */
static int eh_operando(const char *item)
{
    if (item == NULL)
        return 0;

    char *fim;
    strtod(item, &fim);

    return (*fim == '\0');
}

/*
 * Efetua o cálculo da operação aritmética opr entre os operandos op1 e op2,
 * respectivamente.
 *
 * Retorno: o resultado da operação ou NAN em caso de erro.
 *
 * Exemplos:
 * calcula('+', 1, 1) retorna 2.
 * calcula('*', 2, 3) retorna 6.
 * calcula('/', 0, 0) retorna NAN.
 */
static double calcula(char opr, double op1, double op2)
{
    switch (opr) {
    case ADD:
        return op1 + op2;
    case SUB:
        return op1 - op2;
    case MUL:
        return op1 * op2;
    case DIV:
        return op1 / op2;
    case EXP:
        return pow(op1, op2);
    case MOD:
        return fmod(op1, op2);
    }

    return NAN;
}

char *proximo_item(void)
{
    static char buffer[TAMANHO_MAXIMO_ITEM + 1];

    if (scanf("%s", buffer) == EOF)
        return NULL;

    return strcpy(malloc(sizeof(char) * (strlen(buffer) + 1)), buffer);
}

double avalia(void)
{
    char *item = proximo_item();

    if (eh_operador(item)) {
        char opr = item[0];
        free(item);

        double op1 = avalia();
        double op2 = avalia();

        return calcula(opr, op1, op2);
    }

    if (eh_operando(item)) {
        double val = strtod(item, NULL);
        free(item);

        return val;
    }

    free(item);

    return NAN;
}
