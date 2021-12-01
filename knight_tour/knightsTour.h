//
// Created by USER on 01/12/2021.
//

#ifndef KNIGHTS_TOUR_KNIGHTSTOUR_H
#define KNIGHTS_TOUR_KNIGHTSTOUR_H

#include <vector>
#include <array>

class KnightsTour {
    std::vector<std::vector<int>> board;

    //steps horizontally
    const static std::array<int, 8> x_moves;

    //steps vertically
    const static std::array<int, 8> y_moves;

    constexpr static int BOARD_SIZE = 8;
public:
    KnightsTour();

    void solveKnightTourProblem();


private:
    void initializeBoard();

    bool solveProblem(int step_count, int x, int y);

    bool moveValid(int x, int y);

    void printSolution();
};


#endif //KNIGHTS_TOUR_KNIGHTSTOUR_H
