#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 2
//THIS PROGRAM CAN SOLVE THE SQUARE EQUATION

void get_number(double * num);
void equation_solver(double a, double b, double c, double * x1, double * x2);

int main(void){

    double a = 0, b = 0, c = 0;

    double x1 = 0, x2 = 0;
    printf("|Square Equation Solver|\n");
    printf("Enter a:_____\b\b\b\b\b");
    get_number(&a);
    printf("Enter b:_____\b\b\b\b\b");
    get_number(&b);
    printf("Enter c:_____\b\b\b\b\b");
    get_number(&c);

    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", a, b, c);
    equation_solver(a, b, c, &x1, &x2);
    double array[SIZE] = {x1, x2};

    for (int i = 0; i < 2; i++){
        if (array[i] != NULL){printf("x = %.1lf\n", array[i]);}


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


void equation_solver(double a, double b, double c, double * x1, double * x2)
{
    double d = 0;

    d = pow(b, 2) - 4 * a * c;
    if (d > 0)
    {
        *x1 = ((-b + sqrt(d)) / (2 * a)); *x2 = ((-b - sqrt(d)) / (2 * a));
    }
    else if (d == 0)
    {
        *x1 = (-b / (2 * a));
        *x2 = NULL;
    }

    else if (d < 0)
    {
        *x1 = NULL; *x2 = NULL;

   }
}


