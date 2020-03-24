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
	SDL_Rect pos_score;
        int stage; 
}PERSO_PRINCIPALE;





//****** HEAD PERSONAGE *******


void init_persoP(PERSO_PRINCIPALE *p);
void afficher_personnageP(PERSO_PRINCIPALE *perso,SDL_Surface *fenetre);
void deplacement_clavier(PERSO_PRINCIPALE *perso,int sens,int bg , int vitesse);
void animer_clavier(PERSO_PRINCIPALE * perso,int sens);










#endif
