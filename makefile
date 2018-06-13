/bin/sorts:  build build/main.o build/sorts.o 
		gcc build/main.o build/sorts.o -o bin/sorts

build/main.o: src/main.c
		gcc -Wall -g -c src/main.c -o build/main.o

build/sorts.o: src/sorts.c
		gcc -Wall -g -c src/sorts.c -o build/sorts.o

