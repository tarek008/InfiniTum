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
 #define FPS 60
#define TEMPS 30


//****** HEAD STRUCTURE *******

typedef struct BACKGROUND
{
SDL_Surface*  bg;
SDL_Surface* bg_collision;
SDL_Rect position;
SDL_Rect position_collision;
//SDL_Rect scroll;
int stage;
//int speed;
    SDL_Rect cam;
SDL_Surface* fenetre;
}BACKGROUND;

typedef struct PERSO_PRINCIPALE
{
	int vie;
	int sens_mouvement;
	int position_actuel;
      SDL_Rect position;
	SDL_Surface *tab[30];
	int time;
	int score; 
	 
}PERSO_PRINCIPALE;

typedef struct ENTITE_SECONDAIRE 
{ 
SDL_Surface* enemis[34];
SDL_Surface* die[7];
SDL_Rect position;
int position_actuel;
int position_mort;
int health;

}ENTITE_SECONDAIRE ;




typedef struct Vie
{
	SDL_Surface* vie_img[4];
	SDL_Rect posVie;
	int valVie;	
}Vie;

 typedef struct Score{
	SDL_Surface* fondScore;
	SDL_Rect posFond;
	SDL_Surface* texteScore;
	TTF_Font *police;
	SDL_Rect posScore;
	int scoreActuel;
	
}Score;




typedef struct Entite
{
        SDL_Surface* enemis[5];
	SDL_Rect position;
        int sens;
}Entite;



typedef struct Time {
	SDL_Surface *msg;
	TTF_Font *font;
	int time;
	char timeString[10];
} Time;





//****** HEAD PERSONAGE *******


void init_persoP(PERSO_PRINCIPALE *p);
void afficher_personnageP(PERSO_PRINCIPALE *perso,SDL_Surface *fenetre);
void deplacement_clavier(PERSO_PRINCIPALE *perso,int sens,BACKGROUND *bg, int vitesse);
void animer_clavier(PERSO_PRINCIPALE * perso,int sens);

void deplacement_sourie(PERSO_PRINCIPALE *perso,int *sens, int k,int *right,int *left);



//********* HEAD BACKGROUD *******

void init_bk(BACKGROUND* b);
void afficher_bk(BACKGROUND *bk,SDL_Surface *fenetre);
void scrollingbg(int sens,BACKGROUND *bg,PERSO_PRINCIPALE *p,double xVel);



//********* entite secondaire *******
void initEntite(Entite E[]);
void blitEntite(Entite E[] , SDL_Surface *ecran);
void MoveEntiteleft(Entite E[]);
void MoveEntiteright(Entite E[]);
void freeEntite(Entite E[]);
int position(int x, int y);
void deplacerEntite(Entite E[], SDL_Surface *screen, SDL_Rect positionecran, int posmax , int posmin , int posmax_x , int posmin_x);


//********* score *******
void initialiserScore(Score *score );
void afficherScore(SDL_Surface *ecran , Score *score,BACKGROUND bg,int collision );



//********* vie *******
void initialiserVie(Vie *vie);
void nbVie(int collision,int *gameOver ,Vie *vie,SDL_Surface *screen);





void initializerTemps(Time *time);
void afficherTemps(Time *time,SDL_Surface **screen);






SDL_Surface *rect;
SDL_Surface *rectperso;
SDL_Rect pos2;

//int collision(SDL_Surface* a, SDL_Rect pos_a, SDL_Surface *b, SDL_Rect pos_b);
int collision(SDL_Rect pos_a,SDL_Rect pos_b);



//********* enigme *******
typedef struct
{
 SDL_Surface *img;
 SDL_Rect p;
}enigme;

void init_enigme(enigme * e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;
 int solution_e (char image []) ;
int resolution (int * running,int *run);
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;
int randGenerFunc(SDL_Surface * screen, float optt[],int *aa,int *bb);
void blitTXT(SDL_Surface * screen, float optt[],int *aa,int *bb);





//******* SAVE ********
void SaveGame(char* nomFich,PERSO_PRINCIPALE p,BACKGROUND b,Vie vie);
void LoadGame(char* nomFich,PERSO_PRINCIPALE *p,BACKGROUND* b,Vie* vie);





//********* MAP *******

int mapaffiche(SDL_Surface * screen  ,int persoPOS);

void miniMapCorner(SDL_Surface *screen,int persoPOS,int verti);






#endif
