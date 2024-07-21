#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct {
    char *name;
    int id;
} Vertex;

bool** adjacencyMatrix(char *fileName, Vertex graph[]) {
    int numVertices;
    char tempString[50];
    char throwString[50];
    int tempInt;

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
        graph[i].name = (char *)malloc(50 * sizeof(char)); 
    }

    // Read adjacent vectors
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        graph[i].name = (char *)malloc(50 * sizeof(char)); 
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

int main() {
    char *fileName = "graph2.txt";  
    Vertex graph[MAX_VERTICES];
    bool **adjMatrix;
    int numVertices = 0;

    adjMatrix = adjacencyMatrix(fileName, graph);
    if (adjMatrix == NULL) {
        fprintf(stderr, "Error reading adjacency matrix\n");
        return 1;
    }

    FILE *file = fopen(fileName, "r");

    fseek(file, 0, SEEK_SET);
    fscanf(file, "%d", &numVertices);

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if(adjMatrix[i][j] == true) {
                printf(" %d ", 1);      
            } else {
                printf(" %d ", 0);
            }
        }
        printf("%c", '\n');
    }
    
    return 0;
}
