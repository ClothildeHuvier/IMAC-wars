#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include "Joueur.hpp"
#include "Unite.hpp"

Joueur:: Joueur(int id,std::string pseudo):
m_id(id), m_pseudo(pseudo) {
}

void Joueur::initJoueur(){
    int x = 0;
    if (this->m_id == 2){
       x = LONGUEUR_GRILLE-1;
    }
    Unite* newUnite1 = new Unite(1,x,0,this->m_id);
    Unite* newUnite2 = new Unite(1,x,1,this->m_id);
    Unite* newUnite3 = new Unite(2,x,2,this->m_id);
    Unite* newUnite4 = new Unite(3,x,3,this->m_id);
    this->m_tabUnites = {newUnite1,newUnite2,newUnite3,newUnite4};
}

Unite* Joueur::getTabUnite(int i){
  return(this->m_tabUnites[i]);
}
