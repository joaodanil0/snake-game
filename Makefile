
CC = g++
CCFLAGS = -g -Wall
LDFLAGS = -lm

all: launch

launch: launch.o board.o
	$(CC) $(LDFLAGS) -o launch launch.o Board.o

launch.o: launch.cpp
	$(CC) $(CCFLAGS) -c launch.cpp

board.o: */Board.cpp
	$(CC) $(CCFLAGS) -c */Board.cpp

clean:
		rm -rf *.o
		rm launch