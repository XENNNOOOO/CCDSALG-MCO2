#ifndef CCDSALG_MCO2_SEARCH_H
#define CCDSALG_MCO2_SEARCH_H

#include <stdio.h>
#include <stdlib.h>

#include "../datastructures/queue.c"
#include "../datastructures/stack.c"

bool isVertexTraversed(Vertex* traversal, Vertex vertex, int numOfVertices);
Vertex* getBFSTraversal(bool** adjacencyMatrix, Vertex vertices[], Vertex root, int numOfVertices);
bool isInStack(Stack stack, Vertex vertex);
Vertex* getDFSTraversal(bool** adjacencyMatrix, Vertex vertices[], Vertex root, int numOfVertices);

#endif //CCDSALG_MCO2_SEARCH_H