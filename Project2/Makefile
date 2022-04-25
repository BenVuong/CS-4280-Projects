OBJS	= main.o Parser.o Scanner.o TestTree.o TreeParser.o
SOURCE	= main.cpp Parser.cpp Scanner.cpp TestTree.cpp TreeParser.cpp
HEADER	= Node.h Parser.h Scanner.h TestTree.h Token.h TreeParser.h
OUT	= frontEnd
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

Parser.o: Parser.cpp
	$(CC) $(FLAGS) Parser.cpp -std=c++11

Scanner.o: Scanner.cpp
	$(CC) $(FLAGS) Scanner.cpp -std=c++11

TestTree.o: TestTree.cpp
	$(CC) $(FLAGS) TestTree.cpp -std=c++11

TreeParser.o: TreeParser.cpp
	$(CC) $(FLAGS) TreeParser.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)