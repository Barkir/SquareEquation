/** @file **/

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "header/solve_equation.h"
#include "header/constants_structures.h"

double discriminant(double a, double b, double c)
{
    return (b * b) - (4 * a * c);
}

int is_null(double a)
{
    return fabs(a) < eps;
}

int is_equal(double num1, double num2)
{
    return fabs(num1 - num2) <= eps;
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

        roots.x1 = k1 - k2;
        roots.x2 = k1 + k2;

        if (roots.x1 > roots.x2) {interchange(&roots.x1, &roots.x2);}
        roots.root_amount = TWO_ROOTS;
    }
    else if (is_null(d))
    {
        roots.x1 = (-coefs.b / (2 * coefs.a));
        roots.x2 = 0;
        roots.root_amount = ONE_ROOT;
    }
    else
    {
        roots.x1 = 0;
        roots.x2 = 0;
        roots.root_amount = NO_ROOTS;
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
        if (is_null(coefs.c))
        {
            roots.x1 = 0;
            roots.x2 = 0;
            roots.root_amount = INF_SOLUTIONS;
        }
        else{roots.root_amount = NO_ROOTS;}
    }
    else
    {
        roots.x1 = (-coefs.c)/(coefs.b);
        roots.root_amount = ONE_ROOT;
    }
    return roots;
}

// INTERCHANGE THE VALUE OF X1 and X2
void interchange(double * x1, double * x2)
{
    double temp = 0;
    temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}
