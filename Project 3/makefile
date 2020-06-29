output: main.o Game.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o InputValidation.o
	g++ main.o Game.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o InputValidation.o -o output
	
main.o: main.cpp
	g++ -c main.cpp
	
Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp
	
Character.o: Character.cpp Character.hpp
	g++ -c Character.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp
	
Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

InputValidation.o: InputValidation.cpp
	g++ -c InputValidation.cpp

clean: 
	rm *.o output