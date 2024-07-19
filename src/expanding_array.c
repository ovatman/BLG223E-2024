#include "expanding_array.h"
#include <stdlib.h>
#include <stdio.h>

void init_expanding_array(ExpandingArray* ea, int _capacity){
    if(_capacity <= 0) return;

    ea->capacity = _capacity;
    ea->size = 0;
    ea->array = (int*) calloc(_capacity, sizeof(int));
    ea->delta = 10;
}

void add_to_expanding_array(ExpandingArray* ea, int value){
    if(ea->size == ea->capacity)
        expand_expanding_array(ea);
    
    ea->array[ea->size++] = value;
}

int read_from_expanding_array(ExpandingArray* ea, int index){
    if(index < 0 || index > ea->size)
        return -1;
    
    return ea->array[index];
}

void expand_expanding_array(ExpandingArray* ea){
    ea->capacity += ea->delta;
    ea->array = (int*) realloc(ea->array, ea->capacity * sizeof(int));   //can be direct copy, can be memcpy
}

bool insert_into_expanding_array(ExpandingArray* ea, int value, int index){
    if(index >= ea->size || index < 0)
        return false;

    if(ea->size == ea->capacity)
        expand_expanding_array(ea);
    
    for(int i=ea->size; i>index; i--)
        ea->array[i] = ea->array[i-1]; 
    ea->array[index] = value;
    
    ea->size++; //Easy to forget 

    return true;
}

bool replace_in_expanding_array(ExpandingArray* ea, int value, int index){
    if(index >= ea->size || index < 0)
        return false;
    
    ea->array[index] = value;

    return true;
}

bool remove_from_expanding_array(ExpandingArray* ea, int index){
    if(index >= ea->size || index < 0)
        return false;
    
    for(int i=index; i < ea->size; i++)
        ea->array[i] = ea->array[i+1]; 
    
    ea->size--; //Easy to forget 

    if(ea->capacity - ea->size > ea->delta)
        shrink_expanding_array(ea);
    
    return true;
}

void shrink_expanding_array(ExpandingArray* ea){ //Too bad we can also directly call this func
    ea->capacity -= ea->delta;
    ea->array = (int*) realloc(ea->array, ea->capacity * sizeof(int));   //can be direct copy, can be memcpy
}

void destroy_expanding_array(ExpandingArray* ea){
    ea->capacity = -1;
    ea->size = -1;
    ea->delta = -1;
    free(ea->array);
    ea->array = NULL;
}
