#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "finDeJeu.h"

void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool * terminer,int *debutX, int *debutY,int *numSprite , int* positionX , int* positionY) ;