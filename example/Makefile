
CC=g++
CLAGS=-Wall -Wextra -Wpedantic -Werror -std=c++11

.PHONY: default all clean

default: all

all: main.o
	$(CC) -o main main.o

main.o: main.cpp ../easyTimer.hpp
	$(CC) $(CLAGS) -c main.cpp

clean:
	- rm *.o main

run: clean all
	./main

