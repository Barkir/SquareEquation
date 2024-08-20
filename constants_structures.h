#ifndef CONSTANTS_STRUCTURES_H
#define CONSTANTS_STRUCTURES_H

const int INF_SOLUTIONS = -1;
const double eps = 10e-8;

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
