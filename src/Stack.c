#include <iostream>
#include "Stack.h"

using namespace std;

void init_stack(STACK* astack){
    astack->top = NULL;
}
      
void push(STACK* astack, int val){
    NODEPTR newnode = init_node(val);
    newnode->next = astack->top;
    astack->top = newnode;
}

bool is_empty(STACK* astack){
    return astack->top == NULL;
}

int pop(STACK* astack){
    if(astack->top == NULL)
        return -1;

    int ret_val = astack->top->data;
    NODEPTR tmp = astack->top;

    astack->top = astack->top->next;

    free(tmp);

    return ret_val;
}


int peek(STACK* astack){
    if(astack->top == NULL)
        return -1;

    return astack->top->data;
}


void clear(STACK* astack){
    NODEPTR tmp = astack->top;
    NODEPTR tmp_next;

    while(tmp){
        tmp_next = tmp->next;
        free(tmp);
        tmp = tmp_next;
    }
    astack->top = NULL;
}

void print_stack(STACK* astack){
    NODEPTR tmp = astack->top;
    while(tmp){
        cout << tmp->data << " | ";
        tmp = tmp->next;
    }
    cout << endl;
}

