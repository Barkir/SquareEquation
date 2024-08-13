#include <stdio.h>
#include <ctype.h>
#include <math.h>

//THIS PROGRAM CAN SOLVE THE SQUARE EQUATION

void get_number(double * num);
int equation_solver(double a, double b, double c, double * x1, double * x2);

int main(void){

    double a = 0, b = 0, c = 0;
    int cnt = 0;

    double x1 = 0, x2 = 0;
    printf("|Square Equation Solver|\n");
    printf("Enter a:_____\b\b\b\b\b");
    get_number(&a);
    printf("Enter b:_____\b\b\b\b\b");
    get_number(&b);
    printf("Enter c:_____\b\b\b\b\b");
    get_number(&c);

    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", a, b, c);
    cnt = equation_solver(a, b, c, &x1, &x2);

    if (cnt == 0) {printf("No solutions.");}
    else if (cnt == 1) {printf("x = %.1lf", x1);}
    else if (cnt == 2) {printf("x1 = %.1lf\nx2 = %.1lf"), x1, x2;}





    return 0;
}



void get_number(double * num)
{
    while (scanf("%lf", num) != 1)
    {
        char ch;

        while (ch = getchar() != '\n'){}
        printf("NOT A NUMBER!\n");
    }


}


int equation_solver(double a, double b, double c, double * x1, double * x2)
{
    double d = 0;

    d = pow(b, 2) - 4 * a * c;
    if (d > 0)
    {
        *x1 = ((-b + sqrt(d)) / (2 * a)); *x2 = ((-b - sqrt(d)) / (2 * a));
        return 2;
    }
    else if (d == 0)
    {
        *x1 = (-b / (2 * a));
        return 1;
    }

    else if (d < 0)
    {
        return 0;

   }
}


