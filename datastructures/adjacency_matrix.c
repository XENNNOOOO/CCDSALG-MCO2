#ifndef CCDSALG_MCO2_ADJACENCY_MATRIX_C
#define CCDSALG_MCO2_ADJACENCY_MATRIX_C

#include "adjacency_matrix.h"

int parseInt(char* str) {
    char*   ptr;
    int     num = (int) strtol(str, &ptr, 10);

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

bool** fillAdjacencyMatrix(char *filename, Vertex graph[], int* numOfVertices) {
    char tempString[STRING_LEN];

    // File checking
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the first integer
    fscanf(file, "%s", tempString);
    *numOfVertices = parseInt(tempString);
    strcpy(tempString, "");

    // Allocate memory
    bool **adjacencyMatrix = (bool **)malloc(*numOfVertices * sizeof(bool *));
    for (int i = 0; i < *numOfVertices; ++i) {
        adjacencyMatrix[i] = (bool *)malloc(*numOfVertices * sizeof(bool));
        for (int j = 0; j < *numOfVertices; ++j) {
            adjacencyMatrix[i][j] = false;
        }
    }

    for (int i = 0; i < *numOfVertices; ++i) {
        graph[i].name = (char *)malloc(STRING_LEN * sizeof(char));
    }

    // Read adjacent vectors
    for (int i = 0; i < *numOfVertices; ++i) {
        graph[i].name = (char *)malloc(STRING_LEN * sizeof(char));
        fscanf(file, "%s", graph[i].name);
        graph[i].id = i;


        while (fscanf(file, "%s", tempString) == 1 && strcmp(tempString, "-1") != 0) {
            for (int j = 0; j < *numOfVertices; ++j) {
                if (strcmp(tempString, graph[j].name) == 0) {
                    adjacencyMatrix[i][j] = true;
                    adjacencyMatrix[j][i] = true;
                    break; 
                }
            }
        }
    }

    fclose(file);
    return adjacencyMatrix;
}

#endif