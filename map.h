#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constante.h"
#include "fenetreDuJeu.h"
#include "finDeJeu.h"




void carteDuJeu (SDL_Renderer* ecran, SDL_Texture* sol,SDL_Texture* ciel , SDL_Texture* obstacle ,SDL_Texture* trou, SDL_Texture* tour4, SDL_Texture* tour5, int w, int h,int debutX, char* map, SDL_Texture* gain,int largeur, int hauteur);

int hauteur_une_case(int h, int hauteur) ;

int largeur_une_case(int w);

