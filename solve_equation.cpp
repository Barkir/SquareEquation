/**
* @file solve_equation.cpp
* @brief a file for solving a square equation

*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "header/solve_equation.h"
#include "header/constants_structures.h"

/**
* @brief a function for solving discriminant
* @param a first coef
* @param b second coef
* @param c third coef
* @return discriminant
*/

double discriminant(double a, double b, double c)
{
    return (b * b) - (4 * a * c);
}

/**
* @brief a function for comparing double number with null
 */

int is_null(double a)
{
    return fabs(a) < eps;
}

/**
* @brief a function for comparing two dobule numbers (equal or not?)
 */

int is_equal(double num1, double num2)
{
    return fabs(num1 - num2) <= eps;
}

int is_nan(double a)
{
    return (a >= 0.0) == (a < 0.0);
}

int is_finite(double a)
{
    return !(is_nan(a)) && (a > -DBL_MAX && a < DBL_MAX);
}

/**
* @brief a function for solving square equation
* @param coefs a stucture with coefs (a, b, c)
* @return a structure with roots and root amount (x1, x2, root_amount)
 */

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

/**
* @brief a function for solving a linear equation
* @param coefs a structure with coefs (a = 0, b, c)
* @return a structure with a root and root amount (x1, x2 = 0, root_amount)
 */

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
        else{
            roots.x1 = 0;
            roots.x2 = 0;
            roots.root_amount = NO_ROOTS;
            }
    }
    else
    {
        roots.x1 = (-coefs.c)/(coefs.b);
        roots.x2 = 0;
        roots.root_amount = ONE_ROOT;
    }
    return roots;
}

/**
* @brief a function for interchanging the values of two numbers
 */

// INTERCHANGE THE VALUE OF X1 and X2
void interchange(double * x1, double * x2)
{
    double temp = 0;
    temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}
