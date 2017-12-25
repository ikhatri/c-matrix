CXX = clang++
FLAGS = -std=c++11
OBJS = cmatrix.o

.DEFAULT = all

all: main

main: main.cpp $(OBJS)
	$(CXX) $(FLAGS) $^ -o main

cmatrix.o: cmatrix.h cmatrix.cpp
	$(CXX) $(FLAGS) -c cmatrix.cpp

clean:
	rm cmatrix.o main