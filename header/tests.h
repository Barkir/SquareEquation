/**
* @file tests.h
*
* @brief A file with test examples
*/

#ifndef TESTS_H
#define TESTS_H

const struct equation all_coefs[TESTS_NUMBER] =
{
//   A       B      C
    {0,      0,     0},
    {0,      0,     1},
    {0,      1,     0},
    {0,      2,     5},
    {0,      3,    -7},
    {1,      0,    -4},
    {1,      0,     4},
    {1,      0,    -3},
    {1,      5,    -6},
    {1,      4,     0},
    {1,     -4,     4},
    {2,      5,    -3},
    {3,     -6,     3},
    {4,      4,     1},
    {1,      3,     2},
    {2,     -8,     8},
    {-1,     2,    -1},
    {3,     -2,    -1},
    {1,     -5,     6},
    {2,      7,     3},
    {4,     -12,    9},
    {-2,     8,    -8},
    {1,      4,     4},
    {3,     -5,    -2},
    {-1,     3,    -2},
    {5,     -10,    5},
    {2,      1,    -3},
    {1,     -6,     9},
    {4,     -4,    -1},
    {-2,    -7,    -3}
};

const struct solution all_roots[TESTS_NUMBER] =
{
    {0,             0,              INF_SOLUTIONS},
    {0,             0,              NO_ROOTS},
    {0,             0,              ONE_ROOT},
    {-5./2,         0,              ONE_ROOT},
    {7./3,          0,              ONE_ROOT},
    {-2,            +2,             TWO_ROOTS},
    {0,             0,              NO_ROOTS},
    {-sqrt(3),      +sqrt(3),       TWO_ROOTS},
    {-6,            1,              TWO_ROOTS},
    {-4,            0,              TWO_ROOTS},
    {2,             0,              ONE_ROOT},
    {-3,            0.5,            TWO_ROOTS},
    {1,             0,              ONE_ROOT},
    {-0.5,          0,              ONE_ROOT},
    {-2,            -1,             TWO_ROOTS},
    {2,             0,              ONE_ROOT},
    {1,             0,              ONE_ROOT},
    {-1./3,         1,              TWO_ROOTS},
    {2,             3,              TWO_ROOTS},
    {-3,           -0.5,            TWO_ROOTS},
    {1.5,           0,              ONE_ROOT},
    {2,             0,              ONE_ROOT},
    {-2,            0,              ONE_ROOT},
    {-1./3,         2,              TWO_ROOTS},
    {1,             2,              TWO_ROOTS},
    {1,             0,              ONE_ROOT},
    {-1.5,          1,              TWO_ROOTS},
    {3,             0,              ONE_ROOT},
    {(1-sqrt(2))/2, (1+sqrt(2))/2,  TWO_ROOTS},
    {-3,            -0.5,           TWO_ROOTS}
};


struct equation txt_coefs[TESTS_NUMBER] = {};
struct solution txt_roots[TESTS_NUMBER] = {};
#endif
