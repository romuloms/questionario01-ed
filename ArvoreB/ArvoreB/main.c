//
//  main.c
//  ArvoreB
//
//  Created by Rômulo Santana on 14/09/23.
//

#include <stdio.h>
#include "ArvoreB.h"

int main(int argc, const char * argv[]) {
    struct BTree* btree = createBTree(3); // Crie uma árvore B com um grau mínimo de 3 (ajuste de acordo com suas necessidades)

    // Insira chaves na árvore B
    insert(btree, 10);
    insert(btree, 20);
    insert(btree, 5);
    insert(btree, 6);
    insert(btree, 12);
    insert(btree, 30);
    insert(btree, 7);
    insert(btree, 17);

    printf("Traversal of the constructed tree is: ");
    traverse(btree->root);
    printf("\n");

    int keyToSearch = 6;
    struct BTreeNode* result = search(btree->root, keyToSearch);

    if (result != NULL) {
        printf("Chave %d encontrada na árvore B!\n", keyToSearch);
    } else {
        printf("Chave %d não encontrada na árvore B.\n", keyToSearch);
    }

    keyToSearch = 15;
    result = search(btree->root, keyToSearch);

    if (result != NULL) {
        printf("Chave %d encontrada na árvore B!\n", keyToSearch);
    } else {
        printf("Chave %d não encontrada na árvore B.\n", keyToSearch);
    }

    // Libere a memória alocada pela árvore B (você pode implementar essa função em btree.c)
    // Implemente uma função de liberação de memória para evitar vazamentos de memória.

    return 0;
}
