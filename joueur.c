#include "joeur.h"
 void init_persoP(PERSO_PRINCIPALE *p)
{
p->position.x=400;
p->position.y=520;
char nomFich[22];

int i;
for(i=0;i<=21;i++)
{
    sprintf(nomFich,"bunny/%d.png",i);
    p->tab[i]=IMG_Load(nomFich);
}
p->position_actuel=11;
p->time=0;
p->score=0;
p->vie=5;
}


void afficher_personnageP(PERSO_PRINCIPALE *perso,SDL_Surface *fenetre)
{
    SDL_BlitSurface(perso->tab[perso->position_actuel],NULL,fenetre,&(perso->position));
}


void deplacement_clavier(PERSO_PRINCIPALE *perso,int sens, int bg , int vitesse)
{

if(sens==1)
    {
        
        perso->position.x+=vitesse;

    }


    if(sens==2)
    {
  
        perso->position.x-=vitesse;
    }
 
       }
    


void animer_clavier(PERSO_PRINCIPALE* perso,int sens)
{
    if(sens==2) //3al lisar
    {
        if(perso->position_actuel>10)
        {
            perso->position_actuel=0;
        }
        else
        {
            if(perso->position_actuel<10)
            {
            	perso->position_actuel++;
            }
            else 
            {
                perso->position_actuel=0;
            }
        }
    }
    else if(sens==1)
    {
        if(perso->position_actuel<11)
        {
            perso->position_actuel=21;
        }
        else
        {
            if(perso->position_actuel<21)
            {
                perso->position_actuel++;
            }
            else
            {
                perso->position_actuel=11;
            }
        }
    }
}

