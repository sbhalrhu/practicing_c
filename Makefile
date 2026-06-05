CFLAGS = -Wall -Wextra -Werror -std=gnu11 -pedantic

all: clpractice

debug: CFLAGS += -g
debug: clean all

clpractice: clpractice.o
	gcc -o clpractice clpractice.o

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o