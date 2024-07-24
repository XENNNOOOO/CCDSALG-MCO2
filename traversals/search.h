//
// Created by Clive on 22 Jul 2024.
//

#ifndef CCDSALG_MCO2_SEARCH_H
#define CCDSALG_MCO2_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include "datastructures/adjacency_matrix.h"

#include "datastructures/queue.c"
#include "datastructures/stack.c"

bool isVertexTraversed(Vertex *traversal, Vertex vertex, int numOfVertices);
bool isInStack(Stack stack, Vertex vertex);
Vertex* getBFSTraversal(bool** adjacencyMatrix, Vertex vertices[], Vertex root, int numOfVertices);
Vertex* getDFSTraversal(bool** adjacencyMatrix, Vertex vertices[], Vertex root, int numOfVertices);


#endif //CCDSALG_MCO2_SEARCH_H
