output: main.o menu.o
	g++ -std=c++0x -Wall main.o menu.o -o GOP

main.o: main.cpp
	g++ -c main.cpp
	@echo COMPILATO CON SUCCESSO

menu.o: menu.cpp menu.h
	g++ -c menu.cpp
	@echo COMPILATO CON SUCCESSO
	
	@echo 
	@echo TUTTI I FILE SONO STATI COMPILATI CON SUCCESSO
	
clean:
	rm *.o GOP
