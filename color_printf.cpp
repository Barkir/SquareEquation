/**
* @file color_printf.cpp
* @brief a module with function for writing colorful text
 */

#if !defined WIN32
#error "This code works only on Windows OS"
#endif

#include <stdio.h>
#include <io.h>

#include "header/color_printf.h"
#include "header/constants_structures.h"


/**
* @brief main function for printing colorful text (works like fprintf() but has a color as an arg)
* @param stream stream where you want to print your text(stdout, stderr etc.)
* @param color enum value of a color (e.g COLOR_PRINT_RED)
* @param text you want to print
 */

void color_printf(FILE * stream, int color, const char * text, ...)
{
    const char * string_color = choose_color(color);
    va_list ptr;

    if (!_isatty(_fileno(stream)))                                                          // check if file discriptor not associated
    {                                                                                       // with stdin, stdout, stderr
        va_start(ptr, text);
        vfprintf(stream, text, ptr);
        va_end(ptr);
    }
    else
    {
        fprintf(stream, "%s", string_color);
        va_start(ptr, text);
        vfprintf(stream, text, ptr);
        fprintf(stream, "%s", choose_color(COLOR_PRINT_RESET));
        va_end(ptr);
    }

}

void color_vprintf(int color, const char * format, va_list local_argv)
{
    printf("%s", choose_color(color));
    vprintf(format, local_argv);
    printf("%s", choose_color(COLOR_PRINT_RESET));

}


/**
* @brief a function for converting enum color value to string (esc sequence)
* @param val enum color value
 */

const char * choose_color(int val)
{
    switch (val)
    {
        case COLOR_PRINT_RED:
        return "\x1b[31m";

        case COLOR_PRINT_GREEN:
        return "\x1b[32m";
        break;

        case COLOR_PRINT_YELLOW:
        return "\x1b[33m";

        case COLOR_PRINT_BLUE:
        return "\x1b[34m";

        case COLOR_PRINT_MAGENTA:
        return "\x1b[35m";

        case COLOR_PRINT_CYAN:
        return "\x1b[36m";

        case COLOR_PRINT_RESET:
        return "\x1b[0m";

        default:
        return "\x1b[0m";
    }
}
