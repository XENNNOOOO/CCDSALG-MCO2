//
// Created by Clive on 22 Jul 2024.
//

#include "driver.h"

bool** importFile(char* filename) {
    bool**  adjMatrix;
    Vertex  graph[MAX_VERTICES];

    adjMatrix = fillAdjacencyMatrix(filename, graph);
    if (adjMatrix == NULL) {
        fprintf(stderr, "Error reading adjacency matrix\n");
        return NULL;
    }

    return adjMatrix;
}

void exportFile(bool** adjacencyMatrix) {
//    List* BFS = getBFSTraversal();
//    List* DFS = getDFSTraversal();
}

void displayMatrix(char* filename, bool** adjacencyMatrix) {
    int numVertices;
    FILE *file = fopen(filename, "r");

    fseek(file, 0, SEEK_SET);
    fscanf(file, "%d", &numVertices);

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] == true) {
                printf(" %d ", 1);
            } else {
                printf(" %d ", 0);
            }
        }
        printf("%c", '\n');
    }
}

int main() {
    char    filename[STRING_LEN];
    bool**  adjMatrix;

    printf("Input file name:");
    scanf("%255[^\n]s", filename);

    adjMatrix = importFile(filename);

    displayMatrix(filename, adjMatrix);

    return 0;
}