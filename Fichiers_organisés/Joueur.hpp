#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include "Constantes.h"
#include "Unite.hpp"

class Joueur{
//  private:
  public:
    int m_id;
    std::string m_pseudo;
    std::vector<Unite*> m_tabUnites; //tableau dynamique contenant toutes les unités du joueur

  //  public:
    void initJoueur();
    Unite* getTabUnite(int i);
    Joueur(int id, std::string);
};

#endif
