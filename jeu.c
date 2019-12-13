#include "fenetreDuJeu.h"
#include "finDeJeu.h"
#include "gestionDesTouches.h"
#include "constante.h"
#include "map.h"
#include "personnage.h"

#include "lecture_map.h"
#include "menu.h"


int main(void)
{
  
  Carte map1 ;
  map1.carteJeu = NULL;
  
  lire_fichier("map.txt",&map1);
  SDL_Window *fenetre;  // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre
  bool terminer = false;

  // Créer la fenêtre
  fenetre = fenetreDuJeu();

  //initialisation de l'image du menu
  SDL_Renderer *ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

  //  Sprites des composants de la map
  SDL_Texture *sol = charger_image("sol.bmp", ecran);
  SDL_Texture *ciel = charger_image("ciel.bmp", ecran);
  SDL_Texture *troux = charger_image("trou.bmp", ecran);
  SDL_Texture *obstacle = charger_image("obstacle.bmp", ecran);
  SDL_Texture *pics = charger_image_transparente("pics.bmp",ecran,255,0,0);
  SDL_Texture *vie = charger_image_transparente("vie.bmp" ,ecran ,255,255,255);

  SDL_Texture *gain = charger_image("win.bmp", ecran); //image du win

  //Sprite du personnage
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

  //SDL_Texture *balle_image = charger_image_transparente("balle1.bmp", ecran, 0, 128, 255);
  SDL_Texture *tour4 = charger_image_transparente("tour4.bmp", ecran,54,157,211);
  SDL_Texture *tour5 = charger_image_transparente("tour5.bmp", ecran,54,157,211);
  SDL_Texture *tour6 = charger_image_transparente("tour6.bmp", ecran,54,157,211);
  SDL_Texture *tour7 = charger_image_transparente("tour7.bmp", ecran,54,157,211);
  SDL_Texture *tour8 = charger_image_transparente("tour8.bmp", ecran,54,157,211);

  //SDL_Texture *laser_image = charger_image_transparente("laser.bmp", ecran, 0, 0, 0);

  //initialisation des valeurs

  int w = 0; // permet de recuperer la largeur de la carte
  int h = 0; // permet de recuperer la hauteur de la carte 
  int debutX = 0; // colonne a partir de laquelle on affiche la map
 
  int numSprite = 10;
  int positionX = debutX + 1; // position sur l'axe des abscisses du perso 
  int positionY = 0; //recupere la position sur l'axe des ordonnees  du perso
  int affichage_position_x = 1; //position d'affichage du personnage
  SDL_Rect *sprite = sprite_personnage(); //tableau de sprite du personnage
  int temps_debut = 0 ;
  int temps_fin = 0; 
  int mode = 0 ;
  int num = 0 ; // numero dans le menu
  int numero = 0 ;  // numero de niveau

 //int hauteur = 0;
 //int largeur = 0;

  //int direction = 0;
  int nb_vie = 3 ;

  int posX = 0; 
  int posY = 0;

  // nécessaires pour les animations
  /*int temps_debut_animation = 0;
  int temps_fin_animation = 0;*/

  
/*
  element balle1, balle2, balle3;  
 

  balle1 = creer_balle1(balle1, 0, balle_image, w, h, map1);
  balle2 = creer_balle2(balle2, 0, balle_image, w, h, map1);
  balle3 = creer_balle3(balle3, 0, balle_image, w, h, map1);
*/

 // Boucle principale
  while (!terminer)
  {

    temps_debut = SDL_GetTicks();
    //temps_debut_animation = SDL_GetTicks();
    SDL_GetWindowSize(fenetre, &w, &h);
    /*
    if (w != largeur || h != hauteur){

      balle1 = definir_sprite_balle(balle1, w, h, map1);
      balle1 = definir_position_balle1(balle1, w, h, map1);
      
      balle2 = definir_sprite_balle(balle2, w, h, map1);
      balle2 = definir_position_balle2(balle2, w, h, map1);
      
      balle3 = definir_sprite_balle(balle3, w, h, map1);
      balle3 = definir_position_balle3(balle3, w, h, map1);

      largeur = w;
      hauteur = h;

      }
   

    positionY -= collision_element(balle1, positionY, w, h, map1);
    positionY -= collision_element(balle2,positionY, w, h, map1);*/
  
    SDL_RenderClear(ecran);
    if(mode == 0){ 
      choix_menu(ecran,tableau[num]) ;
    }
    else if (mode == 1){
     
      carteDuJeu(ecran, sol, ciel, troux, obstacle, tour4, tour5, tour6, tour7, tour8, w, h, debutX, gain,map1,pics); // affiche la map
    
      personnage_jeu(ecran, h, w, positionY, perso, numSprite, sprite, affichage_position_x,map1);
      nb_vie_perso(positionX,positionY,map1,&nb_vie,&posX,&posY);
      vie_du_personnage(ecran,vie,nb_vie);
      
      /*afficher_element(balle1, ecran);
      afficher_element(balle2, ecran);*/
      if (nb_vie == 0){
        gameOver("gameOver.bmp", ecran);
         terminer = true ;
      }
                  
      /*if (positionX > 10){
        afficher_element(balle3, ecran);
      }*/

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
          break;
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
    
    /*if (temps_debut_animation - temps_fin_animation > VITESSE_JEU)
    {
    
      balle1 = animer_balle(balle1,w);
      balle2 = animer_balle(balle2,w);
      
      if (positionX > 10){

        balle3 = animer_balle(balle3, w);
      }

      temps_fin_animation = temps_debut_animation;
    }*/

    SDL_RenderPresent(ecran);
    if (SDL_PollEvent(&evenements))
    {
      gestionTouche(evenements, ecran, &terminer, &debutX, &numSprite, &positionX, &positionY, &affichage_position_x ,&mode,&num,&numero,map1);

      //balle1 = correction_position_element(balle1, evenements, positionX, positionY, direction, w, map1);
      //balle2 = correction_position_element(balle2, evenements, positionX, positionY, direction, w, map1);

     /* if (positionX > 10){
        balle3 = correction_position_element(balle3, evenements, positionX, positionY, direction, w, map1);
      }*/
      

    }
    temps_fin = SDL_GetTicks();
    if(temps_fin - temps_debut < 30){
      SDL_Delay(30-(temps_fin - temps_debut));
    }
    
  }
  // Quitter SDL
  free(sprite);

  SDL_DestroyTexture(ciel);
  SDL_DestroyTexture(sol);
  SDL_DestroyTexture(troux);
  SDL_DestroyTexture(obstacle);
  SDL_DestroyTexture(perso);
  SDL_DestroyTexture(gain);
  SDL_DestroyWindow(fenetre);
  SDL_DestroyTexture(tour4);
  SDL_DestroyTexture(tour5);
  SDL_DestroyTexture(tour6);
  SDL_DestroyTexture(tour7);
  SDL_DestroyTexture(tour8);
  SDL_DestroyTexture(jouer);
  SDL_DestroyTexture(option);
  SDL_DestroyTexture(niveau);
  SDL_DestroyTexture(quitter);
  SDL_DestroyTexture(pics);
  SDL_DestroyTexture(vie);

  SDL_DestroyTexture(niv1);
  SDL_DestroyTexture(niv2);
  SDL_DestroyTexture(niv3);
  SDL_DestroyTexture(niv4);
  SDL_DestroyTexture(niv5);
  SDL_DestroyTexture(niv6);

  //SDL_DestroyTexture(balle_image);
  //SDL_DestroyTexture(scientifique);
  //SDL_DestroyTexture(laser_image);
  //SDL_DestroyTexture(missile_image);
  
  
  SDL_DestroyRenderer(ecran);
  SDL_Quit();
  return 0;
}