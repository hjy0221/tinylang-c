# TinyLang Lexer in C

[日本語](README.ja.md) · [English](README.md) · [한국어](README.ko.md)

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
