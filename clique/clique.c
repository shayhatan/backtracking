//
// Created by USER on 02/12/2021.
//

#include "clique.h"

#define CONNECTED 1

int hasClique(int friends[][N], int k) {
    int colors[N] = {0};
    return solve(friends, colors, 0, 0, k);
}

bool validColor(int node_index, int color_index, int graph[][N], int *colors) {
    for (int i = 0; i < N; i++) {
        int temp = graph[node_index][i];
        int temp2 = colors[i];
        if (graph[node_index][i] == CONNECTED && colors[i] == color_index) {
            return false;
        }
    }
    return true;
}

bool solve(int graph[][N], int *colors, int clique, int node_index, int k) {
    if (clique > k) {
        return true;
    }
    if (node_index >= N) {
        return false;
    }
    for (int color_index = 1; color_index <= N; ++color_index) {
        if (validColor(node_index, color_index, graph, colors)) {
            colors[node_index] = color_index;
            if (solve(graph, colors, color_index, node_index + 1, k)) {
                return true;
            }
        }
    }
    return false;
}
