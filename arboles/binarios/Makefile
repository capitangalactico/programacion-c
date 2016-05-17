run:a.out
	./a.out
a.out:main.o arbol.o
	gcc main.o arbol.o
main.o:main.c
	gcc -c -Wall main.c
arbol.o:main.c
	gcc -c -Wall arbol.c
