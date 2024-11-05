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
#define LOG "log"

/*
 * Verifica se o item é um operador.
 *
 * Um item é um operador quando é uma string que representa alguma das
 * operações aritméticas definidas (+, -, *, /, ^, %, log).
 *
 * Retorno: 1 se é um operador ou 0 se não é um operador. Em caso de erro
 * retorna 0.
 */
static int eh_operador(const char *item)
{
    if (item == NULL)
        return 0;

    if (strlen(item) == 1) {
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

    if (strcmp(item, LOG) == 0)
        return 1;

    return 0;
}

/*
 * Verifica se o item é um operando.
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
 * Para a operação log, op1 é o logaritmando e op2 é a base.
 *
 * Retorno: o resultado da operação ou NAN em caso de erro.
 *
 * Exemplos:
 * calcula("-", 5, 3) retorna 2.
 * calcula("log", 8, 2) retorna 3.
 * calcula("/", 0, 0) retorna NAN.
 */
static double calcula(const char *opr, double op1, double op2)
{
    if (strlen(opr) == 1) {
        switch (opr[0]) {
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

    if (strcmp(opr, LOG) == 0)
        return log(op1) / log(op2);

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

    if (eh_operando(item)) {
        double val = strtod(item, NULL);

        free(item);
        return val;
    }

    if (eh_operador(item)) {
        double op1 = avalia();
        double op2 = avalia();
        double val = calcula(item, op1, op2);

        free(item);
        return val;
    }

    free(item);
    return NAN;
}
