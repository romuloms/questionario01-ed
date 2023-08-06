//
//  main.c
//  ListaEncadeada
//
//  Created by Rômulo Santana on 05/08/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ListaEncadeada.h"

// Imprime na tela o status da lista
void imprimirStatus(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}

// Testa a insercao de valores na lista
void testarInserir(LISTA *l)
{
    printf("=> Teste de Inserir\n");
    int qtd;
    printf("Quantos itens deseja guardar na lista? ");
    scanf("%d", &qtd);

    ITEM item;
    for (int i = 1; i <= qtd; i++)
    {
        printf("Digite o valor %d/%d: ", i, qtd);
        scanf("%d", &item);
        inserir(item, l);
    }

    imprimirStatus(l);
}

void testarInsercaoOrdenada(LISTA *l)
{
    printf("=> Teste de Insercao Ordenada\n");
    int qtd;
    printf("Quantos itens deseja guardar na lista? ");
    scanf("%d", &qtd);

    ITEM item;
    for (int i = 1; i <= qtd; i++)
    {
        printf("Digite o valor %d/%d: ", i, qtd);
        scanf("%d", &item);
        insercaoOrdenada(item, l);
    }

    imprimirStatus(l);
}

// Testa a insercao de valores no final da lista
void testarInserirNoFinal(LISTA *l)
{
    printf("=> Teste de Inserir no final\n");
    int qtd;
    printf("Quantos itens deseja guardar no final da lista? ");
    scanf("%d", &qtd);

    ITEM item;
    for (int i = 1; i <= qtd; i++)
    {
        printf("Digite o valor %d/%d: ", i, qtd);
        scanf("%d", &item);
        inserirNoFinal(item, l);
    }

    imprimirStatus(l);
}

// Testa a insercao de valores na lista escolhendo a posicao
void testarInserirNaPos(LISTA *l)
{
    printf("=> Teste de InserirNaPos\n");
    int qtd;
    printf("Quantos itens deseja inserir na lista? ");
    scanf("%d", &qtd);

    ITEM item;
    for (int i = 0; i < qtd; i++)
    {
        printf("Digite a posicao de insercao (de 0 a %d): ", tamanho(l));
        int p;
        scanf("%d", &p);
  
        printf("Digite o valor para a posicao [%d]: ", p);
        scanf("%d", &item);
        if (inserirNaPos(item, p, l))
            printf("Insercao com sucesso\n");
        else
            printf("Erro na insercao\n");

        imprimirStatus(l);
    }

}
// Testa a busca de valores na lista
void testarBuscar(LISTA *l)
{
   // Testa a busca por um valor existente
    printf("=> Teste de Busca\n");
    printf("Digite o valor que deseja buscar: ");
    ITEM item;
    scanf("%d", &item);
    int pos = buscar(item, l);
    if (pos >= 0)
        printf("Achou na posicao: %d\n", pos);
    else
        printf("Nao achou o item na lista\n");

    // Testa a busca por uma posicao existente
    printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
    int p;
    scanf("%d", &p);
    while (p != -1)
    {
        ITEM item = enesimo(p, l);
        printf("Achou na posicao[%d] o valor: %d\n", p, item);
        // Leitura da proxima posicao a ser acessada
        printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
        scanf("%d", &p);
    }

}

// Testa a alteracao de um valor numa posicao
void testarAlterar(LISTA *l)
{
    printf("=> Teste da Alteracao\n");
    int p;
    printf("Digite a posicao que deseja alterar (ou -1 para sair): ");
    scanf("%d", &p);
    while (p != -1)
    {
        // Leitura do novo valor
        printf("Digite o NOVO valor para a posicao [%d]: ", p);
        ITEM item;
        scanf("%d", &item);
        if (alterar(item, p, l))
           printf("Alterou com sucesso\n");
        else
           printf("Erro na alteracao\n");

        imprimirStatus(l);

        // Leitura da proxima posicao a ser acessada
        printf("Digite a posicao que deseja alterar (ou -1 para sair): ");
        scanf("%d", &p);
    }
}


void testarRemover(LISTA *l)
{
    printf("=> Teste da Remocao\n");
    int i;
    printf("Digite o item que deseja remover (ou -1 para sair): ");
    scanf("%d", &i);
    while (i != -1)
    {
        if (remover(i, l))
           printf("Removeu com sucesso\n");
        else
           printf("Erro na remocao\n");

        imprimirStatus(l);

        // Leitura do proximo item a ser removido
        printf("Digite o item que deseja remover (ou -1 para sair): ");
        scanf("%d", &i);
    }
}


void testarRemoverNaPos(LISTA *l)
{
    printf("=> Teste da Remocao na posicao\n");
    int p;
    int item;
    printf("Digite a posicao que deseja remover (ou -1 para sair): ");
    scanf("%d", &p);
    
    if (removerNaPos(&item, p, l))
       printf("Removeu com sucesso o elemento %d\n", item);
    else
       printf("Erro na remocao\n");

    imprimirStatus(l);
}


void testarClonar(LISTA *l)
{
    printf("=> Teste da Clonagem\n");
    LISTA* listaClonada = clonar(l);
    
    imprimirStatus(listaClonada);
}

/////////////////////////////////////////////////////

int main(){
    LISTA l;
    
    inicializar(&l);
    testarInsercaoOrdenada(&l);
//    testarInserir(&l);
//    testarInserirNaPos(&l);
//    testarInserirNoFinal(&l);
//    testarBuscar(&l);
//    testarAlterar(&l);
//    testarRemover(&l);
//    testarRemoverNaPos(&l);
//    testarClonar(&l);
    destruir(&l);
    imprimirStatus(&l);
        
    getchar();
    return 0;
}
