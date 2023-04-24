# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -O2

# Target executable
TARGET = player1

# Source files
SRCS = src/player1.cpp src/unit.cpp src/map.cpp src/tile.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Include directory
INCDIR = include

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(INCDIR)/unit.hpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@
%.o: %.cpp $(INCDIR)/map.hpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@
%.o: %.cpp $(INCDIR)/tile.hpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)