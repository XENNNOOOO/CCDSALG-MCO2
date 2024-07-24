#ifndef CCDSALG_MCO2_DRIVER_C
#define CCDSALG_MCO2_DRIVER_C

#include "driver.h"

/**
 * Imports graph information from a file and returns a GraphInfo structure.
 *
 * @param filename The name of the file containing the graph data.
 * @return A GraphInfo structure containing the adjacency matrix, vertices, and number of vertices.
 */
GraphInfo importFile(char* filename) {
    return fillGraphInfo(filename);
}

/**
 * Searches for a vertex by its name.
 *
 * @param rootName The name of the vertex to search for.
 * @param vertices The array of vertices in the graph.
 * @param numOfVertices The number of vertices in the graph.
 * @return A pointer to the vertex if found; otherwise, NULL.
 */
Vertex* searchVertexByName(char* rootName, Vertex* vertices, int numOfVertices) {
    for (int i = 0; i < numOfVertices; i++) {
        if (strcmp(vertices[i].name, rootName) == 0) {
            return &vertices[i];
        }
    }
    return NULL;
}

/**
 * Calculates the degree of a vertex.
 *
 * @param adjacencyMatrix The adjacency matrix representing the graph.
 * @param vertex The vertex whose degree is to be calculated.
 * @param numOfVertices The number of vertices in the graph.
 * @return The degree of the vertex.
 */
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

/**
 * Exports graph traversal results and vertex degrees to a file.
 *
 * @param rootName The name of the starting vertex for traversal.
 * @param graph A pointer to the GraphInfo structure containing the graph data.
 */
void exportFile(char* rootName, GraphInfo* graph) {
    const char filename[STRING_LEN] = {"TRAVERSALS.TXT"};

    Vertex* root = searchVertexByName(rootName, graph->vertices, graph->numOfVertices);

    if (root == NULL) {
        //assign null/0
        graph->adjacencyMatrix = NULL;
        graph->vertices = NULL;
        graph->numOfVertices = 0;
        return;
    }

    FILE *file = fopen(filename, "w");

    Vertex* BFS = getBFSTraversal(graph->adjacencyMatrix, graph->vertices, *root, graph->numOfVertices);
    Vertex* DFS = getDFSTraversal(graph->adjacencyMatrix, graph->vertices, *root, graph->numOfVertices);

    // Print vertex IDs with corresponding degrees
    for (int i = 0; i < graph->numOfVertices; i++) {
        char vertexName[STRING_LEN];
        int degree = getVertexDegree(graph->adjacencyMatrix, &graph->vertices[i], graph->numOfVertices);
        strcpy(vertexName, graph->vertices[i].name);
        fprintf(file, "%s\t%d\n", graph->vertices[i].name, degree);
    }
    fprintf(file, "\n");

    // Print BFS traversal sequence
    for (int i = 0; i < graph->numOfVertices; i++) {
        fprintf(file, "%s ", BFS[i].name);
    }
    fprintf(file, "\n");

    // Print DFS traversal sequence
    for (int i = 0; i < graph->numOfVertices; i++) {
        fprintf(file, "%s ", DFS[i].name);
    }
    fprintf(file, "\n");

    fclose(file);
}

/**
 * Displays the adjacency matrix of the graph.
 *
 * @param filename The name of the file containing the graph data.
 * @param adjacencyMatrix The adjacency matrix representing the graph.
 * @param vertices The array of vertices in the graph.
 */
void displayMatrix(char* filename, bool** adjacencyMatrix, Vertex* vertices) {
    char tempString[STRING_LEN];
    int numOfVertices;
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Get number of vertices
    fscanf(file, "%s", tempString);
    numOfVertices = parseInt(tempString);

    // Print headers
    printf("     ");
    for (int i = 0; i < numOfVertices; i++) {
        printf("%.3s", vertices[i].name);
        int length = strlen(vertices[i].name);
        for (int j = length; j < 3; j++) {
            putchar(' ');
        }
        printf(" ");
    }
    printf("\n");

    // Print top border
    printf("    +");
    for (int i = 0; i < numOfVertices; i++) {
        printf("---+");
    }
    printf("\n");

    // Print matrix body
    for (int i = 0; i < numOfVertices; i++) {
        printf("%.3s", vertices[i].name);
        int length = strlen(vertices[i].name);
        for (int j = length; j < 3; j++) {
            putchar(' ');
        }

        printf(" |");
        for (int j = 0; j < numOfVertices; j++) {
            printf(" %d |", adjacencyMatrix[i][j]);
        }
        printf("\n");

        // Print border
        printf("    +");
        for (int j = 0; j < numOfVertices; j++) {
            printf("---+");
        }
        printf("\n");
    }

    fclose(file);
}

int main() {
    char        filename[STRING_LEN];
    char        rootName[STRING_LEN];
    GraphInfo   graph;

    printf("Input filename: ");
    scanf("%255[^\n]s", filename);
    while (getchar() != '\n');

    graph = importFile(filename);

    if (graph.adjacencyMatrix == NULL) {
        printf("%s not found.", filename);
        return 0;
    }

    printf("Input start vertex for the traversal: ");
    scanf("%255[^\n]s", rootName);
    while (getchar() != '\n');

    exportFile(rootName, &graph);

    if (graph.adjacencyMatrix == NULL) {
        printf("Vertex %s not found.", rootName);
        return 0;
    }

    displayMatrix(filename, graph.adjacencyMatrix, graph.vertices);

    return 0;
}

#endif