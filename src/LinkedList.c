#include <iostream>
#include "LinkedList.h"

using namespace std;

void init_linked_list(LINKED_LIST& l){
    l.head = init_empty_node_ptr(-1);
    l.head->next = l.head;
}


void add(LINKED_LIST& l, int val){
    NODE* cur = init_empty_node_ptr(val);
    NODE* prev = find_prev(l, val);

    if(prev){
        cur->next = prev->next;
        prev->next = cur;
    }
}

void remove(LINKED_LIST& l, int val){
    NODE* cur = find(l, val);
    NODE* prev = find_prev(l, val);

    if(!cur) return;

    if(prev){
        NODE* temp = prev->next;
        prev->next = temp->next;
        free(temp);
    } 
}



NODE* find_prev(LINKED_LIST& l, int val){
    NODE* tmp = l.head->next;

    while(tmp->next != l.head){
        if(tmp->next->data >= val)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

NODE* find(LINKED_LIST& l, int val){
    NODE* tmp = l.head->next;

    while(tmp != l.head){
        if(tmp->data == val)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

void traverse(LINKED_LIST& l){
    NODE* tmp = l.head->next;

    while(tmp != l.head){
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}

void clear(LINKED_LIST& l){
    NODE* tmp = l.head->next;
    NODE* next;
    while(tmp != l.head){
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    l.head->next = l.head;
}
