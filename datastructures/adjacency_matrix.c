#include "adjacency_matrix.h"

bool** fillAdjacencyMatrix(char *fileName, Vertex graph[]) {
    int     numVertices;
    char    tempString[50];
    char    throwString[50];
    int     tempInt;

    // File checking
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the first integer
    fscanf(file, "%d", &numVertices);

    // Allocate memory
    bool **adjacencyMatrix = (bool **)malloc(numVertices * sizeof(bool *));
    for (int i = 0; i < numVertices; ++i) {
        adjacencyMatrix[i] = (bool *)malloc(numVertices * sizeof(bool));
        for (int j = 0; j < numVertices; ++j) {
            adjacencyMatrix[i][j] = false;
        }
    }

    for (int i = 0; i < numVertices; ++i) {
        graph[i].name = (char *)malloc(STRING_LEN * sizeof(char));
    }

    // Read adjacent vectors
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        graph[i].name = (char *)malloc(STRING_LEN * sizeof(char));
        fscanf(file, "%s", graph[i].name);
        graph[i].id = i;


        while (fscanf(file, "%s", tempString) == 1 && strcmp(tempString, "-1") != 0) {
            for (int j = 0; j < numVertices; ++j) {
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
