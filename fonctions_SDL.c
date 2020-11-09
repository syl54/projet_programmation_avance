#include<stdio.h>
#include <stdlib.h>
#include<SDL2/SDL.h>
#include  "fonctions_SDL.h"


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
 
    offset.x = x;
    offset.y = y;
 
    //On blitte la surface
    SDL_BlitSurface( source, clip, destination, &offset );
}


//doit charger une image et retourner la surface de texture
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer){
 	

	SDL_Surface* surface =  SDL_LoadBMP( nomfichier) ;
	SDL_Texture*texture = SDL_CreateTextureFromSurface( renderer, surface) ;
 	
 	
 	return texture;
 	
 	SDL_FreeSurface(surface) ;

	SDL_DestroyTexture(texture) ;
}



//charger image transparente 
SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b) {

	
	SDL_Surface* surface = SDL_LoadBMP( nomfichier) ;
	
	SDL_Texture* texture;
  	 

	
	// Récupérer les attributs d’une texture
	//int SDL_QueryTexture( texture, Uint32* format, int* access, int* w, int* h) ;
 	
	// Récupérer la valeur (RGB) du pixel au format donné.
	//Uint32 couleur= SDL_MapRGB(const SDL_PixelFormat* format, r, g, b);
	
	// Définir la couleur (pixel transparent) dans une surface.
	//int SDL_SetColorKey(SDL_Surface* surface, int flag, couleur) ;
	
	texture = SDL_CreateTextureFromSurface( renderer, surface) ;


	return texture;
	SDL_FreeSurface(surface) ;

	SDL_DestroyTexture(texture) ;
	
}


char** lire_fichier(const char* nomFichier)
{	
	FILE* file = fopen(nomFichier,"r");

	char** tab = malloc(30*sizeof(char*));
	if(tab == NULL){exit(EXIT_FAILURE);}
	for(int i = 0; i < 30 ; i++){
	tab[i] = malloc(30*sizeof(char));}
	
	if (file==NULL){
		perror ("Error opening file");}
	else 
	{
		for(int i=0; i<6 ; i++){
			for(int j=0; j<10 ; j++){
			fscanf(file,"%c",&tab[i][j]); 
			
	}}
	fclose(file);}
	return tab ; 
}
char ** allouer_tab_2D(int n, int m)
{
	char ** T = malloc(n*sizeof(char*));
	if(T == NULL){
	exit(EXIT_FAILURE);}
	for(int i = 0; i < n ; i++){
	T[i] = malloc(m*sizeof(char));}
	return T;
}

void desallouer_tab_2D(char** tab, int n)
{
	for(int i = 0; i < n; i++){
	free(tab[i]);}
	free(tab);
	tab = NULL;
}

void afficher_tab_2D(char** tab, int n, int m)
{
	for( int i=0 ; i<n ; i++)
	{
		for (int j=0 ; j<m ; j++){
	printf("%c",tab[i][j]);
	} }
}
/*compter le nombre max de lignes (nbLig) et de colonnes (nbCol) dans le fichier
dont le nom est nomFichier*/
void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol)
{
printf("Taille du fichier %s :  %d x %d \n", nomFichier, *nbLig, *nbCol);
}


char ** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau)
{

	for (int i=0 ; i<n ; i++){
		for (int j=0 ; j<m ; j++){
			tab[i][j]= tab[i][j];	
			if ( tab[i][j] == ancien ) {
				tab[i][j] = nouveau ;
			}

	}}
	return tab;
}

