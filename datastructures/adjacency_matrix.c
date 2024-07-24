#ifndef CCDSALG_MCO2_ADJACENCY_MATRIX_C
#define CCDSALG_MCO2_ADJACENCY_MATRIX_C

#include "adjacency_matrix.h"

int parseInt(char* str) {
    char* ptr;
    int num = (int) strtol(str, &ptr, 10);

    if (ptr == str) {
        printf("No digits were found\n");
        return 0; // Return a default value or handle as needed
    } else if (*ptr != '\0') {
        printf("Invalid characters encountered: %s\n", ptr);
        return 0; // Return a default value or handle as needed
    } else {
        return num;
    }
}

GraphInfo fillGraphInfo(char *filename) {
    GraphInfo result;
    char tempString[STRING_LEN];

    // file checking
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");

        //assign null/0
        result.adjacencyMatrix = NULL;
        result.graph = NULL;
        result.numOfVertices = 0;
        return result;
    }

    // memory for vertices
    result.graph = (Vertex *)malloc(result.numOfVertices * sizeof(Vertex));
    for (int i = 0; i < result.numOfVertices; ++i) {
        result.graph[i].name = (char *)malloc(STRING_LEN * sizeof(char));
        result.graph[i].id = i;
    }

    // memory for adjacency matrix
    result.adjacencyMatrix = (bool **)malloc(result.numOfVertices * sizeof(bool *));
    for (int i = 0; i < result.numOfVertices; ++i) {
        result.adjacencyMatrix[i] = (bool *)malloc(result.numOfVertices * sizeof(bool));
        for (int j = 0; j < result.numOfVertices; ++j) {
            result.adjacencyMatrix[i][j] = false;
        }
    }

    // read adjacent vectors
    for (int i = 0; i < result.numOfVertices; ++i) {
        fscanf(file, "%s", result.graph[i].name);
        while (fscanf(file, "%s", tempString) == 1 && strcmp(tempString, "-1") != 0) {
            for (int j = 0; j < result.numOfVertices; ++j) {
                if (strcmp(tempString, result.graph[j].name) == 0) {
                    result.adjacencyMatrix[i][j] = true;
                    result.adjacencyMatrix[j][i] = true;
                    break;
                }
            }
        }
    }

    fclose(file);
    return result;
}

#endif
