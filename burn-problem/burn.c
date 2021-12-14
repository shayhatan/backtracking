//
// Created by USER on 07/12/2021.
//

#include "burn.h"
#include <stdio.h>


int solve(int *sizes, int index, int space, bool *chosen) {
    int space1, space2;
    if (index == N) {
        return space;
    }
    //the best possible we must return!
    if (space == 0) {
        for (int i = index; i < N; ++i) {
            chosen[i] = false;
        }
        return 0;
    }
    chosen[index] = false;
    // curr not be included in order to consider all options
    space1 = solve(sizes, index + 1, space, chosen);
    if (sizes[index] <= space) {
        bool chosen2[N];
        chosen2[index] = true;
        space2 = solve(sizes, index + 1, space - sizes[index], chosen2);
        if (cmpSpace(space2, space1)) {
            for (int i = index; i < N; ++i) {
                chosen[i] = chosen2[i];
            }
            return space2;
        }
    }
    return space1;
}

bool cmpSpace(int space1, int space2) {
    return space1 < space2;
}

int bestBurn(int *sizes, int space, int *result) {
    bool chosen[N];
    initializeResult(result);
    int space_left = solve(sizes, 0, space, chosen);
    fillResult(result, sizes, chosen);
    return space_left;

}

void initializeResult(int *res) {
    for (int i = 0; i < N; ++i) {
        res[i] = 0;
    }
}

void fillResult(int *res, int *sizes, bool chosen[]) {
    int index = 0;
    for (int i = 0; i < N; ++i) {
        if (chosen[i]) {
            res[index++] = sizes[i];
        }
    }
}

void printResult(int *res) {
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", res[i]);
    }
}
