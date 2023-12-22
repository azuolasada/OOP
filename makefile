# Makefile 

# Compiler settings
CXX = g++                       # Specifies the C++ compiler
CXXFLAGS = -Wall -std=c++17     # Compiler flags: Enable all warnings, use C++17 standard
LDFLAGS =                       # Linker flags, if any needed

# Project files
OBJ = v2.0.o side_functions.o   # Object files to be generated
TARGET = v2.0                   # Name of the final executable

# Rule for making the final target
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^   # $@ refers to the target, $^ refers to all dependencies

# Rule for compiling source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<    # $< refers to the first dependency (the source file)

# Clean rule for removing compiled files
clean:
	rm -f $(OBJ) $(TARGET)      # Removes all object files and the final executable
