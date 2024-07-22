#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"

List* bfs(List root) {
    Queue temp;
    Queue queue;
    Queue storage;

    int numOfParents = 0;

    initQueue(&queue);
    initQueue(&temp);
    initQueue(&storage);

    enqueue(&temp, root);
    while (!isQueueEmpty(temp)) {
        while (!isQueueEmpty(temp)) {
            List current = dequeue(&temp);
            for (int i = 0; i < current.numOfLinks; i++) {
                enqueue(&queue, current.lists[i]);
            }
            enqueue(&storage, current);
            numOfParents++;
        }
        while (!isQueueEmpty(queue)) {
            enqueue(&temp, dequeue(&queue));
        }
    }

    List* lists = malloc(numOfParents * sizeof(List));

    if (lists == NULL) {
        return NULL;
    }

    for (int i = 0; i < numOfParents; i++) {
        lists[i] = dequeue(&storage);
    }

    return lists;
}

List* dfs (List root) {
    Stack temp;
    Stack stack;
    Stack reverse;
    Queue storage;

    int numOfParents = 0;

    initStack(&temp);
    initStack(&stack);
    initStack(&reverse);
    initQueue(&storage);

    push(&stack, root);

    while(!isStackEmpty(stack) && !isStackEmpty(temp)) {
        for(int i = 0; i < peekStack(stack).numOfLinks; i++) {
            push(reverse, peekStack(stack)->lists[i]);
        }
        for(int i = 0; i < peekStack(stack).numOfLinks; i++) {
            push(temp, pop(reverse));
        }
        enqueue(storage, pop(stack));
        numOfParents++;
        push(stack, pop(temp));
    }

    List* lists = malloc(numOfParents * sizeof(List));

    if (lists == NULL) {
        return NULL;
    }

    for(int i = 0; i < numOfParents; i++) {
        lists[i] = dequeue(&storage);
    }

    return lists;
}
