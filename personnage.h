#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "constante.h"
#include "map.h"
#include "fenetreDuJeu.h"
#include "finDeJeu.h"


void personnage_jeu(SDL_Renderer* ecran ,int h, int w  , int positionY , SDL_Texture* perso , int numSprite,SDL_Rect* sprite, int affichage_position_x)  ;

SDL_Rect* sprite_personnage() ;

void deplacement_sur_map (int* debutX, int direction , int* positionX , int * affichage_position_x) ;

bool collision(int *map, int direction ,int positionX, int positionY);

//void gravite(int vitesse,  int *positionY);
void gravite(int direction, int *positionY);

bool collision_pied(int *map,  int positionX, int positionY);

bool collision_tete(int *map, int positionX, int positionY);

bool trou(int* map, int positionX, int positionY);

void saut (int direction, int vitesse, int* positionY);

bool gagner(int*map,int positionX, int positionY);