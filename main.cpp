#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <assert.h>
//THIS PROGRAM CAN SOLVE THE SQUARE EQUATION

const int INF_SOLUTIONS = -1;
const double eps = 10e-8;

int get_number(double * num);
int solve_square_equation(struct equation * coefs, struct solution * roots);
int solve_linear_equation(struct equation * coefs, struct solution * roots);
int is_null(double num);
double discriminant(double a, double b, double c);
void root(struct solution coefs);
void enter_numbers(struct equation * coefs);

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

    struct equation coefs;
    struct solution roots;

    enter_numbers(&coefs);

    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", coefs.a, coefs.b, coefs.c);
    roots.root_amount = solve_square_equation(&coefs, &roots);

    root(roots);

    return 0;
}


int get_number(double * num)
{
    //GETS A NUMBER AND RETURNS IT INTO NUM BY ADDRESS

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
        if (empty = getchar() != '\n')
        {
            printf("NOT A NUMBER!\n");
            get_number(num);
        }
    }

    return 0;
}


int solve_square_equation(struct equation * coefs, struct solution * roots)
{

    // SOLVES A SQUARE EQUATION

    assert(&roots -> x1 != NULL);
    assert(&roots -> x2 != NULL);

    if (is_null(coefs -> a))
    {
        return solve_linear_equation(coefs, roots);
    }

    double d = discriminant(coefs -> a, coefs -> b, coefs -> c);
    if (d > 0)
    {
        double sqrt_d = sqrt(d);

        double k1 = -(coefs -> b) / (2 * coefs -> a);
        double k2 = (sqrt_d) / (2 * coefs -> a);

        roots -> x1 = k1 + k2;
        roots -> x2 = k1 - k2;
        return 2;
    }
    else if (is_null(d))
    {
        roots -> x1 = (-coefs -> b / (2 * coefs -> a));
        return 1;
    }
    return 0;
}


int solve_linear_equation(struct equation * coefs, struct solution * roots)
{

    // SOLVES A LINEAR EQUATION

    assert(&roots -> x1 != NULL);
    if (is_null(coefs -> a))
    {
        if (is_null(coefs -> b)) {return INF_SOLUTIONS;}
        return 0;
    }

    roots -> x1 = -(coefs -> b)/(coefs -> a);
    return 1;
}


int is_null(double a)
{
    return fabs(a) < eps;
}

double discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}


void root(struct solution roots)
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

void enter_numbers(struct equation * coefs)
{
    char check = 0;
    printf("|Square Equation Solver|\n");
    printf("Enter a:_____\b\b\b\b\b");
    if (check = get_number(&(coefs -> a)) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    printf("Enter b:_____\b\b\b\b\b");
    if (check = get_number(&(coefs -> b)) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    printf("Enter c:_____\b\b\b\b\b");
    if (check = get_number(&(coefs -> c)) == EXIT_FAILURE){exit(EXIT_FAILURE);}
}
