#include <stdio.h>
#include <math.h>

//THIS PROGRAM CAN SOLVE THE SQUARE EQUATION

int get_number(double * num);
int equation_solver(double a, double b, double c, double * x1, double * x2);

int main(void){

    double a = 0, b = 0, c = 0;
    int cnt = 0;
    char check;

    double x1 = 0, x2 = 0;
    printf("|Square Equation Solver|\n");
    printf("Enter a:_____\b\b\b\b\b");
    if (check = get_number(&a) == EXIT_FAILURE){exit(1);}
    printf("Enter b:_____\b\b\b\b\b");
    if (check = get_number(&b) == EXIT_FAILURE){exit(1);}
    printf("Enter c:_____\b\b\b\b\b");
    if (check = get_number(&c) == EXIT_FAILURE){exit(1);}

    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", a, b, c);
    cnt = equation_solver(a, b, c, &x1, &x2);

    switch(cnt)
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

        case -1:
        printf("Infinite number of solutions.");
        break;
    }

    return 0;
}



int get_number(double * num)
{
    char empty = -1, eof_check = -1;
    while ((eof_check = scanf("%lf", num)) != 1)
    {
        if (eof_check == EOF){return EXIT_FAILURE;}
        while ((empty = getchar()) != '\n'){}
        printf("NOT A NUMBER!\n");
    }
    return 0;
}


int equation_solver(double a, double b, double c, double * x1, double * x2)
{
    double d = 0;
    const double eps = 10e-8;

    if (abs(a) <= eps)
    {
        if (abs(b) <= eps)
        {
            if (abs(c) <= eps){return -1;}
            else{return 0;}
        }
        else{*x1 = -c / b; return 1;}
    }

    d = (b*b) - 4 * a * c;
    if (d > 0)
    {
        double sqrt_d = sqrt(d);
        *x1 = ((-b + sqrt_d) / (2 * a)); *x2 = ((-b - sqrt_d) / (2 * a));
        return 2;
    }

    else if (abs(d) < eps)
    {*x1 = (-b / (2 * a)); return 1;}

    else if (d < 0){return 0;}
    return 0;
}
