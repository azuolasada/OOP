# Makefile

CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = 
OBJ = v1.2.o side_functions.o
TARGET = v1.2

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
