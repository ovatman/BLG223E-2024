#include <iostream>
#include "LinkedList.h"

using namespace std;

void add(LINKED_LIST& l, int val){
    NODE* cur = init_empty_node_ptr(val);
    NODE* prev = find_prev(l, val);

    if(!l.head)
        add_to_empty(l, cur);
    else if(prev == l.tail)
        add_to_tail(l, cur);
    else if(prev == NULL)
        add_to_head(l, cur);
    else
        add_between(l, cur, prev);
}

void remove(LINKED_LIST& l, int val){
    NODE* cur = find(l, val);
    NODE* prev = find_prev(l, val);

    if(cur == l.head && cur == l.tail)
        remove_to_empty(l);
    else if(cur == l.head)
        remove_from_head(l);
    else if(cur == l.tail)
        remove_from_tail(l);
    else
        remove_between(l, prev);  
}

void add_to_empty(LINKED_LIST& l, NODE* cur){
    l.head = cur;
    l.tail = l.head;
}

void add_to_head(LINKED_LIST& l, NODE* cur){
    NODE* temp = cur;
    temp->next = l.head;
    l.head = temp;
}

void add_between(LINKED_LIST& l, NODE* cur, NODE* prev_node){
    if(prev_node){
        NODE* temp = cur;
        temp->next = prev_node->next;
        prev_node->next = temp;
    }
}

void add_to_tail(LINKED_LIST& l, NODE* cur){
    l.tail->next = cur;
    l.tail = l.tail->next;
}



void remove_to_empty(LINKED_LIST& l){
    free(l.head);
    l.head = NULL;
    l.tail = NULL;
}


void remove_from_head(LINKED_LIST& l){
    NODE* temp = l.head;
    l.head = l.head->next;
    free(temp);
}

void remove_from_tail(LINKED_LIST& l){
    NODE* temp = l.head;
    while(temp->next != l.tail)
        temp = temp->next;
    
    free(temp->next);
    l.tail = temp;
    l.tail->next = NULL;
}


void remove_between(LINKED_LIST& l, NODE* prev){
    if(prev){
        NODE* temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }
}

NODE* find_prev(LINKED_LIST& l, int val){
    NODE* tmp = l.head;
    if (!tmp || tmp->data >= val)
        return NULL;

    while(tmp->next){
        if(tmp->next->data >= val)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

NODE* find(LINKED_LIST& l, int val){
    NODE* tmp = l.head;

    while(tmp){
        if(tmp->data == val)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

void traverse(LINKED_LIST& l){
    NODE* tmp = l.head;

    while(tmp != NULL){
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}

void clear(LINKED_LIST& l){
    NODE* tmp = l.head;
    NODE* next;
    while(tmp){
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    l.head = NULL;
    l.tail = NULL;
}
