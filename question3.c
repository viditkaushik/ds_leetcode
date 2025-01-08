typedef struct {
    int* queue;
    int front;
    int rear;
    int size;
    int capacity;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->capacity = 10000; 
    obj->queue = (int*)malloc(obj->capacity * sizeof(int));
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    return obj;
}

void enqueue(RecentCounter* obj, int t) {
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->queue[obj->rear] = t;
    obj->size++;
}

void dequeue(RecentCounter* obj) {
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
}


int recentCounterPing(RecentCounter* obj, int t) {
    enqueue(obj, t);

    while (obj->size > 0 && obj->queue[obj->front] < t - 3000) {
        dequeue(obj);
    }

    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}
