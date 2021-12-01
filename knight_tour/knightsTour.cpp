//
// Created by USER on 01/12/2021.
//

#include "knightsTour.h"
#include <iostream>

using std::vector;
using std::array;
using std::cout;
using std::endl;


//valid steps for the knight ( x_moves[i], y_moves[i] )  i = { 0, 1, 2, 3, 4, 5, 6, 7 }
const array<int, 8> KnightsTour::x_moves = {2, 1, -1, -2,
                                            -2, -1, 1, 2};

const array<int, 8> KnightsTour::y_moves = {1, 2, 2, 1,
                                            -1, -2, -2, -1};

KnightsTour::KnightsTour() {
    board.resize(BOARD_SIZE);
    for (auto &it: board) {
        it.resize(BOARD_SIZE);
    }
    initializeBoard();
}

void KnightsTour::solveKnightTourProblem() {
    //the knight start from (0,0)
    board[0][0] = 0;

    //no sol
    if (!solveProblem(1, 0, 0)) {
        cout << " No feasible solution found...";
    }
    printSolution();
}

void KnightsTour::initializeBoard() {
    //INT_MIN means the knight haven't step on that cell
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = INT_MIN;
        }
    }
}

bool KnightsTour::solveProblem(int step_count, int x, int y) {
    if (step_count == BOARD_SIZE * BOARD_SIZE) {
        return true;
    }
    for (size_t i = 0; i < x_moves.size(); ++i) {
        int next_x = x + x_moves[i];
        int next_y = y + y_moves[i];
        if (moveValid(next_x, next_y)) {
            board[next_x][next_y] = step_count;
            if (solveProblem(step_count + 1, next_x, next_y)) {
                return true;
            }
            board[next_x][next_y] = INT_MIN;
        }
    }
    return false;
}

bool KnightsTour::moveValid(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false;
    }
    if (board[x][y] != INT_MIN) {
        return false;
    }
    return true;
}

void KnightsTour::printSolution() {
    //INT_MIN means the knight haven't step on that cell
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if(board[i][j] < 10) {
                cout << "| " << board[i][j] << "  |";
            }else {
                cout << "| " << board[i][j] << " |";
            }
        }
        cout << endl;
    }
}




