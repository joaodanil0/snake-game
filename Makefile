
CC = g++
CCFLAGS = -g -Wall -Werror -Wextra
LDFLAGS = -lncurses

TARGET = launch

all: $(TARGET)

$(TARGET): launch.o board.o
	$(CC) -o launch launch.o Board.o $(LDFLAGS)

launch.o: launch.cpp
	$(CC) $(CCFLAGS) -c launch.cpp

board.o: */*/Board.cpp
	$(CC) $(CCFLAGS) -c */*/Board.cpp

# apple.o: */Apple.cpp
# 	$(CC) $(CCFLAGS) -c */Apple.cpp

clean:
		rm -rf *.o
		rm $(TARGET)