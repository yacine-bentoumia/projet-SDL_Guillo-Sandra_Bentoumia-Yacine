#include "elements.h"

/*

  Définitions des fonctions des élements

*/

// création d'un élément

element creer_missile1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_missile(e);
  e = definir_position_missile1(e, largeur, hauteur, map1);

  return e;
}

element creer_balle1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_balle(e);
  e = definir_position_balle1(e, largeur, hauteur, map1);

  return e;
}

element creer_balle2(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_balle(e);
  e = definir_position_balle2(e, largeur, hauteur, map1);

  return e;
}
//364 --> 343
element creer_balle3(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_balle(e);
  e = definir_position_balle3(e, largeur, hauteur, map1);

  return e;
}
/*
element creer_explosion1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_explosion(e);
  e = definir_position_explosion1(e, largeur, hauteur, map1);

  return e;
}*/

// fonctions de construction générales

element definir_vitesse_element(element e, int vitesse)
{

  e.vitesse = vitesse;

  return e;
}

element definir_image_element(element e, SDL_Texture *image)
{

  e.image = image;

  return e;
}

void afficher_element(element e, SDL_Renderer *ecran)
{

  SDL_RenderCopy(ecran, e.image, &e.sprite, &e.position_sprite);
}

// définition du laser par défaut

element definir_sprite_laser(element e)
{

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = 878;
  e.sprite.w = 162;

  return e;
}
/*
element definir_position_laser(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.x = 760; //135;
  e.position_sprite.y = 265;
  e.position_sprite.h = 430;
  e.position_sprite.w = 100;

  return e;
}*/

// définition des balles par défaut

element definir_sprite_balle(element e)
{

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = 7;
  e.sprite.w = 16;

  return e;
}

element definir_position_balle1(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.w = largeur_une_case(largeur) / 3;
  e.position_sprite.h = hauteur_une_case(hauteur, map1) / 2;

  e.abscisse_reference = 6 * largeur_une_case(largeur) - e.position_sprite.w;
  e.ordonnee_reference = 30 * hauteur_une_case(hauteur, map1) - e.position_sprite.h - e.position_sprite.h / 10;

  e.position_sprite.x = e.abscisse_reference;
  e.position_sprite.y = e.ordonnee_reference;

  /*if (e.position_sprite.w != 0){

  printf("w %d, h %d\n", e.position_sprite.w, e.position_sprite.h);
  printf("larg %d, haut %d\n", largeur_une_case(largeur), hauteur_une_case(hauteur, map1));

  }*/
  /*printf("abs ref: %d\t", lire_abscisse_reference(e));
  printf("ord ref: %d\n", lire_ordonnee_reference(e));*/
  //printf("larg: %d\n", largeur);

  return e;
}

element definir_position_balle2(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.w = largeur_une_case(largeur) / 3;
  e.position_sprite.h = hauteur_une_case(hauteur, map1) / 2;

  e.abscisse_reference = 13 * largeur_une_case(largeur) - e.position_sprite.w;
  e.ordonnee_reference = 32 * hauteur_une_case(hauteur, map1) - e.position_sprite.h + e.position_sprite.h / 2;

  e.position_sprite.x = e.abscisse_reference;
  e.position_sprite.y = e.ordonnee_reference;

  return e;
}

element definir_position_balle3(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.w = largeur_une_case(largeur) / 3;
  e.position_sprite.h = hauteur_une_case(hauteur, map1) / 2;

  e.abscisse_reference = largeur - e.position_sprite.w;
  e.ordonnee_reference = 31 * hauteur_une_case(hauteur, map1);

  e.position_sprite.x = e.abscisse_reference;
  e.position_sprite.y = e.ordonnee_reference;

  return e;
}

// definition des missiles par défaut

element definir_sprite_missile(element e)
{

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = 88;
  e.sprite.w = 32;

  return e;
}

element definir_position_missile1(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.w = largeur_une_case(largeur) / 2 + largeur_une_case(largeur) / 8;
  e.position_sprite.h = 5 * hauteur_une_case(hauteur, map1) - hauteur_une_case(hauteur, map1) / 2;

  e.abscisse_reference = 9 * largeur_une_case(largeur) + largeur_une_case(largeur) / 5;
  e.ordonnee_reference = 4 * hauteur_une_case(hauteur, map1) + hauteur_une_case(hauteur, map1) / 5;

  e.position_sprite.x = e.abscisse_reference;
  e.position_sprite.y = e.ordonnee_reference;

  

  return e;
}

// explosion

element definir_sprite_explosion(element e)
{


  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = HAUTEUR_SPRITE_EXPLOSION / 3;
  e.sprite.w = LARGEUR_SPRITE_EXPLOSION / 8;

  return e;
}

// fonction de lecture

int lire_abscisse_reference(element e)
{

  return e.abscisse_reference;
}

int lire_ordonnee_reference(element e)
{

  return e.ordonnee_reference;
}

// collision entre un élément et le personnage principal

int collision_element(element e,int positionY, int largeur, int hauteur, Carte map1){
  int toucher = 0;
  if (e.position_sprite.x <= 2 * largeur_une_case(largeur) && e.position_sprite.x >= largeur_une_case(largeur)){
    if (e.position_sprite.y >= hauteur_une_case(hauteur, map1) * positionY){
      if (e.position_sprite.y <= hauteur_une_case(hauteur, map1) * positionY + 3 * hauteur_une_case(hauteur, map1)){
        toucher = 1;
      }
    }
  }

  return toucher;
}


/*

  Fonctions d'animation

*/

element animer_laser(element e){
  int animer = 0;
  if (animer == 0){
    animer = 1;
  }
  else if (animer == 1){
    e.sprite.x += e.sprite.w;
    animer = 2;
  }
  else if (animer == 2){
    e.sprite.x = 0;
    animer = 0;
  }
  return e;
}

element animer_balle(element e,int largeur){
  if (e.position_sprite.x > -e.sprite.w){
    e.position_sprite.x -= largeur / 100;
  }
  else{
    e.position_sprite.x = lire_abscisse_reference(e);
  }
  return e;
}

element animer_missile(element e,int hauteur, Carte map1){
  if (e.position_sprite.y < 30 * hauteur_une_case(hauteur, map1)){
    e.position_sprite.y += hauteur_une_case(hauteur, map1) / 2;
  }
  else{
    e.position_sprite.y = POS_MISSILE1_Y;
  }
  if (e.sprite.x == 0){
    e.sprite.x += 32;
  }
  else if (e.sprite.x == 32){
    e.sprite.x = 0;
  }
  return e;
}



element correction_position_element(element e, SDL_Event evenements,int positionX,int positionY, int direction, int largeur, Carte map1){
  switch (evenements.key.keysym.sym){
    case SDLK_LEFT:
      direction = -1;
      break;
    case SDLK_RIGHT:
      direction = 1;
      break;
  }
 
  if (positionX == 0 || positionX == 1 || collision(direction, positionX, positionY, map1)){
    e.abscisse_reference += 0;
  }
  else{
    e.abscisse_reference -= (direction * largeur_une_case(largeur)) / 2;
  }
  return e;
}