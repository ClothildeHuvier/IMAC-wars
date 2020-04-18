# makefile
#OPT = -O2
OPT = -O0 -g
all: imacwars2

imacwars2: main.o Affichage.o Case.o Texture.o Fonctions.o Unite.o Joueur.o Game.o
	g++ $(OPT) -o imacwars2 main.o Affichage.o Case.o Texture.o Fonctions.o Unite.o Joueur.o Game.o -Wall -lstdc++ -lSDL -lSDL_image -lGLU -lGL -lm

main.o: main.cpp Affichage.hpp Case.hpp Texture.h Constantes.h Fonctions.hpp Unite.hpp Joueur.hpp Game.hpp
	g++ $(OPT) -c main.cpp -Wall -lSDL -lSDL_image -lGLU -lGL -lm

Affichage.o: Affichage.cpp Affichage.hpp
	g++ $(OPT) -c Affichage.cpp -Wall -lSDL -lSDL_image -lGLU -lGL -lm

Case.o: Case.cpp Case.hpp
	g++ $(OPT) -c Case.cpp -Wall -lSDL -lSDL_image -lGLU -lGL -lm

Texture.o: Texture.cpp Texture.h
	g++ $(OPT) -c Texture.cpp -Wall -lSDL -lSDL_image -lGLU -lGL -lm

Fonctions.o: Fonctions.cpp Fonctions.hpp
	g++ $(OPT) -c Fonctions.cpp -Wall -lSDL -lSDL_image -lGLU -lGL -lm

Unite.o: Unite.cpp Unite.hpp
	g++ $(OPT) -c Unite.cpp -Wall -lSDL -lSDL_image -lGLU -lGL -lm

Joueur.o: Joueur.cpp Joueur.hpp
	g++ $(OPT) -c Joueur.cpp -Wall -lSDL -lSDL_image -lGLU -lGL -lm

Game.o: Game.cpp Game.hpp
	g++ $(OPT) -c Game.cpp -Wall -lSDL -lSDL_image -lGLU -lGL -lm
clean:
	rm *.o
