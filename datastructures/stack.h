#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "adjacency_matrix.h"

#define MAX_SIZE 128

typedef struct StackTag {
    Vertex  vertices[MAX_SIZE];
    int     topIndex;
} Stack;

void initStack(Stack* stack);
void push(Stack* stack, Vertex* vertex);
Vertex* pop(Stack* stack);
Vertex* peekStack(Stack* stack);
bool isStackEmpty(Stack stack);
bool isStackFull(Stack stack);
void clearStack(Stack* stack);

#endif