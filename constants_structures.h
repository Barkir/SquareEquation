#ifndef CONSTANTS_STRUCTURES_H
#define CONSTANTS_STRUCTURES_H

#include <math.h>

const int INF_SOLUTIONS = -1;
const int NO_ROOTS = 0;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const double eps = 10e-5;
const int TESTS_NUMBER = 30;

struct equation
{
    double a, b, c;
};

struct solution
{
    double x1, x2;
    int root_amount;
};

#endif
