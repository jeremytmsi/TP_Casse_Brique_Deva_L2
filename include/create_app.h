#include <SDL.h>
#include <stdio.h>

SDL_Window *creerFenetre(char *titreFenetre, int longueur, int largeur, Uint32 modeAffichage);

void close_app(SDL_Window *window,SDL_Surface *surface);