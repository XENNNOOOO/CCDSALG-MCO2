//
// Created by KYLE on 20/07/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Queue.h"
#include "Stack.h"
#include "string.h"

typedef char *String;

typedef struct listTag{
    String name;
    int numOfLinks{};
    struct listTag lists[];
}List;


#endif //LINKEDLIST_H
