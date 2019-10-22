#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void afficher_chat1(SDL_Renderer* ecran , SDL_Texture *chat1)  ;

SDL_Rect sprite_chat1() ;


void deplacer_chat1(SDL_Renderer* ecran , SDL_Texture *chat1, SDL_Rect sprite, SDL_Rect emplacement_chat1)  ;
