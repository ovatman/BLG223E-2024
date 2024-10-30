#include<iostream>
#include "Queue.h"

using namespace std;

void init_queue(QUEUEPTR q, int cap){
    q->array = (int*) malloc(sizeof(int)*cap);
    q->front = 0;
    q->back = -1;
    q->capacity = cap;
}

void destruct_queue(QUEUEPTR q){
    free(q->array);
}

void enqueue(QUEUEPTR q, int val){
    q->array[++q->back] = val;
}

void dequeue(QUEUEPTR q){
    q->front = (q->front+1) % q->capacity;
}

int peek_front(QUEUEPTR q){
    return q->array[q->front];
}

int peek_back(QUEUEPTR q){
    return q->array[q->back];
}

void print_queue(QUEUEPTR q){
    for(int i = q->front; i <= q->back ;i++)
        cout << q->array[i] << " ";
    
    cout << endl;
}
