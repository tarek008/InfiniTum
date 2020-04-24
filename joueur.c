#include "joeur.h"
 void init_persoP(PERSO_PRINCIPALE *p)
{

 p->position.x=500;
  p->position.y=200;
  p->position.w=1200;
  p->position.h=600;



char nomFich[22];

int i;
for(i=0;i<=21;i++)
{
    sprintf(nomFich,"wal/%d.png",i);
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


void deplacement_clavier(PERSO_PRINCIPALE *perso,int sens, BACKGROUND *bg , int vitesse)
{

if(sens==1)
    {
    if(perso->position.x>255)
        perso->position.x-=vitesse;
        else
        perso->position.x+=vitesse;
   }


    if(sens==2)
    {
       if(perso->position.x<545)
        perso->position.x+=vitesse;
        else
        perso->position.x+=vitesse;
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




void deplacement_sourie(PERSO_PRINCIPALE *perso,int *sens, int k,int *right,int *left)
{
int z=(perso->position.x)-k;
if(z>0) {
*sens=2;
*left=1;
}
if(z<0) {
*sens=1;
*right=1;
}
       }















