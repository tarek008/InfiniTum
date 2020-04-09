#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"
//#include "enigf.c"
int main()
{ 

	SDL_Surface *screen,*image1 ;
	SDL_Rect p ;
	p.x=0 ;
	p.y=0 ;
	enigme  e;
	FILE *f ;
	int s,r,run =1,running=1,alea;
	char image[30]="";
	 SDL_Event event;
   f=fopen("test.txt","a") ;
	 
	 SDL_Init ( SDL_INIT_VIDEO ) ;

	 screen=SDL_SetVideoMode(1366,768,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF | SDL_FULLSCREEN );


	 init_enigme(&e);
	
	 if(e.img==NULL)
	 {
	 	fprintf(f,"%d\n",1800) ;

	 }	
    
	
	 	 
	 
	 while (run)
	 {
		 running=1,r=0 ;
	   SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                run = 0;
	 break ;
	

        }	
        	fprintf(f,"%d\n",e.p.x) ;
	         fprintf(f,"%d\n",e.p.y) ;
         generate_afficher ( screen  , image ,&e,&alea) ;
	        fprintf(f,"%s\n",image) ;

      s=solution_e (image );
			do{
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;
			fprintf(f,"run=%d\n",run) ;
			fprintf(f,"s= %d\nr=%d\n",s,r) ;
			
      while(running){

				afficher_resultat (screen,s,r,&e) ;
			  SDL_WaitEvent(&event);
        switch(event.type)
        {
					 case SDL_QUIT :
            running =0 ;
						run=0 ;
					  break ;
            case SDL_KEYDOWN :
						    
                  switch( event.key.keysym.sym )
                {
			             case  SDLK_ESCAPE: 
			              running= 0 ;
run=0 ;

			              break ;
case SDLK_SPACE:
running=0;
break;
			  
			   
			          }
						break ;
        }
				
			

			}
			
	
	
	
   }
	 fclose(f) ;
      SDL_FreeSurface(screen);
      SDL_Quit();
	return 0;
}
