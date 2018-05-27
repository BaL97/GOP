output: main.cpp menu.o game.o Carte.o Mazzo.o
	g++ main.cpp menu.o game.o Carte.o Mazzo.o -o GOP
	@echo Main - Done
	@echo Everything Done!

game.o: game.cpp game.h menu.h Mazzo.h
	g++ -c game.cpp game.h menu.h Mazzo.h
	@echo GAME - Done

Mazzo.o: Mazzo.cpp Mazzo.h Carte.h
	g++ -c Mazzo.cpp Mazzo.h Carte.h
	@echo MAZZO - done

Carte.o: Carte.cpp Carte.h
	g++ -c Carte.cpp Carte.h
	@echo CARTE - done

menu.o: menu.cpp menu.h 
	g++ -c menu.cpp menu.h 
	@echo Menu - Done

clean:
	rm *.o GOP
	@echo Removed All!
