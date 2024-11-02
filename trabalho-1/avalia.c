#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avalia.h"

//------------------------------------------------------------------------------
char *proximo_item(void) {

  static char buffer[TAMANHO_MAXIMO_ITEM+1];

  if ( scanf("%s", buffer) == EOF )

    return NULL;
  
  return strcpy(malloc(sizeof(char)*(strlen(buffer)+1)), buffer);
}
//------------------------------------------------------------------------------
// Sugestão: informe-se sobre as funções em ctype.h como
//           isdigit(), isalpha() etc, bem como sobre as funções em
//           stdlib.h como strtod() etc.

double avalia(void) {

  char *item = proximo_item();

  free(item);

  return item == NULL ? NAN : 0;
}

