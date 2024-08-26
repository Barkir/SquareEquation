/**
* @file main.cpp
* @brief main file in Square Equation
*/

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TXLib.h"
#include "header/constants_structures.h"
#include "header/input_output.h"
#include "header/solve_equation.h"
#include "header/testing.h"
#include "header/cmd_flag_structure.h"
#include "header/cmd.h"
#include "header/color_print.h"
#include "header/red_assert.h"

int main(int argc, char *argv[]){

    int ret = RET;

    for (int i = 1; i < argc; i++)
    {
        switch (ret = output_cmd(parse_cmd_args(argv[i], flag_array, flag_array_size)))
        {
            case CMD_EXIT:
                return CMD_EXIT;

            case CMD_CONTINUE:
                break;

            case CMD_ERROR:
                color_printf(stderr, COLOR_PRINT_RED, "This flag doesn't exist");
                return CMD_ERROR;

            default:
                color_printf(stderr, COLOR_PRINT_RED, "This flag doesn't exist");
                return EXIT_FAILURE;

        }

    }

    if (ret == CMD_CONTINUE) {return 0;}
    system("python test_generator.py");
    if (all_test_init("rnd_tests.txt"))
    {
        struct equation coefs = enter_numbers();
        color_printf(stdout, COLOR_PRINT_CYAN, "Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", coefs.a, coefs.b, coefs.c);
        struct solution roots = solve_square_equation(coefs);
        print_roots(roots);
    }

    return 0;
}
