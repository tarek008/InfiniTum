#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "joeur.h"
#include "fire.h"


void main(SDL_Surface* screen){

int x=3;
int x2=3;

int xscore=0;



//The images
PERSO_PRINCIPALE perso;
PERSO_PRINCIPALE perso2;
	BACKGROUND b;
ENTITE_SECONDAIRE ennemi;
int dT;
   double FrmStrt=0,FrmEnd=0;

	SDL_Event event;
	int sens;
	int sens2;
int direction=0;
		SDL_Rect posdT;
   double xVel,yVel,canJump=1;
   double xVel2,yVel2,canJump2=1;
   double v_jump = -7;
   double gravity = 0.2;
   int right,left;
   int right2,left2;

//collision moraba3
//pos2.x =700;
//pos2.y = 280;

pos2.x =700;
pos2.y = 250;


/*rect = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);
rectperso = SDL_CreateRGBSurface(0,32,70,32,0,0,0,0);*/


//SDL_FillRect(rectperso,NULL,0xffffff);
//SDL_FillRect(rect,NULL,0xffffff);

rect =IMG_Load("1.png");


SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	Time time;
	initializerTemps(&time);





Score score;
	initialiserScore(&score);
Vie vie;
Vie vie2;
initialiserVie(&vie);
initialiserVie2(&vie2);
	char string[20];

SDL_Rect posScore;
posScore.x=490;
	posScore.y=350;


	//initialiser la fenetre principal
	b.fenetre=screen;
	b.stage=1;


	//init bk & perso
	init_persoP(&perso);
	init_persoP2(&perso2);
	init_bk(&b);
  


//initi fire 
Clochard c;
	CLOCHARD_Init(&c);






//enigme
SDL_Surface *image1 ;
	SDL_Rect p ;
	p.x=0 ;
	p.y=0 ;
	enigme  e;
	FILE *f ;
	int s,r,run =1,running=1,alea;
	char image[30]="";
   f=fopen("test.txt","a") ;

//init enigme
 init_enigme(&e);
 if(e.img==NULL)
	 {
	 	fprintf(f,"%d\n",1800) ;
	 }	
    

 //déclaration entite secondaire
        Entite E[8] ;
        int y = 0;
        int posmax = 400;
        int posmin = 250;
        int posmax_x = 600;
        int posmin_x = 200;
 SDL_Rect positionecran;
initEntite(E);






//img gameover
SDL_Surface *gameover;
gameover=IMG_Load("gameoverr.png");







//Start SDL
    if(SDL_Init( SDL_INIT_VIDEO )!=0)
      {
        printf("Unable to initialize SDL: %s\n",SDL_GetError());
      };
//Set up screen
    screen = SDL_SetVideoMode(1200, 520, 32, SDL_HWSURFACE);
     if(screen == NULL)
      {
        printf("Unable to set video mode: %s",SDL_GetError());
      }




int continuer=1;
int vitesse=0;
int sprint=0;
int sprint2=0;
SDL_EnableKeyRepeat(100,100);




//jump
   void jump()
	{
	if (canJump==1) yVel=v_jump;
	}



while(continuer){
		FrmEnd=SDL_GetTicks();
	  	afficher_bk(&b,screen);
nbVie(0,0,&vie,screen);
nbVie(0,0,&vie2,screen);
//entite secondaire
     blitEntite(E,screen);
     deplacerEntite(E,screen,positionecran,posmax,posmin,posmax_x,posmin_x);




    while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				continuer=0;
				break;

				case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					continuer = 0;
					break;


                               case SDLK_s:
                               sprint =1;
                                     break;
                               case SDLK_c:
                               sprint2 =1;
                                     break;

                          case SDLK_u: 
		            SaveGame("save.txt",perso,b,vie);

		            break;
		            case SDLK_l: 
		            LoadGame("save.txt",&perso,&b,&vie);
                            x=vie.valVie;
                            //xscore=
		            break;


		         	case SDLK_RIGHT: // Flèche droite
	           		sens=1;
                                 right=1;		   
		           	//animer_clavier(&perso, sens);
		           	//deplacement_clavier(&perso,sens,&b,vitesse);
		           	break;

                               case SDLK_d: // Flèche droite
	           		sens2=1;
                                 right2=1;		   
		           	break;






                                        case SDLK_SPACE:
                                          jump();
                                        break;

                                case SDLK_t:
                                         yVel2=v_jump;
                                        break;


		            case SDLK_LEFT: // Flèche gauche
		            sens=2;
                                 left=1;
		           // animer_clavier(&perso, sens) ;
		            //deplacement_clavier(&perso,sens,&b,vitesse);
		            break;



                             case SDLK_q: // Flèche gauche
		            sens2=2;
                                 left2=1;		         
		            break;
		        }
		        break;




case SDL_MOUSEBUTTONDOWN:
if(SDL_BUTTON_LEFT)
{
int k=event.motion.x;
deplacement_sourie(&perso,&sens,k,&right,&left);

}
break;


case SDL_MOUSEBUTTONUP :
{(sens)=0;
right=0; left=0;
break;
}


		        case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					continuer = 0;
					break;



                                case SDLK_s: 
                                       sprint =0;
		           	break;

                                 case SDLK_c: 
                                       sprint2 =0;
		           	break;


		         	case SDLK_RIGHT: 
                                  right=0;
		           	break;

                              case SDLK_d: 
                                  right2=0;
		           	break;


		            case SDLK_LEFT: 
                                  left=0;
		            break;


                              case SDLK_q: 
                                  left2=0;
		            break;

		        }
		        break;
		        
		    }
    }	    


	//x movement
	if(right==1) {
xVel+=0.3;
animer_clavier(&perso,sens);
}


	if(right2==1) {
xVel2+=0.3;
animer_clavier(&perso2,sens2);
}


	if(left==1) {
xVel-=0.3;
animer_clavier(&perso,sens);

}
	
