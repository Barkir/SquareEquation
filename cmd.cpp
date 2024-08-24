/**
* @file cmd.cpp
*
* @brief .cpp file with functions to analyze and parse command line arguments
 **/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "header/cmd.h"
#include "header/cmd_flags.h"
#include "header/constants_structures.h"

/**
* @brief function for parsing command line arguments (converts a flag into enum)
* @param w_flag a single flag
* @param flag_array a structure with defined flags (such as --help or --out)
* @param size a size of flag_array

*/

// PARSES THE ARGUMENTS YOU TYPE IN CMD
int parse_cmd_args(char * w_flag, struct flag * flag_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(w_flag, flag_array[i].name) == 0) {return flag_array[i].code;}
    }
    return RET;
}

/**
* @brief output_cmd performs a flag using switch case
* @param code enum code of a flag (CMD_HELP, CMD_DOC etc.)
 */

// OUTPUTS SMTH IN CMD
int output_cmd(int code)
{
    switch (code)
    {
        case CMD_HELP:
            printf("%s", help);
            return EXIT;

        case CMD_DOC:
            printf("%s", doc);
            system("html\\index.html");
            return EXIT;

        case CMD_OUT:
            printf("%s", out);
            return CONTINUE;


        default:
            break;
    }

    return 0;

}
