typedef struct Queue{
    int* array;
    int front;
    int back;
    int capacity;
} QUEUE;

typedef struct Queue* QUEUEPTR;

void init_queue(QUEUEPTR, int);
void destruct_queue(QUEUEPTR);

void enqueue(QUEUEPTR, int);
void dequeue(QUEUEPTR);
int peek_front(QUEUEPTR);
int peek_back(QUEUEPTR);

void print_queue(QUEUEPTR);