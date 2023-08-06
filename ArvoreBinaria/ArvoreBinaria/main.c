//
//  main.c
//  ArvoreBinaria
//
//  Created by Rômulo Santana on 06/08/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ArvoreBinaria.h"

/////////////////////////////////////////////////////
// Visita um NO da arvore, imprimindo o valor da chave
// entre parenteses
void visite(ARVORE_BINARIA *arvore) {
    printf("%s", &arvore->item);
}

/////////////////////////////////////////////////////

int main()
{
    ARVORE_BINARIA *arv = NULL;
    inicializar(arv);

    ITEM item;
    item = '+';
    criarNo(item, &arv); // cria o no Raiz

    item = '2';
    adicionarFilho(item, NoEsquerdo, arv);
    item = '+';
    adicionarFilho(item, NoDireito, arv);

    item = '*';
    adicionarFilho(item, NoEsquerdo, arv->dir);
    item = '7';
    adicionarFilho(item, NoDireito, arv->dir);

    item = '3';
    adicionarFilho(item, NoEsquerdo, arv->dir->esq);
    item = '5';
    adicionarFilho(item, NoDireito, arv->dir->esq);
  
    inOrdem(arv, visite);
    
    /*
            +
          /   \
         2     +
             /   \
            *     7
           / \
          3   5
     */

    disposeArvore(arv);
    
    return 0;
}
