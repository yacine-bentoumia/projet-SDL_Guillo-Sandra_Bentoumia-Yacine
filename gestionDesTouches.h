#ifndef GESTIONDESTOUCHES_H
#define GESTIONDESTOUCHES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "finDeJeu.h"
#include "constante.h"
#include "personnage.h"
#include "map.h"


void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool * terminer,int *debutX, int *numSprite , int* positionX , int* positionY,
                                                int * affichage_position_x , int*map,int largeur, int hauteur, int* mode,int *num,int* numero) ;

#endif