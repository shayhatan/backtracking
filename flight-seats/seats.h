//
// Created by USER on 03/12/2021.
//

#ifndef SEATS_H
#define SEATS_H

#include <stdbool.h>

#define N 4
#define OPTIONS 2

bool seatValid(int *res, int node_index, int seat_num);

bool solve(int preferences[N][OPTIONS], int *res, int node_index);

bool findSeats(int preferences[N][OPTIONS], int res[N]);

#endif //SEATS_H
