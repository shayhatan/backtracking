//
// Created by USER on 03/12/2021.
//

#include "seats.h"

#define EMPTY -1;

bool seatValid(int *res, int node_index, int seat_num) {

    for (int i = 0; i < node_index; ++i) {
        if (res[i] == seat_num) {
            return false;
        }
    }
    return true;

}


bool solve(int preferences[N][OPTIONS], int *res, int node_index) {
    if (node_index == N) {

        return true;
    }
    for (int option_index = 0; option_index < OPTIONS; ++option_index) {
        if (seatValid(res, node_index, preferences[node_index][option_index])) {
            res[node_index] = preferences[node_index][option_index];
            if (solve(preferences, res, node_index + 1)) {
                return true;
            }
        }
    }
    return false;
}

bool findSeats(int preferences[N][OPTIONS], int res[N]) {
    return solve(preferences, res, 0);
}

//bool find_path_sum(int mat[][N]);