
CC = g++
CCFLAGS = -g -Wall -Wextra #-Werror
LDFLAGS = -lncurses

TARGET = launch

all: $(TARGET)

$(TARGET): launch.o board.o game.o drawable.o apple.o empty.o snakepiece.o snake.o
	$(CC) -o launch launch.o Board.o Game.o Drawable.o Apple.o Empty.o SnakePiece.o Snake.o $(LDFLAGS)

launch.o: launch.cpp
	$(CC) $(CCFLAGS) -c launch.cpp

board.o: */*/Board.cpp
	$(CC) $(CCFLAGS) -c */*/Board.cpp

game.o: */*/Game.cpp
	$(CC) $(CCFLAGS) -c */*/Game.cpp

drawable.o: */*/Drawable.cpp
	$(CC) $(CCFLAGS) -c */*/Drawable.cpp

apple.o: */*/Apple.cpp
	$(CC) $(CCFLAGS) -c */*/Apple.cpp

empty.o: */*/Empty.cpp
	$(CC) $(CCFLAGS) -c */*/Empty.cpp

snakepiece.o: */*/SnakePiece.cpp
	$(CC) $(CCFLAGS) -c */*/SnakePiece.cpp

snake.o: */*/Snake.cpp
	$(CC) $(CCFLAGS) -c */*/Snake.cpp

clean:
		rm -rf *.o
		rm $(TARGET)