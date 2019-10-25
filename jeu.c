
#include "fenetreDuJeu.h"
#include "finDeJeu.h"
#include "gestionDesTouches.h"
#include "constante.h"
#include "map.h"
#include "personnage.h"




int main(int argc, char *argv[])
{
  

  SDL_Window* fenetre; // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre

  bool terminer = false;
  // Créer la fenêtre
  fenetre = fenetreDuJeu();
  
  //initialisation de l'image du menu
  SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  SDL_Texture* fond = charger_image("raccoon.bmp", ecran ); //charger l'image de fond
  
  SDL_Texture* sol = charger_image ("sol.bmp", ecran);
  SDL_Texture* ciel = charger_image ("ciel.bmp", ecran);
  SDL_Texture* trou = charger_image ("trou.bmp", ecran);
  SDL_Texture* obstacle = charger_image ("obstacle.bmp", ecran);
  SDL_Texture* perso = charger_image_transparente("mario.bmp", ecran, 0, 115, 0);
  // Boucle principale

  int w = 0 ;
  int h = 0 ;
  int debutX = 0; // colonne a partir de laquelle on affiche la map
  int debutY = 0 ;// ligne a partir de laquelle on affiche la map
  int numSprite = 10 ;
  int positionX = 1;
  int positionY = HAUTEUR_TABLEAU - 5;// * hauteur_une_case(h);
  int affichage_position_x = 1 ;
  SDL_Rect* sprite = sprite_personnage();
  while(!terminer)
  {
   
    SDL_GetWindowSize(fenetre , &w , &h);
    //printf("%d,%d \n",w,h);
    SDL_RenderClear(ecran);
    SDL_RenderCopy(ecran, fond, NULL, NULL); // affiche le fond
    
    carteDuJeu (ecran, sol, ciel, trou, obstacle, w, h, debutX, debutY) ; // affiche la map
    personnage_jeu(ecran ,h, w, positionX , positionY,  perso, numSprite,sprite, affichage_position_x) ;
    SDL_RenderPresent(ecran); 
    if (SDL_PollEvent(&evenements)){ 
      gestionTouche(evenements, ecran ,&terminer,&debutX,&debutY, &numSprite,&positionX, &positionY,&affichage_position_x ,w);
    }
    //SDL_Delay(1000);
}
// Quitter SDL
free(sprite);
SDL_DestroyWindow(fenetre);
SDL_Quit();
return 0;
}