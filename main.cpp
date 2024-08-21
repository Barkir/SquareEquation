#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants_structures.h"
#include "input_output.h"
#include "solve_equation.h"
#include "testing.h"
#include "colors.h"
#include "cmd_flags.h"

int main(int argc, char *argv[]){

    if (argc == 2 && strcmp(argv[1], "--doc") == 0)
    {
    printf("%s", doc);
    return 0;
    }

    if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
    printf("%s", help);
    return 0;
    }



    if (all_test_init())
    {
        struct equation coefs = enter_numbers();
        printf(CYAN "Your equation is: %.1lfx^2%+.1lfx%+.1lf" RESET "\n", coefs.a, coefs.b, coefs.c);\
        struct solution roots = solve_square_equation(coefs);
        print_roots(roots);
    }

    return 0;
}
