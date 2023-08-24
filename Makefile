CC := gcc
CFLAGS := -g -Iinclude -Wall

BUILD_DIR := build
BIN := bin
OBJ := obj

SRC_FILES := $(wildcard src/*.c)
OBJ_FILES := $(patsubst src/%.c,$(BUILD_DIR)/$(OBJ)/%.o,$(SRC_FILES))

# common.o is shared to avoid recompiling
COMMON_OBJ := $(BUILD_DIR)/$(OBJ)/common.o

TARGET1 := $(BUILD_DIR)/$(BIN)/tcpc
TARGET2 := $(BUILD_DIR)/$(BIN)/tcps

.PHONY: all clean directories

all: directories $(TARGET1) $(TARGET2)

directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/$(BIN)
	@mkdir -p $(BUILD_DIR)/$(OBJ)

$(TARGET1): $(BUILD_DIR)/$(OBJ)/tcpClient.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET2): $(BUILD_DIR)/$(OBJ)/tcpServer.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/$(OBJ)/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)
