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
When you enter the coefficients the program will run this [function](https://github.com/Barkir/SquareEquation/blob/main/solve_equation.cpp) <br />
```C++
struct solution solve_linear_equation(struct equation coefs);
```
This function creates a struct of roots out of coefs structure solving the square equation <sub> (or a linear equation if a = 0) </sub> <br />
Then the program writes the roots of the equation using this [function](https://github.com/Barkir/SquareEquation/blob/main/input_output.cpp) <br />
```C++ 
void print_roots(struct solution roots);
```

<sup>👏👏👏</sup>

# Unit-testing 📝
I wrote a python [script](https://github.com/Barkir/SquareEquation/blob/main/test_generator.py) 
```test_generator.py``` <br />
It writes tests into a file in this format: _[a, b, c, x1_exp, x2_exp, root_amount]_ <br />
```system("python test_generator.py");``` <br />
This line in main() inits a python script and generates new random tests 🐍 <br />

# Other interesting features 🪶
In this program you can also see such files as [color_print.cpp](https://github.com/Barkir/SquareEquation/blob/main/color_print.cpp) or [red_assert.cpp](https://github.com/Barkir/SquareEquation/blob/main/red_assert.cpp) <br />
Judging by filenames we can guess that it's our own color print module and assert module. <br />

### color_print.cpp
```C++
void color_print(FILE * stream, int color, const char * text, ...);
const char * choose_color(int val);
```
**color_print()** works the same as **fprintf()** but in the second argument you enter enum value of color.
```C++
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
```C++
#define red_assert(COND, LINE, ...)                                     \
    color_print(stderr, COLOR_PRINT_RED, "%s\n", #COND);                \
    red_assert_func(COND, __FILE__, __func__, __LINE__, LINE __VA_ARGS__)

void red_assert_func(int cond, const char * source_file, const char * source_func, int source_line, const char * line, ...);
```
This assert differs from a regular one. You can write a message about an error in it. <br />
It will also print **condition, file, function, line.** <br />
It will print you everything in red.

### Command Line Flags
For now there are two flags available (you can see them in this [file](https://github.com/Barkir/SquareEquation/blob/main/header/cmd_flags.h)) <br />
Command line processing [here](https://github.com/Barkir/SquareEquation/blob/main/cmd.cpp) <br />
```--help``` - this flag introduces you a brief info about program and how to use it. <br />
```--doc``` - this flag prints docs in command line and opens a doxygen .html file where you can learn about the program more. ✌️<br />
