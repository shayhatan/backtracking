//
// Created by USER on 05/12/2021.
//

#include "path.h"

bool boundsValid(int row, int col) {
    return (row >= 0 && row < N && col >= 0 && col < N);
}

bool moveValid(int math[][N], int sum, int path[][N], int row_index, int col_index) {

    if (!boundsValid(row_index, col_index)) {
        return false;
    }

    if (path[row_index][col_index] == true) {
        return false;
    }

    if (math[row_index][col_index] > sum) {
        return false;
    }
    return true;

}


bool findPathSum(int math[][N], int sum, int path[][N]) {
    initialize_path(path);
    int x_moves[OPTIONS] = {1, -1, 0, 0};
    int y_moves[OPTIONS] = {0, 0, 1, -1};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (solve(math, sum, path, i, j, x_moves, y_moves)) {
                return true;
            }
        }
    }
    return false;
}

bool initialize_path(int path[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            path[i][j] = false;
        }
    }
}

bool solve(int math[][N], int sum, int path[][N], int row, int col, int *x_moves, int *y_moves) {
    if (sum == 0) {
        return true;
    }
    if (!(moveValid(math, sum, path, row, col))) {
        return false;
    }
    path[row][col] = true;
    for (int i = 0; i < OPTIONS; ++i) {
        if (solve(math, sum - math[row][col], path, row + y_moves[i], col + x_moves[i], x_moves, y_moves)) {
            return true;
        }
    }
    path[row][col] = false;
    return false;
}


