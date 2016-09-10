# make dummy 'all' target
all:
	

# build
main: tmp/objects.o tmp/closures.o
	gcc -o bin/jcc tmp/objects.o tmp/closures.o
######################
# build object files
######################
tmp/objects.o: src/objects.c src/objects.h
	gcc -c src/objects.c -o tmp/objects.o

tmp/closures.o: src/closures.c src/closures.h
	gcc -c src/closures.c -o tmp/closures.o

clean:
	rm -rf *.o
