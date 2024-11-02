#include <stdio.h>
#include <math.h>
#include "avalia.h"

//------------------------------------------------------------------------------
// implementa uma calculadora de expressões aritméticas em notação pré-fixa
// 
// cada expressão lida de stdin(3) é avaliada e seu valor é escrito em stdout(3)
//
// a execução termina ao receber NAN(3) de avalia()

int main(void) {

  double valor;

  while ( ! isnan(valor=avalia()) ) {

    printf("%f\n", valor);

    fflush(stdout);
  }

  return 0;
}
