#include <stdio.h>
#include "../include/struct.h"

void dessin(Brique **tabBriques, int nbLignes, int nbColonnes, SDL_Surface *ecran, SDL_Window *window);
void creer_briques(Brique **tabBriques,int nbLignes, int nbColonnes);
Raquette *creer_raquette();
void dessiner_raquette(Raquette raquette, SDL_Surface *ecran,SDL_Window *window);
void capturer_event_keyboard(SDL_Event e, Raquette *raq);