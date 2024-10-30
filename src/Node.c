#include "Node.h"

NODEPTR init_node(int val){
    NODEPTR anode = (NODEPTR) malloc(sizeof(NODE));
    anode->data = val;
    return anode;
}