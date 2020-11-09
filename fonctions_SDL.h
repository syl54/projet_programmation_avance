#include<stdio.h>
#include <stdlib.h>
#include<SDL2/SDL.h>



void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);

//charger image et retourner la surface de texture associé 
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer);


//charger image transparente 
SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b) ;


char** lire_fichier(const char* nomFichier);


char ** allouer_tab_2D(int n, int m);
void desallouer_tab_2D(char** tab, int n);
void afficher_tab_2D(char** tab, int n, int m);
void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol);
char ** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau);


