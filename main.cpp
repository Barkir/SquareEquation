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
#include "header/color_printf.h"
#include "header/red_assert.h"

int main(int argc, char *argv[]){
    // TODO: conditional compilation
    int ret = CMD_RET;                                                                  // Start value of ret

    for (int i = 1; i < argc; i++)
    {
        switch (ret = output_cmd(parse_cmd_args(argv[i], flag_array, flag_array_size))) // Command line flags analyzing
        {
            case CMD_EXIT:
                return CMD_EXIT;

            case CMD_CONTINUE:
                break;

            case CMD_ERROR:
                color_printf(stderr, COLOR_PRINT_RED, "This flag doesn't exist");
                return CMD_ERROR;

            default:
                color_printf(stderr, COLOR_PRINT_RED, "Something went wrong...");
                return EXIT_FAILURE;
        }
    }
    red_assert(0, "error");
    if (ret == CMD_CONTINUE) {return 0;}
    system("python test_generator.py");                                             // Writes random tests in rnd_tests.txt
    if (all_test_init("rnd_tests.txt"))                                             // Checks the tests
    {
        struct equation coefs = enter_numbers();                                    // Enter three coefficients (a, b, c)
        color_printf(stdout, COLOR_PRINT_CYAN, "Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", coefs.a, coefs.b, coefs.c);
        struct solution roots = solve_square_equation(coefs);                       // Solving the equation
        print_roots(roots);                                                         // Print roots
    }

    return 0;
}
