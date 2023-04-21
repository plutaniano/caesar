CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
OBJ = src/main.o src/caesar.o
EXECUTABLE = caesar

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

src/main.o: src/main.c src/caesar.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/caesar.o: src/caesar.c src/caesar.h
	$(CC) $(CFLAGS) -c src/caesar.c -o src/caesar.o

clean:
	rm -f $(OBJ) $(EXECUTABLE)

