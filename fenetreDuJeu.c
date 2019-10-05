#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fenetreDuJeu.h"




/*
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer){
  // Convertir la surface de l’image au format texture avant de l’appliquer
  
  SDL_Surface* surface =  SDL_LoadBMP(nomfichier) ;
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface) ;
  return texture ;
}
*/



SDL_Window* fenetreDuJe()
{
  SDL_Window* fenetre; // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre
  bool terminer = false;
  if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
      printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
      SDL_Quit();
      return EXIT_FAILURE;
    }

  
  // Créer la fenêtre
  fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1346, 830, SDL_WINDOW_RESIZABLE);
  if(fenetre == NULL) // En cas d’erreur
    {
      printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
      SDL_Quit();
      return EXIT_FAILURE;
    }


  // Créer un contexte de rendu (renderer) pour l’image
  // SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags) ;

  //SDL_Renderer* ecran;
  //ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

  /*
    // Boucle principale
  while(!terminer)
    {
      //SDL_RenderClear(ecran);
      //SDL_RenderCopy(ecran, fond, NULL, NULL); // affiche le fond
      //SDL_RenderCopy(ecran,obj,&SrcR,&DestR); // affiche l'image en transparence
      //SDL_RenderCopy(ecran, chat, DestR_sprite,&DestCha) ; // afficher les sprites
      //SDL_RenderCopy(ecran,texte,NULL,&text_pos); //afficher du texte
      //SDL_RenderPresent(ecran);
      while( SDL_PollEvent( &evenements ) )
	      switch(evenements.type)
	      {
	        case SDL_QUIT:
	          terminer = true; break;
	        case SDL_KEYDOWN:
	        switch(evenements.key.keysym.sym)
	        {
	          case SDLK_ESCAPE:
	          case SDLK_q:
		          terminer = true;  break;
	      }
	  }
    }


  // Quitter SDL
  SDL_DestroyWindow(fenetre);
  SDL_Quit();*/
  return fenetre;

}