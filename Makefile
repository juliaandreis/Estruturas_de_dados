CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -I./TGB

SRCS = TGB/main.cpp TGB/arrayGenerator.cpp TGB/mean.cpp TGB/printTable.cpp TGB/sortingAlgorithms.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = TGB/benchmark

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
