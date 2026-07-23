# Makefile for Pascal compier w/ Stack VM
#
#   make			builds bin/pascal
#   make clean		removes build artifacts
#	make examples	build example programs
#
# Works with gcc or clang; on macOS the Xcode command-line tools provide
# a `cc` that behaves the same way, so this Makefile needs no changes
# there.

# Assembler
CC      ?= cc
CFLAGS  ?= -std=c99 -O2 -Wall -Wextra

# Multi-file
SRC_DIR := src
BIN_DIR := bin
SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(SOURCES:.c=.o)
TARGET  := $(BIN_DIR)/pascal

TEST_DIR := tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.pas)
TEST_BIN := $(TEST_SRC:.pas=.bin)



# Make
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o
	rm tests/*.bin

# Tests
tests: $(TEST_BIN)

$(TEST_BIN): $(TEST_SRC)

%.bin: %.pas
	$(TARGET) -c $< $@


