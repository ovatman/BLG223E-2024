#include <stdio.h>
#include "expanding_array.h"

int main(int argc, char** argv){
    
    ExpandingArray ea;
    init_expanding_array(&ea, 10);
    for(int i=0; i<15; i++)
        add_to_expanding_array(&ea, 15 - i);

    replace_in_expanding_array(&ea, 100, 10);
    insert_into_expanding_array(&ea, 50, 1);

    for(int i=0; i < ea.size; i++) // use ea.capacity to see what's left
       printf("%d ", read_from_expanding_array(&ea, i));

    printf("\n");
    
    for(int i=0; i<5; i++)
        remove_from_expanding_array(&ea, 0);
    
    for(int i=0; i<ea.size; i++)
       printf("%d ", read_from_expanding_array(&ea, i));
       
    printf("\n");

    destroy_expanding_array(&ea);
    return 0;
}