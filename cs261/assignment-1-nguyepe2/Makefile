CC=gcc --std=c99 -g

all: test

students.o: students.c students.h
	$(CC) -c students.c

test: test.c students.o
	$(CC) test.c students.o -o test

clean:
	rm -f test students.o
