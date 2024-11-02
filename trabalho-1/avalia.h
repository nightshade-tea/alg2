#ifndef _AVALIA_
#define _AVALIA_

//------------------------------------------------------------------------------
// tamanho máximo de um item da entrada
#define TAMANHO_MAXIMO_ITEM 1024

//------------------------------------------------------------------------------
// Tenta ler o próximo item de stdin(3) 
//
// Devolve o item lido em memória dinamicamente alocada, ou NULL caso
// não haja mais nada a ser lido
//
// Um item é uma 'string' ininterrupta de "não brancos" (conforme o
// entendimento de isspace(3) do que são "brancos" e "não brancos") 
//
// O usuário deve liberar a memória alocada por proximo_item() quando
// não for mais necessária

char *proximo_item(void);

//------------------------------------------------------------------------------
// Lê a próxima expressão em notação pré-fixa de stdin(3) e devolve seu valor.
// 
// Caso não haja mais nada a ser lido, devolve NAN(3)
//
// A função supõe que a expressão está corretamente escrita: nenhuma
// checagem de consistência é feita. Caso a expressão não esteja
// corretamente escrita, o valor devolvido e o comportamento da função
// são indefinidos

double avalia(void);

#endif
