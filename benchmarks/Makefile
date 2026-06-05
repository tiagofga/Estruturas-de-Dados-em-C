.RECIPEPREFIX := >
CC      := gcc
CCFLAGS := -pedantic-errors -Wall -Wextra -Werror -O2
INCLUDE := -I../AVL/include -I../TabelaHash/include -I../AlgoritmosGrafos/include
LDFLAGS := -lm
BUILD   := ./build
TARGET  := benchmark
SRC     := benchmark.c ../AVL/src/avl.c ../TabelaHash/src/tabela_hash.c ../AlgoritmosGrafos/src/algoritmos_grafos.c

.PHONY: all run clean

all:
>@mkdir -p $(BUILD)
>$(CC) $(CCFLAGS) $(INCLUDE) -o $(BUILD)/$(TARGET) $(SRC) $(LDFLAGS)

run: all
>$(BUILD)/$(TARGET)

clean:
>-@rm -rvf $(BUILD)
