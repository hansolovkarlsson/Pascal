#ifndef COMPILER_H
#define COMPILER_H

#include "common.h"

extern Instruction code[MAX_CODE];
extern int code_idx;
extern char sym_table[MAX_SYMBOLS][MAX_NAME];
extern int sym_count;

void compile(const char *source);

#endif
