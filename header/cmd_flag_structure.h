/** @file **/

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
