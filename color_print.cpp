#include <stdio.h>
#include <stdarg.h>

#include "header/color_print.h"
#include "header/constants_structures.h"

void color_print(FILE * stream, int color, const char * text, ...)
{
    const char * string_color = choose_color(color);
    va_list ptr;
    fprintf(stream, "%s", string_color);
    va_start(ptr, text);
    vfprintf(stream, text, ptr);
    fprintf(stream, "%s", choose_color(COLOR_PRINT_RESET));
    va_end(ptr);
}

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
