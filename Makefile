
CFLAGS = -g -Wall -Werror -std=c++20
CC = g++

yettoku: yettoku.o grid.o main.o
	$(CC) $(CFLAGS) -o yettoku yettoku.o grid.o main.o 


main.o: main.cpp yettoku.hpp
	$(CC) $(CFLAGS) -c main.cpp 

yettoku.o: yettoku.cpp yettoku.hpp
	$(CC) $(CFLAGS) -c yettoku.cpp

grid.o: grid.cpp yettoku.hpp
	$(CC) $(CFLAGS) -c grid.cpp
#
# Clean the src directory
#
clean:
	rm -rf *.o
	rm -f csim: