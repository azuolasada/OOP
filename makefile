# Makefile for cross-compiling to Windows from Linux

CXX = x86_64-w64-mingw32-g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS =
OBJ = v3.0.o side_functions.o
TARGET = v3.0.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
