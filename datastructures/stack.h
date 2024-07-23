#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"

#define MAX_SIZE 128

typedef struct StackTag {
    List    list[MAX_SIZE];
    int     topIndex;
} Stack;

void initStack(Stack* stack);
void push(Stack* stack, List* list);
List* pop(Stack* stack);
List* peekStack(Stack stack);
bool isStackEmpty(Stack stack);
bool isStackFull(Stack stack);
void clearStack(Stack* stack);

#endif