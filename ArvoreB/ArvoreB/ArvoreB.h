//
//  ArvoreB.h
//  ArvoreB
//
//  Created by Rômulo Santana on 14/09/23.
//

#ifndef ArvoreB_h
#define ArvoreB_h

#include <stdio.h>

// A BTree node
struct BTreeNode {
    int* keys; // An array of keys
    int t; // Minimum degree (defines the range for number
            // of keys)
    struct BTreeNode** C; // An array of child pointers
    int n; // Current number of keys
    int leaf; // Is true when node is leaf. Otherwise false
};

// A BTree
struct BTree {
    struct BTreeNode* root; // Pointer to root node
    int t; // Minimum degree
};

// Function to create a new BTree node
struct BTreeNode* createNode(int t, int leaf);

// Function to traverse all nodes in a subtree rooted
// with this node
void traverse(struct BTreeNode* root);

// Function to search a key in the subtree rooted with
// this node.
struct BTreeNode* search(struct BTreeNode* root, int k);

// Function to insert a new key into the BTree
void insert(struct BTree* t, int k);

// Constructor for BTree class
struct BTree* createBTree(int t);


#endif /* ArvoreB_h */
