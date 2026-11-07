# TinyLang Lexer in C

[日本語](https://github.com/hjy0221/tinylang-c#%E6%97%A5%E6%9C%AC%E8%AA%9E) · [English](https://github.com/hjy0221/tinylang-c#english) · [한국어](https://github.com/hjy0221/tinylang-c#%ED%95%9C%EA%B5%AD%EC%96%B4)

## 日本語

TinyLangコンパイラの最初のステップであるLexerです。次のコードをトークンで除算します。

```text
var x = 10 + 20 - 5;
```

## プロジェクト構造

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

## どこで実行しますか？

すべてのコマンドは、`Makefile`がある** `tinylang-c`フォルダーから実行されます。**

```sh
cd tinylang-c
```

## ビルドと実行

上記のプロジェクトルートの場所から次のコマンドを実行します。

```sh
make
make run
```

## 実行結果

`make run`を実行すると、次のように出力されます。

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

直接コードを渡すこともできます。

```sh
./build/tinylang "var value = 7 + 5;"
```

引数なしで実行すると、標準入力から1行が読み取られます。

```sh
./build/tinylang
var x = 10 + 20 - 5;
```

ビルド結果を消去するには、次のようにします。

```sh
make clean
```

## 処理順序

1. `main.c`はソースコードを1行受け取ります。
2. `lexer_init` このレクサーの開始位置を 0 に設定します。
3. `lexer_next_token`は空白をスキップし、トークンを1つずつ返します。
4. `main.c`が`TOKEN_EOF`に会うまでトークンを出力します。

## English

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

## 한국어

TinyLang 컴파일러의 첫 단계인 Lexer입니다. 다음 코드를 토큰으로 나눕니다.

```text
var x = 10 + 20 - 5;
```

## 프로젝트 구조

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

## 어디에서 실행하나요?

모든 명령은 `Makefile`이 있는 **`tinylang-c` 폴더에서 실행합니다.**

```sh
cd tinylang-c
```

## 빌드와 실행

위의 프로젝트 루트 위치에서 다음 명령을 실행합니다.

```sh
make
make run
```

## 실행 결과

`make run`을 실행하면 다음과 같이 출력됩니다.

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

직접 코드를 넘길 수도 있습니다.

```sh
./build/tinylang "var value = 7 + 5;"
```

인자 없이 실행하면 표준 입력에서 한 줄을 읽습니다.

```sh
./build/tinylang
var x = 10 + 20 - 5;
```

빌드 결과를 지우려면 다음을 실행합니다.

```sh
make clean
```

## 처리 순서

1. `main.c`가 소스 코드 한 줄을 받습니다.
2. `lexer_init`이 Lexer의 시작 위치를 0으로 설정합니다.
3. `lexer_next_token`이 공백을 건너뛰고 토큰을 하나씩 반환합니다.
4. `main.c`가 `TOKEN_EOF`를 만날 때까지 토큰을 출력합니다.
