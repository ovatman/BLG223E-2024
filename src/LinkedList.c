#include <iostream>
#include "LinkedList.h"

using namespace std;

void add_to_empty(LinkedList& l, int val){
    l.head = init_empty_node_ptr(val);
    l.tail = l.head;
}


void add_to_tail(LinkedList& l, int val){
    l.tail->next = init_empty_node_ptr(val);
    l.tail = l.tail->next;
}

void traverse(LinkedList& l){
    NODE* tmp = l.head;

    while(tmp != NULL){
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}