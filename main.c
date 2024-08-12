#include <stdio.h>
#include <ctype.h>
#include <math.h>
//THIS PROGRAM CAN SOLVE THE SQUARE EQUATION

void getdigit(int * num);

int main(void){

    double a, b, c;
    double d;
    double x1, x2;
    printf("|Square Equation Solver|\n");
    printf("Enter a:_____\b\b\b\b\b");
    getdigit(&a);
    printf("Enter b:_____\b\b\b\b\b");
    getdigit(&b);
    printf("Enter c:_____\b\b\b\b\b");
    getdigit(&c);

    printf("Your equation is: %.1lfx^2%+.1lfx%+.1lf\n", a, b, c);

    d = pow(b, 2) - 4 * a * c;
    if (d > 0) 
    {
        x1 = ((-b + sqrt(d)) / (2 * a)); x2 = ((-b - sqrt(d)) / (2 * a));
        printf("x1 = %.1lf\nx2 = %.1lf", x1, x2);
    }
    else if (d == 0)
    {
        x1 = (-b / (2 * a));
        printf("x = %.1lf", x1);
    }

    else if (d < 0)
    {
        printf("No solutions.");
    }
    









    return 0;
}



void getdigit(int * num)
{
    while (scanf("%lf", num) != 1)
    {
        char ch;
        
        while (ch = getchar() != '\n'){}
        printf("NOT INTEGER!\n");
    }
    
    
}


