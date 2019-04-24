//
// Created by  on 2019-04-16.
//

#ifndef DB_READFILE_H
#define DB_READFILE_H

#include <stdio.h>

extern FILE* fp;

int open_file(const char* filename);
int read_int(int* int_ptr);
int read_string(char* c_str);
int read_float(float* float_ptr);
void close_file();

#endif //DB_READFILE_H
