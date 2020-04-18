#ifndef DEF_UNITE
#define DEF_UNITE

#include <iostream>
using namespace std;
#include <cstring>
#include <vector>

class Unite{
//  private:
  public:
    int m_typeUnite;
    std::string m_nomTypeUnite;
    int m_ptsVie;
    vector <int> m_porteeAttaque;//permet de stocker
    //de quelle case à quelle case l'unite peut attaquer
    int m_prix;
    vector <float> m_efficacite; //on stocke ici les efficacités d'attaque en fonction du type d'unite attaquée
    //positions
    int m_positionUniteX;
    int m_positionUniteY;
    int m_joueur;
// public:

    int getPositionX();
    int getPositionY();
    int getTypeUnite();

Unite(int typeCase, int positionUniteX, int positionUniteY,int id_joueur);
};


#endif
