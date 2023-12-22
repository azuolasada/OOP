# Makefile 

# Compiler settings
CXX = g++                       # Specifies the C++ compiler
CXXFLAGS = -Wall -std=c++17     # Compiler flags: Enable all warnings, use C++17 standard

# Google Test settings
GTEST_DIR = /workspaces/OOP/googletest/googletest
GTEST_INCLUDE = -I$(GTEST_DIR)/include      # Google Test include path

# Project files
OBJ = side_functions.o   # Object files to be generated for the main application
MAIN_OBJ = v2.0.o        # Object file for the main application
TEST_OBJ = test.o        # Object file for the test
TARGET = v2.0            # Name of the final executable for the main application
TESTS = tests            # Name of the test executable

# Rule for making the final target and tests
all: $(TARGET) $(TESTS)

# Rule to link the object files into the final executable
$(TARGET): $(MAIN_OBJ) $(OBJ)
	$(CXX) -o $@ $^

# Rule for compiling source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Test executable
$(TESTS) : $(TEST_OBJ) $(OBJ)
	$(CXX) $(GTEST_INCLUDE) -o $@ $^ -pthread -lgtest -lgtest_main

# Compile main application object file
v2.0.o: v2.0.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Compile test object file
test.o: test.cpp
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) -c $<

# Clean rule for removing compiled files
clean:
	rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(TARGET) $(TESTS) *.o