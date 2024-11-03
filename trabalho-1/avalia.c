#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avalia.h"

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

static int eh_operador(const char *item)
{
    if (item == NULL || strlen(item) > 1)
        return 0;

    switch (item[0]) {
    case ADD:
    case SUB:
    case MUL:
    case DIV:
        return 1;
    }

    return 0;
}

static int eh_operando(const char *item)
{
    if (item == NULL)
        return 0;

    char *fim;
    strtod(item, &fim);

    return (*fim == '\0');
}

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
    }

    return 0;
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

    if (item == NULL)
        return NAN;

    if (eh_operador(item)) {
        char opr = item[0];
        free(item);

        double op1 = avalia();
        double op2 = avalia();

        return calcula(opr, op1, op2);
    }

    if (eh_operando(item)) {
        double valor = strtod(item, NULL);
        free(item);

        return valor;
    }

    free(item);

    return NAN;
}
