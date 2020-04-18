#include "Game.hpp"
using namespace std;
#include "Joueur.hpp"
#include "Affichage.hpp"
#include "Case.hpp"
#include "Fonctions.hpp"


//constructeur de la classe Unite
Game::Game(){
}

void Game::initGame(Case** tabCases, Affichage affichage,Joueur Joueur1, Joueur Joueur2, int tabCarteChiffres[]){
  initMatriceCases(tabCases,tabCarteChiffres);
  Joueur1.initJoueur();
  Joueur2.initJoueur();
  initUniteCases(tabCases,Joueur1);
  initUniteCases(tabCases,Joueur2);
}

int Game::selectionX(int clickX){
  return(clickX-(GL_VIEW_WIDTH/2));
}

int Game::selectionY(int clickY){
  return(clickY/(LARGEUR_GRILLE*10));
}
