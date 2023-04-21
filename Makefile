CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
OBJ = src/main.o src/caeser.o
EXECUTABLE = caesar

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

src/main.o: src/main.c src/caeser.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/caeser.o: src/caeser.c src/caeser.h
	$(CC) $(CFLAGS) -c src/caeser.c -o src/caeser.o

clean:
	rm -f $(OBJ) $(EXECUTABLE)

