#include "fenetreDuJeu.h"
#include "finDeJeu.h"
#include "gestionDesTouches.h"
#include "constante.h"
#include "map.h"
#include "personnage.h"
#include "ennemis.h"
#include "lecture_map.h"
#include "structures.h"
#include "menu.h"

int main(void)//int argc, char *argv[])
{
  
  Carte map1 ;
  map1.carteJeu = NULL;
  //char *map = lire_fichier("map.txt",&hauteur, &largeur, &taille);
  lire_fichier("map.txt",&map1);
  //printf("%d\n",hauteur);

  SDL_Window *fenetre;  // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre

  bool terminer = false;
  // Créer la fenêtre
  fenetre = fenetreDuJeu();

  //initialisation de l'image du menu
  SDL_Renderer *ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  //SDL_Texture *fond = charger_image("raccoon.bmp", ecran); //charger l'image de fond


  //  Sprites des composants de la map
  SDL_Texture *sol = charger_image("sol.bmp", ecran);
  SDL_Texture *ciel = charger_image("ciel.bmp", ecran);
  SDL_Texture *troux = charger_image("trou.bmp", ecran);
  SDL_Texture *obstacle = charger_image("obstacle.bmp", ecran);

  SDL_Texture *gain = charger_image("win.bmp", ecran); //image du win

  SDL_Texture* perso = charger_image_transparente("mario.bmp", ecran, 0, 115, 0); // image du perso

  //image pour le menu
  SDL_Texture *jouer = charger_image("raccoon_jouer.bmp", ecran);
  SDL_Texture *option = charger_image("raccoon_option.bmp", ecran);
  SDL_Texture *niveau = charger_image("raccoon_niveau.bmp", ecran);
  SDL_Texture *quitter = charger_image("raccoon_quitter.bmp", ecran);

  //tableau de texture pour le menu
  SDL_Texture *tableau[4] ;
  tableau[0] = jouer ;
  tableau[1] = option ;
  tableau[2] = niveau ;
  tableau[3] = quitter ;

  //menu des options
  SDL_Texture *commande = charger_image("options.bmp", ecran);

  //niveau differents
  SDL_Texture *niv1 = charger_image("niveau_un.bmp", ecran);
  SDL_Texture *niv2 = charger_image("niveau_deux.bmp", ecran);
  SDL_Texture *niv3 = charger_image("niveau_trois.bmp", ecran);
  SDL_Texture *niv4 = charger_image("niveau_quatre.bmp", ecran);
  SDL_Texture *niv5 = charger_image("niveau_cinq.bmp", ecran);
  SDL_Texture *niv6 = charger_image("niveau_six.bmp", ecran);

  //tableau de texture de niveau 
  SDL_Texture *tab_niv[6] ;
  tab_niv[0] = niv1 ;
  tab_niv[1] = niv2 ;
  tab_niv[2] = niv3 ;
  tab_niv[3] = niv4 ;
  tab_niv[4] = niv5 ;
  tab_niv[5] = niv6 ;
  
  // Sprites des différents ennemis

  //SDL_Texture *perso = charger_image_transparente("rocket.bmp", ecran, 0, 137, 84);

  //SDL_Texture *balle1 = charger_image_transparente("balle1.bmp", ecran, 0, 128, 255);
  SDL_Texture *tour4 = charger_image("tour4.bmp", ecran);
  SDL_Texture *tour5 = charger_image("tour5.bmp", ecran);
  //SDL_Texture *tour6 = charger_image("tour6.bmp", ecran);
  //SDL_Texture *tour7 = charger_image("tour7.bmp", ecran);
  //SDL_Texture *tour8 = charger_image("tour8.bmp", ecran);

 // SDL_Texture *scientifique = charger_image_transparente("scientifique.bmp", ecran, 255, 0, 0);

 

  int w = 0;
  int h = 0;
  int debutX = 0; // colonne a partir de laquelle on affiche la map
  //int debutY = 0; ligne a partir de laquelle on affiche la map
  int numSprite = 10;
  int positionX = debutX + 1;
  int positionY = 0;//map1.hauteur - 5; // * hauteur_une_case(h);
  int affichage_position_x = 1;
  SDL_Rect *sprite = sprite_personnage();
  int temps_debut = 0 ;
  int temps_fin = 0; 
  int mode = 0 ;
  int num = 0 ; // numero dans le menu
  int numero = 0 ;  // numero de niveau

 
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


 // Boucle principale
  while (!terminer)
  {
    temps_debut = SDL_GetTicks();
    SDL_GetWindowSize(fenetre, &w, &h);
    SDL_RenderClear(ecran);
    if(mode == 0){
      choix_menu(ecran,tableau[num]) ;
    }
    else if (mode == 1){
     
      carteDuJeu(ecran, sol, ciel, troux, obstacle, tour4, tour5, w, h, debutX, gain,map1); // affiche la map
    
      personnage_jeu(ecran, h, w, positionY, perso, numSprite, sprite, affichage_position_x,map1);
    //emplacement_balle1(ecran, balle1, image_balle1, map);

    //afficher_personnage(scientist, ecran);

    //animer_ennemi(scientist, ecran);


      if (!collision_pied(positionX, positionY, map1)){
        if (!trou(positionX, positionY, map1)){
          gravite(1 , &positionY,map1);
        }
        else {
         gameOver("gameOver.bmp", ecran);
         terminer = true ;
        }
     
      }
      if (gagner(positionX, positionY,map1)){
        win("winner.bmp", ecran);
        terminer = true ;

      }
    


    //stf(ecran, scientifique, &image_scientifique);
    //deplacement_stf(ecran, pos_stf, s, scientifique, debutX, positionX, positionY, affichage_position_x);

    }else if(mode == 2){
      choix_option( ecran,commande);
    }else if(mode == 3){
      
      choix_niveau(ecran, tab_niv[numero]);
      switch (numero){
        case 0 :
          lire_fichier("map.txt",&map1);

          break;
        case 1 :
          
          lire_fichier("map1.txt",&map1);
/*          
  */       break;
        case 2 :
          lire_fichier("map2.txt",&map1);
          
          break ;
        case 3 :
        lire_fichier("map1.txt",&map1);
          
          break;
        case 4:
          lire_fichier("map3.txt",&map1);
         
          break;
        case 5:
          lire_fichier("map2.txt",&map1);
          
          break;
        default :
          lire_fichier("map.txt",&map1);
        
          break;
        }
    }
    
    

    SDL_RenderPresent(ecran);
    if (SDL_PollEvent(&evenements))
    {
      gestionTouche(evenements, ecran, &terminer, &debutX, &numSprite, &positionX, &positionY, &affichage_position_x ,&mode,&num,&numero,map1);

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
  //free(map1);
  
 
  //SDL_DestroyTexture(fond);
  SDL_DestroyTexture(ciel);
  SDL_DestroyTexture(sol);
  SDL_DestroyTexture(troux);
  SDL_DestroyTexture(obstacle);
  SDL_DestroyTexture(perso);
  SDL_DestroyTexture(gain);
  SDL_DestroyWindow(fenetre);
  SDL_DestroyTexture(tour4);
  SDL_DestroyTexture(tour5);
  SDL_DestroyTexture(jouer);
  SDL_DestroyTexture(option);
  SDL_DestroyTexture(niveau);
  SDL_DestroyTexture(quitter);

  SDL_DestroyTexture(niv1);
  SDL_DestroyTexture(niv2);
  SDL_DestroyTexture(niv3);
  SDL_DestroyTexture(niv4);
  SDL_DestroyTexture(niv5);
  SDL_DestroyTexture(niv6);
  
  
  SDL_DestroyRenderer(ecran);
  SDL_Quit();
  return 0;
}