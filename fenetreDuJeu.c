#include "fenetreDuJeu.h"





SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer){
  // Convertir la surface de l’image au format texture avant de l’appliquer
  
  SDL_Surface* surface =  SDL_LoadBMP(nomfichier) ;
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface) ;
  return texture ;
}




SDL_Window* fenetreDuJeu()
{
  SDL_Window* fenetre; // Déclaration de la fenêtre
  
  // Créer la fenêtre 1300 * 900
  fenetre = SDL_CreateWindow("THE RACCOON", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_RESIZABLE);
  if(fenetre == NULL) // En cas d’erreur
    {
      printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
      SDL_Quit();
      //return EXIT_FAILURE;
      
    }

  return fenetre;

}


