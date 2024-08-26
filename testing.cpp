/**
* @file testing.cpp
* @brief a file with functions to do unit-tests
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "header/testing.h"
#include "header/solve_equation.h"
#include "header/constants_structures.h"
#include "header/tests.h"
#include "header/input_output.h"
#include "header/color_print.h"

/**
* @brief a function for running a single test
* @param test_n a number of a test
* @param coefs a stucture with coefs (a, b, c)
* @param roots_exp a structure with expected roots
* @return test_n if failed, 0 if success
 */


// INIT OF A SINGLE TEST
int test_init(int test_n, struct equation coefs, struct solution roots_exp)
{
    struct solution roots = solve_square_equation(coefs);
    if ((!is_equal(roots_exp.x1, roots.x1)) || (!is_equal(roots_exp.x2, roots.x2)) || (roots_exp.root_amount != roots.root_amount))
    {
        color_printf(stdout, COLOR_PRINT_RED, "Test %d. a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, root_amount = %d\n"
                "Expected: x1 = %lg, x2 = %lg, root_amount = %d\n",
                test_n, coefs.a, coefs.b, coefs.c, roots.x1, roots.x2, roots.root_amount,
                roots_exp.x1, roots_exp.x2, roots_exp.root_amount);
        return test_n;
    }
    color_printf(stdout, COLOR_PRINT_GREEN, "Test %d passed!\n", test_n);
    color_printf(stdout, COLOR_PRINT_GREEN, "a = %lg, b = %lg, c = %lg "
                                            "x1 = %lg, x2 = %lg, root_amount = %d\n",
                                            coefs.a, coefs.b, coefs.c,
                                            roots.x1, roots.x2, roots.root_amount);
    return 0;


}


/**
* @brief a function for running all tests
* @return 1 if all tests passed, 0 if failed
 */

// INIT OF ALL TESTS
int all_test_init(const char * file_name)
{
    FILE * file = fopen(file_name, "r");
    int right = 1;
    int check = 0;
    int n_test = 1;

    do
    {
        struct equation coefs = {};
        fscanf(file, "%lf", &coefs.a);
        fscanf(file, "%lf", &coefs.b);
        fscanf(file, "%lf", &coefs.c);

        struct solution roots = {};
        fscanf(file, "%lf", &roots.x1);
        fscanf(file, "%lf", &roots.x2);
        fscanf(file, "%d", &roots.root_amount);

        if (test_init(n_test, coefs, roots)) {right = 0;}
        check = getc(file);
        n_test++;
    } while(check = getc(file) != EOF);
    if (right)
    {
        color_printf(stdout, COLOR_PRINT_GREEN, "TESTS PASSED!\n");
        return right;
    }

    fclose(file);
    return right;
}

