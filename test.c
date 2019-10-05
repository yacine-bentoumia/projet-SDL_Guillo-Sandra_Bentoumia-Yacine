#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(int argc, char *argv[])
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

/*

  // Créer un contexte de rendu (renderer) pour l’image
  // SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags) ;

  SDL_Renderer* ecran;
  ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  
  // Charger une image
 
  SDL_Texture* fond = charger_image("fond.bmp", ecran );
  
   
  // Charger l'image avec la transparence 
  Uint8 r = 255, g = 255, b = 255;
  SDL_Texture* obj = charger_image_transparente("obj.bmp", ecran,r,g,b);


  int objetW = 640 ;
  int objetH = 192 ;
  SDL_Rect SrcR;
  SrcR.x = 0;
  SrcR.y = 0;
  SrcR.w = objetW ; // largeur de l'objet 
  SrcR.h = objetH ; // hauteur de l'objet 

  SDL_Rect DestR ;
  DestR.x = 900 ;
  DestR.y = 450 ;
  DestR.w = objetW/3 ;
  DestR.h = objetH/3 ;


  //sprites
  r = 0 ; 
  g = 255 ;
  b = 255 ;
  SDL_Texture* chat = charger_image_transparente("sprites.bmp", ecran,r,g,b);
  SDL_Rect DestR_sprite[6] ;
  for (int i = 0 ; i < 6 ; i++)
  {
    DestR_sprite[i].x = i > 2 ? 60*(i+2)+100 : 60*(i+2) ;
    DestR_sprite[i].y = i > 2 ? 60 : 120 ;
    DestR_sprite[i].w = 285/3;
    DestR_sprite[i].h = 250/2 ;
  }
  SDL_Rect DestCha ;
  DestCha.x = 500;
  DestCha.y = 500;
  DestCha.h = 250 / 2;
  DestCha.w = 285 / 3;


 //afficher texte
  TTF_Init();
  TTF_Font* font = TTF_OpenFont("./angelina.TTF",28);
  SDL_Color color = {0,0,0,0};
  char msg[] = "TP sur Makefile et SDL";
  SDL_Texture* texte = charger_texte(msg,ecran,font,color);
  SDL_Rect text_pos; // Position du texte
  text_pos.x = 10;
  text_pos.y = 100;
  text_pos.w = 450;
  text_pos.h = 150;*/

  // Boucle principale
  while(!terminer)
    {
      //SDL_RenderClear(ecran);
      /*SDL_RenderCopy(ecran, fond, NULL, NULL); // affiche le fond
      SDL_RenderCopy(ecran,obj,&SrcR,&DestR); // affiche l'image en transparence
      SDL_RenderCopy(ecran, chat, DestR_sprite,&DestCha) ; // afficher les sprites
      SDL_RenderCopy(ecran,texte,NULL,&text_pos); //afficher du texte
      SDL_RenderPresent(ecran);*/
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
  SDL_Quit();
  return 0;

}
