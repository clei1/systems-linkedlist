all: linked_list.c linked_list.h
	gcc -o linked_list.o linked_list.c

run: all
	./linked_list.o

clean:
	rm *.o
	rm *~
