#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solve_equation.h"

double discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

int is_null(double a)
{
    return fabs(a) < eps;
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
