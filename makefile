# Makefile

CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = 
OBJ = v2.0.o side_functions.o
TARGET = v2.0

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
