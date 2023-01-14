all: compila

compila: main.o funzioni.o
	g++ main.o funzioni.o -o compila

main.o: es2.1.cc funzioni.h
	g++ -c es2.1.cc -o main.o

funzioni.o: funzioni.cc funzioni.h
	g++ -c funzioni.cc -o funzioni.o

clean: 
	rm compila
	rm *.o