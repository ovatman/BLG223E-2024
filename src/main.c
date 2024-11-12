#include<iostream>
#include "Tree.h"

using namespace std;

int main(){
    TREE t; 
    populate_tree(&t);

    cout << t.root->left->right->left->data << endl;
    return 0;
}