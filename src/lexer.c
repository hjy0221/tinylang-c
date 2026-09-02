#include "lexer.h"

#include <ctype.h>
#include <stddef.h>
#include <string.h>

static char current_char(const Lexer *lexer)
{
    return lexer->source[lexer->position];
}

static void advance(Lexer *lexer)
{
    if (current_char(lexer) != '\0') {
        lexer->position++;
    }
}

static void skip_whitespace(Lexer *lexer)
{
    while (isspace((unsigned char)current_char(lexer))) {
        advance(lexer);
    }
}

static Token make_token(TokenType type, const char *start, size_t length)
{
    Token token;
    size_t copy_length = length;

    token.type = type;

    if (copy_length >= TOKEN_TEXT_CAPACITY) {
        copy_length = TOKEN_TEXT_CAPACITY - 1;
    }

    memcpy(token.text, start, copy_length);
    token.text[copy_length] = '\0';

    return token;
}

static Token read_identifier(Lexer *lexer)
{
    size_t start = lexer->position;
    size_t length;

    while (isalnum((unsigned char)current_char(lexer)) ||
           current_char(lexer) == '_') {
        advance(lexer);
    }

    length = lexer->position - start;

    if (length == 3 && strncmp(lexer->source + start, "var", length) == 0) {
        return make_token(TOKEN_VAR, lexer->source + start, length);
    }

    return make_token(TOKEN_IDENTIFIER, lexer->source + start, length);
}

static Token read_number(Lexer *lexer)
{
    size_t start = lexer->position;

    while (isdigit((unsigned char)current_char(lexer))) {
        advance(lexer);
    }

    return make_token(TOKEN_NUMBER,
                      lexer->source + start,
                      lexer->position - start);
}

void lexer_init(Lexer *lexer, const char *source)
{
    lexer->source = source;
    lexer->position = 0;
}

Token lexer_next_token(Lexer *lexer)
{
    const char *token_start;
    char character;

    skip_whitespace(lexer);
    token_start = lexer->source + lexer->position;
    character = current_char(lexer);

    if (isalpha((unsigned char)character) || character == '_') {
        return read_identifier(lexer);
    }

    if (isdigit((unsigned char)character)) {
        return read_number(lexer);
    }

    switch (character) {
    case '=':
        advance(lexer);
        return make_token(TOKEN_EQUAL, token_start, 1);
    case '+':
        advance(lexer);
        return make_token(TOKEN_PLUS, token_start, 1);
    case ';':
        advance(lexer);
        return make_token(TOKEN_SEMICOLON, token_start, 1);
    case '\0':
        return make_token(TOKEN_EOF, token_start, 0);
    default:
        advance(lexer);
        return make_token(TOKEN_ERROR, token_start, 1);
    }
}

const char *token_type_name(TokenType type)
{
    switch (type) {
    case TOKEN_VAR:
        return "TOKEN_VAR";
    case TOKEN_IDENTIFIER:
        return "TOKEN_IDENTIFIER";
    case TOKEN_EQUAL:
        return "TOKEN_EQUAL";
    case TOKEN_NUMBER:
        return "TOKEN_NUMBER";
    case TOKEN_PLUS:
        return "TOKEN_PLUS";
    case TOKEN_SEMICOLON:
        return "TOKEN_SEMICOLON";
    case TOKEN_EOF:
        return "TOKEN_EOF";
    case TOKEN_ERROR:
        return "TOKEN_ERROR";
    }

    return "TOKEN_UNKNOWN";
}
