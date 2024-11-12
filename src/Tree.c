#include "Tree.h"

void populate_tree(TREE* t){
    NODE* root = init_node('A');
    root->left = init_node('B');
    root->right = init_node('C');

    root->left->left = init_node('D');
    root->left->right = init_node('E');
    root->right->left = init_node('F');
    root->right->right = init_node('G');

    root->left->left->left = init_node('H');
    root->left->left->right = init_node('I');
    root->left->right->left = init_node('J');
    root->left->right->right = init_node('K');

    root->right->left->left = init_node('L');
    root->right->left->right = init_node('M');
    root->right->right->left = init_node('N');
    root->right->right->right = init_node('O');

    t->root = root;
}