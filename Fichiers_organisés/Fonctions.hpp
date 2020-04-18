#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Unite.hpp"
#include "Joueur.hpp"

void initMatriceCases(Case* tabCases[],int tabGrille[]);
void initUniteCases(Case* tabCases[],Joueur joueur);
