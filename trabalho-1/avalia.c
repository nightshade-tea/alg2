#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avalia.h"

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

// Sugestão: informe-se sobre as funções em ctype.h como
//           isdigit(), isalpha() etc, bem como sobre as funções em
//           stdlib.h como strtod() etc.

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
    char *opr = proximo_item();

    if (opr == NULL)
        return NAN;

    return 0;
}
