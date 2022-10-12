all: prog

prog: fibonacci.o factorial.o copystring.o main.o 
	g++ -std=c++11 fibonacci.o factorial.o copystring.o main.o -o prog

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

copystring.o: copystring.cpp copystring.h
	g++ -std=c++11 -c copystring.cpp -o copystring.o

fibonacci.o: fibonacci.cpp fibonacci.h
	g++ -std=c++11 -c fibonacci.cpp -o fibonacci.o

factorial.o: factorial.cpp factorial.h
	g++ -std=c++11 -c factorial.cpp -o factorial.o

clean:
	rm -f *.o prog