#include <stdio.h>

#include "input_output.h"
#include "solve_equation.h"

int main(void){

    struct equation coefs = enter_numbers();
    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", coefs.a, coefs.b, coefs.c);\
    struct solution roots = solve_square_equation(coefs);
    print_roots(roots);

    return 0;
}
