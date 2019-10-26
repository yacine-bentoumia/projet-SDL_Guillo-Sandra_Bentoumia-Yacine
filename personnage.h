#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constante.h"
#include "map.h"
#include "fenetreDuJeu.h"
#include "finDeJeu.h"


void personnage_jeu(SDL_Renderer* ecran ,int h, int w  , int positionY , SDL_Texture* perso , int numSprite,SDL_Rect* sprite, int affichage_position_x)  ;

SDL_Rect* sprite_personnage() ;

void deplacement_sur_map (int* debutX, int direction , int* positionX , int* positionY,int * affichage_position_x) ;

bool collision(int* map,int direction ,int positionX, int positionY);

bool trou(int* map, int positionX, int positionY);