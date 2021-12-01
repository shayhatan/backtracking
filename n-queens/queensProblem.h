//
// Created by USER on 29/11/2021.
//

#ifndef BACKTRACKING_QUEENSPROBLEM_H
#define BACKTRACKING_QUEENSPROBLEM_H

#include <vector>

class QueensProblem {
    std::vector<std::vector<int>> board;
    int num_of_queens;
public:
    explicit QueensProblem(int _num_of_queens);

    void solve();

private:
    bool setQueens(int col_index);

    bool placeValid(int row, int col);

    void printQueens() const;
};

#endif //BACKTRACKING_QUEENSPROBLEM_H
