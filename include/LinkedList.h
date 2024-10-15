#include "Node.h"
typedef struct LinkedList{
    NODE* head;
    NODE* tail;
}LINKED_LIST;

void add_to_empty(LinkedList& l, int);
void add_to_tail(LinkedList& l, int);
void traverse(LinkedList& l);
