all: prog

prog: main.o library.o comic.o novel.o magazine.o document.o
		g++ -std=c++11 -O2 -Wall main.o library.o comic.o novel.o magazine.o document.o -o prog

main.o: main.cpp
		g++ -std=c++11 -O2 -Wall -c main.cpp -o main.o

library.o: library.cpp library.h
		g++ -std=c++11 -O2 -Wall -c library.cpp -o library.o

comic.o: comic.cpp comic.h
		g++ -std=c++11 -O2 -Wall -c comic.cpp -o comic.o

novel.o: novel.cpp novel.h
		g++ -std=c++11 -O2 -Wall -c novel.cpp -o novel.o

magazine.o: magazine.cpp magazine.h
		g++ -std=c++11 -O2 -Wall -c magazine.cpp -o magazine.o

document.o: document.cpp document.h
		g++ -std=c++11 -O2 -Wall -c document.cpp -o document.o

clean:
		rm -f *.o prog