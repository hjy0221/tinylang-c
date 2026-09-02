# TinyLang Lexer in C

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
