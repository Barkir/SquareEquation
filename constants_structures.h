#ifndef CONSTANTS_STRUCTURES_H
#define CONSTANTS_STRUCTURES_H

#include <math.h>

const double eps = 10e-5;
const int TESTS_NUMBER = 30;
const int flag_array_size = 3;

struct equation
{
    double a, b, c;
};

struct solution
{
    double x1, x2;
    int root_amount;
};

struct flag
{
    const char * name;
    int code;
};

enum roots{
    INF_SOLUTIONS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

enum operation
{
    CMD_DOC,
    CMD_HELP,
    CMD_OUT
};

enum analyze_output
{
    EXIT,
    CONTINUE
};

#endif


