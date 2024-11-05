#include<iostream>
#include "Queue.h"

using namespace std;

void init_queue(QUEUEPTR q, int cap){
    q->array = (int*) malloc(sizeof(int)*cap);
    q->front = 0;
    q->back = -1;
    q->capacity = cap;
    q->size = 0;
}

void destruct_queue(QUEUEPTR q){
    free(q->array);
}

void enqueue(QUEUEPTR q, int val){
    if(q->size < q->capacity){
        q->back = (q->back + 1) % q->capacity;
        q->array[q->back] = val;
        q->size++;
    }
}

void dequeue(QUEUEPTR q){
    if(q->size > 0){
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
}


bool is_empty(QUEUEPTR q){
    return q->size == 0;
}

bool is_full(QUEUEPTR q){
    return q->size == q->capacity;
}


int peek_front(QUEUEPTR q){
    return q->array[q->front];
}

int peek_back(QUEUEPTR q){
    return q->array[q->back];
}

int clear_queue(QUEUEPTR q){
    q->size = 0;
    q->front = 0;
    q->back = -1;
}

void print_queue(QUEUEPTR q){
    for(int i = q->front, j=0; j < q->size ; i = (i+1) % q->capacity, j++)
        cout << q->array[i] << " ";
    
    cout << endl;
}
