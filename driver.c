#ifndef CCDSALG_MCO2_DRIVER_C
#define CCDSALG_MCO2_DRIVER_C

#include "driver.h"

GraphInfo importFile(char* filename) {
    return fillGraphInfo(filename);
}

Vertex* searchVertexByName(char* rootName, Vertex* vertices, int numOfVertices) {
    for (int i = 0; i < numOfVertices; i++) {
        if (strcmp(vertices[i].name, rootName) == 0) {
            return &vertices[i];
        }
    }
    return NULL;
}

int getVertexDegree(bool** adjacencyMatrix, Vertex* vertex, int numOfVertices) {
    int degree = 0;
    int id = vertex->id;

    for (int i = 0; i < numOfVertices; i++) {
        if (adjacencyMatrix[id][i] == true) {
            degree++;
        }
    }
    return degree;
}

void exportFile(char* rootName, bool** adjacencyMatrix, Vertex* vertices, int numOfVertices) {
    const char filename[STRING_LEN] = {"TRAVERSALS.TXT"};

    Vertex* root = searchVertexByName(rootName, vertices, numOfVertices);

    if (root == NULL) {
        fprintf(stderr, "Vertex %s not found.\n", rootName);
        return;
    }

    FILE *file = fopen(filename, "w");

    Vertex* BFS = getBFSTraversal(adjacencyMatrix, vertices, *root, numOfVertices);
    Vertex* DFS = getDFSTraversal(adjacencyMatrix, vertices, *root, numOfVertices);

    // Print vertex IDs with corresponding degrees
    for (int i = 0; i < numOfVertices; i++) {
        char vertexName[STRING_LEN];
        int degree = getVertexDegree(adjacencyMatrix, &vertices[i], numOfVertices);
        strcpy(vertexName, vertices[i].name);
        fprintf(file, "%s\t%d", vertices[i].name, degree);
    }
    fprintf(file, "\n");

    // Print BFS traversal sequence
    for (int i = 0; i < numOfVertices; i++) {
        fprintf(file, "%s ", BFS[i].name);
    }
    fprintf(file, "\n");

    // Print DFS traversal sequence
    for (int i = 0; i < numOfVertices; i++) {
        fprintf(file, "%s ", DFS[i].name);
    }
    fprintf(file, "\n");

    fclose(file);
}

void displayMatrix(char* filename, bool** adjacencyMatrix) {
    char    tempString[STRING_LEN];
    int     numOfVertices;
    FILE*   file = fopen(filename, "r");

    // Get number of vertices
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%s", tempString);
    numOfVertices = parseInt(tempString);
    strcpy(tempString, "");

    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
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
    char        filename[STRING_LEN];
    char        rootName[STRING_LEN];
    GraphInfo   graph;

    printf("Input filename: ");
    scanf("%255[^\n]s", filename);
    while (getchar() != '\n');

    graph = importFile(filename);

    printf("Input start vertex for the traversal: ");
    scanf("%255[^\n]s", rootName);
    while (getchar() != '\n');

    exportFile(rootName, graph.adjacencyMatrix, graph.vertices, graph.numOfVertices);

    displayMatrix(filename, graph.adjacencyMatrix);

    return 0;
}

#endif