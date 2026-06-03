.RECIPEPREFIX := >
CC       := gcc
CCFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   := app
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.c)

OBJECTS := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.c
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
>@mkdir -p $(@D)
>$(CC) $(CCFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release run

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

run:
>./$(BUILD)/$(TARGET)
