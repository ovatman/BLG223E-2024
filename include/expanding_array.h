#include <stdbool.h>

typedef struct ExpandingArray{
    int* array;
    int capacity;
    int size;
    int delta;
} ExpandingArray;

void init_expanding_array(ExpandingArray* ea, int _capacity);

void add_to_expanding_array(ExpandingArray* ea, int value);
int read_from_expanding_array(ExpandingArray* ea, int index);

void expand_expanding_array(ExpandingArray* ea);

bool insert_into_expanding_array(ExpandingArray* ea, int value, int index);
bool replace_in_expanding_array(ExpandingArray* ea, int value, int index);

bool remove_from_expanding_array(ExpandingArray* ea, int index);
void shrink_expanding_array(ExpandingArray* ea);

void destroy_expanding_array(ExpandingArray* ea);


