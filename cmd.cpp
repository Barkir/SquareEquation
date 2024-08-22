/** @file **/

#include "header/cmd.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "header/cmd_flags.h"
#include "header/constants_structures.h"


// PARSES THE ARGUMENTS YOU TYPE IN CMD
int parse_cmd_args(char * w_flag, struct flag * flag_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(w_flag, flag_array[i].name) == 0) {return flag_array[i].code;}
    }
    return RET;
}

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
