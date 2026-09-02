#ifndef TINYLANG_LEXER_H
#define TINYLANG_LEXER_H

#include <stddef.h>

#include "token.h"

typedef struct {
    const char *source;
    size_t position;
} Lexer;

void lexer_init(Lexer *lexer, const char *source);
Token lexer_next_token(Lexer *lexer);
const char *token_type_name(TokenType type);

#endif
