#ifndef DEF_AFFICHAGE
#define DEF_AFFICHAGE

#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Unite.hpp"
#include "Case.hpp"
#include "Constantes.h"

class Affichage{
  private:
    int m_posX;
    int m_posY;
    int m_cellsCountX;
    int m_cellsCountY;
    int m_width;
    int m_height;
    int m_tabGrilleUnite[LONGUEUR_GRILLE*LARGEUR_GRILLE];

    GLuint m_textureForet;
    GLuint m_textureMontagne;
    GLuint m_textureVille;
    GLuint m_texturePlaine;
    GLuint m_textureMer;

    void affichageElement(int i, int j,GLuint textureID);

    //converti les cooronnées fenetres en coordonnées OpenGL
    float conversionX (float x);
    float conversionY (float y);

  public:
    void initAffichage();
    void genereTabUnite(Case** tabCases);
    void affichageCarte(int tabgrille[]);
    void liberationMemoire();
    void afficheUnites();

      //Constructeur
      Affichage(int posX, int posY,
      int cellsCountX, int cellsCountY, int width, int height);
  };

#endif
