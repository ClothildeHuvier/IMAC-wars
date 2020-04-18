#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Affichage.hpp"
#include "Constantes.h"
#include "Unite.hpp"
#include "Case.hpp"

void Affichage::genereTabUnite(Case** tabCases){
  for (int i = 0; i< LONGUEUR_GRILLE; i++){
    for(int j = 0; j< LARGEUR_GRILLE;j++){
      if(tabCases[j*LONGUEUR_GRILLE+i]->presenceUnite()){
        this->m_tabGrilleUnite[j*LONGUEUR_GRILLE+i]=
        tabCases[j*LONGUEUR_GRILLE+i]->getPointeurUnite()->getTypeUnite();
          }else{
        this->m_tabGrilleUnite[j*LONGUEUR_GRILLE+i]=0;
      }
    }
  }
}

void Affichage::affichageElement(int i, int j,GLuint textureID){
  int x = this->m_width/this->m_cellsCountX;
  int y = this->m_height/this->m_cellsCountY;
  glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
      glBegin(GL_QUADS);
      glTexCoord2f(0, 1);
      glVertex2f(conversionX(i*x),conversionY((j+1)*y));
      glTexCoord2f(1, 1);
      glVertex2f(conversionX((i+1)*x),conversionY((j+1)*y));
      glTexCoord2f(1, 0);
      glVertex2f(conversionX((i+1)*x), conversionY(j*y));
      glTexCoord2f(0, 0);
      glVertex2f(conversionX(i*x),conversionY(j*y));
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
  glPopMatrix();
}

//converti les cooronnées fenetres en coordonnées OpenGL
float Affichage::conversionX (float x){
  x=x/GL_VIEW_WIDTH-0.5;
  x = x*(GL_VIEW_WIDTH);
  return x;
}

float Affichage::conversionY (float y){
  y=y/GL_VIEW_HEIGHT-0.5;
  y = y*(GL_VIEW_HEIGHT)*-1;
  return y;
}

void Affichage::initAffichage(){
  this->m_textureForet = setTexture(filenameForet);
  this->m_textureMontagne = setTexture(filenameMontagne);
  this->m_textureVille = setTexture(filenameVille);
  this->m_texturePlaine = setTexture(filenamePlaine);
  this->m_textureMer = setTexture(filenameMer);
}

void Affichage::affichageCarte(int tabgrille[]){
  int parcourtTab= this -> m_cellsCountX;
  for (int i = 0; i< this->m_cellsCountX; i++){
    for (int j = 0; j< this->m_cellsCountY; j++){
      if (tabgrille[j*parcourtTab+i] == 0)
        affichageElement(i,j,m_texturePlaine);
      if (tabgrille[j*parcourtTab+i] == 1)
        affichageElement(i,j,m_textureForet);
      if (tabgrille[j*parcourtTab+i] == 2)
        affichageElement(i,j,m_textureMontagne);
      if (tabgrille[j*parcourtTab+i] == 3)
        affichageElement(i,j,m_textureMer);
      if (tabgrille[j*parcourtTab+i] == 4)
        affichageElement(i,j,m_textureVille);
    }
  }
}

void Affichage::afficheUnites(){
  for (int i = 0; i< LONGUEUR_GRILLE; i++){
    for (int j = 0; j< LARGEUR_GRILLE; j++){
      if (this->m_tabGrilleUnite[j*LONGUEUR_GRILLE+i] == 1)
        affichageElement(i,j,m_textureForet);
      if (this->m_tabGrilleUnite[j*LONGUEUR_GRILLE+i] == 2)
        affichageElement(i,j,m_textureMontagne);
      if (this->m_tabGrilleUnite[j*LONGUEUR_GRILLE+i] == 3)
        affichageElement(i,j,m_textureMer);
    }
  }
}

void Affichage::liberationMemoire(){
  /******* Libération des données GPU *************/
  glDeleteTextures(1, &m_textureForet);
  glDeleteTextures(1, &m_textureMontagne);
  glDeleteTextures(1, &m_textureVille);
  glDeleteTextures(1, &m_texturePlaine);
  glDeleteTextures(1, &m_textureMer);
  /*** Liberation des ressources de la SDL ******/
  SDL_Quit();
}

    //Constructeur
Affichage::Affichage(int posX, int posY, int cellsCountX, int cellsCountY, int width, int height):
 m_posX(conversionX (posX)),  m_posY(conversionY (posY)), m_cellsCountX(cellsCountX), m_cellsCountY(cellsCountY),m_width(width), m_height(height)
{}
