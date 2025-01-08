int minimumCoins(int* prices, int pricesSize) {
    typedef struct {
        int* data;
        int front;
        int rear;
        int size;
        int capacity;
    } Queue;

    
    Queue* createQueue(int capacity) {
        Queue* queue = (Queue*)malloc(sizeof(Queue));
        queue->data = (int*)malloc(capacity * sizeof(int));
        queue->front = 0;
        queue->rear = -1;
        queue->size = 0;
        queue->capacity = capacity;
        return queue;
    }

    
    void enqueue(Queue* queue, int value) {
        if (queue->size < queue->capacity) {
            queue->rear = (queue->rear + 1) % queue->capacity;
            queue->data[queue->rear] = value;
            queue->size++;
        }
    }

    
    int dequeue(Queue* queue) {
        if (queue->size > 0) {
            int value = queue->data[queue->front];
            queue->front = (queue->front + 1) % queue->capacity;
            queue->size--;
            return value;
        }
        return -1; 
    }

    
    void freeQueue(Queue* queue) {
        free(queue->data);
        free(queue);
    }

    
    Queue* freeFruits = createQueue(pricesSize);

    int totalCoins = 0;

    for (int i = 0; i < pricesSize; i++) {
        
        while (freeFruits->size > 0 && freeFruits->data[freeFruits->front] < i) {
            dequeue(freeFruits);
        }

        if (freeFruits->size > 0 && freeFruits->data[freeFruits->front] == i) {
            dequeue(freeFruits);
            continue;
        }

        
        totalCoins += prices[i];

        
        for (int j = 1; j <= i && (i + j) < pricesSize; j++) {
            enqueue(freeFruits, i + j);
        }
    }

    freeQueue(freeFruits);
    return totalCoins;
}
