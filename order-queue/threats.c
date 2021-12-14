//
// Created by USER on 05/12/2021.
//

#include "threats.h"

#define FACTOR 3
#define ILLEGAL -1


bool included(int *res, int node_index, int place) {
    for (int i = 0; i < place; ++i) {
        if (res[i] == node_index) {
            return true;
        }
    }
    return false;
}

bool threat(int node_index, int graph[][N], int place) {
    for (int i = 1; i <= FACTOR; ++i) {
        if (place >= i && graph[place - i][node_index]) {
            return true;
        }
    }
    return false;
}

bool valid(int graph[][N], int *res, int node_index, int place) {
    if (included(res, node_index, place)) {
        return false;
    }

    if (threat(node_index, graph, place)) {
        return false;
    }
    return true;
}

bool solve(int graph[][N], int *res, int node_index, int place) {
    if (place == N) {
        return true;
    }
    if (!valid(graph, res, node_index, place)) {
        return false;
    }
    res[place] = node_index;
    for (int i = 0; i < N; ++i) {
        if (solve(graph, res, i, place + 1)) {
            return true;
        }
    }
    res[place] = ILLEGAL;
    return false;
}

bool orderQueue(int threats[][N], int *queue) {
    return solve(threats, queue, 0, 0);
}