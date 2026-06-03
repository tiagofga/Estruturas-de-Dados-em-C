.RECIPEPREFIX := >
CC       := gcc
CCFLAGS  := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   := app
STATIC_TARGET := app_static
TEST_TARGET := test_runner
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.c)
TEST_SRC := $(wildcard tests/*.c)

ALL_OBJECTS  := $(SRC:%.c=$(OBJ_DIR)/%.o)
TEST_OBJECTS := $(TEST_SRC:%.c=$(OBJ_DIR)/%.o)
LIB_OBJECTS  := $(filter-out $(OBJ_DIR)/src/main.o $(OBJ_DIR)/src/main_estatica.o, $(ALL_OBJECTS))

DYNAMIC_OBJECTS := $(OBJ_DIR)/src/pilha.o $(OBJ_DIR)/src/main.o
STATIC_OBJECTS  := $(OBJ_DIR)/src/pilha_estatica.o $(OBJ_DIR)/src/main_estatica.o

all: build dynamic

dynamic: $(APP_DIR)/$(TARGET)

static: build $(APP_DIR)/$(STATIC_TARGET)

$(OBJ_DIR)/%.o: %.c
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(DYNAMIC_OBJECTS)
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) $(LDFLAGS) -o $@ $^

$(APP_DIR)/$(STATIC_TARGET): $(STATIC_OBJECTS)
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) $(LDFLAGS) -o $@ $^

test: build $(APP_DIR)/$(TEST_TARGET)
>$(APP_DIR)/$(TEST_TARGET)

$(APP_DIR)/$(TEST_TARGET): $(LIB_OBJECTS) $(TEST_OBJECTS)
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) $(LDFLAGS) -o $@ $^

.PHONY: all build clean debug release run run_static test dynamic static

build:
>@mkdir -p $(APP_DIR)
>@mkdir -p $(OBJ_DIR)

debug: CCFLAGS += -DDEBUG -g
debug: all

release: CCFLAGS += -O3
release: all

clean:
>-@rm -rvf $(OBJ_DIR)/*
>-@rm -rvf $(APP_DIR)/*

run: dynamic
>./$(BUILD)/$(TARGET)

run_static: static
>./$(BUILD)/$(STATIC_TARGET)
