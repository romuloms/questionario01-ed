//
//  ListaSequencialEstatica.c
//  listaSequencialEstatica
//
//  Created by Rômulo Santana on 09/07/23.
//

#include "ListaSequencialEstatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


LISTA* criarLista(int capacidade)
{
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    if (lista == NULL)
    {
        printf("Erro: memoria insuficiente para criar a lista.\n");
        
        return NULL;
    }
    lista->itens = (ITEM**)malloc(capacidade*sizeof(ITEM*));    // aqui eh o vetor de apontadores
    if (lista->itens == NULL)
    {
        printf("Erro: memoria insuficiente para criar lista.\n");
        free(lista);
        return NULL;
    }
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    
    return lista;
}


bool inserirItem(LISTA* lista, int valor)
{
    if (lista == NULL)
    {
        printf("Erro: lista nao existe.\n");
        return false;
    }
    
    if (lista->tamanho >= lista->capacidade)
    {
        printf("Erro: lista esta cheia.\n");
        return false;
    }
    
    ITEM* novoItem = (ITEM*)malloc(sizeof(ITEM));   // aqui eh o apontador que vai apontar pra novoItem
    if (novoItem == NULL)
    {
        printf("Erro: memoria insuficiente para inserir o item na lista");
        return false;
    }
    
    novoItem->valor = valor;
    lista->itens[lista->tamanho] = novoItem;
    lista->tamanho++;
    
    return true;
}


bool removerNaPos(LISTA* lista, int indice)
{
    if (lista == NULL)
    {
        printf("Erro: lista nao existe.\n");
        return false;
    }
    if (indice < 0 || indice >= lista->tamanho)
    {
        printf("Erro: indice inexistente.\n");
        return false;
    }
    
    free(lista->itens[indice]);
    
    for (int i = indice; i < lista->tamanho - 1; i++)
        lista->itens[i] = lista->itens[i+1];
    
    return true;
}


