#include "Node.h"

typedef struct Tree{
    NODE* root;
}TREE;

void populate_tree(TREE*);

void preorder_traverse_tree(TREE&);
void inorder_traverse_tree(TREE&);
void postorder_traverse_tree(TREE&);
void destruct_tree(TREE&);

void search_bin_tree(TREE&, int);

void preorder_traverse(NODE*);
void inorder_traverse(NODE*);
void postorder_traverse(NODE*);
void po_destruct(NODE*);
void breadth_first_traverse(TREE&);
void destruct(NODE*);

NODE* search(NODE*, int);
