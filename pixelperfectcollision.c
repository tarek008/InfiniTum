#include"joeur.h"

/*int collision(SDL_Surface *a, SDL_Rect pos_a, SDL_Surface *b, SDL_Rect pos_b){
	/*for(int xa = pos_a.x; xa < pos_a.x + a->w; xa++){
		for(int ya = pos_a.y; ya < pos_a.y + a->h; ya++){
			for(int xb = pos_b.x; xb < pos_b.x + b->w; xb++){
				for(int yb = pos_b.y; yb < pos_b.y + b->h; yb++){
					if(xa == xb && ya == yb)
						return 1;
				}
			}
			
		}
	}


*/
int collision(SDL_Rect pos_a, SDL_Rect pos_b){
if(((pos_a.x+pos_a.w)<pos_b.x)||(pos_a.x>(pos_b.x+pos_b.w))||((pos_a.y+pos_a.h)<(pos_b.y))||(pos_a.y>(pos_b.y+pos_b.h))){
return 0;
}else{
return 1;
}

}
