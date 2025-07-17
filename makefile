# Config
PROJECT_NAME = App
CC = gcc
CFLAGS = $(INC) -Wall -Wextra -std=c99 -g
LDFLAGS = -Llibs -lglfw3dll -lglfw3 -lopengl32

# Root Directories
SRC = src
BIN = bin

# Auto-discover all source directories
ALL_SRC_DIRS = $(shell find $(SRC) -type d)
INC_PROJECT_HEADERS = $(addprefix -I, $(ALL_SRC_DIRS))
INC = -I./include $(INC_PROJECT_HEADERS)

SHADERS_SRC = $(SRC)/shaders

OBJs = $(patsubst %.c, %.o, $(DIR_SRC:%=$(SRC)/%.c))



# File src
C_FILES = $(shell find $(SRC) -name "*.c")
OBJ_FILES = $(C_FILES:.c=.o)

TARGET = $(BIN)/$(PROJECT_NAME)

# Default target: build, clean objects, and run
Dev: dependencies build clean-objects run

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

dependencies: 
	@mkdir -p $(BIN)
	@cp libs/*.dll $(BIN)/
	@mkdir -p $(BIN)/shaders
	@cp $(SHADERS_SRC)/*.glsl $(BIN)/shaders/

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