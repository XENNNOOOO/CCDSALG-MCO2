//
// Created by Clive on 22 Jul 2024.
//

#ifndef CCDSALG_MCO2_SEARCH_H
#define CCDSALG_MCO2_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include "adjacency_matrix.h"

#include "datastructures/queue.c"
#include "datastructures/stack.c"

Vertex* getBFSTraversal(List root);
Vertex* getDFSTraversal(List root);

#endif //CCDSALG_MCO2_SEARCH_H
