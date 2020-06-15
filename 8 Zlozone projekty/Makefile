all: main.o libmath.dll
	gcc -o main main.o -L. -llibmath

main.o: main.c 
	gcc -Iinc -c main.c

libmath.dll: add.o sub.o
	gcc -shared -o libmath.dll add.o sub.o

add.o: add.s
	gcc -c add.s

sub.o: sub.c
	gcc -c -Iinc sub.c

clean:
	del main.exe add.o libmath.a sub.o main.o