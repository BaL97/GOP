output: main.o menu.o
	g++ -std=c++0x -Wall main.o menu.o -o output

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.h
	g++ -c menu.cpp

clean:
	rm *.o output
