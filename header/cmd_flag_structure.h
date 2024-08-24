/**
* @file cmd_flag_structure.h
* @brief a file for storing flag_array structure, cmd flags and their enum codes
*/

#ifndef CMD_FLAG_STRUCTURE_H
#define CMD_FLAG_STRUCTURE_H

#include "constants_structures.h"

struct flag flag_array[flag_array_size] =
{
    {.name = "--help", .code = CMD_HELP},
    {.name = "--doc", .code = CMD_DOC},
    {.name = "--out", .code = CMD_OUT}
};

#endif
