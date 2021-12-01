//
// Created by USER on 30/11/2021.
//

#include "coloringProblem.h"
#include "iostream"

#define CONNECTED 1

GraphColoring::GraphColoring(const std::vector<std::vector<int>> &graph, int _num_of_colors) : graph_matrix(graph), num_of_colors(_num_of_colors) {
    colors.resize(graph_matrix.size());
}

int GraphColoring::operator()() {
    if (solve(0)) {
        printResult();
        std::cout<<std::endl;
        return true;
    } else {
        std::cout << "No solution" << std::endl;
    }
    return false;
}

bool GraphColoring::solve(size_t node_index) {
    //if we considered all the nodes in the graph and assign all colors we done
    if (node_index == graph_matrix.size()) {
        return true;
    }
    // try all colors
    for (int color_index = 1; color_index <= num_of_colors; ++color_index) {
        //check if given color valid
        if (colorValid(node_index, color_index)) {
            colors[node_index] = color_index;
            if (solve(node_index + 1)) {
                return true;
            }
        }
    }
    return false;
}

void GraphColoring::printResult() {
    for (size_t i = 0; i < graph_matrix.size(); i++) {
        std::cout << " Node " << (i + 1) << " has color index " << colors[i]<<std::endl;
    }
}

bool GraphColoring::colorValid(size_t node_index, size_t color_index) {
    for (size_t i = 0; i < graph_matrix.size(); ++i) {
        if (graph_matrix[node_index][i] == CONNECTED && color_index == colors[i]) {
            return false;
        }
    }
    return true;
}