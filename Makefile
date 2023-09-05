
CC = g++
CCFLAGS = -g -Wall
LDFLAGS = -lm

TARGET = launch

all: $(TARGET)

$(TARGET): launch.o board.o apple.o
	$(CC) $(LDFLAGS) -o launch launch.o Board.o Apple.o

launch.o: launch.cpp
	$(CC) $(CCFLAGS) -c launch.cpp

board.o: */Board.cpp
	$(CC) $(CCFLAGS) -c */Board.cpp

apple.o: */Apple.cpp
	$(CC) $(CCFLAGS) -c */Apple.cpp

clean:
		rm -rf *.o
		rm $(TARGET)