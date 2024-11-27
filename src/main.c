#include<iostream>
#include "Tree.h"

using namespace std;

int main(){
    TREE t; 
    init_tree(t);

    add_element(t, 10);
    add_element(t, 5);
    add_element(t, 15);
    add_element(t, 3);
    add_element(t, 12);
    add_element(t, 9);
    add_element(t, 1);
    add_element(t, 4);

    remove_element(t, 5);

    preorder_traverse_tree(t);
    inorder_traverse_tree(t);
    postorder_traverse_tree(t);
    breadth_first_traverse(t);

    search_bin_tree(t, 65);

    destruct_tree(t);
    return 0;
}