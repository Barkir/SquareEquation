#include <stdio.h>
#include <math.h>

#include "testing.h"
#include "solve_equation.h"
#include "constants_structures.h"
#include "tests.h"
#include "colors.h"
#include "input_output.h"

int test_init(int test_n, struct equation coefs, struct solution roots_exp)
{
    struct solution roots = solve_square_equation(coefs);
    if ((!is_equal(roots_exp.x1, roots.x1)) || (!is_equal(roots_exp.x2, roots.x2)) || (roots_exp.root_amount != roots.root_amount))
    {
        printf("Test %d. a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, root_amount = %d\n"
                "Expected: x1 = %lg, x2 = %lg, root_amount = %d\n",
                test_n, coefs.a, coefs.b, coefs.c, roots.x1, roots.x2, roots.root_amount,
                roots_exp.x1, roots_exp.x2, roots_exp.root_amount);
        return test_n;
    }
    printf(GREEN "Test %d passed!" RESET "\n", test_n);
    return 0;


}

int all_test_init()
{
    int right = 1;
    for (int i = 0; i < LENGTH; i++)
    {
        if (test_init(i + 1, all_coefs[i], all_roots[i])){right = 0;}
    }
    if (right)
    {
        printf(GREEN "TESTS PASSED!" RESET "\n");
        return right;
    }
    return right;
}

