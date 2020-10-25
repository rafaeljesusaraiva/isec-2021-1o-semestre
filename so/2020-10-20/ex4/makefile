FLAGS=-D DEBUG

ex4: programa.o imprime.o
	gcc programa.o imprime.o -o ex4

programa.o: programa.c imprime.h
	gcc $(FLAGS) programa.c -c 

imprime.o: imprime.c
	gcc $(FLAGS) imprime.c -c

limpa:
	rm *.o

instala:
	echo 'Vou instalar... (copiar)'