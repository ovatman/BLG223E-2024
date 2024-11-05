typedef struct Queue{
    int* array;
    int front;
    int back;
    int capacity;
    int size;
} QUEUE;

typedef struct Queue* QUEUEPTR;

void init_queue(QUEUEPTR, int);
void destruct_queue(QUEUEPTR);

void enqueue(QUEUEPTR, int);
void dequeue(QUEUEPTR);
int peek_front(QUEUEPTR);
int peek_back(QUEUEPTR);

bool is_empty();
bool is_full();

void print_queue(QUEUEPTR);