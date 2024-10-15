typedef struct Node{
    int data;
    struct Node* next;
} NODE;

void init_node(NODE& n, int the_data, NODE* the_next);
NODE* init_empty_node_ptr(int);
void init_empty_node(NODE** n_ptr, int the_data);