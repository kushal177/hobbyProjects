CFLAGS=-c -Wall

assign1: main.o arrange.o
	gcc  main.o arrange.o -o assign1

main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o

arrange.o: arrange.c
	gcc $(CFLAGS) -c arrange.c -o arrange.o

clean:
	rm -rf *.o *~ assign1