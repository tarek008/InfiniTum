
 
#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL_rotozoom.h>

#define TEMPS 30
#define FPS 60

//****** HEAD STRUCTURE *******

typedef struct PERSO_PRINCIPALE
{
	int vie;
	int sens_mouvement;
	int position_actuel; 
    SDL_Rect position;
	SDL_Surface *tab[64];
	float time;
	int score;
    int stage; 
	int objective; 
}PERSO_PRINCIPALE;

typedef struct BACKGROUND
{
 SDL_Rect position;
 SDL_Surface img;
int nb_img;

}BACKGROUND;

//****** MENU PRICIPALE *******

int menu(SDL_Surface *screen);
void Intro(SDL_Surface *screen);


//****** HEAD PERSONAGE *******
void init_persoP(PERSO_PRINCIPALE *p);
void afficher_personnageP(PERSO_PRINCIPALE *perso,SDL_Surface *fenetre);
void deplacement_clavier(PERSO_PRINCIPALE *perso,int sens, BACKGROUND *bg);
void animer_clavier(PERSO_PRINCIPALE * perso,int sens);

//********* HEAD BACKGROUD *******
void init_bk(BACKGROUND* b);
void afficher_bk(BACKGROUND *bk,SDL_Surface *fenetre);
void scrollingbg(int sens,BACKGROUND *bg,PERSO_PRINCIPALE *p);

//******** HEAD COLLISION *******

SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y);
int collision_perpri(BACKGROUND *bg,PERSO_PRINCIPALE *per);
int collision_enigme(BACKGROUND *bg,PERSO_PRINCIPALE *per);
int collision_ENDLV(BACKGROUND *bg,PERSO_PRINCIPALE *per);

#endif
