#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef ANIM_H
#define ANIM_H

void anim_saut(SDL_Event evenements, SDL_Window *fenetre, SDL_Renderer *ecran, SDL_Texture *raccoon, SDL_Rect sprite_raccoon, SDL_Rect emplacement_raccoon);

void anim_tir(SDL_Event evenements, SDL_Renderer *ecran,
              SDL_Texture *balle, SDL_Rect sprite_balle, SDL_Rect emplacement_balle,
              SDL_Texture *raccoon, SDL_Rect sprite_raccoon, SDL_Rect emplacement_raccoon,
              SDL_Texture *chat_level1, SDL_Rect sprite_chat_level1, SDL_Rect emplacement_chat_level1);

void anim_r(SDL_Event evenements, SDL_Renderer *ecran, SDL_Texture *raccoon, SDL_Rect sprite_raccoon, SDL_Rect emplacement_raccoon);

void anim_chat1(SDL_Event evenements, SDL_Renderer *ecran, SDL_Texture *chat1, SDL_Rect sprite_chat1, SDL_Rect emplacement_chat1);

void anim_chat2(SDL_Event evenements, SDL_Renderer *ecran, SDL_Texture *chat2, SDL_Rect sprite_chat2, SDL_Rect emplacement_chat2);




#endif