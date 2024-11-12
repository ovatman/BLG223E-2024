typedef struct Node{
    char data;
    struct Node* left;
    struct Node* right;
}NODE;

NODE* init_node(char);