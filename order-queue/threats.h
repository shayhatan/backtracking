//
// Created by USER on 05/12/2021.
//

#ifndef HREATS_H
#define THREATS_H

#include <stdbool.h>

#define N 4

bool included(int *res, int node_index, int place);

bool threat(int node_index, int graph[][N], int place);

bool valid(int graph[][N], int *res, int node_index, int place);

bool solve(int graph[][N], int *res,int node_index, int place);

bool orderQueue(int threats[][N], int* queue);

#endif //THREATS_H
