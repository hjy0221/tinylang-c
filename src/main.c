#include "lexer.h"

#include <stdio.h>

#define INPUT_CAPACITY 1024

static void print_token(Token token)
{
    if (token.type == TOKEN_IDENTIFIER || token.type == TOKEN_NUMBER ||
        token.type == TOKEN_ERROR) {
        printf("%s(%s)\n", token_type_name(token.type), token.text);
        return;
    }

    printf("%s\n", token_type_name(token.type));
}

int main(int argc, char *argv[])
{
    char input[INPUT_CAPACITY];
    const char *source;
    Lexer lexer;
    Token token;

    if (argc > 2) {
        fprintf(stderr, "Usage: %s \"source code\"\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        source = argv[1];
    } else {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            fprintf(stderr, "No source code was provided.\n");
            return 1;
        }
        source = input;
    }

    lexer_init(&lexer, source);

    do {
        token = lexer_next_token(&lexer);
        print_token(token);

        if (token.type == TOKEN_ERROR) {
            fprintf(stderr, "Unexpected character: '%s'\n", token.text);
            return 1;
        }
    } while (token.type != TOKEN_EOF);

    return 0;
}
