#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define TWO 2
#define ONE 1
//THIS PROGRAM CAN SOLVE THE SQUARE EQUATION

void get_number(double * num);
double * equation_solver(double a, double b, double c);

int main(void){

    double a = 0, b = 0, c = 0;
    double * array;

    double x1 = 0, x2 = 0;
    printf("|Square Equation Solver|\n");
    printf("Enter a:_____\b\b\b\b\b");
    get_number(&a);
    printf("Enter b:_____\b\b\b\b\b");
    get_number(&b);
    printf("Enter c:_____\b\b\b\b\b");
    get_number(&c);

    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", a, b, c);
    array = equation_solver(a, b, c);
    for (int i = 0; array[i] != '\0'; i++){
        printf("x = %.1lf\n", array[i]);
    }

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


double * equation_solver(double a, double b, double c)
{
    double d = 0;
    double x1 = 0, x2 = 0;

    d = pow(b, 2) - 4 * a * c;
    if (d > 0)
    {
        static double array[TWO];
        x1 = ((-b + sqrt(d)) / (2 * a)); x2 = ((-b - sqrt(d)) / (2 * a));
        array[0] = x1; array[1] = x2;
        return array;
    }
    else if (d == 0)
    {
        static double array[ONE];
        x1 = (-b / (2 * a));
        array[0] = x1;
        return array;
    }

    else if (d < 0)
    {
        static double array[ONE];
        array[0] = NULL;
        return array;

   }
}


