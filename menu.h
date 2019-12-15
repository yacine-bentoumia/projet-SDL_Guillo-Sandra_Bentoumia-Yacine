#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fenetreDuJeu.h"



void choix_menu(SDL_Renderer* ecran, SDL_Texture *tableau);

//void choix_option(SDL_Renderer* ecran,SDL_Texture* commande);
void choix_option(SDL_Renderer* ecran,SDL_Texture* commande,SDL_Texture* fleche,SDL_Rect dest,int h , int w);

void choix_niveau(SDL_Renderer* ecran, SDL_Texture *tab_niv);

#endif