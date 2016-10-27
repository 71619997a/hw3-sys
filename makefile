all: randfile.o
	gcc -o RAND.out randfile.o

randfile.o: randfile.c
	gcc -c randfile.c

run: RAND.out
	./RAND.out


clean:
	rm *.txt
	rm *.out
	rm *.o
