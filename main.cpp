#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TXLib.h"
#include "constants_structures.h"
#include "input_output.h"
#include "solve_equation.h"
#include "testing.h"
#include "colors.h"
#include "cmd_flag_structure.h"

int main(int argc, char *argv[]){

    int ret = -1;

    for (int i = 1; i < argc; i++)
    {
        switch (ret = output_cmd(parse_cmd_args(argv[i], flag_array, flag_array_size)))
        {
            case EXIT:
            return EXIT;

            case CONTINUE:
            break;

            default:
            break;

        }

    }

    if (!ret) {return 0;}



    if (all_test_init())
    {
        struct equation coefs = enter_numbers();
        printf(CYAN "Your equation is: %.1lfx^2%+.1lfx%+.1lf" RESET "\n", coefs.a, coefs.b, coefs.c);\
        struct solution roots = solve_square_equation(coefs);
        print_roots(roots);
    }

    return 0;
}
