output: main.o menu.o
	g++ main.o menu.o -o GOP

main.o: main.cpp
	g++ -c main.cpp
	@echo Main - DONE!

menu.o: menu.cpp menu.h
	g++ -c menu.cpp
	@echo Menu - DONE!
	
	@echo 
	@echo Everything DONE!
	
clean:
	rm *.o GOP
	@echo Removed All!
