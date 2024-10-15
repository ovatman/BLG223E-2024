#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LINKED_LIST l;
    add_to_empty(l, 5);
    add_to_tail(l, 3);
    add_to_tail(l, 6);
    add_to_tail(l, 2);
    add_to_tail(l, 9);
    add_to_tail(l, -55);
    add_to_tail(l, 3);
    add_to_tail(l, 1);
    traverse(l);
    
    return 0;
}

