/**
* @file solve_equation.h
*
* @brief a header file for solve_equation.cpp
*/

#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

double discriminant(double a, double b, double c);
int is_null(double a);
int is_equal(double num1, double num2);
void interchange(double * x1, double * x2);
struct solution solve_square_equation(struct equation coefs);
struct solution solve_linear_equation(struct equation coefs);
int is_nan(double a);
int is_finite(double a);

#endif
