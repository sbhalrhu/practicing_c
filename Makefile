CFLAGS = -Wall -Wextra -std=gnu11 -pedantic

all: parent child finalq2

debug: CFLAGS += -g
debug: clean all

finalq2: finalq2.o
	gcc -o finalq2 finalq2.o

child: child.o
	gcc -o child child.o

parent: parent.o
	gcc -o parent parent.o

%.o: %.c
	gcc $(CFLAGS) -c $<


clean: 
	rm -f *.o