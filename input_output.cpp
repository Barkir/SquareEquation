/**
* @file input_output.cpp
* @brief .cpp file with functions for user input/output while running a program
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "header/input_output.h"
#include "header/constants_structures.h"
#include "header/color_print.h"

/**
* @brief function for getting a number from user
* @param num pointer for coef (a, b, c)
* @return EXIT_FAILURE if EOF 0 if success
 */

// GETS A NUMBER AND RETURNS IT INTO NUM BY ADDRESS
int get_number(double * num)
{
    assert(num != NULL);

    int empty = -1, eof_check = -1;
    const char * eof = "END OF FILE";

    while ((eof_check = scanf("%lf", num)) != 1)
    {
        if (eof_check == EOF){
        for (int i = 0; eof[i] != '\0'; i++)
        {
            fprintf(stderr, "%s%c%s", choose_color(COLOR_PRINT_RED), eof[i], choose_color(COLOR_PRINT_RESET));
        }
        return EXIT_FAILURE;
        }
        while ((empty = getchar()) != '\n'){}
        printf("NOT A NUMBER!\n");
    }
    if (eof_check)
    {
        empty = getchar();
        while(empty == ' '){empty = getchar();}
        if (empty != '\n')
        {
            color_print(stderr, COLOR_PRINT_RED, "NOT A NUMBER!\n");
            while ((empty = getchar()) != '\n'){}
            get_number(num);
        }
    }

    return 0;
}

/**
* @brief a function for entering coefs
* @return structure with coefs (a, b, c)
 */

// ENTER A NUMBER
struct equation enter_numbers()
{
    struct equation coefs;
    int check = -1;
    color_print(stdout, COLOR_PRINT_YELLOW, "|Square Equation Solver|\n");
    color_print(stdout, COLOR_PRINT_CYAN, "Enter a:_____\b\b\b\b\b");
    if ((check = get_number(&(coefs.a))) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    color_print(stdout, COLOR_PRINT_CYAN, "Enter b:_____\b\b\b\b\b");
    if ((check = get_number(&(coefs.b))) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    color_print(stdout, COLOR_PRINT_CYAN, "Enter c:_____\b\b\b\b\b");
    if ((check = get_number(&(coefs.c))) == EXIT_FAILURE){exit(EXIT_FAILURE);}

    return coefs;
}

/**
* @brief function for printing roots
* @param roots structure with roots
 */

// PRINTS ALL ROOTS
void print_roots(struct solution roots)
{
    assert(isfinite(roots.x1));
    assert(isfinite(roots.x2));

    switch(roots.root_amount)
    {
        case 0:
            color_print(stdout, COLOR_PRINT_MAGENTA ,"No solutions.");
            break;

        case 1:
            color_print(stdout, COLOR_PRINT_MAGENTA, "x = %lf", roots.x1);
            break;

        case 2:
            color_print(stdout, COLOR_PRINT_MAGENTA, "x1 = %lf\nx2 = %lf", roots.x1, roots.x2);
            break;

        case INF_SOLUTIONS:
            color_print(stdout, COLOR_PRINT_MAGENTA, "Infinite number of solutions.");
            break;

        default:
            assert(0);
            break;
    }
}