void destruirLista(LISTA *lista)
{
    if (lista == NULL)
    {
        printf("Erro: lista nao existe.\n");
        return;
    }
    
    for (int i = 0; i < lista->tamanho; i++)
        free(lista->itens[i]);

    free(lista->itens);
    free(lista);
}
//char compare(ITEM x, ITEM y)
//{
//    return x > y ? 1 : (x < y ? -1 : 0);
//}
//
//
//bool igual(ITEM x, ITEM y)
//{
//    return compare(x,y) == 0;
//}
//
//
//void inicializar(LISTA *l)
//{
//    // a funcao recebe um ponteiro como argumento
//    l->tamanho = 0;
//    // o ponteiro acessa o endereco de memoria da variavel tamanho e altera para 0
//}
//
//
//int tamanho(LISTA *l)
//{
//    // a funcao recebe um ponteiro como argumento
//    return l->tamanho;
//    // o ponteiro acessa o endereco de memoria da variavel tamanho e
//    // a funcao retorna o valor contido nesse endereco
//}
//
//
//bool cheia(LISTA *l)
//{
//    // a funcao recebe um ponteiro como argumento
//    // depois, invoca a funcao tamanho() com o mesmo ponteiro de argumento
//    // a funcao tamanho retorna um inteiro com o valor do tamanho do vetor de itens
//    // a funcao cheia verifica se esse tamanho eh igual aa constante MAX(1000)
//    return tamanho(l) == MAX;
//}
//
//
//bool vazia(LISTA *l)
//{
//    // faz o mesmo que a funcao cheia(), mas verificando se o tamanho eh 0
//    return tamanho(l) == 0;
//}
//
//
//bool inserir(ITEM item, LISTA *l)
//{
//    if (tamanho(l) == MAX)
//        return false; // lista cheia
//    else
//       l->itens[l->tamanho++] = item;
//    // caso a lista nao esteja cheia, o ponteiro acessa o end de memoria
//    // do vetor itens, adiciona 1 unidade ao indice do vetor e aloca o item
//    // que foi passado como argumento nesse indice do vetor
//    return true;
//}
//
//
//int buscar(ITEM item, LISTA *l)
//{
//    // confere indice por indice se eh igual ao item passado como argumento na funcao
////    for (int pos = 0; pos < tamanho(l); pos++)
////       if (igual(item, l->itens[pos]))
////           return pos; // achou
////    return -1; // nao achou
//    int inicio = 0;
//    int fim = l->tamanho;
//    return buscarEm(item, inicio, fim, l);
//}
//
//
//int buscarEm(ITEM item, int inicio, int fim, LISTA *l)
//{
//    for (int posicao = inicio; posicao < fim; posicao ++)
//        if (igual(item, l->itens[posicao]))
//            return posicao;
//    return -1;
//}
//
//
//ITEM enesimo(int n, LISTA *l)
//{
//    // retorna o n-esimo item da lista
//    if (n >= 0 && n < tamanho(l))
//       return (l->itens[n]);
//    else
//       exit(EXIT_FAILURE);
//}
//
//
//bool alterar(ITEM item, int pos, LISTA *l)
//{
//    if (pos >= 0 && pos < tamanho(l))
//    {
//        // verifica se a posicao existe na lista
//        // se existir, altera o item desejado
//        l->itens[pos] = item;
//        return true;
//    }
//    return false;
//}
//
//
//bool inserirNaPos(ITEM item, int posicao, LISTA *l)
//{
//    // a posicao tem que estar entre 0 e MAX-1 e ate o tamanho atual
//    if ((tamanho(l) >= MAX) || (posicao < 0) || (posicao > tamanho(l)))
//        return false; // lista cheia ou indice invalido
//
//    // se for inserido no meio, e necessario abrir espaco para o item
//    // os ultimos elementos vao sendo realocados para uma posicao a frente
//    // abrindo um espaco vazio para o numero desejado na posicao desejada
//    for (int j = tamanho(l); j > posicao; j--)
//        l->itens[j] = l->itens[j-1];
//
//    // coloca o item em um espaco vago e ajusta o tamanho
//    l->itens[posicao] = item;
//    l->tamanho++;
//    return true;
//}
//
//
//bool remover(ITEM item, LISTA *l)
//{
//    int i, j;
//    for (i = 0; i < tamanho(l); i++)
//        if (igual(item, l->itens[i]))
//        {
//            // o trecho seguinte faz o inverso do for na funcao inserirNaPos()
//            // o valor desejado vai ser substituido pelo valor seguinte e
//            // o tamanho da lista diminui em uma unidade
//            for (j = i; j < l-> tamanho - 1; j++)
//               l->itens[j] = l->itens[j + 1];
//
//            l->tamanho--;
//            return true; // achou
//        }
//    return false; // nao achou
//}
//
//
//bool removerDaPos(int posicao, LISTA *l)
//{
//    if ((tamanho(l) >= MAX) || (posicao > tamanho(l)) || (posicao < 0))
//        return false;
//    for (int i = posicao; i < tamanho(l); i++)
//        l->itens[i] = l->itens[i+1];
//    l->tamanho--;
//    return true;
//}
//
//
//void exibirItem(ITEM i)
//{
//    printf("%d", i);
//}
//
//
//void exibirLista(LISTA *l)
//{
//    printf("[");
//    for(int i = 0; i < tamanho(l);)
//    {
//        exibirItem(l->itens[i++]);
//        if (i < tamanho(l))
//           printf(",");
//    }
//    printf("]");
//}
//
//void exibirListaReversa(LISTA *l)
//{
//    printf("[");
//    for(int i = tamanho(l) - 1; i >= 0;)
//    {
//        exibirItem(l->itens[i--]);
//        if (i >= 0)
//            printf(",");
//    }
//    printf("]");
//}
//
//void limpar(LISTA *l)
//{
//    l->tamanho = 0;
//}
//
//void destruir(LISTA *l)
//{
//   limpar(l);
//}
