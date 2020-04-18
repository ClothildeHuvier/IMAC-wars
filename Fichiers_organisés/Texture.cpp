#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include "Texture.h"

using namespace std;

int isLoaded (SDL_Surface* image) {
    if (image == NULL) {
        printf("Texture loading failed\n");
        SDL_Quit();
        return 0;
    }
    return 1;
}

GLuint setTexture(const char* filename) {
	// Chargement et traitement de la texture
    SDL_Surface *image = IMG_Load(filename);
    if(!image) {
        printf("IMG_Load: %s\n", IMG_GetError());
        return 0;
    }

    GLuint textureID;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Envoie des données texture à la carte graphique
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        image->w,
        image->h,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        image->pixels);

    // Libération des données CPU
    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(image);

    return textureID;
}
