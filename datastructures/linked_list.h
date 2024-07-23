//
// Created by KYLE on 20/07/2024.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define STRING_LEN 255
#define MAX_VERTICES 128

typedef struct listTag {
    char    name[STRING_LEN];
    int     numOfLinks;
    struct  listTag* lists[MAX_VERTICES];
} List;

#endif //LINKED_LIST_H
