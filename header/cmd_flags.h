#ifndef HELP_H
#define HELP_H

#include "colors.h"
#include "constants_structures.h"

const char * doc =
"Instructions for SquareSolver: ... \n"
"                   FILES\n\n"
"   -main.cpp                main file\n"
"   -solve_equation.cpp      file for solving equations.\n"
"   -input_output.cpp        file for user input/output\n"
"   -testing.cpp             file for testing the program using unit-tests\n"
"   -cmd.cpp                 file for input flags in cmd\n"
"\n"
"   -solve_equation.h        header file for solve_equation.cpp\n"
"   -input_output.h          header file for input_output.cpp\n"
"   -testing.h               header file for testing.cpp\n"
"   -cmd.h                   header file for cmd.cpp\n"
"   -tests.h                 header file with reference roots and coefs (a, b, c, x1, x2)\n"
"   -colors.h                header file with defined colors for colorful text\n"
"   -constants_structures.h  header file with defined structures and constants\n"
"   -cmd_flags.h             header file with defined text for flags\n"
"   -cmd_flag_structure      header file with a flag structure for cmd.cpp"
"\n"
"                   FUNCTIONS\n\n"
"                   solve_equation.cpp/square_equation.h\n"
"   -discriminant            function for finding a discriminant\n"
"   -is_null                 return true if double number equals zero\n"
"   -is_equal                returns true if double numbers are equal\n"
"   -interchange             interchanges the values of two double numbers (used to sort equation solutions)\n"
"   -solve_square_equation   function for solving square equation\n"
"   -solve_linear_equation   function for solving linear equation\n\n"
"                   input_output.cpp/input_output.h\n"
"   -enter_numbers           function for entering numbers(merges 3 get_number() functions)\n"
"   -get_number              function for getting a number from a user (a, b, c)\n"
"   -print_roots             function for printing roots of the equation\n\n"
"                   testing.cpp/testing.h\n"
"   -test_init               function for initializing a single test\n"
"   -all_test_init           function for initializng a number of tests(calls a number of test_init functions)\n\n"
"                    colors.h\n"
"   -RED                     red text color\n"
"   -BLUE                    blue text color\n"
"   -MAGENTA                 magenta text color\n"
"   -GREEN                   green text color\n"
"   -YELLOW                  yellow text color\n"
"   -CYAN                    cyan text color\n"
"   -RESET                   reset text color\n\n"
"                   cmd_flag_structure.h\n"
"   -flag flag_array         structure with defined flags for cmd.cpp\n\n"
"                   constants_structures.h\n"
"       --constants\n"
"   -INF_SOLUTIONS           enum value for defining infinite solutions\n"
"   -NO_ROOTS                enum value for defining no solutions\n"
"   -ONE_ROOT                enum value foe defining one root\n"
"   -TWO_ROOTS               enum value for defining two solutions\n"
"   -TESTS_NUMBER            constant value for defining tests number\n"
"   -eps                     constant value for defining a very small number\n"
"       --structures\n"
"   -equation                structure for defining equation coefs\n"
"   -solution                structure for defining equation solutions\n"
"   -flag                    structure for defining flags and their enum values";


const char * help =
BLUE "               This is a help instruction for using Square Equation Solver" RESET "\n\n"
BLUE "I." RESET "             The first step is to start the program.\n"
"               To do this, open cmd and move to directory where this project is located.\n"
"               Then enter this " YELLOW "\"g++ -o a.exe main.cpp solve_equation.cpp testing.cpp input_output.cpp\"" RESET "\n"
"               To run the program type " YELLOW "\"a\"" RESET " in cmd\n\n"
BLUE "II." RESET "            You will be suggested to enter the coefs of a square equation " CYAN "(a, b, c)" RESET "\n"
"               Please enter them one by one, when you tap " CYAN "Enter" RESET "\n"
"               the program will suggest you to enter the next coef.\n"
"               If you enter the coef incorrectly, the program\n"
"               will warn you using this message: " RED "\"NOT A NUMBER!\"" RESET "\n\n"
BLUE "III" RESET "            When you finish entering the coefs, the program will automatically\n"
"               find the solutions of the equation and you will see the result.\n"
"               The program prints: " GREEN "\"No solutions.\"" RESET ", if there are no solutions.\n\n"
"                                   " GREEN "one solution" RESET " if the equation is linear\n"
"                                   or has two equal square solutions\n\n"
"                                   " GREEN "two solutions" RESET " if there are two of them\n\n"
"                                   " GREEN "\"Infinite number of solutions\"" RESET "\n"
"                                   when a == b == c == 0\n";


const char * out = YELLOW  "OUT\n" RESET
                   GREEN   "OUT\n" RESET
                   MAGENTA "OUT\n" RESET
                   BLUE    "OUT\n" RESET
                   CYAN    "OUT\n" RESET
                   RED     "OUT\n" RESET;

#endif
