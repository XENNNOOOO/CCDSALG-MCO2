#include "search.h"

bool isVertexTraversed(Vertex *traversal, Vertex vertex, int numOfVertices) {
    bool isTraversed = false;
    if (traversal == NULL) {
        // Handle or log the error, depending on your application logic
        return false;  // or true, depending on how you want to handle this case
    }

    for(int i = 0; i < numOfVertices; i++) {
        if(traversal[i].name == vertex.name) {
            isTraversed = true;
            break;
        }
    }

    return isTraversed;
}

Vertex* getBFSTraversal(bool** adjacencyMatrix, Vertex vertices[], Vertex root, int numOfVertices) {
    Queue children;
    Queue current;

    Vertex *traversal = malloc(sizeof(Vertex) * numOfVertices);
    int currentIndex = 0;

    initQueue(&children);
    initQueue(&current);

    enqueue(&current, &root);

    while(currentIndex < numOfVertices) {
        while(!isQueueEmpty(current)){
            for(int i = 0; i < numOfVertices; i++){
                if(adjacencyMatrix[frontOfQueue(&current)->id][i] &&
                    !isVertexTraversed(traversal, vertices[i], numOfVertices)){
                    enqueue(&children, &vertices[i]);
                }
            }

            traversal[currentIndex] = *dequeue(&current);
            currentIndex++;
        }
        while(!isQueueEmpty(children)){
            enqueue(&current, dequeue(&children));
        }
    }

    return traversal;
}

bool isInStack(Stack stack, Vertex vertex) {
    Stack temp;
    initStack(&temp);
    bool isInStack = false;
    while(!isStackEmpty(stack) && isInStack == false) {
        if(peekStack(stack).name == vertex.name) {
            isInStack = true;
        }
        else {
            push(&temp, pop(&stack));
        }
    }
    push(&stack, pop(&temp));
    return isInStack;
}

Vertex* getDFSTraversal(bool** adjacencyMatrix, Vertex vertices[], Vertex root, int numOfVertices) {
    Stack children;
    Stack current;

    Vertex *traversal = malloc(sizeof(Vertex) * numOfVertices);
    int currentIndex = 0;

    initStack(&children);
    initStack(&current);

    push(&current, &root);

    while(currentIndex < numOfVertices) {
        for(int i = 0; i < numOfVertices; i++){
            if(adjacencyMatrix[peekStack(current).id][i] &&
                !isVertexTraversed(traversal, vertices[i], numOfVertices)){
                push(&children, &vertices[i]);
                }
        }
        traversal[currentIndex] = peekStack(current);
        currentIndex++;
        while(!isStackEmpty(children)) {
            if(!isInStack(current, peekStack(children))){
                push(&current, pop(&children));
            }else {
                pop(&children);
            }
        }
    }

    return traversal;
}



