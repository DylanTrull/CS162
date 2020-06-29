Output: main.o Ant.o Menu.o Board.o InputValidation.o
	g++ main.o Ant.o Menu.o Board.o InputValidation.o -o output

main.o: main.cpp
	g++ -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp

InputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -c InputValidation.cpp



Clean:
	rm *.o output