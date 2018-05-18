output: main.cpp menu.o
	g++ main.cpp menu.o -o GOP
	@echo Main - Done
	@echo Everything Done!

menu.o: menu.cpp menu.h 
	g++ -c menu.cpp menu.h 
	@echo Menu - Done

clean:
	rm *.o GOP
	@echo Removed All!
