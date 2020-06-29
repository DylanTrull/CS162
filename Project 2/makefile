Output: main.o Animal.o Zoo.o Tiger.o Penguin.o Turtle.o InputValidation.o
	g++ main.o Animal.o Zoo.o Tiger.o Penguin.o Turtle.o InputValidation.o -o output

main.o: main.cpp
	g++ -c main.cpp

Zoo.o:	Zoo.cpp Zoo.hpp
	g++ -c Zoo.cpp

Animal.o:	Animal.cpp Animal.hpp
	g++ -c Animal.cpp

Tiger.o:	Tiger.cpp Tiger.hpp
	g++ -c Tiger.cpp

Penguin.o:	Penguin.cpp Penguin.hpp
	g++ -c Penguin.cpp

Turtle.o:	Turtle.cpp Turtle.hpp
	g++ -c Turtle.cpp

InputValidation.o:	InputValidation.cpp
	g++ -c InputValidation.cpp







Clean:
	rm *.o output