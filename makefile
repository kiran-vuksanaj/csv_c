all: main.o csv.o
	gcc -o driver main.o csv.o
main.o: main.c csv.h
	gcc -c main.c
csv.o: csv.c csv.h
	gcc -c csv.c
run:
	./driver
clean:
	rm *.o
	rm driver
	rm *~
grind:
	valgrind ./driver
