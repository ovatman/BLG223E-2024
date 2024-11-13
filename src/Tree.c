#include <iostream>
#include <queue>
#include "Tree.h"

void preorder_traverse_tree(TREE& t){
    preorder_traverse(t.root);
    std::cout << std::endl;
}

void inorder_traverse_tree(TREE& t){
    inorder_traverse(t.root);
    std::cout << std::endl;
}

void postorder_traverse_tree(TREE& t){
    postorder_traverse(t.root);
    std::cout << std::endl;
}

void destruct_tree(TREE& t){
    destruct(t.root);
    std::cout << std::endl;
}

void search_bin_tree(TREE& t, int val){
    NODE* n = search(t.root, val);
    if(n) std::cout << n->data << std::endl;
    else std::cout << val << "Not found" << std::endl;
}

void preorder_traverse(NODE* n){
    if(n){
        std::cout << n->data << " ";
        preorder_traverse(n->left);
        preorder_traverse(n->right);
    }
}

void inorder_traverse(NODE* n){
    if(n){
        inorder_traverse(n->left);
        std::cout << n->data << " ";
        inorder_traverse(n->right);
    }
}

void postorder_traverse(NODE* n){
    if(n){
        postorder_traverse(n->left);
        postorder_traverse(n->right);
        std::cout << n->data << " ";
    }
}

void destruct(NODE* n){
    if(n){
        destruct(n->left);
        destruct(n->right);
        free(n);
    }
}

void breadth_first_traverse(TREE& t){
    std::queue<NODE*> q;
    NODE* temp;

    q.push(t.root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        std::cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    std::cout << std::endl;
}

NODE* search(NODE* n, int val){
    if(!n) return n;
    
    if(val > n->data)
        return search(n->right, val);
    else if(val < n->data)
        return search(n->left, val);
    else return n;
}

void populate_tree(TREE* t){
    NODE* root = init_node(30);
    root->left = init_node(15);
    root->right = init_node(34);

    root->left->left = init_node(7);
    root->left->right = init_node(25);
    root->right->left = init_node(32);
    root->right->right = init_node(72);

    root->left->left->right = init_node(10);
    root->right->right->left = init_node(65);

    t->root = root;
}