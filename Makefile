# Compiler
CXX := g++

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Output executable name
TARGET := $(BIN_DIR)/app

# Find all .cpp files in the src directory
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
# Generate object files in the build directory
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Compiler flags
CXXFLAGS := -Wall \
						-Weffc++ \
						-Wextra \
						-Wconversion \
						-Wsign-conversion \
						-Werror \
						-std=c++23 \
						-pedantic-errors \
						-ggdb


# C++2c is C++26
# -O2 and -DNDEBUG for production builds

# Colors for output
COLOR_RESET := \033[0m
COLOR_CYAN := \033[1;36m
COLOR_GREEN := \033[1;32m
COLOR_YELLOW := \033[1;33m
COLOR_RED := \033[1;31m

# Build target
.PHONY: build
build: $(TARGET)

# Build target executable
$(TARGET): $(OBJS)
	@echo "$(COLOR_CYAN)Linking... $(COLOR_RESET)"
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(COLOR_GREEN)Build successful!$(COLOR_RESET)"

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "$(COLOR_YELLOW)Compiling $<...$(COLOR_RESET)"
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
# @echo "$(COLOR_GREEN)Compiled $< successfully!$(COLOR_RESET)"

# Clean build files
.PHONY: clean
clean:
	@echo "$(COLOR_RED)Cleaning build and bin directories...$(COLOR_RESET)"
	$(RM) -r $(BUILD_DIR) $(BIN_DIR)
	@echo "$(COLOR_GREEN)Clean complete!$(COLOR_RESET)"

# Run the compiled executable
.PHONY: run
run: build
	@echo "$(COLOR_CYAN)Running $(TARGET)...$(COLOR_RESET)\n"
	@./$(TARGET)
