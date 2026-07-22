#ifndef COMMON_H
#define COMMON_H

#define MAX_NAME 32
#define MAX_SYMBOLS 100
#define MAX_CODE 1000
#define MAX_STACK 256

typedef enum {
    TOKEN_PROGRAM, TOKEN_VAR, TOKEN_BEGIN, TOKEN_END, TOKEN_INTEGER,
    TOKEN_IDENTIFIER, TOKEN_NUMBER, TOKEN_ASSIGN, TOKEN_PLUS, TOKEN_MINUS,
    TOKEN_MUL, TOKEN_DIV, TOKEN_SEMI, TOKEN_COLON, TOKEN_COMMA, TOKEN_PERIOD,
    TOKEN_EOF, TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char text[MAX_NAME];
    int value;
} Token;

typedef enum { OP_PUSH, OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_LOAD, OP_STORE, OP_HALT } OpCode;

typedef struct {
    OpCode op;
    int arg;
} Instruction;

#endif
