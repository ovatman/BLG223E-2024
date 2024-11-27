#include <iostream>
#include <queue>
#include "Tree.h"

void init_tree(TREE& t){
    t.root = NULL;
}


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
    else std::cout << val << " Not found" << std::endl;
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


NODE** search_parents_ref(TREE& t, int val){
    NODE** ret=NULL;

    NODE* cur = t.root;

    while(cur){
        if(val < cur->data){
            ret = &cur->left;
            cur = cur->left;
        }
        else if (val > cur->data){
            ret = &cur->right;
            cur = cur->right;
        }
        else return ret;
    }
    
    return NULL;

}

void add_element(TREE& t, int val){
    if(!t.root){ 
        t.root = init_node(val);
        return;
    }
    
    NODE* cur = t.root;
    NODE** child = NULL;
    while(cur){
        if(cur->data > val){
            child = &cur->left;
            cur = cur->left;
        }
        else if (cur->data < val){
            child = &cur->right;
            cur = cur->right;
        }
        else return;
    }

    *child = init_node(val);

}

NODE* find_greatest_node(NODE* cur){
    while(cur->right)
        cur = cur->right;
    
    return cur;
}

void remove_element(TREE& t, int val){
    NODE** parent_ref = search_parents_ref(t, val);
    NODE* left_child = (*parent_ref)->left;
    NODE* right_child = (*parent_ref)->right;
    free(*parent_ref);
    *parent_ref = left_child;
    NODE* greatest_node = find_greatest_node(left_child);
    greatest_node->right = right_child;

}
