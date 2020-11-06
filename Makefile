all: Livro.o Eletronico.o Impresso.o AudioBook.o  main.cpp
	g++ -std=c++11 -o main main.cpp Livro.o Eletronico.o Impresso.o AudioBook.o

Livro.o: Livro.cpp
	g++ -std=c++11 -o Livro.o -c Livro.cpp

Eletronico.o: Eletronico.cpp
	g++ -std=c++11 -o Eletronico.o -c Eletronico.cpp

Impresso.o: Impresso.cpp
	g++ -std=c++11 -o Impresso.o -c Impresso.cpp

AudioBook.o: AudioBook.cpp
	g++ -std=c++11 -o AudioBook.o -c AudioBook.cpp

clean:
	rm -f *.o main

run:
	./main < input.txt> output.txt