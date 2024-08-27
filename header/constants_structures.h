/**
* @file constants_structures.h
*
* @brief a header file with all constants and structures
*/

#ifndef CONSTANTS_STRUCTURES_H
#define CONSTANTS_STRUCTURES_H

#include <math.h>
/**
* @param print_color macros for printing colorful text(not used)
* @param eps a very small value (used for working with double)
* @param TESTS_NUMBER a number of unit_tests
* @param flag_array_size a size of flag_array structure array
*/

#define print_color(COLOR, STRING, ...) printf(COLOR STRING RESET, __VA_ARGS__)
const double eps = 10e-3;
const int TESTS_NUMBER = 30;
const int flag_array_size = 3;


/**
* @brief structure for storing coefs (a, b, c)
* @param a first coef
* @param b second coef
* @param c third coef
*/

struct equation
{
    double a, b, c;
};

/**
* @brief structure for storing roots and their amount
* @param x1 first root
* @param x2 second root
* @param root_amount understandable? yes.
 */

struct solution
{
    double x1, x2;
    int root_amount;
};

/**
* @brief flag a structure for storing flags
* @param name a string for storing flag name
* @param code a string for storing flag code
*/

struct flag
{
    const char * name;
    int code;
};

/**
* @brief enum for storing number of roots
* @param INF_SOLUTIONS value for infinite solutions
* @param NO_ROOTS value for no solutions
* @param ONE_ROOT value for one root
* @param TWO_ROOTS value for two roots
 */

enum roots{
    INF_SOLUTIONS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

/**
* @brief enum for storing cmd flags
* @param CMD_DOC value for --doc flag
* @param CMD_HELP value for --help flag
* @param CMD_OUT value for --out flag
*/

enum operation
{
    CMD_DOC,
    CMD_HELP,
    CMD_OUT
};

/**
* @brief enum for cmd flag analyzing
* @param CMD_EXIT flag for exit (program exit after --doc, --help or other flag)
* @param CMD_CONTINUE value for flags that can be written before other flags
* @param CMD_RET start value
*/

enum analyze_output
{
    CMD_EXIT,
    CMD_CONTINUE,
    CMD_ERROR,
    CMD_RET
};

enum enum_colors
{
    COLOR_PRINT_RED,
    COLOR_PRINT_GREEN,
    COLOR_PRINT_YELLOW,
    COLOR_PRINT_BLUE,
    COLOR_PRINT_MAGENTA,
    COLOR_PRINT_CYAN,
    COLOR_PRINT_RESET
};

#endif


