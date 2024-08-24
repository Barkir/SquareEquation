#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "header/red_assert.h"
#include "header/color_print.h"
#include "header/constants_structures.h"

void red_assert_func(int cond, const char * source_file, const char * source_func,  int source_line, const char * line, ...)
{
    color_print(stderr, COLOR_PRINT_RED, "FILE: %s, FUNCTION: %s, LINE: %d\n", source_file, source_func, source_line);
    va_list ptr;
    va_start(ptr, line);
    if (!cond){
        color_print(stderr, COLOR_PRINT_RED, "Assertion failed!\n");
        va_start(ptr, line);
        printf("%s", choose_color(COLOR_PRINT_RED));
        vprintf(line, ptr);
        printf("%s", choose_color(COLOR_PRINT_RESET));
        va_end(ptr);
        abort();
    }
    va_end(ptr);
}


//fix консоли ne krasil
// svuy isnan isfinite
// fix svoy output
