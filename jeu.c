
#include "fenetreDuJeu.h"




int main(int argc, char *argv[])
{
  SDL_Window* fenetre; // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre

  bool terminer = false;
  // Créer la fenêtre
  fenetre = fenetreDuJeu();
  if(fenetre == NULL) // En cas d’erreur
    {
      printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
      SDL_Quit();
      return EXIT_FAILURE;
    }
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
        case SDLK_ESCAPE:
        case SDLK_q:
        terminer = true; 
        break;
      }
   }
}
// Quitter SDL
SDL_DestroyWindow(fenetre);
SDL_Quit();
return 0;
}