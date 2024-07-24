#ifndef CCDSALG_MCO2_ADJACENCY_MATRIX_H
#define CCDSALG_MCO2_ADJACENCY_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STRING_LEN 256
#define MAX_VERTICES 128

typedef struct {
    char*   name;
    int     id;
} Vertex;

typedef struct {
    bool**  adjacencyMatrix;
    Vertex* vertices;
    int     numOfVertices;
} GraphInfo;

int parseInt(char* str);
GraphInfo fillGraphInfo(char *fileName);

#endif //CCDSALG_MCO2_ADJACENCY_MATRIX_H