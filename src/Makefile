output: main.cpp menu.o game.o Carte.o Mazzo.o player.o box.o map.o
	g++ main.cpp menu.o game.o Carte.o Mazzo.o player.o box.o map.o -o ../GOP
	rm *.o *.h.gch
	@echo Main - Done
	@echo Everything Done!

box.o: box.cpp box.h
	g++ -c box.cpp box.h
	@echo Box - done

map.o: map.cpp map.h box.h
	g++ -c map.cpp map.h box.h
	@echo Map - done

game.o: game.cpp game.h menu.h Mazzo.h player.h map.h
	g++ -c game.cpp game.h menu.h Mazzo.h player.h map.h
	@echo GAME - Done

Mazzo.o: Mazzo.cpp Mazzo.h Carte.h
	g++ -c Mazzo.cpp Mazzo.h Carte.h
	@echo MAZZO - done

Carte.o: Carte.cpp Carte.h
	g++ -c Carte.cpp Carte.h
	@echo CARTE - done

player.o: player.cpp player.h
	g++ -c player.cpp player.h
	@echo PLAYER - done

menu.o: menu.cpp menu.h 
	g++ -c menu.cpp menu.h 
	@echo Menu - done

clean:
	rm ../GOP
	@echo Removed All!
