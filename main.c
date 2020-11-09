#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <stdbool.h>
 #include "fonctions_SDL.h"
 
int main(int argc, char* argv[])
{
SDL_Init(SDL_INIT_VIDEO);
if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL ( utilisation memoire)
	{
		printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
		SDL_Quit(); return EXIT_FAILURE;
	}

SDL_Event evenements ; 
char ** T = allouer_tab_2D(6, 11);
T = lire_fichier("fond.txt");

char ** T1 = allouer_tab_2D(1, 6);
T1 = lire_fichier("morceau1.txt");

char ** T2 = allouer_tab_2D(3, 3);
T2 = lire_fichier("morceau2.txt");

char ** T3 = allouer_tab_2D(3, 2);
T3 = lire_fichier("morceau3.txt");

char ** T4 = allouer_tab_2D(3, 3);
T4 = lire_fichier("morceau4.txt");

char ** T5 = allouer_tab_2D(3, 3);
T5 = lire_fichier("morceau5.txt");

char ** T6 = allouer_tab_2D(2, 4);
T6 = lire_fichier("morceau6.txt");

char ** T7 = allouer_tab_2D(3, 3);
T7 = lire_fichier("morceau7.txt");

char ** T8 = allouer_tab_2D(2, 3);
T8 = lire_fichier("morceau8.txt");

char ** T9 = allouer_tab_2D(3, 3);
T9 = lire_fichier("morceau9.txt");

char ** T10 = allouer_tab_2D(3, 3);
T10 = lire_fichier("morceau10.txt");

char ** T11 = allouer_tab_2D(2, 4);
T11 = lire_fichier("morceau11.txt");

char ** T12 = allouer_tab_2D(2, 4);
T12 = lire_fichier("morceau12.txt");

bool terminer = false;

//Les attributs de l'écran 
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 194;
 
//Les attributs de la feuille de sprites + taille de chaque sprite
const int SHEET_WIDTH = 512;
const int SHEET_HEIGHT = 320;
const int SPRITE_WIDTH = 512/16; 
const int SPRITE_HEIGHT = 320/10;

	
// Créer la fenêtre
SDL_Window* fenetre = SDL_CreateWindow("Fenetre SDL", 500, 500,700, 400, SDL_WINDOW_SHOWN);

	if(fenetre == NULL) // En cas d’erreur
	{ printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
      	  SDL_Quit(); return EXIT_FAILURE; }


// Mettre en place un contexte de rendu de l’écran
SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);


//Les surfaces
SDL_Surface* screen =  SDL_LoadBMP( "pavage.bmp") ;
SDL_Texture* sprites = SDL_CreateTextureFromSurface( ecran, screen) ;


SDL_Rect SrcR;
SrcR.x = 0;
SrcR.y = 0;
SrcR.w = 320; // Largeur de l’objet en pixels (à récupérer)
SrcR.h = 194; // Hauteur de l’objet en pixels (à récupérer)

//Les différentes parties de la feuille de sprites qui vont être blittés
SDL_Rect clip[ 6 ];
//On coupe la partie en haut à gauche (premier sprite)
clip[ 0 ].x = 0;
clip[ 0 ].y = 0;
clip[ 0 ].w = SHEET_WIDTH/16;
clip[ 0 ].h = SHEET_HEIGHT/10;

//On coupe la partie en haut au milieu (second sprite)
clip[ 1 ].x = SHEET_WIDTH/16;
clip[ 1 ].y = 0;
clip[ 1 ].w = SHEET_WIDTH/16;
clip[ 1 ].h = SHEET_HEIGHT/10;

//On coupe la partie en haut à droite (troisième sprite)
clip[ 2 ].x = 2*(SHEET_WIDTH/16);
clip[ 2 ].y = 0;
clip[ 2 ].w = SHEET_WIDTH/16;
clip[ 2 ].h = SHEET_HEIGHT/10;

//On coupe la partie en bas à gauche (quatrième sprite)
clip[ 3 ].x = 3*(SHEET_WIDTH/16);
clip[ 3 ].y = 0;
clip[ 3 ].w = SHEET_WIDTH/16;
clip[ 3 ].h = SHEET_HEIGHT/10;

//On coupe la partie au milieu en bas (quatrieme partie)
clip[ 4 ].x = 4*(SHEET_WIDTH/16);
clip[ 4 ].y = 0;
clip[ 4 ].w = SHEET_WIDTH/16;
clip[ 4 ].h = SHEET_HEIGHT/10;

