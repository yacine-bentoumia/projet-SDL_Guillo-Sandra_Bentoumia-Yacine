
#include "fenetreDuJeu.h"
#include "finDeJeu.h"




int main(int argc, char *argv[])
{
  SDL_Window* fenetre; // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre

  bool terminer = false;
  // Créer la fenêtre
  fenetre = fenetreDuJeu();
  
    //initialisation de l'image de fond
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* fond = charger_image("raccoon.bmp", ecran ); //charger l'image de fond
  



  

  
  // Boucle principale
  while(!terminer)
  {
    SDL_RenderClear(ecran);
    SDL_RenderCopy(ecran, fond, NULL, NULL); // affiche le fond
    SDL_RenderPresent(ecran); 
    while( SDL_PollEvent( &evenements ) )
    switch(evenements.type)
    {
      case SDL_QUIT:
      terminer = true; 
      break;
      case SDL_KEYDOWN:
      switch(evenements.key.keysym.sym)
      {
        case SDLK_ESCAPE: //touche echappe
        case SDLK_q:
          terminer = true; 
          break;
          //test de l'affichage du game over avec la touche entrer
        case SDLK_RETURN  : //touche entrer
          gameOver("gameOver.bmp", ecran);
          terminer = true ;
          break;
        //test affichage du winner avec la touche espace
        case SDLK_SPACE : //touche barre d'espace
          win("winner.bmp", ecran);
          terminer = true ;
          break ;

      }
   }
}
// Quitter SDL
SDL_DestroyWindow(fenetre);
SDL_Quit();
return 0;
}