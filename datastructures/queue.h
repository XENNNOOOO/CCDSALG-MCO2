#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "adjacency_matrix.h"

typedef struct NodeTag {
    Vertex          vertex;
    struct NodeTag* next;
    struct NodeTag* prev;
} Node;

typedef struct QueueTag {
    struct NodeTag* front;
    struct NodeTag* rear;
} Queue;

void initQueue(Queue* queue);
void enqueue(Queue* queue, Vertex* vertex);
Vertex* dequeue(Queue* queue);
Vertex* frontOfQueue(Queue* queue);
Vertex* rearOfQueue(Queue* queue);
bool isQueueEmpty(Queue queue);
void clearQueue(Queue* queue);

#endif