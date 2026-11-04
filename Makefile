CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET   = matrix
OBJS     = main.o Matrix.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
