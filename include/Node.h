#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} NODE;

typedef struct Node* NODEPTR;

NODEPTR init_node(int);