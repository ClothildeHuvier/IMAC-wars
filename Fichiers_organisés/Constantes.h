#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Texture.h"

/* Dimensions initiales et titre de la fenetre */
static const unsigned int WINDOW_WIDTH = 500;
static const unsigned int WINDOW_HEIGHT = 400;
static const char WINDOW_TITLE[] = "IMAC";

/* Espace fenetre virtuelle */
static const float GL_VIEW_WIDTH = 800;
static const float GL_VIEW_HEIGHT = 400;

const int NBUNITE = 4;
/* Nombre de bits par pixel de la fenetre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

int const LARGEUR_GRILLE = 4;
int const LONGUEUR_GRILLE = 5;


static const char* filenamePlaine = "./plainesImacWars2.BMP";
static const char* filenameForet = "./logo_imac.png";
static const char* filenameMer = "./Mer.png";
static const char* filenameVille = "./Ville.png";
static const char* filenameMontagne = "./Montagne.png";
