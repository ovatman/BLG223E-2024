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
    //clear(l);
    remove(l, 3);
    remove(l, 2);
    remove(l, 5);
    remove(l, 4);
    traverse(l);
    
    return 0;
}

