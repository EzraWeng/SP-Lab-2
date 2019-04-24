//
// Created by  on 2019-04-16.
//

#include "readfile.h"

FILE* fp = NULL;

int open_file(const char* filename) {
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    return 0;
}

int read_int(int* int_ptr) {
    if (fp == NULL) {
        return -1;
    }
    int ret = fscanf(fp, "%d", int_ptr);
    if (ret == EOF) {
        return -1;
    }
    return 0;
}

int read_string(char* c_str) {
    if (fp == NULL) {
        return -1;
    }
    int ret = fscanf(fp, "%s", c_str);
    if (ret == EOF) {
        return -1;
    }
    return 0;
}

int read_float(float* float_ptr) {
    if (fp == NULL) {
        return -1;
    }
    int ret = fscanf(fp, "%f", float_ptr);
    if (ret == EOF) {
        return -1;
    }
    return 0;
}

void close_file() {
    if (fp != NULL) {
        fclose(fp);
    }

}