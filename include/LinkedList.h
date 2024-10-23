#include "Node.h"
typedef struct LinkedList{
    NODE* head;
}LINKED_LIST;

void init_linked_list(LINKED_LIST&);
void add(LINKED_LIST&, int);
void remove(LINKED_LIST&, int);

void clear(LINKED_LIST&);

NODE* find(LINKED_LIST&, int);
NODE* find_prev(LINKED_LIST&, int);
void traverse(LINKED_LIST&);
