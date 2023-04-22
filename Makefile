# Makefile for Shining text-based game

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Target executable name
TARGET = shining_game

# Name of cpp
CPP = .\src\shining_game.cpp

# Object files directory
OBJ_DIR = bin

# Object files
OBJS = $(OBJ_DIR)\shining_game.o

# Build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
$(OBJS): $(CPP)
	$(CXX) $(CXXFLAGS) -c $(CPP) -o $(OBJS)

# Clean up the build
.PHONY: clean
clean:
	rm -rf $(TARGET) $(OBJ_DIR)
