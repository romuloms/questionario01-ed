//
//  ArvoreB.c
//  ArvoreB
//
//  Created by Rômulo Santana on 14/09/23.
//

#include "ArvoreB.h"

#include <stdio.h>
#include <stdlib.h>

// Function to create a new BTree node
struct BTreeNode* createNode(int t, int leaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->t = t;
    newNode->leaf = leaf;
    newNode->keys = (int*)malloc(sizeof(int) * (2 * t - 1));
    newNode->C = (struct BTreeNode**)malloc(sizeof(struct BTreeNode*) * (2 * t));
    newNode->n = 0;
    return newNode;
}

// Function to traverse all nodes in a subtree rooted
// with this node
void traverse(struct BTreeNode* root) {
    int i;
    for (i = 0; i < root->n; i++) {
        if (root->leaf == 0)
            traverse(root->C[i]);
        printf(" %d", root->keys[i]);
    }

    if (root->leaf == 0)
        traverse(root->C[i]);
}

// Function to search key k in subtree rooted with this node
struct BTreeNode* search(struct BTreeNode* root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;

    if (root->keys[i] == k)
        return root;

    if (root->leaf == 1)
        return NULL;

    return search(root->C[i], k);
}

// Função para dividir o filho y deste nó
void splitChild(struct BTreeNode* x, int i, struct BTreeNode* y) {
    struct BTreeNode* z = createNode(y->t, y->leaf);
    x->C[x->n + 1] = NULL;
    for (int j = x->n; j >= i + 1; j--) {
        x->C[j + 1] = x->C[j];
        x->keys[j] = x->keys[j - 1];
    }
    x->C[i + 1] = z;
    x->keys[i] = y->keys[y->t - 1];
    x->n++;
    for (int j = 0; j < y->t - 1; j++) {
        z->keys[j] = y->keys[j + y->t];
    }
    if (!y->leaf) {
        for (int j = 0; j < y->t; j++) {
            z->C[j] = y->C[j + y->t];
        }
    }
    y->n = y->t - 1;
}

// Função para inserir uma nova chave em um nó não cheio
void insertNonFull(struct BTreeNode* x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && k < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && k < x->keys[i]) {
            i--;
        }
        i++;
        if (x->C[i]->n == 2 * x->t - 1) {
            splitChild(x, i, x->C[i]);
            if (k > x->keys[i]) {
                i++;
            }
        }
        insertNonFull(x->C[i], k);
    }
}

// Function to insert a new key into the BTree
void insert(struct BTree* t, int k) {
    struct BTreeNode* root = t->root;
    if (root == NULL) {
        t->root = createNode(t->t, 1);
        t->root->keys[0] = k;
        t->root->n = 1;
    } else {
        if (root->n == 2*(t->t) - 1) {
            struct BTreeNode* s = createNode(t->t, 0);
            s->C[0] = root;
            splitChild(s, 0, root);
            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            insertNonFull(s->C[i], k);
            t->root = s;
        } else {
            insertNonFull(root, k);
        }
    }
}

// Constructor for BTree class
struct BTree* createBTree(int t) {
    struct BTree* newBTree = (struct BTree*)malloc(sizeof(struct BTree));
    newBTree->root = NULL;
    newBTree->t = t;
    return newBTree;
}
