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


void personnage_jeu(SDL_Renderer* ecran ,int h, int w  , int positionY , SDL_Texture* perso , int numSprite,SDL_Rect* sprite, int affichage_position_x,int hauteur)  ;

SDL_Rect* sprite_personnage() ;

void deplacement_sur_map (int* debutX, int direction , int* positionX , int * affichage_position_x, int largeur) ;

bool collision(char *map, int direction ,int positionX, int positionY, int largeur);

//void gravite(int vitesse,  int *positionY);
void gravite(int direction, int *positionY, int hauteur);

bool collision_pied(char *map,  int positionX, int positionY, int largeur);

bool collision_tete(char *map, int positionX, int positionY, int largeur);

bool trou(char* map, int positionX, int positionY, int largeur);

void saut (int direction, int vitesse, int* positionY, int hauteur);

bool gagner(char *map,int positionX, int positionY, int largeur);