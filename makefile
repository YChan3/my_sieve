all: main.o sieve.o
	gcc -o out main.o sieve.o -lm

main.o: main.c
	gcc -c main.c

sieve.o: sieve.c
	gcc -c sieve.c -lm

run:
	./out

clean:
	rm out
	rm *.o
