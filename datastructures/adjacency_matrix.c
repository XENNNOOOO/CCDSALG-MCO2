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

    // Check if file exists
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        //assign null/0
        result.adjacencyMatrix = NULL;
        result.vertices = NULL;
        result.numOfVertices = 0;
        return result;
    }

    // Read the first integer
    fscanf(file, "%s", tempString);
    result.numOfVertices = parseInt(tempString);
    strcpy(tempString, "");

    // Check if graph exists
    if (result.numOfVertices == 0) {
        //assign null/0
        result.adjacencyMatrix = NULL;
        result.vertices = NULL;
        result.numOfVertices = 0;
        return result;
    }

    // Memory for vertices
    result.vertices = (Vertex *)malloc(result.numOfVertices * sizeof(Vertex));
    for (int i = 0; i < result.numOfVertices; ++i) {
        result.vertices[i].name = (char *)malloc(STRING_LEN * sizeof(char));
        result.vertices[i].id = i;
    }

    // Memory for adjacency matrix
    result.adjacencyMatrix = (bool **)malloc(result.numOfVertices * sizeof(bool *));
    for (int i = 0; i < result.numOfVertices; ++i) {
        result.adjacencyMatrix[i] = (bool *)malloc(result.numOfVertices * sizeof(bool));
        for (int j = 0; j < result.numOfVertices; ++j) {
            result.adjacencyMatrix[i][j] = false;
        }
    }

    // Read adjacent vectors
    for (int i = 0; i < result.numOfVertices; ++i) {
        fscanf(file, "%s", result.vertices[i].name);
        while (fscanf(file, "%s", tempString) == 1 && strcmp(tempString, "-1") != 0) {
            for (int j = 0; j < result.numOfVertices; ++j) {
                if (strcmp(tempString, result.vertices[j].name) == 0) {
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