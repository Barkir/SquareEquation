#include <stdio.h>

#include "constants_structures.h"
#include "input_output.h"
#include "solve_equation.h"
#include "testing.h"
#include "colors.h"

int main(void){

    if (all_test_init())
    {
        struct equation coefs = enter_numbers();
        printf(CYAN "Your equation is: %.1lfx^2%+.1lfx%+.1lf" RESET "\n", coefs.a, coefs.b, coefs.c);\
        struct solution roots = solve_square_equation(coefs);
        print_roots(roots);
    }

    return 0;
}
