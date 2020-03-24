prog:main.o joueur.o
	gcc main.o joueur.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g
joueur.o:joueur.c
	gcc -c joueur.c -g