if(left2==1) {
xVel2-=0.3;
animer_clavier(&perso2,sens2);
}




	if(right ==0 && xVel>0.2) xVel-=0.1;
	if(left ==0 && xVel<-0.2) xVel+=0.1;

	if(right==0 && left ==0 && xVel>=-0.2 && xVel<0.2) xVel=0; //STOP threshhold




	if(right2 ==0 && xVel2>0.2) xVel2-=0.1;
	if(left2 ==0 && xVel2<-0.2) xVel2+=0.1;

	if(right2==0 && left2 ==0 && xVel2>=-0.2 && xVel2<0.2) xVel2=0; //STOP threshhold






//speed controle
if(sprint==1){
vitesse=9;
}else{
vitesse=5;
}


//speed controle2
if(sprint2==1){
vitesse=9;
}else{
vitesse=5;
}




perso.position.x +=xVel;

perso2.position.x +=xVel2;

 perso.position.y +=yVel;

 perso2.position.y +=yVel2;

yVel += gravity*2;

yVel2 += gravity*2;


if (perso.position.y > 200){
	yVel=0;canJump=1;}
if(perso.position.y < 200){
 canJump=0;
}

if (perso2.position.y > 200){
	yVel2=0;canJump2=1;}
if(perso2.position.y < 200){
 canJump2=0;
}





//enigme
if(perso.position.x >= 1100){

 while(running){

 generate_afficher ( screen  , image ,&e,&alea) ;
 s=solution_e (image );

do{
r=resolution (&running,&run);
}while((r>3 || r<1) && running!=0) ;

afficher_resultat (screen,s,r,&e) ;
running=0;

if(r==s && x<3 && x2<3){
x++;
x2++;
vie.valVie=x;
vie2.valVie=x2;
}

if(r==s){
xscore+=1000;
score.scoreActuel=xscore;
}

}

if(r!=s){
x--;
x2--;
perso.position.x=0;
perso2.position.x=80;
vie.valVie=x;
vie2.valVie=x2;
running=1;
}

}


if(xVel>vitesse) xVel=vitesse;
if(xVel<-vitesse) xVel=-vitesse;



if(xVel2>vitesse) xVel2=vitesse;
if(xVel2<-vitesse) xVel2=-vitesse;



 afficher_personnageP(&perso,screen);
//SDL_BlitSurface(rectperso,NULL,screen,&perso.position);


 afficher_personnageP(&perso2,screen);


scrollingbg(sens,&b,&perso,xVel);


scrollingbg(sens2,&b,&perso2,xVel2);


afficherTemps(&time,&screen);
			SDL_Delay(12);




afficherScore(screen,&score,b,0);
sprintf(string, "score = %d ", score.scoreActuel);


CLOCHARD_Render(&c,&screen);



//collision moraba3
/*if(collision(rectperso,perso.position,rect,pos2)){
				perso.position.x=0;
x--;
score.scoreActuel=xscore;
vie.valVie=x;
		}*/

if(collision(perso.position,pos2)){
				perso.position.x=0;
x--;
vie.valVie=x;
		}




if(collision(perso2.position,pos2)){
				perso2.position.x=0;
x2--;
vie2.valVie=x2;
		}



if(vie.valVie==0 || vie2.valVie==0){
SDL_BlitSurface(gameover, NULL, screen,0);
}

//SDL_BlitSurface(rect,NULL,b.bg,&pos2);
//CLOCHARD_Render(&c,&b.bg);





SDL_Flip(screen);

dT=SDL_GetTicks()-FrmEnd;
	if (1000/FPS>dT)
	{
        SDL_Delay(1000/FPS-dT);
	}


}


SDL_EnableKeyRepeat(0,0);

    SDL_FreeSurface(screen);    


  //  pause=getchar();

}


