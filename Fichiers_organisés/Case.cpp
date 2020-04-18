#include "Case.hpp"
using namespace std;

void Case::recevoirUnite(Unite* unite){
  this->m_unite = unite;
}

void Case::retirUnite(){
  this->m_unite = NULL;
}

bool Case::presenceUnite(){
  return(this->m_unite!=NULL);
}

Unite* Case::getPointeurUnite(){
  return(this->m_unite);
}

void Case::setPointeurUnite(Unite* pointeurUnite){
  this->m_unite = pointeurUnite;
}

//constructeur de la classe case
Case::Case(int typeCase):
m_typeCase(typeCase), m_unite(NULL){
  if(typeCase == 0){
    this->m_nomTypeCase = "Plaine";
    this->m_accessibilites = {1,1,1}; //artillerie, bazooka, tank
  }
  if(typeCase == 1){
    this->m_nomTypeCase = "Foret";
    this->m_accessibilites = {1,1,0}; //artillerie, bazooka, tank
  }
  if(typeCase == 2){
    this->m_nomTypeCase = "Montagne";
    this->m_accessibilites = {0,0,0}; //artillerie, bazooka, tank
  }
  if(typeCase == 3){
    this->m_nomTypeCase = "Mer";
    this->m_accessibilites = {0,0,0}; //artillerie, bazooka, tank
  }
  if(typeCase == 4){
    this->m_nomTypeCase = "Mer";
    this->m_accessibilites = {1,1,1}; //artillerie, bazooka, tank
  }
}
