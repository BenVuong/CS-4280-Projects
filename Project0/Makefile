OBJS	= main.o BuildTree.o Traversals.o
SOURCE	= main.cpp BuildTree.cpp Traversals.cpp
HEADER	= BuildTree.h Node.h Traversals.h
OUT	= p0
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

BuildTree.o: BuildTree.cpp
	$(CC) $(FLAGS) BuildTree.cpp -std=c++11

Traversals.o: Traversals.cpp
	$(CC) $(FLAGS) Traversals.cpp -std=c++11


clean:
	rm -f main.o