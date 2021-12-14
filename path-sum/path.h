//
// Created by USER on 05/12/2021.
//

#ifndef PATH_H
#define PATH_H

#include <stdbool.h>

#define USED 1
#define UNUSED 0
// N can get any value, 5 is just an example
#define N 4
#define OPTIONS 4


bool initialize_path(int path[][N]);

bool findPathSum(int math[][N], int sum, int path[][N]);

bool solve(int math[][N], int sum, int path[][N], int row, int col,int x_moves[OPTIONS],int y_moves[OPTIONS]);

bool moveValid(int math[][N], int sum, int path[][N], int row_index, int col_index);

bool boundsValid(int row, int col);





#endif PATH_H