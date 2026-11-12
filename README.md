# TinyLang Lexer in C

[日本語](README.ja.md) · [English](README.md) · [한국어](README.ko.md)

Lexer is the first step of the TinyLang compiler. Split the following code into tokens:

```text
var x = 10 + 20 - 5;
```

## Project structure

```text
tinylang-c/
├── include/
│   ├── lexer.h
│   └── token.h
├── src/
│   ├── lexer.c
│   └── main.c
├── Makefile
└── README.md
```

## Where do I run it?

All commands run from the **`tinylang-c` folder where `Makefile` is located.**

```sh
cd tinylang-c
```

## Build and run

Run the following command from the above project root location:

```sh
make
make run
```

## Execution result

When you run `make run`, the output is as follows:

```text
./build/tinylang "var x = 10 + 20 - 5;"
TOKEN_VAR
TOKEN_IDENTIFIER(x)
TOKEN_EQUAL
TOKEN_NUMBER(10)
TOKEN_PLUS
TOKEN_NUMBER(20)
TOKEN_MINUS
TOKEN_NUMBER(5)
TOKEN_SEMICOLON
TOKEN_EOF
```

You can also pass the code directly.

```sh
./build/tinylang "var value = 7 + 5;"
```

When run without arguments, one line is read from standard input.

```sh
./build/tinylang
var x = 10 + 20 - 5;
```

To clear build results, run:

```sh
make clean
```

## Processing order

1. `main.c` receives one line of source code.
2. `lexer_init` sets the starting position of Lexer to 0.
3. `lexer_next_token` skips spaces and returns tokens one by one.
4. `main.c` outputs tokens until it encounters `TOKEN_EOF`.
