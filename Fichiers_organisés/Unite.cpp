#include "Unite.hpp"
using namespace std;

//constructeur de la classe Unite
Unite::Unite(int typeUnite,int positionUniteX,int positionUniteY,int id_joueur):
m_typeUnite(typeUnite),m_positionUniteX(positionUniteX),m_joueur(id_joueur),
m_positionUniteY(positionUniteY),m_ptsVie(100){
  if(typeUnite == 1){
    this->m_nomTypeUnite = "Artillerie";
    this->m_efficacite = {1.,1.,1.}; //artillerie, bazooka, tank
    this->m_prix = 1;
    this->m_porteeAttaque = {1,1};
  }
  if(typeUnite == 2){
    this->m_nomTypeUnite = "Bazooka";
    this->m_efficacite = {1.,1.,1.}; //artillerie, bazooka, tank
    this->m_prix = 1;
    this->m_porteeAttaque = {1,4};
  }
  if(typeUnite == 3){
    this->m_nomTypeUnite = "Tank";
    this->m_efficacite = {1.,1.,1.}; //artillerie, bazooka, tank
    //de quelle case à quelle case l'unite peut attaquer
    this->m_prix = 1;
    this->m_porteeAttaque = {2,4};
  }
}

int Unite::getTypeUnite(){
  return(this->m_typeUnite);
}

int Unite::getPositionX(){
  return(this->m_positionUniteX);
}

int Unite::getPositionY(){
  return(this->m_positionUniteY);
}
