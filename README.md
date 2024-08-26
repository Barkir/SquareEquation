[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Fira+Code&pause=1000&color=6C7AF7&width=435&lines=This+is+a+square+equation+solver)](https://git.io/typing-svg)

# Let's start 🧑‍🚀️
  ### This is a simple equation solver. It is the main task on MIPT Summer School for freshmen 🙋 <br />
  This program asks for three coefficients of a square equation _(a, b, c)_ <br />
  You cannot enter words or any symbols, the program will only count a double number

# How to compile
  1. Clone the repository to your PC
  2. Enter ```make -B release``` in command line
  3. The program will create a binary file called ```release.exe```
  4. Enter ```release``` in command line
  5. Done! The program is running.
## Next steps
The program will ask you to enter three coefficients (must be a double number) (e.g:  ```Enter a:_____```) <br />
When you enter the coefficients the program will run this code <br />
```
struct solution solve_linear_equation(struct equation coefs)
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
```
This function creates a struct of roots out of coefs structure solving the square equation <sub> (or a linear equation if a = 0) </sub> <br />
Then the program writes the roots of the equation! <sup>👏👏👏</sup>

# Other interesting features
In this program you can also see such files as ```color_print.cpp``` or ```red_assert.cpp``` <br />
Judging by filenames we can guess that it's our own color print module and assert module. <br />

### color_print.cpp
```
void color_print(FILE * stream, int color, const char * text, ...);
const char * choose_color(int val);
```
**color_print()** works the same as **fprintf()** but in the second argument you enter enum value of color.
```
enum enum_colors
{
    COLOR_PRINT_RED,
    COLOR_PRINT_GREEN,
    COLOR_PRINT_YELLOW,
    COLOR_PRINT_BLUE,
    COLOR_PRINT_MAGENTA,
    COLOR_PRINT_CYAN,
    COLOR_PRINT_RESET
};
```

### red_assert.cpp
```
#define red_assert(COND, LINE, ...)                                     \
    color_print(stderr, COLOR_PRINT_RED, "%s\n", #COND);                \
    red_assert_func(COND, __FILE__, __func__, __LINE__, LINE __VA_ARGS__)

void red_assert_func(int cond, const char * source_file, const char * source_func, int source_line, const char * line, ...);
```
This assert differs from a regular one. You can write a message about an error in it. <br />
It will also print **condition, file, function, line.** <br />
It will print you everything in red.

