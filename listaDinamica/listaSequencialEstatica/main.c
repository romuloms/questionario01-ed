//
//  main.c
//  listaSequencialEstatica
//
//  Created by Rômulo Santana on 09/07/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ListaSequencialEstatica.h"

// Imprime na tela o status da lista
//void imprimirStatus(LISTA *l)
//{
//    printf("Tamanho = %d\n", tamanho(l));
//    exibirLista(l);
//    printf("\n");
//}
//
//// Imprime os elementos da lista na ordem inversa
//void imprimirListaInversa(LISTA *l)
//{
//    printf("Lista inversa: ");
//    exibirListaReversa(l);
//    printf("\n");
//}
//
//// Remove o elemento pela posicao dada
//void testarRemoverNaPos(LISTA *l)
//{
//    printf("=> Teste de Remover na Posicao\n");
//    int posicao;
//    printf("Digite a posicao do valor que quer remover: ");
//    scanf("%d", &posicao);
//    int item = enesimo(posicao, l);
//
//    if ((posicao >= tamanho(l)) || (posicao < 0))
//        printf("Posicao invalida.\n");
//    else
//    {
//        if (removerDaPos(posicao, l))
//        {
//            printf("Item removido: %d\n", item);
//            imprimirStatus(l);
//        }
//        else
//            printf("Erro na remocao\n");
//    }
//}
//
//// Testa a insercao de valores na lista
//void testarInserir(LISTA *l)
//{
//    printf("=> Teste de Inserir\n");
//    int qtd;
//    printf("Quantos itens deseja guardar na lista? ");
//    scanf("%d", &qtd);
//
//    ITEM item;
//    for (int i = 0; i < qtd; i++)
//    {
//        printf("Digite o valor para a posicao [%d]: ", i);
//        scanf("%d", &item);
//        inserir(item, l);
//    }
//
//    imprimirStatus(l);
//}
//
//// Testa a insercao de valores na lista escolhendo a posicao
//void testarInserirNaPos(LISTA *l)
//{
//    printf("=> Teste de Inserir na posicao\n");
//    int qtd;
//    printf("Quantos itens deseja inserir na lista? ");
//    scanf("%d", &qtd);
//
//    ITEM item;
//    for (int i = 0; i < qtd; i++)
//    {
//        printf("Digite a posicao de insercao (de 0 a %d): ", tamanho(l));
//        int p;
//        scanf("%d", &p);
//
//        printf("Digite o valor para a posicao [%d]: ", p);
//        scanf("%d", &item);
//        if (inserirNaPos(item, p, l))
//            printf("Insercao com sucesso\n");
//        else
//            printf("Erro na insercao\n");
//
//        imprimirStatus(l);
//    }
//
//}
//// Testa a busca de valores na lista
//void testarBuscar(LISTA *l)
//{
//   // Testa a busca por um valor existente
//    printf("=> Teste de Busca\n");
//    printf("Digite o valor que deseja buscar: ");
//    ITEM item;
//    scanf("%d", &item);
//    int pos = buscar(item, l);
//    if (pos >= 0)
//        printf("Achou na posicao: %d\n", pos);
//    else
//        printf("Nao achou o item na lista\n");
//
//    // Testa a busca por uma posicao existente
//    printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
//    int p;
//    scanf("%d", &p);
//    while (p != -1)
//    {
//        ITEM item = enesimo(p, l);
//        printf("Achou na posicao[%d] o valor: %d\n", p, item);
//        // Leitura da proxima posicao a ser acessada
//        printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
//        scanf("%d", &p);
//    }
//
//}
//
//void testarBuscarEm(LISTA *l)
//{
//    printf("=> Teste de Busca em um intervalo\n");
//    ITEM item;
//    int inicio, fim, pos;
//    printf("Digite o valor que deseja buscar: ");
//    scanf("%d", &item);
//    printf("Digite o valor inicial do intervalo: ");
//    scanf("%d", &inicio);
//    printf("Digite o valor final do intervalo: ");
//    scanf("%d", &fim);
//    pos = buscarEm(item, inicio, fim, l);
//
//    if (pos != -1)
//        printf("Valor encontrado na posicao: %d\n", pos);
//    else
//        printf("Valor nao encontrado no intervalo passado.\n");
//}
//
//// Testa a alteracao de um valor numa posicao
//void testarAlterar(LISTA *l)
//{
//    printf("=> Teste da Alteracao\n");
//    int p;
//    printf("Digite a posicao que deseja alterar (ou -1 para sair): ");
//    scanf("%d", &p);
//    while (p != -1)
//    {
//        // Leitura do novo valor
//        printf("Digite o NOVO valor para a posicao [%d]: ", p);
//        ITEM item;
//        scanf("%d", &item);
//        if (alterar(item, p, l))
//           printf("Alterou com sucesso\n");
//        else
//           printf("Erro na alteracao\n");
//
//        imprimirStatus(l);
//
//        // Leitura da proxima posicao a ser acessada
//        printf("Digite a posicao que deseja alterar (ou -1 para sair): ");
//        scanf("%d", &p);
//    }
//}

/////////////////////////////////////////////////////

int main(){
    
        
    getchar();
    return 0;
}
