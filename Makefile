CC ?= cc
CPPFLAGS ?= -Iinclude
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic

TARGET := build/tinylang
SOURCES := src/main.c src/lexer.c
HEADERS := include/lexer.h include/token.h

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS) | build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SOURCES) -o $(TARGET)

build:
	mkdir -p build

run: $(TARGET)
	./$(TARGET) "var x = 10 + 20;"

clean:
	rm -rf build
