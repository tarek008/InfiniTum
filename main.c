#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "joeur.h"


void main(SDL_Surface* screen){
//The images
    SDL_Surface *image = NULL;

    SDL_Rect positionecran;
PERSO_PRINCIPALE perso;
	SDL_Event event;
	int sens;

	init_persoP(&perso);


//Start SDL
    if(SDL_Init( SDL_INIT_VIDEO )!=0)
      {
        printf("Unable to initialize SDL: %s\n",SDL_GetError());
      };
//Set up screen
    screen = SDL_SetVideoMode(1300, 1000, 32, SDL_HWSURFACE);
     if(screen == NULL)
      {
        printf("Unable to set video mode: %s",SDL_GetError());
      }

   image = IMG_Load("map.jpg");
     if(image == NULL)
       {
         printf("Unable to load bitmap: %s\n",SDL_GetError());
       }
   positionecran.x=0;
   positionecran.y=0;
   positionecran.w=image->w;
   positionecran.h=image->h;
   

   SDL_BlitSurface(image,NULL,screen,&positionecran);


int continuer=1;
int vitesse=0;
int sprint=0;
SDL_EnableKeyRepeat(100,100);

while(continuer){
   SDL_BlitSurface(image,&positionecran,screen,NULL);
					afficher_personnageP(&perso,screen);

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
		           	animer_clavier(&perso, sens);
		           	//scrollingbg(sens,&b,&perso); 
		           	deplacement_clavier(&perso,sens,0,vitesse);


               
	 	      		
		           	break;

                              

		            case SDLK_LEFT: // Flèche gauche
		            sens=2;

		            animer_clavier(&perso, sens) ;
		            //scrollingbg(sens,&b,&perso);

		            deplacement_clavier(&perso,sens,0,vitesse);

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

		           	break;

		            case SDLK_LEFT: 

		            break;

		        }
		        break;
		        
	

		    }

    }	    
if(sprint==1){
vitesse=9;
}else{
vitesse=3;
}

	    SDL_Delay(5);

SDL_Flip(screen);
}
SDL_EnableKeyRepeat(0,0);



    SDL_FreeSurface(screen);    
    SDL_FreeSurface(image);
    SDL_FreeSurface(screen);

    


}





