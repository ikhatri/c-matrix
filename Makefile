CXX = clang++
FLAGS = -std=c++11
OBJS = cmatrix.o mtcmatrix.o

.DEFAULT = all

all: main

main: main.cpp $(OBJS)
	$(CXX) $(FLAGS) $^ -o main -pthread

cmatrix.o: cmatrix.h cmatrix.cpp
	$(CXX) $(FLAGS) -c cmatrix.cpp

mtcmatrix.o: mtcmatrix.h mtcmatrix.cpp
	$(CXX) $(FLAGS) -c mtcmatrix.cpp

clean:
	rm cmatrix.o mtcmatrix.o main