
CC = g++
CCFLAGS = -g -Wall -Wextra #-Werror
LDFLAGS = -lncurses

TARGET = launch

all: $(TARGET)

$(TARGET): launch.o board.o game.o drawable.o
	$(CC) -o launch launch.o Board.o Game.o Drawable.o $(LDFLAGS)

launch.o: launch.cpp
	$(CC) $(CCFLAGS) -c launch.cpp

board.o: */*/Board.cpp
	$(CC) $(CCFLAGS) -c */*/Board.cpp

game.o: */*/Game.cpp
	$(CC) $(CCFLAGS) -c */*/Game.cpp

drawable.o: */*/Drawable.cpp
	$(CC) $(CCFLAGS) -c */*/Drawable.cpp

clean:
		rm -rf *.o
		rm $(TARGET)