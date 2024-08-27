/**
* @file color_printf.h
* @brief a header file for color_printf.cpp
 */

#ifndef MY_PRINT_H
#define MY_PRINT_H

#include <stdarg.h>

void color_printf(FILE * stream, int color, const char * text, ...);
void color_vprintf(int color, const char * format, va_list local_argv);
const char * choose_color(int val);

#endif
