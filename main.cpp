#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <assert.h>
//THIS PROGRAM CAN SOLVE THE SQUARE EQUATION

const int INF_SOLUTIONS = -1;
const double eps = 10e-8;

int get_number(double * num);
int solve_square_equation(double a, double b, double c, double * x1, double * x2);
int solve_linear_equation(double a, double b, double * x1);
int is_null(double num);
double discriminant(double a, double b, double c);
void root(int root_number, double x1, double x2);
void enter_numbers(double * a, double * b, double * c);

int main(void){

    double a = NAN, b = NAN, c = NAN;
    int root_number = 0;

    double x1 = 0, x2 = 0;

    enter_numbers(&a, &b, &c);

    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", a, b, c);
    root_number = solve_square_equation(a, b, c, &x1, &x2);

    root(root_number, x1, x2);

    return 0;
}


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
        if (empty = getchar() != '\n')
        {
            printf("NOT A NUMBER!\n");
            get_number(num);
        }
    }

    return 0;
}


int solve_square_equation(double a, double b, double c, double * x1, double * x2)
{

    assert(x1 != NULL);
    assert(x2 != NULL);

    if (is_null(a))
    {
        return solve_linear_equation(b, c, x1);
    }

    double d = discriminant(a, b, c);
    if (d > 0)
    {
        double sqrt_d = sqrt(d);
        *x1 = ((-b + sqrt_d) / (2 * a));
        *x2 = ((-b - sqrt_d) / (2 * a));
        return 2;
    }
    else if (is_null(d))
    {
        *x1 = (-b / (2 * a));
        return 1;
    }
    return 0;
}


int solve_linear_equation(double a, double b, double * x)
{

    assert(x != NULL);
    if (is_null(a))
    {
        if (is_null(b)) {return INF_SOLUTIONS;}
        return 0;
    }

    *x = -b/a;
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


void root(int root_number, double x1, double x2)
{
    assert(isfinite(x1));
    assert(isfinite(x2));

     switch(root_number)
    {
        case 0:
        printf("No solutions.");
        break;

        case 1:
        printf("x = %lf", x1);
        break;

        case 2:
        printf("x1 = %lf\nx2 = %lf", x1, x2);
        break;

        case INF_SOLUTIONS:
        printf("Infinite number of solutions.");
        break;

        default:
        assert(0);
        break;
    }
}

void enter_numbers(double * a, double * b, double * c)
{
    char check = 0;
    printf("|Square Equation Solver|\n");
    printf("Enter a:_____\b\b\b\b\b");
    if ((check = get_number(a)) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    printf("Enter b:_____\b\b\b\b\b");
    if (check = get_number(b) == EXIT_FAILURE){exit(EXIT_FAILURE);}
    printf("Enter c:_____\b\b\b\b\b");
    if (check = get_number(c) == EXIT_FAILURE){exit(EXIT_FAILURE);}
}
