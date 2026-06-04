.RECIPEPREFIX := >
CC          := gcc
CCFLAGS     := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS     := -lm
BUILD       := ./build
OBJ_DIR     := $(BUILD)/objects
APP_DIR     := $(BUILD)
TARGET      := app
TEST_TARGET := test_runner
INCLUDE     := -Iinclude/
SRC         := $(wildcard src/*.c)
TEST_SRC    := $(wildcard tests/*.c)

ALL_OBJECTS  := $(SRC:%.c=$(OBJ_DIR)/%.o)
TEST_OBJECTS := $(TEST_SRC:%.c=$(OBJ_DIR)/%.o)
LIB_OBJECTS  := $(filter-out $(OBJ_DIR)/src/main.o, $(ALL_OBJECTS))

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.c
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(ALL_OBJECTS)
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) -o $@ $^ $(LDFLAGS)

test: build $(APP_DIR)/$(TEST_TARGET)
>$(APP_DIR)/$(TEST_TARGET)

$(APP_DIR)/$(TEST_TARGET): $(LIB_OBJECTS) $(TEST_OBJECTS)
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) -o $@ $^ $(LDFLAGS)

.PHONY: all build clean debug release run test

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

run: all
>./$(BUILD)/$(TARGET)
