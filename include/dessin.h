#include <stdio.h>
#include "../include/struct.h"

void dessin(Brique **tabBriques, int nbLignes, int nbColonnes, SDL_Renderer *renderer);
Brique **creer_briques(int nbLignes, int nbColonnes);