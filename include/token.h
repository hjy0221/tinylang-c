#ifndef TINYLANG_TOKEN_H
#define TINYLANG_TOKEN_H

#define TOKEN_TEXT_CAPACITY 64

typedef enum {
    TOKEN_VAR,
    TOKEN_IDENTIFIER,
    TOKEN_EQUAL,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_SEMICOLON,
    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    char text[TOKEN_TEXT_CAPACITY];
} Token;

#endif
