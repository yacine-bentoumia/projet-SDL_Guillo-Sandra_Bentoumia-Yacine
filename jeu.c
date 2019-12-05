#include "fenetreDuJeu.h"
#include "finDeJeu.h"
#include "gestionDesTouches.h"
#include "constante.h"
#include "map.h"
#include "personnage.h"
#include "ennemis.h"
#include "lecture_map.h"
#include "structures.h"

int main(int argc, char *argv[])
{

  char *map = lire_fichier("map.txt");

  SDL_Window *fenetre;  // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre

  bool terminer = false;
  // Créer la fenêtre
  fenetre = fenetreDuJeu();

  //initialisation de l'image du menu
  SDL_Renderer *ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  SDL_Texture *fond = charger_image("raccoon.bmp", ecran); //charger l'image de fond


  //  Sprites des composants de la map
  SDL_Texture *sol = charger_image("sol.bmp", ecran);
  SDL_Texture *ciel = charger_image("ciel.bmp", ecran);
  SDL_Texture *troux = charger_image("trou.bmp", ecran);
  SDL_Texture *obstacle = charger_image("obstacle.bmp", ecran);
  SDL_Texture *gain = charger_image("win.bmp", ecran);
  SDL_Texture* perso = charger_image_transparente("mario.bmp", ecran, 0, 115, 0);


  // Sprites des différents ennemis

  //SDL_Texture *perso = charger_image_transparente("rocket.bmp", ecran, 0, 137, 84);

  //SDL_Texture *balle1 = charger_image_transparente("balle1.bmp", ecran, 0, 128, 255);
  SDL_Texture *tour4 = charger_image("tour4.bmp", ecran);
  SDL_Texture *tour5 = charger_image("tour5.bmp", ecran);
  //SDL_Texture *tour6 = charger_image("tour6.bmp", ecran);
  //SDL_Texture *tour7 = charger_image("tour7.bmp", ecran);
  //SDL_Texture *tour8 = charger_image("tour8.bmp", ecran);

 // SDL_Texture *scientifique = charger_image_transparente("scientifique.bmp", ecran, 255, 0, 0);

  // Boucle principale

  int w = 0;
  int h = 0;
  int debutX = 0; // colonne a partir de laquelle on affiche la map
  //int debutY = 0; ligne a partir de laquelle on affiche la map
  int numSprite = 10;
  int positionX = debutX + 1;
  int positionY = HAUTEUR_TABLEAU - 5; // * hauteur_une_case(h);
  int affichage_position_x = 1;
  SDL_Rect *sprite = sprite_personnage();
  int temps_debut = 0 ;
  int temps_fin = 0; 

  
  // definition de l'ennemi

  //ennemi scientist;

  //scientist = definir_vie(scientist, 200);
  //printf("vie : %u\n", lire_vie(scientist));

  //scientist = definir_vitesse(scientist, -10);
  //printf("vitesse : %d\n", lire_vitesse(scientist));

  //scientist = definir_image(scientist, scientifique);
  //scientist = definir_sprite(scientist, image_stf);
  //scientist = definir_emplacement_sprite(scientist, pos_stf);

  //scientist = definir_sprite_stf(scientist);
  //scientist = definir_emplacement_stf(scientist);

  while (!terminer)
  {
    temps_debut = SDL_GetTicks();
    SDL_GetWindowSize(fenetre, &w, &h);
    SDL_RenderClear(ecran);
    SDL_RenderCopy(ecran, fond, NULL, NULL); // affiche le fond

    

    carteDuJeu(ecran, sol, ciel, troux, obstacle, tour4, tour5, w, h, debutX, map,gain); // affiche la map
    personnage_jeu(ecran, h, w, positionY, perso, numSprite, sprite, affichage_position_x);
    //emplacement_balle1(ecran, balle1, image_balle1, map);

    //afficher_personnage(scientist, ecran);

    //animer_ennemi(scientist, ecran);


    if (!collision_pied(map, positionX, positionY)){
      if (!trou(map, positionX, positionY)){
        gravite(1 , &positionY);//int *map, int vitesse, int *positionX, int direction, int *positionY
      }
      else {
        gameOver("gameOver.bmp", ecran);
        terminer = true ;
      }
     
    }
    if (gagner(map, positionX, positionY)){
      win("winner.bmp", ecran);
      terminer = true ;

    }
    


    //stf(ecran, scientifique, &image_scientifique);
    //deplacement_stf(ecran, pos_stf, s, scientifique, debutX, positionX, positionY, affichage_position_x);

    SDL_RenderPresent(ecran);
    if (SDL_PollEvent(&evenements))
    {
      gestionTouche(evenements, ecran, &terminer, &debutX, &numSprite, &positionX, &positionY, &affichage_position_x, map);

      //decalage_stf(ecran, scientifique, &image_stf, &pos_stf);

      

    }
    temps_fin = SDL_GetTicks();
    if(temps_fin - temps_debut < 30){
      SDL_Delay(30-(temps_fin - temps_debut));
    }
    //
  }
  // Quitter SDL
  free(sprite);
  SDL_DestroyTexture(fond);
  SDL_DestroyTexture(ciel);
  SDL_DestroyTexture(sol);
  SDL_DestroyTexture(troux);
  SDL_DestroyTexture(obstacle);
  SDL_DestroyTexture(perso);
  SDL_DestroyTexture(gain);
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
  return 0;
}