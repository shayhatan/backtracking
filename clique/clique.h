//
// Created by USER on 02/12/2021.
//

#ifndef QUEENSPROBLEM_H_CLIQUE_H
#define QUEENSPROBLEM_H_CLIQUE_H
#include <stdbool.h>
#define N 4

int hasClique(int friends[][N], int k);

bool validColor(int node_index, int color_index, int graph[][N], int * colors);

bool solve(int graph[][N],int colors[N], int clique, int node_index, int k);

#endif //QUEENSPROBLEM_H_CLIQUE_H
