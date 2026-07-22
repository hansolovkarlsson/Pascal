#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"
#include "lexer.h"

Instruction code[MAX_CODE];
int code_idx = 0;

char sym_table[MAX_SYMBOLS][MAX_NAME];
int sym_count = 0;

static void emit(OpCode op, int arg) {
    code[code_idx++] = (Instruction){op, arg};
}

static int find_var(const char *name) {
    for (int i = 0; i < sym_count; i++) {
        if (strcmp(sym_table[i], name) == 0) return i;
    }
    printf("Compile Error: Unknown variable %s\n", name);
    exit(1);
}

static void add_var(const char *name) {
    strcpy(sym_table[sym_count++], name);
}

static void match(TokenType type) {
    if (token.type == type) next_token();
    else { printf("Compile Error: Unexpected token syntax\n"); exit(1); }
}

static void expression(void);

static void factor(void) {
    if (token.type == TOKEN_NUMBER) {
        emit(OP_PUSH, token.value);
        match(TOKEN_NUMBER);
    } else if (token.type == TOKEN_IDENTIFIER) {
        emit(OP_LOAD, find_var(token.text));
        match(TOKEN_IDENTIFIER);
    }
}

static void term(void) {
    factor();
    while (token.type == TOKEN_MUL || token.type == TOKEN_DIV) {
        TokenType t = token.type;
        next_token();
        factor();
        emit(t == TOKEN_MUL ? OP_MUL : OP_DIV, 0);
    }
}

static void expression(void) {
    term();
    while (token.type == TOKEN_PLUS || token.type == TOKEN_MINUS) {
        TokenType t = token.type;
        next_token();
        term();
        emit(t == TOKEN_PLUS ? OP_ADD : OP_SUB, 0);
    }
}

void compile(const char *source) {
    init_lexer(source);

    match(TOKEN_PROGRAM);
    match(TOKEN_IDENTIFIER);
    match(TOKEN_SEMI);

    if (token.type == TOKEN_VAR) {
        match(TOKEN_VAR);
        while (token.type == TOKEN_IDENTIFIER) {
            add_var(token.text);
            match(TOKEN_IDENTIFIER);
            while (token.type == TOKEN_COMMA) {
                match(TOKEN_COMMA);
                add_var(token.text);
                match(TOKEN_IDENTIFIER);
            }
            match(TOKEN_COLON);
            match(TOKEN_INTEGER);
            match(TOKEN_SEMI);
        }
    }

    match(TOKEN_BEGIN);
    while (token.type == TOKEN_IDENTIFIER) {
        int var_idx = find_var(token.text);
        match(TOKEN_IDENTIFIER);
        match(TOKEN_ASSIGN);
        expression();
        emit(OP_STORE, var_idx);
        match(TOKEN_SEMI);
    }
    match(TOKEN_END);
    match(TOKEN_PERIOD);
    emit(OP_HALT, 0);
}
