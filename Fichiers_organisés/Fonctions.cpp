#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include "Case.hpp"
#include "Constantes.h"
#include "Unite.hpp"
#include "Fonctions.hpp"


void initMatriceCases(Case* tabCases[], int tabGrille[]){
  for(int i = 0; i< LONGUEUR_GRILLE; i++){
    for(int j = 0; j< LARGEUR_GRILLE; j++){
      tabCases[LONGUEUR_GRILLE*j+i] = new Case(tabGrille[LONGUEUR_GRILLE*j+i]);
    }
  }
}

void initUniteCases(Case* tabCases[],Joueur joueur){
  for(int i = 0; i< NBUNITE; i++){
    int x = (joueur.getTabUnite(i))->getPositionX();
    int y = (joueur.getTabUnite(i))->getPositionY();
    tabCases[y*LONGUEUR_GRILLE+x]->setPointeurUnite(joueur.getTabUnite(i));
  }
}
