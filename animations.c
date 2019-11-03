#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "animations.h"
#include "constante.h"

// à adapter aux différentes structures personnage et aux gestions de touches et fenêtre

// animation de saut

void anim_saut(SDL_Event evenements, SDL_Window *fenetre, SDL_Renderer *ecran, SDL_Texture *raccoon, SDL_Rect sprite_raccoon, SDL_Rect emplacement_raccoon)
{

    int temps_precedent_raccoon = 0;
    int temps_actuel_raccoon = 0;

    int position_maximale = 450;
    int ancienne_position = emplacement_raccoon.y;

    while (emplacement_raccoon.y > position_maximale)
    {

        SDL_RenderCopy(ecran, raccoon, &sprite_raccoon, &emplacement_raccoon);

        temps_actuel_raccoon = SDL_GetTicks();

        if (temps_actuel_raccoon - temps_precedent_raccoon > 20)
        {
            emplacement_raccoon.y -= 10 * TAILLE_PAS;

            temps_precedent_raccoon = temps_actuel_raccoon;
        }

        SDL_UpdateWindowSurface(fenetre);
        SDL_RenderPresent(ecran);
    }

    // il redescend

    while (emplacement_raccoon.y < ancienne_position)
    {

        SDL_RenderCopy(ecran, raccoon, &sprite_raccoon, &emplacement_raccoon);

        temps_actuel_raccoon = SDL_GetTicks();

        if (temps_actuel_raccoon - temps_precedent_raccoon > 20)
        {
            emplacement_raccoon.y += 15 * TAILLE_PAS;

            temps_precedent_raccoon = temps_actuel_raccoon;
        }

        SDL_RenderPresent(ecran);
    }
}

// animation de tir

void anim_tir(SDL_Event evenements, SDL_Renderer *ecran,
              SDL_Texture *balle, SDL_Rect sprite_balle, SDL_Rect emplacement_balle,
              SDL_Texture *raccoon, SDL_Rect sprite_raccoon, SDL_Rect emplacement_raccoon,
              SDL_Texture *chat1, SDL_Rect sprite_chat1, SDL_Rect emplacement_chat1)
{

    int temps_precedent_balle = 0;
    int temps_actuel_balle = 0;

    int temps_precedent_chat1 = 0;
    int temps_actuel_chatlevel1 = 0;

    emplacement_balle.x = emplacement_raccoon.x + 100;
    emplacement_balle.y = emplacement_raccoon.y + 55;

    while (sprite_raccoon.x == 260 && (emplacement_balle.x < LARGEUR_FENETRE || emplacement_balle.x < emplacement_chat1.x))
    {

        SDL_RenderCopy(ecran, balle, &sprite_balle, &emplacement_balle);

        temps_actuel_balle = SDL_GetTicks();

        if (temps_actuel_balle - temps_precedent_balle > 1)
        {
            emplacement_balle.x += 1 * TAILLE_PAS;

            temps_precedent_balle = temps_actuel_balle;
        }

        if (emplacement_balle.x == emplacement_chat1.x)
        {

            //chat1.vie -= 10;

            if (temps_actuel_chatlevel1 - temps_precedent_chat1 > 300)
            {
                emplacement_chat1.x += 0; // le chat est stoppé quand une balle le touche

                temps_precedent_chat1 = temps_actuel_chatlevel1;
            }
        }

        SDL_RenderPresent(ecran);
    }
    emplacement_balle.x = 260;
}

// animation sortie de l'arme si r est enfoncée

void anim_r(SDL_Event evenements, SDL_Renderer *ecran, SDL_Texture *raccoon, SDL_Rect sprite_raccoon, SDL_Rect emplacement_raccoon)
{

    int temps_actuel_parcours_sprite = 0;
    int temps_precedent_parcours_sprite = 0;

    int parcours_sprite = 0;

    while (sprite_raccoon.x < 210)
    {

        SDL_RenderCopy(ecran, raccoon, &sprite_raccoon, &emplacement_raccoon);

        temps_actuel_parcours_sprite = SDL_GetTicks();

        if (temps_actuel_parcours_sprite - temps_precedent_parcours_sprite > 200)
        {
            sprite_raccoon.x += parcours_sprite * 50;
            parcours_sprite++;
            temps_precedent_parcours_sprite = temps_actuel_parcours_sprite;
        }

        SDL_RenderPresent(ecran);
    }
}




// mouvement d'un chat 1

void anim_chat1(SDL_Event evenements, SDL_Renderer *ecran, SDL_Texture *chat1, SDL_Rect sprite_chat1, SDL_Rect emplacement_chat1)
{

    int temps_precedent_chat1 = 0;
    int temps_actuel_chat1 = 0;

    temps_actuel_chat1 = SDL_GetTicks();

    while (temps_actuel_chat1 - temps_precedent_chat1 > 2)
    {

        emplacement_chat1.x -= TAILLE_PAS;

        temps_precedent_chat1 = temps_actuel_chat1;
        SDL_RenderPresent(ecran);

        // printf("%d\n", emplacement_chat1.x);
    }
}



// mouvement du chat2

void anim_chat2(SDL_Event evenements, SDL_Renderer *ecran, SDL_Texture *chat2, SDL_Rect sprite_chat2, SDL_Rect emplacement_chat2)
{

    int temps_precedent_chat2 = 0;
    int temps_actuel_chat2 = 0;

    temps_actuel_chat2 = SDL_GetTicks();

    while (temps_actuel_chat2 - temps_precedent_chat2 > 2)
    {

        emplacement_chat2.x -= TAILLE_PAS;

        temps_precedent_chat2 = temps_actuel_chat2;
        SDL_RenderPresent(ecran);

        // printf("%d\n", emplacement_chat2.x);
    }
}