//
// Created by USER on 30/11/2021.
//

#ifndef COLORINGPROBLEM_H
#define COLORINGPROBLEM_H
#include <vector>

/*
    if we have k colors and want to assign colors to
    vertices in a G(V,E) graph then running time is O(k^v).
                                                                */

class GraphColoring {
    std::vector<std::vector<int>> graph_matrix;
    int num_of_colors;
    std::vector<int> colors;
public:
    GraphColoring(const std::vector<std::vector<int>> & graph , int _num_of_colors);

    int operator()();

private:
    // function to assign colors
    bool solve(size_t node_index);

    bool colorValid(size_t node_index, size_t color_index);

    void printResult();
};


#endif //COLORINGPROBLEM_H
