#ifndef PERSONNAGE_H
#define PERSONNAGE_H

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


void personnage_jeu(SDL_Renderer* ecran ,int h, int w  , int positionY , SDL_Texture* perso , int numSprite,SDL_Rect* sprite, int affichage_position_x, Carte map1)  ;

SDL_Rect* sprite_personnage() ;

void deplacement_sur_map (int* debutX, int direction , int* positionX , int * affichage_position_x, Carte map1) ;

bool collision(int direction ,int positionX, int positionY, Carte map1);

void gravite(int direction, int *positionY, Carte map1);

bool collision_pied(int positionX, int positionY, Carte map1);

void collision_tete(int positionX, int positionY, Carte map1, int* vitesse);

bool collision_balle(int positionX,int positionY,Carte map1,int taille, SDL_Rect* pos_tab,int h,int w);

bool perte_de_vie(int positionX,int positionY,Carte map1);

bool trou(int positionX, int positionY, Carte map1);

void saut (int direction, int vitesse, int* positionY, Carte map1);

bool gagner(int positionX, int positionY, Carte map1);

void vie_du_personnage(SDL_Renderer *ecran,SDL_Texture *vie,int vie_perso);

void nb_vie_perso(int positionX,int positionY,Carte map1,int* nb_vie,int *posX,int *posY);

#endif