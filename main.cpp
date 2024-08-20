#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <assert.h>
//THIS PROGRAM CAN SOLVE THE SQUARE EQUATION

const int INF_SOLUTIONS = -1;
const double eps = 10e-8;

struct solution solve_square_equation(struct equation coefs);
struct solution solve_linear_equation(struct equation coefs);
struct equation enter_numbers();
int get_number(double * num);
int is_null(double num);
double discriminant(double a, double b, double c);
void print_roots(struct solution coefs);

struct equation
{
    double a, b, c;
};


struct solution
{
    double x1, x2;
    int root_amount;
};


int main(void){


    struct equation coefs = enter_numbers();
    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", coefs.a, coefs.b, coefs.c);\
    struct solution roots = solve_square_equation(coefs);
    print_roots(roots);

    return 0;
}


// GETS A NUMBER AND RETURNS IT INTO NUM BY ADDRESS
int get_number(double * num)
{
    assert(num != NULL);

    char empty = -1, eof_check = -1;

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
            get_number(num);
        }
    }

    return 0;
}


// SOLVES A SQUARE EQUATION
struct solution solve_square_equation(struct equation coefs)
{

    struct solution roots;

    assert(&roots.x1 != NULL);
    assert(&roots.x2 != NULL);

    if (is_null(coefs.a))
    {
        return solve_linear_equation(coefs);
    }

    double d = discriminant(coefs.a, coefs.b, coefs.c);
    if (d > 0)
    {
        double sqrt_d = sqrt(d);

        double k1 = -(coefs.b) / (2 * coefs.a);
        double k2 = (sqrt_d) / (2 * coefs.a);

        roots.x1 = k1 + k2;
        roots.x2 = k1 - k2;
        roots.root_amount = 2;
    }
    else if (is_null(d))
    {
        roots.x1 = (-coefs.b / (2 * coefs.a));
        roots.root_amount = 1;
    }
    else
    {
        roots.root_amount = 0;
    }
    return roots;
}


// SOLVES A LINEAR EQUATION
struct solution solve_linear_equation(struct equation coefs)
{


    struct solution roots;

    assert(&roots.x1 != NULL);
    if (is_null(coefs.b))
    {
        if (is_null(coefs.c)) {roots.root_amount = INF_SOLUTIONS;}
        else{roots.root_amount = 0;}
    }
    else
    {
        roots.x1 = -(coefs.c)/(coefs.b);
        roots.root_amount = 1;
    }
    return roots;
}


int is_null(double a)
{
    return fabs(a) < eps;
}

double discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}


void print_roots(struct solution roots)
{
    assert(isfinite(roots.x1));
    assert(isfinite(roots.x2));

    switch(roots.root_amount)
    {
        case 0:
            printf("No solutions.");
            break;

        case 1:
            printf("x = %lf", roots.x1);
            break;

        case 2:
            printf("x1 = %lf\nx2 = %lf", roots.x1, roots.x2);
            break;

        case INF_SOLUTIONS:
            printf("Infinite number of solutions.");
            break;

        default:
            assert(0);
            break;
    }
}

struct equation enter_numbers()
{
    struct equation coefs;
    char check = 0;
    printf("|Square Equation Solver|\n");
    printf("Enter a:_____\b\b\b\b\b");
    if (check = get_number(&(coefs.a)) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    printf("Enter b:_____\b\b\b\b\b");
    if (check = get_number(&(coefs.b)) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    printf("Enter c:_____\b\b\b\b\b");
    if (check = get_number(&(coefs.c)) == EXIT_FAILURE){exit(EXIT_FAILURE);}

    return coefs;
}
