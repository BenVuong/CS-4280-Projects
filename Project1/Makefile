OBJS	= main.o Scanner.o TestScanner.o
SOURCE	= main.cpp Scanner.cpp TestScanner.cpp
HEADER	= Scanner.h TestScanner.h Token.h
OUT	= p1
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

Scanner.o: Scanner.cpp
	$(CC) $(FLAGS) Scanner.cpp -std=c++11

TestScanner.o: TestScanner.cpp
	$(CC) $(FLAGS) TestScanner.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)