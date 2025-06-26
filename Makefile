CXX := g++

CXXFLAGS := -std=c++11 -Wall -Wextra -g

SRCS := main.cpp menu/menu.cpp
OBJS := $(SRCS:.cpp=.o)

TARGET := avl_tree_program

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp tree/tree.h menu/menu.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean
