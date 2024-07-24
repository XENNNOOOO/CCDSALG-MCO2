#ifndef CCDSALG_MCO2_SEARCH_C
#define CCDSALG_MCO2_SEARCH_C

#include "search.h"

bool isVertexTraversed(Vertex *traversal, Vertex vertex, int numOfVertices) {
    bool isTraversed = false;
    if (traversal == NULL) {
        // Handle or log the error, depending on your application logic
        return false;  // or true, depending on how you want to handle this case
    }

    for (int i = 0; i < numOfVertices; i++) {
        if (traversal[i].name == vertex.name) {
            isTraversed = true;
            break;
        }
    }

    return isTraversed;
}

Vertex* getBFSTraversal(bool** adjacencyMatrix, Vertex vertices[], Vertex root, int numOfVertices) {
    Queue children;
    Queue current;

    Vertex* traversal = malloc(sizeof(Vertex) * numOfVertices);
    if (traversal == NULL) {
        // Handle allocation failure
        return NULL;
    }
    int currentIndex = 0;

    initQueue(&children);
    initQueue(&current);

    bool* visited = calloc(numOfVertices, sizeof(bool));
    if (visited == NULL) {
        // Handle allocation failure
        free(traversal);
        return NULL;
    }

    enqueue(&current, &root);
    visited[root.id] = true;

    while (currentIndex < numOfVertices && !isQueueEmpty(current)) {
        Vertex* currentVertex = frontOfQueue(&current);

        // Explore neighbors
        for (int i = 0; i < numOfVertices; i++) {
            if (adjacencyMatrix[currentVertex->id][i] && !visited[i]) {
                enqueue(&children, &vertices[i]);
                visited[i] = true; // Mark as visited
            }
        }

        traversal[currentIndex++] = *dequeue(&current);

        // Move children to current queue
        while (!isQueueEmpty(children)) {
            enqueue(&current, dequeue(&children));
        }
    }

    free(visited);
    return traversal;
}

bool isInStack(Stack* stack, Vertex vertex) {
    bool isInStack = false;

    for (int i = 0; i <= stack->topIndex; i++) {
        if (stack->vertices[i].id == vertex.id) {
            isInStack = true;
            break;
        }
    }

    return isInStack;
}

Vertex* getDFSTraversal(bool** adjacencyMatrix, Vertex vertices[], Vertex root, int numOfVertices) {
    Stack children;
    Stack current;

    Vertex* traversal = malloc(sizeof(Vertex) * numOfVertices);
    if (traversal == NULL) {
        // Handle allocation failure
        return NULL;
    }
    int currentIndex = 0;

    initStack(&children);
    initStack(&current);

    bool* visited = calloc(numOfVertices, sizeof(bool));
    if (visited == NULL) {
        // Handle allocation failure
        free(traversal);
        return NULL;
    }

    push(&current, &root);
    visited[root.id] = true;

    while (!isStackEmpty(current) && currentIndex < numOfVertices) {
        Vertex* currentVertex = peekStack(&current);
        traversal[currentIndex++] = *currentVertex;

        // Explore neighbors
        for (int i = 0; i < numOfVertices; i++) {
            if (adjacencyMatrix[currentVertex->id][i] && !visited[i]) {
                push(&children, &vertices[i]);
                visited[i] = true; // Mark as visited
            }
        }

        pop(&current); // Pop the current vertex

        // Move children to current stack
        while (!isStackEmpty(children)) {
            if (!isInStack(&current, *peekStack(&children))){
                push(&current, pop(&children));
            }
        }
    }

    free(visited);
    return traversal;
}

#endif