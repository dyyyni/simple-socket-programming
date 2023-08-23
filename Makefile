BUILD_DIR := build

CC := gcc
CFLAGS := -g -Iinclude -Wall

SRC_FILES1 := $(wildcard src/tcpClient.c src/common.c)
OBJ_FILES1 := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES1))

SRC_FILES2 := $(wildcard src/tcpServer.c src/common.c)
OBJ_FILES2 := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES2))

TARGET1 := $(BUILD_DIR)/tcpc
TARGET2 := $(BUILD_DIR)/tcps

all: directories $(TARGET1) $(TARGET2)

directories:
	@mkdir -p $(BUILD_DIR)

$(TARGET1): $(OBJ_FILES1)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET2): $(OBJ_FILES2)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BUILD_DIR)
