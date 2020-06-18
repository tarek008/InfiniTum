#include "fichier.h"
#include "SDL.h"
int Gestiondutemps(int *Tempsactuel,int tempmax)
{
if (Tempsactuel<Tempmax){return 0;
sdl_delay(1000);
(*Tempsactuel)++;
}
else{return -1;}
}
