#include <stdlib.h>
#include "Node.h"

NODE* init_node(char val){
    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}