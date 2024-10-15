#include <stdlib.h>
#include "Node.h"

void init_node(NODE& n, int the_data, NODE* the_next){
    n.data = the_data;
    n.next = the_next;
}


NODE* init_empty_node_ptr(int the_data){
    NODE* n_ptr = (NODE*) malloc(sizeof(NODE));
    n_ptr->data = the_data;
    return n_ptr;
}

void init_empty_node(NODE** n_ptr, int the_data){
    (*n_ptr) = (NODE*) malloc(sizeof(NODE));
    (*n_ptr)->data = 5;
}