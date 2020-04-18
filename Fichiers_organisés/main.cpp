#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Case.hpp"
#include "Texture.h"
#include "Constantes.h"
#include "Affichage.hpp"
#include "Fonctions.hpp"
#include "Unite.hpp"
#include "Joueur.hpp"
#include "Game.hpp"

Case** tabCases=(Case**)malloc(LARGEUR_GRILLE*LONGUEUR_GRILLE * sizeof(Case*));
int tabCarteChiffres[LARGEUR_GRILLE*LONGUEUR_GRILLE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Affichage affichage (0,0,LONGUEUR_GRILLE,LARGEUR_GRILLE,GL_VIEW_WIDTH,GL_VIEW_HEIGHT);
Joueur Joueur1 (1,"Valou");
Joueur Joueur2 (2,"Malo");
Game newGame;


int main(){
//Tests//////////////////////////////////////////////////////////////////////////////
    newGame.initGame(tabCases,affichage,Joueur1,Joueur2,tabCarteChiffres);
    affichage.genereTabUnite(tabCases); //ne marche plus si je me mets dans initGame
//////////////////////////////////////////////////////////////////////////////////

    /* Initialisation de la SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(
            stderr,
            "Impossible d'initialiser la SDL. Fin du programme.\n");
        exit(EXIT_FAILURE);
    }

    /* Ouverture d'une fenetre et creation d'un contexte OpenGL */
    SDL_Surface* surface;
    surface = SDL_SetVideoMode(
        WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL,
        SDL_OPENGL | SDL_GL_DOUBLEBUFFER);
    glViewport(0, 0, (surface)->w, (surface)->h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(
        -GL_VIEW_WIDTH/2, GL_VIEW_WIDTH/2,
        -GL_VIEW_HEIGHT/2, GL_VIEW_HEIGHT/2);

    if(NULL == surface) {
        fprintf(
            stderr,
            "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    /* Initialisation du titre de la fenetre */
    SDL_WM_SetCaption(WINDOW_TITLE, NULL);

   affichage.initAffichage();

    int loop = 1;
    while(loop){
    	affichage.affichageCarte(tabCarteChiffres);
      affichage.afficheUnites();
    SDL_GL_SwapBuffers();


      /* Boucle traitant les evenements */
      SDL_Event e;
      while(SDL_PollEvent(&e)){
          /* L'utilisateur ferme la fenetre : */
          if(e.type == SDL_QUIT)
          {
              loop = 0;
              break;
          }
          /* L'utilisateur ferme la fenetre : */
          if(e.type == SDL_QUIT){
            loop = 0;
            break;
          }
          switch(e.type) {
                /* Clic souris */
                case SDL_MOUSEBUTTONUP:
                  printf("clic en (%d, %d)\n", e.button.x, e.button.y);
                  cout << newGame.selectionX( e.button.x)<<endl;
                  cout << newGame.selectionY( e.button.y)<<endl;
                  break;

                default:
                  break;
          }
        }
      }

    affichage.liberationMemoire();
    return EXIT_SUCCESS;

}
