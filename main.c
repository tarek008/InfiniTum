#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "joeur.h"


void main(SDL_Surface* screen){

//The images
PERSO_PRINCIPALE perso;
	BACKGROUND b;
ENTITE_SECONDAIRE ennemi;
int dT;
   double FrmStrt=0,FrmEnd=0;

	SDL_Event event;
	int sens;
int direction=0;
		SDL_Rect posdT;
   double xVel,yVel,canJump=1;
   double v_jump = -10;
   double gravity = 0.2;
   int right,left;



	//initialiser la fenetre principal
	b.fenetre=screen;
	b.stage=1;


	//init bk & perso
	init_persoP(&perso);
	init_bk(&b);
  

//Start SDL
    if(SDL_Init( SDL_INIT_VIDEO )!=0)
      {
        printf("Unable to initialize SDL: %s\n",SDL_GetError());
      };
//Set up screen
    screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE);
     if(screen == NULL)
      {
        printf("Unable to set video mode: %s",SDL_GetError());
      }




int continuer=1;
int vitesse=0;
int sprint=0;
SDL_EnableKeyRepeat(100,100);




//jump
   void jump()
	{
	if (canJump==1) yVel=v_jump;
	}


while(continuer){
		FrmEnd=SDL_GetTicks();
	  	afficher_bk(&b,screen);
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


		         	case SDLK_RIGHT: // Flèche droite
	           		sens=1;
                                 right=1;
		           	animer_clavier(&perso, sens);
		           	deplacement_clavier(&perso,sens,&b,vitesse);



	 	      		
		           	break;

                                        case SDLK_SPACE:
                                          jump();
                                        break;



		            case SDLK_LEFT: // Flèche gauche
		            sens=2;
                                 left=1;
		            animer_clavier(&perso, sens) ;
		            deplacement_clavier(&perso,sens,&b,vitesse);



		            break;
		           

		        }
		        break;

		        case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					continuer = 0;
					break;



                                case SDLK_s: 
                                       sprint =0;
		           	break;

		         	case SDLK_RIGHT: 
                                  right=0; 
		           	break;

		            case SDLK_LEFT: 
                                  left=0;
		            break;

		        }
		        break;
		        


		    }

    }	    



	//x movement
	if(right==1) {
//sens=1;
xVel+=0.3;
	//animer_clavier(&perso, sens);
	//scrollingbg(sens,&b,&perso); 
	//deplacement_clavier(&perso,sens,&b,vitesse);
}


	if(left==1) {
xVel-=0.3;
//animer_clavier(&perso, sens) ;
//scrollingbg(sens,&b,&perso);
//deplacement_clavier(&perso,sens,&b,vitesse);
}


	if(right ==0 && xVel>0.2) xVel-=0.1;
	if(left ==0 && xVel<-0.2) xVel+=0.1;

	if(right==0 && left ==0 && xVel>=-0.2 && xVel<0.2) xVel=0; //STOP threshhold


//speed controle
if(sprint==1){
vitesse=9;
}else{
vitesse=5;
}


perso.position.x +=xVel;


 perso.position.y +=yVel;
yVel += gravity*2;

if (perso.position.y > 400){
	yVel=0;canJump=1;}
if(perso.position.y < 400){
 canJump=0;
}


if(xVel>vitesse) xVel=vitesse;
if(xVel<-vitesse) xVel=-vitesse;

 afficher_personnageP(&perso,screen);
//afficherentite(&ennemi,screen);
//afficherennemi(&ennemi, screen,1);
scrollingbg(sens,&b,&perso,xVel);









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

