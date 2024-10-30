#include "Node.h"
typedef struct Stack{
    NODEPTR top;
} STACK;

void init_stack(STACK*);
void push(STACK*, int);
int pop(STACK*);
int peek(STACK*);
void clear(STACK*);
bool is_empty(STACK*);

void print_stack(STACK*);