CC = gcc
CFLAGS = -Wall

all: validator

validator: validator.c
	$(CC) -o validator validator.c $(CFLAGS)

clean:
	rm -f validator
