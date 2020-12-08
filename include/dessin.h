#include <stdio.h>
#include "../include/struct.h"

void dessin(Brique **tabBriques, int nbLignes, int nbColonnes, SDL_Renderer *renderer);
void creer_briques(Brique **tabBriques,int nbLignes, int nbColonnes);
void dessiner_raquette(SDL_Renderer *renderer, Raquette raquette);
Raquette *creer_raquette();
void dessiner_raquette(SDL_Renderer *renderer, Raquette raquette);
void capturer_event_keyboard(SDL_Event e, Raquette *raq);