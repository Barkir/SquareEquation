#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include "constants_structures.h"

double discriminant(double a, double b, double c);
int is_null(double a);
struct solution solve_square_equation(struct equation coefs);
struct solution solve_linear_equation(struct equation coefs);

#endif
