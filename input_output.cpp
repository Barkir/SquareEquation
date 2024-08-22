#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "header/input_output.h"
#include "header/constants_structures.h"
#include "header/colors.h"

// GETS A NUMBER AND RETURNS IT INTO NUM BY ADDRESS
int get_number(double * num)
{
    assert(num != NULL);

    int empty = -1, eof_check = -1;

    while ((eof_check = scanf("%lf", num)) != 1)
    {
        if (eof_check == EOF){return EXIT_FAILURE;}
        while ((empty = getchar()) != '\n'){}
        printf("NOT A NUMBER!\n");
    }
    if (eof_check)
    {
        empty = getchar();
        while(empty == ' '){empty = getchar();}
        if (empty != '\n')
        {
            printf("NOT A NUMBER!\n");
            while ((empty = getchar()) != '\n'){}
            get_number(num);
        }
    }

    return 0;
}


struct equation enter_numbers()
{
    struct equation coefs;
    int check = -1;
    printf(YELLOW "|Square Equation Solver|" RESET "\n");
    printf(CYAN "Enter a:_____\b\b\b\b\b" RESET);
    if ((check = get_number(&(coefs.a))) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    printf(CYAN "Enter b:_____\b\b\b\b\b" RESET);
    if ((check = get_number(&(coefs.b))) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    printf(CYAN "Enter c:_____\b\b\b\b\b" RESET);
    if ((check = get_number(&(coefs.c))) == EXIT_FAILURE){exit(EXIT_FAILURE);}

    return coefs;
}


void print_roots(struct solution roots)
{
    assert(isfinite(roots.x1));
    assert(isfinite(roots.x2));

    switch(roots.root_amount)
    {
        case 0:
            printf(MAGENTA "No solutions." RESET);
            break;

        case 1:
            printf(MAGENTA "x = %lf" RESET, roots.x1);
            break;

        case 2:
            printf(MAGENTA "x1 = %lf\nx2 = %lf" RESET, roots.x1, roots.x2);
            break;

        case INF_SOLUTIONS:
            printf(MAGENTA "Infinite number of solutions." RESET);
            break;

        default:
            assert(0);
            break;
    }
}
