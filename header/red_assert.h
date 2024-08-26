/**
* @file red_assert.h
* @brief a header file for red_assert.cpp
 */

#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#define red_assert(COND, LINE, ...)                                     \
    color_print(stderr, COLOR_PRINT_RED, "%s\n", #COND);                \
    red_assert_func(COND, __FILE__, __func__, __LINE__, LINE __VA_ARGS__)

void red_assert_func(int cond, const char * source_file, const char * source_func, int source_line, const char * line, ...);

#endif
