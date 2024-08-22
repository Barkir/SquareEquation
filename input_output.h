#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

int get_number(double * num);
void print_roots(struct solution roots);
struct equation enter_numbers();
int output_cmd(int code);
int parse_cmd_args(char * w_flag, struct flag * flag_array, int flag_array_size);

#endif




