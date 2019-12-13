#include "structures.h"
#include "constante.h"


ennemi definir_nouveau_personnage(SDL_Renderer *ecran)
{

    ennemi e;

    e.vie = 0;
    e.vitesse = 0;
    //e.nom = "";
    e.image = NULL;
    /*e.sprite = NULL;
    e.emplacement_sprite = NULL;*/

    return e;
}

// fonctions d'écriture

ennemi definir_vie(ennemi e, unsigned int vie)
{

    e.vie = vie;

    return e;
}

ennemi definir_vitesse(ennemi e, int vitesse)
{

    e.vitesse = vitesse;

    return e;
}


ennemi definir_image(ennemi e, SDL_Texture *image)
{

    e.image = image;

    return e;
}

ennemi definir_sprite(ennemi e, SDL_Rect sprite)
{

    e.sprite = sprite;

    return e;
}

ennemi definir_emplacement_sprite(ennemi e, SDL_Rect emplacement)
{

    e.emplacement_sprite = emplacement;

    return e;
}

// Fonctions de lecture


int lire_vitesse(ennemi e)
{

    return e.vitesse;
}

int lire_abscisse(ennemi e)
{

    return e.emplacement_sprite.x;
}

int lire_ordonnee(ennemi e)
{

    return e.emplacement_sprite.y;
}

void afficher_personnage(ennemi e, SDL_Renderer *ecran)
{

    SDL_RenderCopy(ecran, e.image, &e.sprite, &e.emplacement_sprite);
}



/*SDL_Rect  ennemi definir_sprite_stf(ennemi e){

    e.sprite.x = 7*TAILLE_STF;
    e.sprite.y = 0;
    e.sprite.h = TAILLE_STF;
    e.sprite.w = TAILLE_STF;

    return e;

}*/



/*SDL_Rect ennemi definir_emplacement_stf(ennemi e){

    e.emplacement_sprite.x = 600;
    e.emplacement_sprite.y = 620;
    e.emplacement_sprite.w = 100;
    e.emplacement_sprite.h = 80;

    return e;

}*/






/*void animer_ennemi(ennemi e, SDL_Renderer *ecran)
{

    int temps_actuel = 0;
    int temps_precedent = 0;

    int parcours = -1; // sens du parcours de la feuille de sprite (-1: vers la gauche)

    bool stop = false;

    temps_actuel = SDL_GetTicks();
    while (temps_actuel - temps_precedent > 100 && stop == false)
    {

        afficher_personnage(e, ecran);
     
       
        e.emplacement_sprite.x -= 10;
        e.sprite.x += parcours * (TAILLE_STF);

        //printf("%dx, %dy\n", e.emplacement_sprite.x, e.emplacement_sprite.y);

        if (e.sprite.x == 0 && e.sprite.y == 0)
        {

           
            parcours = 1;s
            e.sprite.y += TAILLE_STF;
          
        }

        if (e.sprite.x == 8 * TAILLE_STF && e.sprite.y == TAILLE_STF)
        {

            e.sprite.x -= TAILLE_STF;
            e.sprite.y += TAILLE_STF;
            parcours = -1;
        }

        if (e.emplacement_sprite.x == -TAILLE_STF || (e.sprite.x == TAILLE_STF && e.sprite.y == 2 * TAILLE_STF))
        {

            stop = true;
            SDL_DestroyTexture(e.image);
        }

        temps_precedent = temps_actuel;
    }

    
}*/
