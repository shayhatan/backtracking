//
// Created by USER on 07/12/2021.
//

#ifndef BURN_H
#define BURN_H

#include <stdbool.h>


#define N 4

/*
    This kind of backtracking (best solution) is the most difficult to get
    the catch is to consider  sol with and without curr and comparing each junction
                                                                                        */
int solve(int *sizes, int index, int space, bool chosen[]);

bool cmpSpace(int space1, int space2);

int bestBurn(int* sizes, int space, int* res);

void initializeResult(int *res);

void fillResult(int *res, int *sizes, bool chosen[]);

void printResult(int *res);

#endif //BURN_H
