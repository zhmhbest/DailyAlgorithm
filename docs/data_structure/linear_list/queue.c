#include <stdio.h>
#include <stdlib.h>
#define ELEMENT int
#define ELEMENT_NULL 0


/*
 * Queue
 */
typedef struct {
    ELEMENT* buffer;
    ELEMENT* front;
    ELEMENT* rear;
    int capacity;
} Queue;


Queue* queue_create(int capacity) {
    capacity++; // 需要预留一个空间判断队满
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->buffer = 
        (ELEMENT*)malloc(sizeof(ELEMENT)*capacity);
    queue->front = queue->rear = queue->buffer;
    queue->capacity = capacity;
    return queue;
}
void queue_drop(Queue* queue) {
    free(queue->buffer);
    free(queue);
}


int queue_empty(Queue* queue) {
    return queue->front == queue->rear;
}
int queue_full(Queue* queue) {
    return
        (
            queue->front - queue->buffer
        ) == (
            (queue->rear - queue->buffer + 1)
            % queue->capacity
        )
    ;
}
int queue_length(Queue* queue) {
    if (queue->rear >= queue->front) {
        return queue->rear - queue->front;
    } else {
        return queue->capacity - (queue->front - queue->rear);
    }
}
int queue_remains(Queue* queue) {
    return queue->capacity - queue_length(queue) - 1;
}


ELEMENT queue_front(Queue* queue) {
    if ( queue_empty(queue) ) {
        return ELEMENT_NULL;
    } else {
        return *(queue->front);
    }
}
void queue_en(Queue* queue, ELEMENT ele) {
    if ( !queue_full(queue) ) {
        *(queue->rear) = ele;
        queue->rear = (
                (queue->rear - queue->buffer + 1)
                % queue->capacity
            ) + queue->buffer;
    }
}
ELEMENT queue_de(Queue* queue) {
    if ( !queue_empty(queue) ) {
        ELEMENT ele = *(queue->front);
        queue->front = (
                (queue->front - queue->buffer + 1)
                % queue->capacity
            ) + queue->buffer;
        return ele;
    } else {
        return ELEMENT_NULL;
    }
}


int main() {
    ELEMENT ele;
    Queue* queue = queue_create(3);

    printf("front=%d\n", queue_front(queue));
    printf("empty=%d\n", queue_empty(queue));
    printf("length=%d\n", queue_length(queue));
    printf("remains=%d\n", queue_remains(queue));
    printf("full=%d\n", queue_full(queue));
    printf("\n");
    
    queue_en(queue, 123);
    printf("front=%d\n", queue_front(queue));
    printf("empty=%d\n", queue_empty(queue));
    printf("length=%d\n", queue_length(queue));
    printf("remains=%d\n", queue_remains(queue));
    printf("full=%d\n", queue_full(queue));
    printf("\n");

    queue_en(queue, 456);
    printf("front=%d\n", queue_front(queue));
    printf("empty=%d\n", queue_empty(queue));
    printf("length=%d\n", queue_length(queue));
    printf("remains=%d\n", queue_remains(queue));
    printf("full=%d\n", queue_full(queue));
    printf("\n");

    ele =  queue_de(queue);
    printf("ele=%d\n", ele);
    printf("front=%d\n", queue_front(queue));
    printf("empty=%d\n", queue_empty(queue));
    printf("length=%d\n", queue_length(queue));
    printf("remains=%d\n", queue_remains(queue));
    printf("full=%d\n", queue_full(queue));
    printf("\n");

    ele =  queue_de(queue);
    printf("ele=%d\n", ele);
    printf("front=%d\n", queue_front(queue));
    printf("empty=%d\n", queue_empty(queue));
    printf("length=%d\n", queue_length(queue));
    printf("remains=%d\n", queue_remains(queue));
    printf("full=%d\n", queue_full(queue));
    printf("\n");

    queue_en(queue, 789);
    printf("front=%d\n", queue_front(queue));
    printf("empty=%d\n", queue_empty(queue));
    printf("length=%d\n", queue_length(queue));
    printf("remains=%d\n", queue_remains(queue));
    printf("full=%d\n", queue_full(queue));
    printf("\n");

    queue_en(queue, 101);
    printf("front=%d\n", queue_front(queue));
    printf("empty=%d\n", queue_empty(queue));
    printf("length=%d\n", queue_length(queue));
    printf("remains=%d\n", queue_remains(queue));
    printf("full=%d\n", queue_full(queue));
    printf("\n");

    queue_en(queue, 369);
    printf("front=%d\n", queue_front(queue));
    printf("empty=%d\n", queue_empty(queue));
    printf("length=%d\n", queue_length(queue));
    printf("remains=%d\n", queue_remains(queue));
    printf("full=%d\n", queue_full(queue));
    printf("\n");

    queue_drop(queue);
    return 0;
}
