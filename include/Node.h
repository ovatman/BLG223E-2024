typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}NODE;

NODE* init_node(int);