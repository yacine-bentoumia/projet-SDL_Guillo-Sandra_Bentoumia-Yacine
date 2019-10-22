#include "chat1.h"
#include "constante.h"

void afficher_chat1(SDL_Renderer *ecran, SDL_Texture *chat1)
{

    SDL_Rect position_chat1;
    SDL_Rect image = sprite_chat1();

    position_chat1.x = 1200;
    position_chat1.y = 600;
    position_chat1.w = LARGEUR_CHAT;
    position_chat1.h = HAUTEUR_CHAT;



    // Pour le parcours pas à pas du chat, on a besoin de la gestion du temps

    int temps_precedent_chat1 = 0;
    int temps_actuel_chat1 = 0;

    temps_actuel_chat1 = SDL_GetTicks();

    while (temps_actuel_chat1 - temps_precedent_chat1 > 2)
    {

        position_chat1.x -= TAILLE_PAS;

        temps_precedent_chat1 = temps_actuel_chat1;
    }

    SDL_RenderCopy(ecran, chat1, &image, &position_chat1);
}

SDL_Rect sprite_chat1()
{
    SDL_Rect sprite;
    //sprite = malloc(sizeof(SDL_Rect) * NB_CASE_PERSO);

    sprite.x = 0;
    sprite.y = 125;
    sprite.w = 95;
    sprite.h = 125;

    return sprite;
}
/*
void deplacer_chat1(SDL_Renderer *ecran, SDL_Texture *chat1, SDL_Rect sprite, SDL_Rect emplacement_chat1)
{
}*/