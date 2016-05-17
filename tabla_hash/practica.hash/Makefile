run:a.out
	./a.out test.txt
a.out:main.o hash.o
	gcc main.o hash.o
main.o:main.c
	gcc -c main.c
hash.o:hash.c
	gcc -c hash.c
clear:
	rm main.o hash.o a.out
