#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LINKED_LIST l;
    add(l, 4);
    add(l, 2);
    add(l, 3);
    add(l, 5);
    traverse(l);
    clear(l);
    /*
    remove_between(l, 3);
    remove_between(l, 4);
    remove_between(l, 2);
    remove_from_tail(l);
    remove_from_head(l);
    remove_to_empty(l);*/
    traverse(l);
    
    return 0;
}