//On coupe la partie en bas à droite (cinquieme sprite)
clip[ 5 ].x = 5*(SHEET_WIDTH/16);
clip[ 5 ].y = 0;
clip[ 5 ].w = SHEET_WIDTH/16;
clip[ 5 ].h = SHEET_HEIGHT/10;


//Position de sprite sur l'image
SDL_Rect DstR;
DstR.x = 0;
DstR.y = 0;
DstR.w = SPRITE_WIDTH; 
DstR.h = SPRITE_HEIGHT;
// Boucle principale
//Pour qque le programme se maaintienne
while(!terminer)
{
DstR.x = 0;
DstR.y = 0;	
for(int i=0; i<6; i++){	
for (int j=0; j<10; j++){
	//SDL_RenderCopy(ecran, sprites, &clip[ 3 ], &DstR);
	if(T[i][j]=='#'){
	SDL_RenderCopy(ecran, sprites, &clip[ 3 ], &DstR);
	}
	if(T[i][j]==' '){
	SDL_RenderCopy(ecran, sprites, &clip[ 1 ], &DstR);
	}
	DstR.x = DstR.x + 32;	
	if(DstR.x == SCREEN_WIDTH){
	DstR.y = DstR.y + 32;
	DstR.x = 0;	
	}
	SDL_RenderPresent(ecran);
}}	

DstR.x= 350;
DstR.y= 10;
for(int i=0; i<6; i++){
	//SDL_RenderCopy(ecran, sprites, &clip[ 5 ], &DstR);
	if(T1[0][i]=='#'){
		DstR.x = DstR.x + 32;
		SDL_RenderCopy(ecran, sprites, &clip[ 5 ], &DstR);

		}
			SDL_RenderPresent(ecran);	
}  

DstR.x= 350;
DstR.y= 50;
for(int i=0; i<4; i++){
for (int j=0; j<5; j++){
	//SDL_RenderCopy(ecran, sprites, &clip[ 5 ], &DstR);
	
	if(T2[i][j]=='#'){
		SDL_RenderCopy(ecran, sprites, &clip[ 5 ], &DstR);}
	
	DstR.x = DstR.x + 32;
	if(DstR.x > 420){
		DstR.y = DstR.y + 32;
		DstR.x= 350;}

		
			SDL_RenderPresent(ecran);	
} }

DstR.x= 500;
DstR.y= 100;
for(int i=0; i<4; i++){
for (int j=0; j<5; j++){
	//SDL_RenderCopy(ecran, sprites, &clip[ 5 ], &DstR);
	
	if(T3[i][j]=='#'){
		SDL_RenderCopy(ecran, sprites, &clip[ 5 ], &DstR);}
	
	DstR.x = DstR.x + 32;
	if(DstR.x > 420){
		DstR.y = DstR.y + 32;
		DstR.x= 350;}

		
			SDL_RenderPresent(ecran);	
} }

DstR.x= 500;
DstR.y= 250;
for(int i=0; i<4; i++){
for (int j=0; j<5; j++){
	//SDL_RenderCopy(ecran, sprites, &clip[ 5 ], &DstR);
	
	if(T5[i][j]=='#'){
		SDL_RenderCopy(ecran, sprites, &clip[ 5 ], &DstR);}
	
	DstR.x = DstR.x + 32;
	if(DstR.x > 420){
		DstR.y = DstR.y + 32;
		DstR.x= 350;}

		
			SDL_RenderPresent(ecran);	
} }

	while( SDL_PollEvent( &evenements ) )
		switch(evenements.type){
			case SDL_QUIT:
				terminer = true; 
			break;
			case SDL_KEYDOWN:
				switch(evenements.key.keysym.sym){
					case SDLK_ESCAPE:
						case SDLK_q:
							terminer = true; 
						break;
				}
		}
}
desallouer_tab_2D(T12, 2);
desallouer_tab_2D(T11, 2);
desallouer_tab_2D(T10, 3);
desallouer_tab_2D(T9, 3);
desallouer_tab_2D(T8, 2);
desallouer_tab_2D(T7, 3);
desallouer_tab_2D(T6, 2);
desallouer_tab_2D(T5, 3);
desallouer_tab_2D(T4, 3);
desallouer_tab_2D(T2, 3);
desallouer_tab_2D(T3, 3);
desallouer_tab_2D(T1, 1);
desallouer_tab_2D(T, 6);
SDL_DestroyTexture(sprites);
SDL_FreeSurface(screen);
SDL_DestroyRenderer(ecran);
SDL_DestroyWindow(fenetre);
SDL_Quit(); //libere la SDL de la memoire
return 0;
}
