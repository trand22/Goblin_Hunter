goblinHunter: Armory.o BossDungeon.o Room.o FirstDungeon.o Goblin.o GoblinCaptain.o Hero.o Infirmary.o Lobby.o Main.o Map.o SecondDungeon.o Space.o UtilityFunctions.o
	g++ -std=c++11 Armory.o BossDungeon.o Room.o FirstDungeon.o Goblin.o GoblinCaptain.o Hero.o Infirmary.o Lobby.o Main.o Map.o SecondDungeon.o Space.o UtilityFunctions.o -o goblinHunter

Armory.o: Armory.cpp
	g++ -c -std=c++11 Armory.cpp

BossDungeon.o: BossDungeon.cpp
	g++ -c -std=c++11 BossDungeon.cpp

Room.o: Room.cpp
	g++ -c -std=c++11 Room.cpp

FirstDungeon.o: FirstDungeon.cpp
	g++ -c -std=c++11 FirstDungeon.cpp

Goblin.o: Goblin.cpp
	g++ -c -std=c++11 Goblin.cpp

GoblinCaptain.o: GoblinCaptain.cpp
	g++ -c -std=c++11 GoblinCaptain.cpp

Hero.o: Hero.cpp
	g++ -c -std=c++11 Hero.cpp

Infirmary.o: Infirmary.cpp
	g++ -c -std=c++11 Infirmary.cpp

Lobby.o: Lobby.cpp
	g++ -c -std=c++11 Lobby.cpp

Main.o: Main.cpp
	g++ -c -std=c++11 Main.cpp

Map.o: Map.cpp
	g++ -c -std=c++11 Map.cpp

SecondDungeon.o: SecondDungeon.cpp
	g++ -c -std=c++11 SecondDungeon.cpp

Space.o: Space.cpp
	g++ -c -std=c++11 Space.cpp

UtilityFunctions.o: UtilityFunctions.cpp
	g++ -c -std=c++11 UtilityFunctions.cpp

clean:
	rm *.o goblinHunter
