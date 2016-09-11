# make dummy 'all' target
all: tmp/tables.o src/prototype.h tmp/jcc.o tmp/object.o main.c
	gcc -o bin/jcc main.c tmp/tables.o tmp/jcc.o tmp/object.o
	
# deps chain:
# prototype ->
# 	jcc.o ->
#		object.o ->
#			main.o
# build
main: tmp/objects.o tmp/closures.o
	gcc -o bin/jcc tmp/objects.o tmp/closures.o
######################
# build object files
######################
tmp/prototype.o: src/prototype.c src/prototype.h
	gcc -c src/prototype.c -o tmp/prototype.o

tmp/tables.o: deps/ckremm/src/tables/tables.h deps/ckremm/src/tables/tables.c
	gcc -c deps/ckremm/src/tables/tables.c -o tmp/tables.o

tmp/object.o: src/object.c src/object.h tmp/jcc.o
	gcc -c src/object.c tmp/jcc.o -o tmp/object.o

tmp/jcc.o: src/jcc.c src/jcc.h src/prototype.h tmp/tables.o
	gcc -c src/jcc.c tmp/tables.o -o tmp/jcc.o

#tmp/closures.o: src/closures.c src/closures.h
#	gcc -c src/closures.c -o tmp/closures.o

clean:
	rm -rf *.o
