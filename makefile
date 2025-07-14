# Config
PROJECT_NAME = GameEngine
CC = gcc
CFLAGS = -I./include -I./src -Wall -Wextra -std=c99 -g
LDFLAGS = -Llibs -lglfw3dll -lglfw3 -lopengl32

# Root Directories
SRC = src
BIN = bin
INCLUDE = include
SHADERS_SRC = $(SRC)/shaders

SRC_CHILDREN = $(SRC)/window

ALL_DIRS = $(SRC) $(SRC_CHILDREN)

OBJs = $(patsubst %.c, %.o, $(ALL_DIRS:%=$(SRC)/%.c))

# File src
C_FILES = $(shell find $(SRC) -name "*.c")
OBJ_FILES = $(C_FILES:.c=.o)

TARGET = $(BIN)/$(PROJECT_NAME)

# Default target: build, clean objects, and run
all: build clean-objects run



Prod: CFLAGS += -O2 -DNDEBUG
Prod: clean build

# Compile .c files to .o files in place
%.o: %.c
	@echo "Compiling $<..."
	@$(CC) -c $(CFLAGS) $(addprefix -I, $(ALL_DIRS)) $< -o $@

# Main target
build: $(OBJ_FILES)
	@mkdir -p $(BIN)
	$(CC) $^ $(LDFLAGS) -o ${TARGET}
	@echo "Copying required DLLs..."
	@cp libs/*.dll $(BIN)/

# Clean object files only
clean-objects:
	@echo "Cleaning object files..."
	@find $(SRC) -name "*.o" -delete

# Clean everything
clean:
	@find $(SRC) -name "*.o" -delete
	@rm -f $(TARGET)
	@rm -f $(BIN)/*.dll

run:
	@echo "Running $(PROJECT_NAME)..."
	@./$(TARGET)

.PHONY: all All Prod build clean clean-objects run 