#ifndef DEF_GAME
#define DEF_GAME

#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include "Joueur.hpp"
#include "Affichage.hpp"
#include "Case.hpp"
#include "Fonctions.hpp"

class Game{

  public:
  void initGame(Case** tabCases, Affichage affichage,Joueur Joueur1, Joueur Joueur2,int tabCarteChiffres[]);
  int selectionX(int clickX);
  int selectionY(int clickY);
Game();
};


#endif
