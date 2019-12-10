#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constante.h"
#include "fenetreDuJeu.h"
#include "finDeJeu.h"

typedef struct Carte Carte ;
struct Carte{
    char* carteJeu ;
    int taille ;
    int hauteur ;
    int largeur ;
};


void carteDuJeu (SDL_Renderer* ecran, SDL_Texture* sol,SDL_Texture* ciel , SDL_Texture* obstacle ,SDL_Texture* trou, SDL_Texture* tour4, SDL_Texture* tour5, SDL_Texture* tour6, SDL_Texture* tour7, SDL_Texture* tour8, int w, int h,int debutX, SDL_Texture* gain, Carte map1);

int hauteur_une_case(int h, Carte map1) ;

int largeur_une_case(int w);

#endif
