#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct NodeTag {
    List            list;
    struct NodeTag* next;
    struct NodeTag* prev;
} Node;

typedef struct QueueTag {
    struct NodeTag* front;
    struct NodeTag* rear;
} Queue;

void initQueue(Queue* queue);
void enqueue(Queue* queue, List list);
List dequeue(Queue* queue);
List frontOfQueue(Queue* queue);
List rearOfQueue(Queue* queue);
bool isQueueEmpty(Queue queue);
void clearQueue(Queue* queue);

#endif