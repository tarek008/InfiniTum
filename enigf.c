#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "joeur.h"
#include <math.h>
#include <tgmath.h>

void init_enigme(enigme * e)//
{
	e->p.x=0;
	e->p.y=0;
	e->img=NULL;
}

void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{
int test=*alea ;
srand(time(NULL));
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"fathallah/%d.png",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
}

 int solution_e (char image [])
 {
 	int solution =0;

 	if(strcmp(image,"fathallah/1.png")==0)
 	{
     		solution =2 ;
 	}
 	else  if(strcmp(image,"fathallah/2.png")==0)
 	{
 		solution =1;

 	}
 	 else if(strcmp(image,"fathallah/3.png")==0)
 	{
 		solution =3;
 	}
	/*else  	if(strcmp(image,"4.png")==0)
 	{
 		solution =1;

 	}
 	else 	if(strcmp(image,"5.png")==0)
 	{
 		solution =3;
 	}
	else  	if(strcmp(image,"6.png")==0)
 	{
 		solution =3;

 	}
 	else  	if(strcmp(image,"7.png")==0)
 	{
 		solution =1;

 	}
 	else  	if(strcmp(image,"8.png")==0)
 	{
 		solution =2;

 	} */


 	return solution;
 }

int resolution (int * running,int *run )//
{
	SDL_Event event ;
  		int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN :
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a:
			  r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e:
			   r=3 ;
			   break;

		}
       break ;
	}
  return r ;
}

 void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)//
 {

 	if (r==s)
 	{
 		en->img=IMG_Load("fathallah/11.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
 		en->img=IMG_Load("fathallah/00.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}

 }



int randGenerFunc(SDL_Surface *screen, float optt[],int *aa,int *bb)
{
    int ran,ranPM,j=0;
    float c,op[3],ranNum;
    SDL_Surface *texte[3]={NULL};
    SDL_Rect positionTexte[3]={0};
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    police = TTF_OpenFont("font.ttf", 30);
    srand(time(0));

    (*aa) = rand()%(20)+1;
    (*bb) = rand()%(20)+1;
	
    c=sqrt((*aa)*(*aa)+(*bb)*(*bb));
    printf("\n a=%d",(*aa));
    printf("\n b=%d",(*bb));
    printf("\n %f",c);
    ran = rand()%(3-1+1)+1;



char affiche[10][10];
    for(int i=0;i<3;i++)
    {
       // srand(time(0));
        if(ran==i+1)
        {
            printf("\n opTT %d: %.2f",i+1,c);
	    sprintf(affiche[i],"%.2f",c);
	    optt[i]=c;
        }
        else
        {
            float r = (float)rand()/(float)RAND_MAX;
            ranNum =(float)(rand()%(5-1+1)+1+r);
            printf("\n ranNUM");
            printf("\n %f",ranNum);
            ranPM =rand()%(2);
            printf("\n ranPM");
            printf("\n %d",ranPM);
            if(ranPM==1)
            {
                op[j]=fabs(c-ranNum);
                printf("\n  opNEG: %.2f",op[j]);
		sprintf(affiche[i],"%.2f",c);
		optt[i]=op[j];
                j++;
            }
            else
            {
                op[j]=c+ranNum;
                printf("\n opPOS: %.2f",op[j]);
		sprintf(affiche[i],"%.2f",c);
		optt[i]=op[j];
                j++;
            }
        }
    }
    //printf("\n Given two sides of a right triangle calculate the remaining side");
    return ran;
}

void blitTXT(SDL_Surface * screen, float optt[],int *aa,int *bb)
{

SDL_Surface *img;
SDL_Rect p;
p.x=0;
p.y=0;



	 SDL_Surface *texte[3]={NULL},*ab[2]={NULL};
    SDL_Rect positionTexte[3]={0},posab[2]={0};
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    police = TTF_OpenFont("font.ttf", 30);
	//printf("\n partie1");

img = IMG_Load("fathallah/engimealea1.png");
 SDL_BlitSurface(img,NULL,screen,&p) ;
char aa1[10],bb1[10];
char affiche[10][10];
sprintf(aa1,"a=%d",(*aa));
sprintf(bb1,"b=%d",(*bb));

sprintf(affiche[0],"%.2f",optt[0]);
sprintf(affiche[1],"%.2f",optt[1]);
sprintf(affiche[2],"%.2f",optt[2]);


ab[0]=TTF_RenderText_Blended(police,aa1, couleurNoire);
ab[1]=TTF_RenderText_Blended(police,bb1, couleurNoire);

posab[0].x =270;
        posab[0].y = 275;
        SDL_BlitSurface(ab[0], NULL, screen, &posab[0]); /* Blit du texte */
posab[1].x =440;
        posab[1].y = 275;
        SDL_BlitSurface(ab[1], NULL, screen, &posab[1]); /* Blit du texte */
	
 //printf("\n partie2");
texte[0] = TTF_RenderText_Blended(police,affiche[0], couleurNoire);
	texte[1] = TTF_RenderText_Blended(police, affiche[1], couleurNoire);
	texte[2] = TTF_RenderText_Blended(police, affiche[2], couleurNoire);

//printf("\n partie3");
positionTexte[0].x =270;
        positionTexte[0].y = 440;
        SDL_BlitSurface(texte[0], NULL, screen, &positionTexte[0]); /* Blit du texte */

positionTexte[1].x =450;
        positionTexte[1].y = 440;
        SDL_BlitSurface(texte[1], NULL, screen, &positionTexte[1]); 

positionTexte[2].x =630;
        positionTexte[2].y = 440;
        SDL_BlitSurface(texte[2], NULL, screen, &positionTexte[2]); 
	
	
	SDL_Flip(screen);

}




