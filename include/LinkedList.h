#include "Node.h"
typedef struct LinkedList{
    NODE* head;
    NODE* tail;
}LINKED_LIST;

void add(LINKED_LIST&, int);
void remove(LINKED_LIST&, int);

void add_to_empty(LINKED_LIST&, NODE*);
void add_to_head(LINKED_LIST&, NODE*);
void add_to_tail(LINKED_LIST&, NODE*);
void add_between(LINKED_LIST&, NODE*, NODE*);


void remove_to_empty(LINKED_LIST&);
void remove_from_tail(LINKED_LIST&);
void remove_from_head(LINKED_LIST&);
void remove_between(LINKED_LIST&, NODE*);

void clear(LINKED_LIST&);

NODE* find(LINKED_LIST&, int);
NODE* find_prev(LINKED_LIST&, int);
void traverse(LINKED_LIST&);
