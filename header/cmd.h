/**
* @file cmd.h
* @brief a header file for cmd.cpp
*/

#ifndef CMD_H
#define CMD_H

int output_cmd(int code);
int parse_cmd_args(char * w_flag, struct flag * flag_array, int size);

#endif
