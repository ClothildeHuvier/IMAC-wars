#ifndef DEF_CASE
#define DEF_CASE

#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include "Unite.hpp"

class Case{
public:
  //---Attributs---
  int m_typeCase ;
  std::string m_nomTypeCase;
  vector <int> m_accessibilites;
  Unite *m_unite;

// public:
  void recevoirUnite(Unite* unite);
  void retirUnite();
  bool presenceUnite();

  Unite* getPointeurUnite();
  void setPointeurUnite(Unite* pointeurUnite);

 Case(int typeCase);
};


#endif
