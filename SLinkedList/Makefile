CC=gcc
CFLAGS=-Wall -Werror -g -std=c99
PROJ=list
OBJS=LinkedList.o test_list.o

all:$(PROJ)

$(PROJ):$(OBJS)
	$(CC) $(CFLAGS) -o $(PROJ) $(OBJS)

LinkedList.c:LinkedList.h
test_list.c:LinkedList.h
.c.o:
	$(CC) -c $(CFLAGS) $<
.PHONY:clean

clean:
	rm -f *.o *~ $(PROJ)
