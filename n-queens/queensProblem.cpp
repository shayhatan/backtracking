//
// Created by USER on 29/11/2021.
//
#include <iostream>
#include "queensProblem.h"

#define QUEEN 1
#define EMPTY 0

using std::cout;

QueensProblem::QueensProblem(int _num_of_queens) : num_of_queens(_num_of_queens) {
    board.resize(num_of_queens);
    for (auto &row : board) {
        row.resize(num_of_queens);
    }

}

void QueensProblem::solve() {
    if(setQueens(0)) {
        printQueens();
    }
}

bool QueensProblem::setQueens(int col) {
    //each column has a queen means N queens
    if (col == num_of_queens) {
        return true;
    }
    //check all rows
    for (int row = 0; row < num_of_queens; ++row) {
        //check if given location is valid
        if (placeValid(row, col)) {
            board[row][col] = QUEEN;

            if (setQueens(col + 1)) {
                return true;
            }
            //means we fail we have to back track moves
            board[row][col] = EMPTY;
        }
    }
    return false;
}

void QueensProblem::printQueens() const {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board.size(); ++j) {
            if (board[i][j] == QUEEN) {
                cout << "|Q|";
            } else {
                cout << "|_|";
            }
        }
        cout << std::endl;
    }

}

bool QueensProblem::placeValid(int row, int col) {
    // cant be in the same row
    for (int j = 0; j < num_of_queens; j++) {
        if (board[row][j] == QUEEN) {
            return false;
        }
    }
    //check diag - top left to bottom right diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == QUEEN) {
            return false;
        }
    }

    //check diag - top right to bottom left diagonal
    for (int i = row, j = col; i < num_of_queens && j >= 0; i++, j--) {
        if (board[i][j] == QUEEN) {
            return false;
        }
    }
    return true;

}


