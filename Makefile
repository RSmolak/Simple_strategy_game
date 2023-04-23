# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -O2

# Target executable
TARGET = player1

# Source files
SRCS = player1.cpp unit.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp unit.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)