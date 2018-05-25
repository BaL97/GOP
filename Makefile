output: main.cpp menu.o game.o
	g++ main.cpp menu.o game.o -o GOP
	@echo Main - Done
	@echo Everything Done!

game.o: game.cpp game.h menu.h
	g++ -c game.cpp game.h menu.h
	@echo GAME - Done

menu.o: menu.cpp menu.h 
	g++ -c menu.cpp menu.h 
	@echo Menu - Done

clean:
	rm *.o GOP
	@echo Removed All!
