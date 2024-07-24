#ifndef CCDSALG_MCO2_DRIVER_H
#define CCDSALG_MCO2_DRIVER_H

#include "datastructures/adjacency_matrix.c"
#include "traversals/search.c"

GraphInfo importFile(char* filename);
Vertex* searchVertexByName(char* rootName, Vertex* vertices, int numOfVertices);
int getVertexDegree(bool** adjacencyMatrix, Vertex* vertex, int numOfVertices);
void exportFile(char* rootName, GraphInfo* graph);
void displayMatrix(char* filename, bool** adjacencyMatrix, Vertex* vertices);

#endif //CCDSALG_MCO2_DRIVER_H